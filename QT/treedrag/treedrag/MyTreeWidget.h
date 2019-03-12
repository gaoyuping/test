#include <QTreeWidget>
#include <QMimeData>
#include <QKeyEvent>
#include <QTreeWidgetItem>
#include <QStack>

class TreeItemMimeData:public QMimeData  
{  
    Q_OBJECT  
public:  
    TreeItemMimeData():QMimeData()  
    {  
        m_pDragItem = NULL;  
    }  
  
    ~TreeItemMimeData()  
    {  
  
    }  
  
    void SetDragData(QString mimeType , QTreeWidgetItem *pItem)  
    {  
        m_format<<mimeType;  
        m_pDragItem = pItem;  
    }  
      
  
  
    QStringList formats() const  
    {  
        return m_format;  
    }  
  
    const QTreeWidgetItem* DragItemData() const  
    {  
        return m_pDragItem;  
    }  
  
  
protected:  
  
    QVariant retrieveData(const QString &mimetype, QVariant::Type preferredType) const  
    {  
        if (mimetype == "ItemMimeData")  
        {  
            return m_pDragItem;  
        }  
        else  
        {  
             return QMimeData::retrieveData(mimetype, preferredType);    
        }  
    }  
private:  
    const QTreeWidgetItem   *m_pDragItem;  
    QStringList              m_format;  
};  
  
class MyTreeWidget:public QTreeWidget  
{  
    Q_OBJECT  
public:  
    MyTreeWidget(QWidget *parent = NULL);  
    ~MyTreeWidget();  
public:
    bool eventFilter(QObject *watched, QEvent *event);
    void focusOutEvent(QFocusEvent *event);
protected:  
    void mouseMoveEvent(QMouseEvent *event);  
    void mousePressEvent(QMouseEvent *event);  
    void mouseReleaseEvent(QMouseEvent *event);  
    void dragEnterEvent(QDragEnterEvent *event);  
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);  
    void dropEvent(QDropEvent *event);  
    void keyPressEvent(QKeyEvent *event);  
    void keyReleaseEvent(QKeyEvent *event);  
private:  
    QPoint     m_startDragPoint;  
    void       performDrag(QPoint);
    QPoint lastdragpos;
    QDrag *m_movedrag;
    bool       m_CtrlPressed;  
    bool       m_drag;
  
};  
