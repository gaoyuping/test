#ifndef NAVVIEW_H
#define NAVVIEW_H

#include <QListView>
#include <QTreeView>
class NavView : public QListView
{
	Q_OBJECT

public:
	NavView(QWidget *parent);
	~NavView();

private:
	
};

#endif // NAVVIEW_H
