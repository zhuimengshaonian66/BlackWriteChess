
#include <QWidget>
#include<QTableWidget>
#include<QStringListModel>
#include<QListView>
#include<QPainter>
#include<QBitmap>
#include<QListView>
#include<QPushButton>
#include<QHBoxLayout>
#include<QLineEdit>
#include<QInputDialog>
#include<QMessageBox>
#include<QDir>
#include<QTreeView>
#include<QFileSystemModel>
#include<QSortFilterProxyModel>
#include<QComboBox>
#include<QLabel>

#include "booleanmodel.h"
#include "booleanparser.h"
#include "booleanwindow.h"

BooleanWindow::BooleanWindow()
{
    label = new QLabel(tr("布尔表达式:"));
    lineEdit = new QLineEdit;

    booleanModel = new BooleanModel(this);

    treeView = new QTreeView;
    treeView->setModel(booleanModel);

    connect(lineEdit, SIGNAL(textChanged(const QString &)),
            this, SLOT(booleanExpressionChanged(const QString &)));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(label, 0, 0);
    layout->addWidget(lineEdit, 0, 1);
    layout->addWidget(treeView, 1, 0, 1, 2);
    setLayout(layout);

    setWindowTitle(tr("by 追梦少年 QQ：1131052403"));
}

void BooleanWindow::booleanExpressionChanged(const QString &expr)
{
    BooleanParser parser;
    Node *rootNode = parser.parse(expr);
    booleanModel->setRootNode(rootNode);
}
