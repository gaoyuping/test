#ifndef QMYTREEDELEGATE_H
#define QMYTREEDELEGATE_H

#include <QStyledItemDelegate>
#include <QComboBox>
class QMyTreeDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    QMyTreeDelegate(QObject *parent);
    ~QMyTreeDelegate();

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    QWidget *createEditor(QWidget *parent,
        const QStyleOptionViewItem &/* option */,
        const QModelIndex & index) const
    {
        if (index.column() == 1) //只对第4列采用此方法编辑
        {
            QComboBox* box = new QComboBox(parent);
            box->addItems(QStringList() << "优" << "良" << "差");
            return box;
        }
        return NULL;
    }

    void setEditorData(QWidget *editor,
        const QModelIndex &index) const
    {
        QString value = index.model()->data(index, Qt::EditRole).toString();
        QComboBox* box = static_cast<QComboBox*>(editor);
        box->setCurrentText(value);
    }

    void setModelData(QWidget *editor, QAbstractItemModel *model,
        const QModelIndex &index) const
    {
        QComboBox* box = static_cast<QComboBox*>(editor);
        model->setData(index, box->currentText(), Qt::EditRole);
    }

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
    {
        editor->setGeometry(option.rect);
    }
private:
    
};

#endif // QMYTREEDELEGATE_H
