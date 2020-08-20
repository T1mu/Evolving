#include "ToolBarWidget.h"
#include <qpainter.h>
#include <qdebug.h>
ToolBarWidget::ToolBarWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_bllDataFlow = BllDataFlow::instance();
	connect(m_bllDataFlow, SIGNAL(resultSignal()), this, SLOT(resultImgShowSlot()));
	QObject::connect(ui.grayImgBtn, &QToolButton::clicked, this, &ToolBarWidget::grayImgBtnClicked);
	QObject::connect(ui.resultImgBtn, &QToolButton::clicked, this, &ToolBarWidget::resultImgBtnClicked);
	
}

ToolBarWidget::~ToolBarWidget()
{

}

void ToolBarWidget::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

//显示点数结果界面
void ToolBarWidget::resultImgShowSlot()
{
	emit resultImgShowSignal();
}

void ToolBarWidget::setVisibleSlot(bool visible)
{
	this->setVisible(visible);
}