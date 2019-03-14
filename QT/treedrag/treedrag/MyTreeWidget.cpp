#include "MyTreeWidget.h"
#include <QApplication>
#include <QDrag>
#include <windows.h>
#include <QEvent>
#include <QDebug>
#include <QPainter>



QTreeItem::QTreeItem()
    :QTreeWidgetItem()
{
    d_ptr = new QTreeItemPrivate();
}
QTreeItem::QTreeItem(QTreeWidget *view, const QStringList &strings, int type)
    : QTreeWidgetItem(view, strings, type)
{
    d_ptr = new QTreeItemPrivate();
    Q_D(QTreeItem);
    d->m_strid = strings.at(0).toStdString();
}
QTreeItem::QTreeItem(QTreeWidgetItem *parent, const QStringList &strings, int type)
    : QTreeWidgetItem(parent, strings, type)
{
    d_ptr = new QTreeItemPrivate();
    Q_D(QTreeItem);
    d->m_strid = strings.at(0).toStdString();
}
QTreeItem::QTreeItem(int type)
    :QTreeWidgetItem(type)
{
    d_ptr = new QTreeItemPrivate();
}
QTreeItem::QTreeItem(const QStringList &strings, int type)
    : QTreeWidgetItem(strings, type)
{
    d_ptr = new QTreeItemPrivate();
}
QTreeItem::QTreeItem(QTreeWidget *view, int type)
    : QTreeWidgetItem(view, type)
{
    d_ptr = new QTreeItemPrivate();
}
QTreeItem::QTreeItem(QTreeWidget *view, QTreeWidgetItem *after, int type)
    : QTreeWidgetItem(view, after, type)
{
    d_ptr = new QTreeItemPrivate();
}
// QTreeItem::QTreeItem(QTreeWidgetItem *parent, int type = Type)
//     : QTreeWidgetItem(parent, type)
// {
//     
// }
QTreeItem::QTreeItem(QTreeWidgetItem *parent, QTreeWidgetItem *after, int type)
    : QTreeWidgetItem(parent, after, type)
{
    d_ptr = new QTreeItemPrivate();
}
QTreeItem::QTreeItem(const QTreeWidgetItem &other)
    : QTreeWidgetItem(other)
{
    d_ptr = new QTreeItemPrivate();
}


QTreeItem::~QTreeItem()
{

}

std::string QTreeItem::getStrId()
{
    Q_D(QTreeItem);
    return d->m_strid;
}

void QTreeItem::setStrId(std::string strid)
{
    Q_D(QTreeItem);
    d->m_strid = strid;
}

int QTreeItem::getilevel()
{
    Q_D(QTreeItem);
    return d->m_ilevel;
}

void QTreeItem::setilevel(int ilevel)
{
    Q_D(QTreeItem);
    d->m_ilevel = ilevel;
}

QTreeItem *QTreeItem::clone() const
{
    QTreeItem *copy = 0;

    QStack<const QTreeWidgetItem*> stack;
    QStack<QTreeWidgetItem*> parentStack;
    stack.push(this);
    parentStack.push(0);

    QTreeItem *root = 0;
    const QTreeItem *item = 0;
    QTreeItem *parent = 0;
    while (!stack.isEmpty()) {
        // get current item, and copied parent
        item = dynamic_cast<const QTreeItem*>(stack.pop());
        parent = dynamic_cast<QTreeItem*>(parentStack.pop());

        // copy item
        copy = new QTreeItem(*item);
        if (!root)
            root = copy;

        // set parent and add to parents children list
        if (parent) {
            parent->insertChild(0, copy);
        }

        for (int i = 0; i < item->childCount(); ++i) {
            stack.push(item->child(i));
            parentStack.push(copy);
        }
    }
    return root;
}
/////////////////////////////////////////////////////////////////////////
MyTreeWidget::MyTreeWidget(QWidget *parent /*= NULL*/):QTreeWidget(parent)  
{  
    m_CtrlPressed = false;  
    this->setSelectionMode(QAbstractItemView::ExtendedSelection);  
    this->setAcceptDrops(true);
    this->setDragEnabled(true);
    m_drag = true;
    m_movedrag = new QDrag(this);
    installEventFilter(this);
}  
  
MyTreeWidget::~MyTreeWidget()  
{  
}  


bool MyTreeWidget::eventFilter(QObject *watched, QEvent *event)
{
    QMouseEvent* mevent = (QMouseEvent*)event;
    switch (mevent->type())
    {
    case QEvent::MouseMove:
        {
            int ii = 0;
        }
        break;
    default:
        //qDebug() << mevent->type();
        break;
    }

    return QTreeWidget::eventFilter(watched, event);
}

void MyTreeWidget::focusOutEvent(QFocusEvent *event)
{
    if (m_movedrag)
    {
        ::ClipCursor(nullptr);
        qDebug() << "MyTreeWidget::focusOutEvent......................";
        emit m_movedrag->cancel();
        //QApplication::postEvent(this, event, 0);
    }
    QTreeWidget::focusOutEvent(event);
}

void MyTreeWidget::keyPressEvent(QKeyEvent *event)  
{  
    if (event->key() == Qt::Key_Control)  
    {  
        m_CtrlPressed = true;  
    }  
}  
  
void MyTreeWidget::keyReleaseEvent(QKeyEvent *event)  
{  
    if (event->key() == Qt::Key_Control)  
    {  
        m_CtrlPressed = false;  
    }  
}  
  
void MyTreeWidget::mousePressEvent(QMouseEvent *event)  
{  
    if (event->button() == Qt::LeftButton)  
    {  
        m_startDragPoint = event->pos();  
    }  
    QTreeWidget::mousePressEvent(event);  
}  
  
void MyTreeWidget::mouseMoveEvent(QMouseEvent *event)  
{  
    if (event->buttons() & Qt::LeftButton)  
    {  
        int dragDistance = (event->pos() - m_startDragPoint).manhattanLength();  
        if (dragDistance > QApplication::startDragDistance())  
        {  
            performDrag(event->pos());
        }  
    }  
    QTreeWidget::mouseMoveEvent(event);  
}
  
void MyTreeWidget::mouseReleaseEvent(QMouseEvent *event)  
{  
    QTreeWidget::mouseReleaseEvent(event);  
}  
  
void MyTreeWidget::dragEnterEvent(QDragEnterEvent *event)  
{  
    qDebug() << "MyTreeWidget::dragEnterEvent";
    if (!m_drag)
    {
        return;
    }
    QWidget *source =  qobject_cast<MyTreeWidget *>(event->source());    
    if (source /*&& source != this*/)   
    {    
        if (m_CtrlPressed)  
        {  
            event->setDropAction(Qt::CopyAction);    
        }   
        else  
        {  
            event->setDropAction(Qt::MoveAction);    
        }  
        event->accept();    
    }    
}

void MyTreeWidget::dragLeaveEvent(QDragLeaveEvent *event)
{
    qDebug() << "MyTreeWidget::dragLeaveEvent";
}

void MyTreeWidget::dragMoveEvent(QDragMoveEvent *event)  
{
    lastdragpos =  event->pos();
    //qDebug() << QCursor::pos().y();
    QWidget *source =  qobject_cast<MyTreeWidget *>(event->source());    
    if (source)  
    {    
        //do something
    } 
}  
  
void MyTreeWidget::dropEvent(QDropEvent *event)  
{
    qDebug() << "MyTreeWidget::dropEvent";
    QWidget *source =  qobject_cast<MyTreeWidget *>(event->source());   
    TreeItemMimeData *pMimeData = dynamic_cast<TreeItemMimeData*>((QMimeData *)event->mimeData());
    const QObject *pMimeData1 = dynamic_cast<const QObject*>(event->mimeData());
    QObject * ptr = this;
    if (source && pMimeData)
    {    
        const QTreeItem *item = dynamic_cast<const QTreeItem*>(pMimeData->DragItemData());
        QTreeItem *pItem = dynamic_cast<QTreeItem*>(item->clone());
        QTreeItem *currentItem = dynamic_cast<QTreeItem*>(this->itemAt(event->pos()));
        if (!pItem)
        {
            return;
        }
        if (currentItem)
        {
            currentItem->addChild(pItem);
        }
        else  
        {
            this->addTopLevelItem(pItem);  
        }
        if (m_CtrlPressed)  
        {
            event->setDropAction(Qt::CopyAction);
        }
        else
        {
            event->setDropAction(Qt::MoveAction);
        }
        event->accept();
    }
}

void MyTreeWidget::performDrag(QPoint mvpos)
{  
    m_item = dynamic_cast<QTreeItem*>(currentItem());
    if (m_item)
    {
        //if (item->getlevel()<0)
        {
            TreeItemMimeData *mimeData = new TreeItemMimeData;
            mimeData->SetDragData("ItemMimeData", m_item);
            m_movedrag = new QDrag(this);
            m_movedrag->setMimeData(mimeData);
            qDebug() << mimeData;
            QPixmap sss(width(), 20);
            QPainter spaint(&sss);
            QBrush brush(QColor(255, 255, 0,100));
            spaint.setBrush(brush);
            spaint.drawRect(-1, -1, sss.width() + 1, 20 + 1);
            spaint.drawText(QRectF(5, 5, 150, 20), m_item->text(0));
            m_movedrag->setPixmap(sss);
            int i = sss.width();
            i = sss.height();
            m_movedrag->setHotSpot(QPoint(mvpos.x(), m_movedrag->pixmap().height() / 2));
            RECT mainWinRect; //RECT在windef.h中被定义
            mainWinRect.left = (LONG)QCursor::pos().x();
            mainWinRect.right = (LONG)QCursor::pos().x()+1;
            mainWinRect.top = (LONG)mapToGlobal(geometry().topLeft()).y() - m_movedrag->pixmap().height() / 2;
            mainWinRect.bottom = (LONG)(mainWinRect.top + geometry().height() - m_movedrag->pixmap().height() / 2 - 1);
            QRect ssrect = geometry();
            ::ClipCursor(&mainWinRect);
            Qt::DropAction ret;
            if (m_CtrlPressed)
            {
                ret = m_movedrag->exec(Qt::CopyAction);
            }
            else
            {
                ret = m_movedrag->exec(Qt::MoveAction);
//                 if (Qt::IgnoreAction != ret)
//                 {
//                     delete item;
//                 }
//                 else
//                 {
//                     //();
//                 }
            }
            m_movedrag->deleteLater();
            m_movedrag = nullptr;
            ::ClipCursor(nullptr);
        }
    }   
}  
