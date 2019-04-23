#include <QTreeWidget>
#include <QMimeData>
#include <QKeyEvent>
#include <QTreeWidgetItem>
#include <QStack>

class QTreeItemPrivate
{
    friend class QTreeItem;
public:
    QTreeItemPrivate() {};
    ~QTreeItemPrivate() {};

    std::string m_strid;
    int m_ilevel;
private:
};

class QTreeItem : public QTreeWidgetItem
{
public:
    ~QTreeItem();
    QTreeItem();


    explicit QTreeItem(int type = Type);
    explicit QTreeItem(const QStringList &strings, int type = Type);

    QTreeItem(QTreeWidget *view, const QStringList &strings, int type = Type);
    explicit QTreeItem(QTreeWidget *view, int type = Type);
    QTreeItem(QTreeWidget *view, QTreeWidgetItem *after, int type = Type);

    QTreeItem(QTreeWidgetItem *parent, const QStringList &strings, int type = Type);
    explicit QTreeItem(QTreeWidgetItem *parent, int type = Type);
    QTreeItem(QTreeWidgetItem *parent, QTreeWidgetItem *after, int type = Type);

    QTreeItem(const QTreeWidgetItem &other);

    std::string getStrId();
    void  setStrId(std::string strid);

    int getilevel();
    void setilevel(int ilevel);
    QTreeItem *QTreeItem::clone() const;
private:
    QTreeItemPrivate *d_ptr;
    Q_DECLARE_PRIVATE(QTreeItem);
};

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
  
    void SetDragData(QString mimeType , QTreeItem *pItem)
    {  
        m_format<<mimeType;  
        m_pDragItem = pItem;  
    }  
      
  
  
    QStringList formats() const  
    {  
        return m_format;  
    }  
  
    const QTreeItem* DragItemData() const
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
    const QTreeItem   *m_pDragItem;
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
public slots:
    void slot_itemSelectionChanged();
    void slot_itemExpanded(QTreeWidgetItem *);
    void slot_itemCollapsed(QTreeWidgetItem *);
    protected slots:
    void verticalScrollbarValueChanged(int value);
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
    QTreeItem *m_item;
  
};  
