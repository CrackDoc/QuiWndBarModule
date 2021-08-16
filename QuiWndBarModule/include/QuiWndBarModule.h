#ifndef QtWndBarModule_h__
#define QtWndBarModule_h__
#include "IQuiWndBarModule.h"
#include <QtWidgets/QWidget>
#include "PublicMarco.h"
#include <QMap>
#include <QPainter>
#include <QPaintEvent>

namespace Ui
{
	class QuiWndBarModuleClass;
}
class QMenu;
class IQuiMenuModule;
class CQuiWndBarModule : public QWidget,public IQuiWndBarModule
{
    Q_OBJECT

public:
	CQuiWndBarModule(QWidget *parent = Q_NULLPTR);
	~CQuiWndBarModule();
public:
	/**
	* @fn       GetName
	* @author   Crack
	* @brief    获取模块名称
	* @date     2021/4/11 22:10
	* @param
	* @return
	*/
    virtual std::string GetName() const;
	/**
	 * @fn       GetCompany
	 * @author   Crack
	 * @brief    获取公司名称
	 * @date     2021/7/29 9:57
	 * @param
	 * @return
	*/
	virtual std::string GetCompany() const;
	/**
	 * @fn       GetVersion
	 * @author   Crack
	 * @brief     获取版本号
	 * @date     2021/7/29 9:57
	 * @param
	 * @return
	*/
	virtual std::string GetVersion() const;
	/**
	 * @fn       GetDescription
	 * @author   Crack
	 * @brief    描述信息
	 * @date     2021/7/29 9:58
	 * @param
	 * @return
	*/
	virtual std::string GetDescription() const;
	/**
	 * @fn       Initialise
	 * @author   Crack
	 * @brief    初始化
	 * @date     2021/7/29 9:58
	 * @param
	 * @return
	*/
	virtual bool Initialise();
	/**
	 * @fn       Uninitialise
	 * @author   Crack
	 * @brief    卸载信息
	 * @date     2021/7/29 9:59
	 * @param
	 * @return
	*/
	virtual bool Uninitialise();
	/**
	 * @fn       SetModuleParent
	 * @author   Crack
	 * @brief    设置窗口父对象
	 * @date     2021/7/29 9:59
	 * @param
	 * @return
	*/
	virtual void SetModuleParent(QWidget* widget);

	/**
	 * @fn       EnableAcceptMouseEvent
	 * @author   Crack
	 * @brief    接收鼠标事件
	 * @date     2021/7/29 9:56
	 * @param
	 * @return
	*/
	virtual void EnableAcceptMouseEvent();
	/**
	 * @fn       UnEnableAcceptMouseEvent
	 * @author   Crack
	 * @brief    关闭接收鼠标事件
	 * @date     2021/7/29 9:56
	 * @param
	 * @return
	*/
	virtual void UnEnableAcceptMouseEvent();
	/**
	 * @fn       SetWndSylesheet
	 * @author   Crack
	 * @brief    设置窗口样式表
	 * @date     2021/7/28 17:37
	 * @param
	 * @return
	*/
	virtual void SetWndSyleSheet(const QString &syle);
	/**
	 * @fn       AppendMenuModule
	 * @author   Crack
	 * @brief
	 * @date     2021/7/28 17:42
	 * @param
	 * @return
	*/
	virtual void AppendMenuModule(IQuiMenuModule* pMenuModule);

	/**
	 * @fn       SetBarBackGroundColor
	 * @author   Crack
	 * @brief       
	 * @date     2021/8/16 16:42
	 * @param    
	 * @return   
	*/
	virtual void SetBarBackGroundColor(const QColor& bgColor);

	/**
	 * @fn       SetBarSyleSheet
	 * @author   Crack
	 * @brief       
	 * @date     2021/8/16 16:44
	 * @param    
	 * @return   
	*/
	virtual void SetBarSyleSheet(const QString& strSyle);
	
protected:
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void mouseDoubleClickEvent(QMouseEvent* event);

	void paintEvent(QPaintEvent* event);
signals:
	/**
	 * @fn       SignalShowMaxWindow
	 * @author   Crack
	 * @brief     最大化窗口  
	 * @date     2021/7/29 14:59
	 * @param    
	 * @return   
	*/
	void SignalShowMaxWindow();
	/**
	 * @fn       SignalShowMinWindow
	 * @author   Crack
	 * @brief    最小化窗口   
	 * @date     2021/7/29 14:59
	 * @param    
	 * @return   
	*/
	void SignalShowMinWindow();
	/**
	 * @fn       SignalCloseWindow
	 * @author   Crack
	 * @brief    关闭窗口  
	 * @date     2021/7/29 14:59
	 * @param    
	 * @return   
	*/
	void SignalCloseWindow();

public slots:
	/**
	 * @fn       SlotMenuClicked
	 * @author   Crack
	 * @brief     menu 点击事件  
	 * @date     2021/7/29 14:57
	 * @param    
	 * @return   
	*/
	void SlotMenuClicked();

private:
    Ui::QuiWndBarModuleClass *ui;
	// 鼠标上次移动开始时相对屏幕的位置
	QPoint m_PntStart;
	// 鼠标是否持续按下
	bool m_bKeepPressed;
	// 窗口样式
	QString m_WndStyle;
	// QMouseEnable
	bool m_bMouseEvent;
	// 存储Menu菜单
	//QMap<QString, QMenu*> m_MenuModuleMap;
	QMap<QString, IQuiMenuModule*> m_MenuModuleMap;

	QString m_strStyleSheet;

	QColor  m_BackGroundColor;
	
};
DECLARE_MODULE(QuiWndBar, extern)
#endif // QtWndBarModule_h__