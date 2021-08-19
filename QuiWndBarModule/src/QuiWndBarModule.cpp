#include "QuiWndBarModule.h"
#include "ui_QuiWndBarModule.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMenu>
#include <QMouseEvent>
#include "IQuiMenuModule.h"
#include <QDesktopWidget>
#include "QuiBaseWndBar.h"

CQuiWndBarModule::CQuiWndBarModule(QWidget *parent)
    : QWidget(parent)
	, m_pQuiBaseWndBar(nullptr)
{
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
	return true;
}

bool CQuiWndBarModule::Uninitialise()
{
	return true;
}
void CQuiWndBarModule::AppendMenuModule(IQuiMenuModule* pMenuModule)
{
	if (!m_pQuiBaseWndBar)
	{
		return;
	}
	if (m_pQuiBaseWndBar->AppendWidget(pMenuModule->GetMenu()))
	{
		QMenu* pQMenu = pMenuModule->GetMenu();
		QString strMenuModuleName = pQMenu->title();
		m_MenuModuleMap[strMenuModuleName] = pMenuModule;
	}
}

void CQuiWndBarModule::SetBarWndWidget(QWidget* widget)
{
	m_pQuiBaseWndBar = qobject_cast<CQuiBaseWndBar*>(widget);
}

QWidget* CQuiWndBarModule::GetBarWndWidget()
{
	return qobject_cast<QWidget*>(m_pQuiBaseWndBar);
}
IMPLEMENT_MODULE(QuiWndBar)

