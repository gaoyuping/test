#include "MyTreeWidget.h"
#include <QApplication>
#include <QDrag>
#include <windows.h>
#include <QEvent>
#include <QDebug>
#include <QPainter>

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
    const TreeItemMimeData *pMimeData = dynamic_cast<const TreeItemMimeData*>(event->mimeData());
    const QObject *pMimeData1 = dynamic_cast<const QObject*>(event->mimeData());
    QObject * ptr = this;
    if (source && pMimeData)
    {    
        const QTreeWidgetItem *item = dynamic_cast<const QTreeWidgetItem*>(pMimeData->DragItemData());
        QTreeWidgetItem *pItem = dynamic_cast<QTreeWidgetItem*>(item->clone());
        QTreeWidgetItem *currentItem = dynamic_cast<QTreeWidgetItem*>(this->itemAt(event->pos()));
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
    QTreeWidgetItem *item = dynamic_cast<QTreeWidgetItem*>(currentItem());
    if (item)   
    {
        //if (item->getlevel()<0)
        {
            TreeItemMimeData *mimeData = new TreeItemMimeData;
            mimeData->SetDragData("ItemMimeData", item);
            m_movedrag = new QDrag(this);
            m_movedrag->setMimeData(mimeData);
            QPixmap sss(width(), 20);
            QPainter spaint(&sss);
            QBrush brush(QColor(255, 255, 0,100));
            spaint.setBrush(brush);
            spaint.drawRect(-1, -1, sss.width() + 1, 20 + 1);
            spaint.drawText(QRectF(5, 5, 150, 20), item->text(0));
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
                if (Qt::IgnoreAction != ret)
                {
                    delete item;
                }
                else
                {
                    //();
                }
            }
            m_movedrag->deleteLater();
            m_movedrag = nullptr;
            ::ClipCursor(nullptr);
        }
    }   
}  
