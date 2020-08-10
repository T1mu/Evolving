# Model/View框架

## 一、Model/View框架简介

![mvcArchitecture](mvcArchitecture.bmp)
### 1、Model/View框架核心思想

Model/View框架的核心思想是模型（数据）与视图（显示）相分离，**模型对外提供标准接口存取数据**，不关心数据如何显示，**视图自定义数据的显示方式**，不关心数据如何组织存储。为了处理用户输入，引入了委托（delegate），可以自定义数据项的**渲染和编辑**。

Model/View框架中存取数据与显示数据的分离，可以允许使用不同界面显示同一数据，也能够在不改变数据的情况下添加新的显示界面。

模型必须为每一个数据提供独一无二的索引，视图通过索引访问模型中的数据。

模型与数据源进行交互，为框架中其它组件提供接口。交互的本质在于数据源的类型以及模型的实现方式。视图从模型获取模型索引，通过将模型索引反向传给模型，视图又可以从数据源获取数据。在标准视图中，委托渲染数据项；在需要编辑数据时，委托使用直接模型索引直接与模型进行交互。

Model/View架构分为三部分：模型、视图和委托。每一个组件都由一个抽象类定义，抽象类提供了基本的公共接口以及一些默认实现。

### 2、Model/View框架工作机制

模型、视图和委托使用信号槽进行交互：

A、底层维护的数据发生改变时，模型发出信号通知视图

B、当用户与视图进行交互时，视图发出信号提供了有关用户与界面进行交互的信息

C、当用户编辑数据项时，委托发出信号用于告知模型和视图编辑器的状态。

### 3、Model/View框架的类

所有的模型都是QAbstractItemModel的子类。QAbstractItemModel类定义了供视图和委托访问数据的接口。模型并不一定存储数据本身。QAbstractItemModel提供的接口足够灵活，足以应付以表格、列表和树的形式显示的数据。如果要为列表或者表格设计自定义的模型，直接继承QAbstractListModel和QAbstractTableModel类会更好，因为这两个类已经实现了很多通用函数。

QT内置了多种标准模型：

类型|作用
---|---
QStringListModel|存储简单的字符串列表
QStandardItemModel|可以用于树结构的存储，提供了层次数据
QFileSystemModel| 本地系统的文件和目录信息
QSqlQueryModel、QSqlTableModel、QSqlRelationalTableModel|存取数据库数据
QT提供了多个预定义好的视图类：

类型|作用
---|---
QListView|用于显示列表
QTableView|用于显示表格
QTreeView|用于显示层次数据
QAbstractItemView|---
QAbstractItemDelegate|所有委托的抽象基类

自 Qt 4.4 以来，默认的委托实现是 QStyledItemDelegate。但是，QStyledItemDelegate 和QItemDelegate 都可以作为视图的编辑器，二者的区别在于，QStyledItemDelegate 使用当前样式进行绘制。在实现自定义委托时，推荐使用QStyledItemDelegate 作为基类，或者结合 Qt style sheets。

## 二、Model

### 1、模型简介

Model/View框架中，Model提供一种标准接口，供视图和委托访问数据。 QT中，Model接口由QAbstractItemModel类进行定义。不管底层数据是如何存储的，只要是QAbstractItemModel的子类，都提供一种表格形式的层次结构。视图利用统一的转换来访问模型中的数据。模型内部数据的组织方式并不一定和视图中数据的显示相同。

List Model虽然是线性的列表，有一个 Root Item（根节点），线性的一个个数据可以看作是一个只有一列的表格，但是它是有层次的，因为有一个根节点。Table Model就比较容易理解，只是也存在一个根节点。Tree Model主要面向层次数据，而每一层次都可以都很多列，因此也是一个带有层次的表格。

### 2、模型索引

为了使数据的显示同存储分离，引入了模型索引（model index）的概念。通过模型索引，可以访问模型的特定元素的特定部分。视图和委托使用模型索引来请求所需要的数据。由此可以看出，只有模型自己需要知道如何获得数据，模型所管理的数据类型可以使用通用的方式进行定义。模型索引保存有创建的它的那个模型的指针，使同时操作多个模型成为可能。

模型索引提供了所需要的信息的临时索引，用于通过模型取回或者修改数据。由于模型随时可能重新组织其内部的结构，因此模型索引很可能变成不可用的，此时，就不应该保存这些数据。如果你需要长期有效的数据片段，必须创建持久索引。持久索引保证其引用的数据及时更新。临时索引（也就是通常使用的索引）由QModelIndex类提供，持久索引则是 QPersistentModelIndex 类。

为了定位模型中的数据，需要三个属性：行号、列号以及父索引。

在类表格的视图中，比如列表和表格，行号和列号足以定位一个数据项。但对于树型结构，由于树型结构是一个层次结构，而层次结构中每一个节点都有可能是一个表格。所以，每一个项需要指明其父节点。由于在模型外部只能用过索引访问内部数据，因此，index()函数还需要一个 parent 参数：

QModelIndex index = model->index(row, column, parent);

### 3、数据角色

模型可以针对不同的组件（或者组件的不同部分，比如按钮的提示以及显示的文本等）提供不同的数据。例如，Qt::DisplayRole用于视图的文本显示。通常来说，模型中的数据项包含一系列不同的数据角色，数据角色定义在 Qt::ItemDataRole 枚举中。

类型|作用
---|---
Qt::DisplayRole|文本表格中要渲染的关键数据
Qt::EditRole|编辑器中正在编辑的数据
Qt::ToolTipRole|数据项的工具提示的显示数据
Qt::WhatsThisRole|项为"What's This?"模式显示的数据

通过为每一个角色提供恰当的数据，模型可以告诉视图和委托如何向用户显示内容。不同类型的视图可以选择忽略自己不需要的数据，也可以添加所需要的额外数据。

### 4、QStringListModel

QStringListModel是一个可编辑的模型，可以为组件提供一系列字符串作为数据，是封装了QStringList的model。QStringListModel通常作为只有一列的视图组件的model，如QListView和QComboBox。

QStringListModel使用实例如下：

```c++
#include <QApplication>
#include <QStringListModel>
#include <QListView>
#include <QStringList>
 
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStringListModel* listModel = new QStringListModel;
    QListView* view = new QListView;
    QStringList  nameList;
    nameList<<"ZheDong Mao"<<"RenLai Zhou"<<"XiaoPing Deng"<<"ShaoQi Liu"<<"De Zhu"<<"DeHuai Peng";
    listModel->setStringList(nameList);
    view->setModel(listModel);
    view->setEditTriggers(QAbstractItemView::AnyKeyPressed | QAbstractItemView::DoubleClicked);
 
    view->setWindowTitle("QStringListModel");
    view->show();
 
    return a.exec();
}
```

### 5、QFileSystemModel

QFileSystemModel是QT标准的文件系统的model。

QFileSystemModel使用实例：

```c++
#include <QApplication>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListView>
 
int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    //创建文件系统模型
    QFileSystemModel model;
    //指定根目录
    model.setRootPath(QDir::currentPath());
    //创建树形视图
    QTreeView tree;
    //为视图指定模型
    tree.setModel(&model);
    //指定根索引
    tree.setRootIndex(model.index(QDir::currentPath()));
    //创建列表视图
    QListView list;
    list.setModel(&model);
    list.setRootIndex(model.index(QDir::currentPath()));
    tree.show();
    list.show();
 
    return app.exec();
}
```

### 6、QSortFilterProxyModel

QSortFilterProxyModel类提供在其他的model和view之间排序和过滤数据的支持。QSortFilterProxyModel不能单独使用，是一个代理，真正的数据需要另外的模型提供。QSortFilterProxyModel的作用是对数据进行排序和过滤。

QSortFilterProxyModel使用实例：

```c++
#include <QApplication>
#include <QFileSystemModel>
#include <QSortFilterProxyModel>
#include <QTreeView>
#include <QListView>
 
int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    //创建文件系统模型
    QFileSystemModel model;
    //指定根目录
    model.setRootPath(QDir::currentPath());
    //创建树形视图
    QSortFilterProxyModel proxymodel;
    proxymodel.setFilterKeyColumn(0);
    proxymodel.setSourceModel(&model);
    QTreeView tree;
    //为视图指定模型
    tree.setModel(&proxymodel);
    //指定根索引
    tree.setRootIndex(proxymodel.index(0, 0, QModelIndex()));
    //创建列表视图
    QListView list;
    list.setModel(&proxymodel);
    list.setRootIndex(proxymodel.index(0, 0, QModelIndex()));
 
    tree.show();
    list.show();
 
    return app.exec();
}
```

## 三、View

Model/View 架构中，视图是数据从模型到最终用户的途径。数据通过视图向用户进行显示，但通常数据的显示同底层数据的存储是完全不同的。

QAbstractItemModel提供标准的模型接口，使用QAbstractItemView提供标准的视图接口，可以将数据同显示层分离，在视图中利用前面所说的模型索引。视图管理来自模型的数据的布局：既可以直接渲染数据本身，也可以通过委托渲染和编辑数据。

视图不仅用于显示数据，还用于在数据项之间的导航以及数据项的选择。另外，视图也需要支持很多基本的用户界面的特性，例如右键菜单以及拖放。视图可以提供数据编辑功能，也可以将编辑功能交由某个委托完成。视图可以脱离模型创建，但是在其进行显示之前，必须存在一个模型。对于用户的选择，多个视图可以相互独立，也可以进行共享。

QT内置了QListView、QTreeView、QTableView视图类，QListView把model中的数据项以一个简单的列表的形式显示，或是以经典的图标视图的形式显示。QTreeView把model中的数据项作为具有层次结构的列表的形式显示，允许以紧凑的深度嵌套的结构进行显示。QTableView把model中的数据项以表格的形式展现。

## 四、Delegate

委托就是供视图实现某种高级的编辑功能。Model/View 没有将用户交互部分完全分离。一般地，视图将数据向用户进行展示并且处理通用的输入。但是，对于某些特殊要求（比如这里的要求必须输入数字），则交予委托完成。这些组件提供输入功能，同时也能渲染某些特殊数据项。委托的接口由 QAbstractItemDelegate定义。

QAbstractItemDelegate 通过paint()和sizeHint()两个函数渲染用户内容（必须自己将渲染器绘制出来）。从QT4.4开始，QT提供了基于组件的子类：QItemDelegate和QStyledItemDelegate。默认的委托是QStyledItemDelegate。QItemDelegate与QStyledItemDelegate的区别在于绘制和向视图提供编辑器的方式。          QStyledItemDelegate使用当前样式绘制，并且能够使用Qt Style Sheet，在自定义委托时推荐使用QStyledItemDelegate作为基类。

继承自QStyledItemDelegate或QItemDelegate的自定义委托类需要重写实现以下几个函数：

```c++
[virtual] QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
```

创建编辑器，作为用户编辑数据时所使用的编辑器，从模型中接受数据，返回用户修改的数据。

```c++
[virtual] void setEditorData(QWidget *editor, const QModelIndex &index) const
```

设置编辑器的数据

```c++
[virtual] void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
```

将数据写入model

```c++
[virtual] void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
```

更新编辑器布局

## 五、项选择模型

### 1、QItemSelectionModel简介

选择是视图中常用的操作。在列表、树或者表格中，通过鼠标点击可以选中某一项，选中项会变成高亮或者反色。在 QT中，选择也是使用了一种模型。在 Model/View架构中，选择模型提供了一种更通用的对选择操作的描述。对于一般应用而言，QT内置的选择模型已经足够，但QT也允许创建自己的选择模型，来实现一些特殊的操作。

QT使用QItemSelectionModel类获取视图中数据项的选择情况。QItemSelectionModel可以保持对视图中选中数据项的跟踪。视图中被选择的数据项的信息存储在一个QItemSelectionModel实例中。选中的数据项的模型索引与所有的视图都是独立的。一个模型设置多个视图时，可以实现在多个视图之间共享同一个选择模型，达到同步操作的目的。视图中总有一个当前数据项和一个选中的数据项，他们可以是同一个数据项。

选择由选择区域组成。模型只将选择区的开始和结束的索引位置记录下来，以保证对大的选区也有很好的性能。非连续选区则由多个连续选择组成。

标准视图类（QListView、QTreeView、QTableView）提供了默认的选择模型，足以满足大多数应用程序的需求。一个视图的选择模型可以通过 selectionModel()函数获取，然后使用setSelectionModel()提供给其它视图共享，因此，一般没有必要新建选择模型。

如果需要创建一个选择区，需要指定一个模型以及一对索引，使用这些数据创建一个QItemSelection对象。索引指向给定的模型中的数据，并且作为一个块状选择区的左上角和右下角的索引。为了将选择区应用到模型上，需要将选择区提交到选择模型。这种操作有多种实现，对于现有选择模型有着不同的影响。

### 2、项选择模型使用

A、构建标准数据项模型并设置设置数据

    //构建7行4列的项目模型

    QStandardItemModel *model = new QStandardItemModel(7,4,this);

    for (int row=0; row < 7; row++)

    {

        for (int col=0; col < 4; col++)

        {

            QStandardItem* item = new QStandardItem(QString("%1").arg(row*4+col));

            //为项目模型添加项目

            model->setItem(row,col,item);

        }

    }

B、添加视图，设置模型

//添加视图，并将视图放在窗体中央

QTableview *view = new QTableView;

view->setModel(model);//为视图添加模型

setCentralWidget(view);

C、获取视图的数据项选择模型

 QItemSelectionModel * selectionModel = view->selectionModel();

D、设置被选择的数据项

    //定义左上，右下的索引，然后使用这两个索引创建选择

    QModelIndex topLeft;

    QModelIndex rightBottom;

    QModelIndex parentIndex = QModelIndex();

    topLeft = model->index(1,1,parentIndex);

    rightBottom = model->index(5,2,parentIndex);

    //设置被选择的数据项

    QItemSelection selection(topLeft, rightBottom);

E、设置选择模式

selectionModel->select(selection,QItemSelectionModel::Select);

QItemSelectionModel::Select：选择所有指定的选区

QItemSelectionModel::Toggle：反向操作

QItemSelectionModel::Deselect：取消指定的已选选区

QItemSelectionModel::Rows：选择行

QItemSelectionModel::Columns：选择列

QItemSelectionModel::Current：将当前选区替换为新的选区

QItemSelectionModel::Clear：取消全部已有选区

F、选择模型的选择改变信号

[signal] void QItemSelectionModel::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected)

选择发生改变时，触发信号。会发送被选择的QItemSelection和未被选择的QItemSelection

[signal] void QItemSelectionModel::currentChanged(const QModelIndex ¤t, const QModelIndex &previous)

当前数据项变化时，触发信号。会发送当前选择的QModelIndex和前一个QModelIndex。

G、选择改变信号的槽函数

void updateSelection(QItemSelection &selected,QItemSelection &deselected);

选择模型改变后的槽函数

void updateSelection(QItemSelection &selected, QItemSelection &deselected)

{

    QModelIndex index;

    QModelIndexList indexList = selected.indexes();

    foreach (index, indexList)

    {

        QString text = QString("(%1,%2)").arg(index.row()).arg(index.column());

        view->model()->setData(index,text);

    }

    indexList = deselected.indexes();

    //清空上一次选择的项目内容

    foreach (index, indexList)

    {

        view->model()->setData(index,"");

    }

}

 

void changeCurrent(const QModelIndex ¤t,const QModelIndex &previous);

显示当前选择项的数据改变情况

void changeCurrent(const QModelIndex ¤t, const QModelIndex &previous)

{

    qDebug() << QString("move(%1,%2)to(%3,%4)")

                .arg(previous.row()).arg(previous.column())

                .arg(current.row()).arg(current.column());

}

H、信号与槽函数的连接

connect(selectionModel,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),

            this,SLOT(updateSelection(QItemSelection&,QItemSelection&)));

connect(selectionModel,SIGNAL(currentChanged(QModelIndex,QModelIndex)),

            this,SLOT(changeCurrent(QModelIndex,QModelIndex)));

 

I、视图间共享选择模型

    QTableView *view2 = new QTableView;

    view2->setWindowTitle("TableView2");

    view2->setModel(model);//设置模型

    view2->setSelectionModel(selectionModel);//设置共同的选择模型

    view2->show();