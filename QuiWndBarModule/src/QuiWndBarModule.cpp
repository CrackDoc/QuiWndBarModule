#include "QuiWndBarModule.h"
#include "ui_QuiWndBarModule.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMenu>
#include <QMouseEvent>
#include "IQuiMenuModule.h"
#include <QDesktopWidget>

CQuiWndBarModule::CQuiWndBarModule(QWidget *parent)
    : QWidget(parent)
	, ui(new Ui::QuiWndBarModuleClass)
	, m_bMouseEvent(false)
	, m_pGeometryWidget(parent)
	, m_bMaxWindow(false)
{
    ui->setupUi(this);
}
CQuiWndBarModule::~CQuiWndBarModule()
{
	
}
std::string CQuiWndBarModule::GetName() const
{
	return "QtWndBarModule";
}

std::string CQuiWndBarModule::GetCompany() const
{
	return "";
}

std::string CQuiWndBarModule::GetVersion() const
{
	return "";
}

std::string CQuiWndBarModule::GetDescription() const
{
	return "";
}

bool CQuiWndBarModule::Initialise()
{
	ui->MinBtn->setIcon(style()->standardIcon(QStyle::SP_TitleBarMinButton));
	ui->MaxBtn->setIcon(style()->standardIcon(QStyle::SP_TitleBarNormalButton));
	ui->CloseBtn->setIcon(style()->standardIcon(QStyle::SP_TitleBarCloseButton));
	
	connect(ui->MinBtn, SIGNAL(clicked()), this, SIGNAL(SignalShowMinWindow()));

	connect(ui->MaxBtn, SIGNAL(clicked()), this, SIGNAL(SignalShowMaxWindow()));

	connect(ui->CloseBtn, SIGNAL(clicked()), this, SIGNAL(SignalCloseWindow()));

	return true;
}

bool CQuiWndBarModule::Uninitialise()
{
	return true;
}


void CQuiWndBarModule::SetModuleParent(QWidget* widget)
{
	if (widget)
	{
		this->setParent(widget);
	}
}

void CQuiWndBarModule::EnableAcceptMouseEvent()
{
	m_bMouseEvent = true;
}

void CQuiWndBarModule::UnEnableAcceptMouseEvent()
{
	m_bMouseEvent = false;
}

void CQuiWndBarModule::SetWndSyleSheet(const QString& syle)
{
	m_WndStyle = syle;
}
void CQuiWndBarModule::AppendMenuModule(IQuiMenuModule* pMenuModule)
{
	QHBoxLayout* layout = (QHBoxLayout*)ui->HWndBarBox->layout();
	if (layout)
	{
		int nSize = layout->count();
		QMenu* pQMenu = pMenuModule->GetMenu();
		QString strMenuModuleName = pQMenu->title();
		QPushButton* btn = new QPushButton(strMenuModuleName,this);
		btn->setFlat(true);
		connect(btn, &QPushButton::clicked, this, &CQuiWndBarModule::SlotMenuClicked);
		btn->setFixedSize(QSize(70, 25));
		layout->insertWidget(nSize - 1, btn);
		m_MenuModuleMap[strMenuModuleName] = pMenuModule;
	}
}

void CQuiWndBarModule::SetBarBackGroundColor(const QColor& bgColor)
{
	m_BackGroundColor = bgColor;
}

void CQuiWndBarModule::SetBarSyleSheet(const QString& strSyle)
{
	m_strStyleSheet = strSyle;

	ui->CenterWidget->setStyleSheet(m_strStyleSheet);
}

void CQuiWndBarModule::SetGeometryWidget(QWidget* widget)
{
	m_pGeometryWidget = widget;
}

void CQuiWndBarModule::mouseMoveEvent(QMouseEvent* event)
{
	QWidget* mWidParent = m_pGeometryWidget;
	// 持续按住才做对应事件
	if (mWidParent && m_bKeepPressed)
	{
		// 将父窗体移动到父窗体之前的位置加上鼠标移动的位置【event->globalPos()- mPntStart】
		mWidParent->move(mWidParent->geometry().topLeft() + event->globalPos() - m_PntStart);
		// 将鼠标在屏幕中的位置替换为新的位置
		m_PntStart = event->globalPos();
	}

	// 设置当前的鼠标箭头符号
	setCursor(Qt::ArrowCursor);
	//向其他窗口发送移动事件
	if (m_bMouseEvent)
	{
		QWidget::mouseMoveEvent(event);
	}	
}
void CQuiWndBarModule::mousePressEvent(QMouseEvent* event)
{
	// 首先判断当前鼠标点在什么位置 
	// 鼠标左键按下事件

	QRect rBarRect = geometry();
	QPoint objectPoint = this->mapTo(this, event->pos());
	if (!rBarRect.contains(objectPoint))
	{
		m_bKeepPressed = false;
		return;
	}
	if (event->button() == Qt::LeftButton)
	{
		// 记录鼠标状态
		m_bKeepPressed = true;
		// 记录鼠标在屏幕中的位置
		m_PntStart = event->globalPos();
	}
	//向其他窗口发送移动事件
	if (m_bMouseEvent)
	{
		QWidget::mousePressEvent(event);
	}

}

void CQuiWndBarModule::mouseReleaseEvent(QMouseEvent* event)
{
	// 鼠标左键释放
	if (event->button() == Qt::LeftButton)
	{
		// 记录鼠标状态
		m_bKeepPressed = false;
	}
	//向其他窗口发送移动事件
	if (m_bMouseEvent)
	{
		QWidget::mouseReleaseEvent(event);
	}
}

void CQuiWndBarModule::mouseDoubleClickEvent(QMouseEvent* event)
{
	QWidget* mWidParent = m_pGeometryWidget;
	if (mWidParent)
	{
		if (m_bMaxWindow)
		{
			m_bMaxWindow = !m_bMaxWindow;
			mWidParent->showNormal();
		}
		else
		{
			m_bMaxWindow = !m_bMaxWindow;
			QDesktopWidget* desktopWidget = QApplication::desktop();
			//QRect screenRect = desktopWidget->screenGeometry();  //屏幕区域
			QRect screenRect = desktopWidget->availableGeometry();  //屏幕区域
			int w = screenRect.width() + 18;
			int h = screenRect.height() + 18;
			mWidParent->showMaximized();
			mWidParent->setGeometry(-9, -9, w, h);

		}
	}
	//向其他窗口发送移动事件
	if (m_bMouseEvent)
	{
		QWidget::mouseDoubleClickEvent(event);
	}
}

void CQuiWndBarModule::paintEvent(QPaintEvent* event)
{
	if (!m_BackGroundColor.isValid())
	{
		return;
	}
	Q_UNUSED(event);

	QPainter p(this);

	p.setPen(Qt::NoPen);

	p.setBrush(m_BackGroundColor);

	QRect rect1 = this->rect();
	rect1.setHeight(rect1.height() - 1);

	p.drawRect(rect1);

}

void CQuiWndBarModule::SlotMenuClicked()
{
	QPushButton* btn = qobject_cast<QPushButton*>(sender());

	QString strModuleName = btn->text();

	if (m_MenuModuleMap.contains(strModuleName))
	{
		QPoint globalPos = this->mapToGlobal(btn->pos());
		QMenu* pQMenu = m_MenuModuleMap[strModuleName]->GetMenu();
		globalPos =  QPoint(globalPos.x(), globalPos.y()+this->height());
		pQMenu->exec(globalPos);
	}
}
IMPLEMENT_MODULE(QuiWndBar)

