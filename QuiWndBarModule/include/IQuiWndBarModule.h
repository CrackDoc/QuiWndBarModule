#ifndef IQuiWndBarModule_h__
#define IQuiWndBarModule_h__


#include <string>
#include <QBoxLayout>
#include <QMenu>
#include <QtWidgets/QWidget>
#include "IQuiMenuModule.h"

class IQuiWndBarModule
{
public:
	virtual ~IQuiWndBarModule(){}
	/**
	 * @fn       GetName
	 * @author   Crack
	 * @brief    获取模块名称
	 * @date     2021/4/11 22:10
	 * @param    
	 * @return   
	*/
	virtual std::string GetName() const  = 0;

	/**
	 * @fn       GetCompany
	 * @author   Crack
	 * @brief    获取公司名称
	 * @date     2021/7/29 9:57
	 * @param    
	 * @return   
	*/
	virtual std::string GetCompany() const  = 0;
	/**
	 * @fn       GetVersion
	 * @author   Crack
	 * @brief     获取版本号  
	 * @date     2021/7/29 9:57
	 * @param    
	 * @return   
	*/
	virtual std::string GetVersion() const  = 0;

	/**
	 * @fn       GetDescription
	 * @author   Crack
	 * @brief    描述信息  
	 * @date     2021/7/29 9:58
	 * @param    
	 * @return   
	*/
	virtual std::string GetDescription() const = 0;
	
	/**
	 * @fn       Initialise
	 * @author   Crack
	 * @brief    初始化  
	 * @date     2021/7/29 9:58
	 * @param    
	 * @return   
	*/

	virtual bool Initialise() = 0;
	
	/**
	 * @fn       Uninitialise
	 * @author   Crack
	 * @brief    卸载信息
	 * @date     2021/7/29 9:59
	 * @param    
	 * @return   
	*/
	virtual bool Uninitialise() = 0;

	/**
	 * @fn       SetModuleParent
	 * @author   Crack
	 * @brief    设置窗口父对象 
	 * @date     2021/7/29 9:59
	 * @param    
	 * @return   
	*/
	virtual void SetModuleParent(QWidget* widget) = 0;

	/**
	 * @fn       EnableAcceptMouseEvent
	 * @author   Crack
	 * @brief    接收鼠标事件
	 * @date     2021/7/29 9:56
	 * @param    
	 * @return   
	*/
	virtual void EnableAcceptMouseEvent() = 0;
	/**
	 * @fn       UnEnableAcceptMouseEvent
	 * @author   Crack
	 * @brief    关闭接收鼠标事件
	 * @date     2021/7/29 9:56
	 * @param
	 * @return
	*/
	virtual void UnEnableAcceptMouseEvent() = 0;
	/**
	 * @fn       SetWndSylesheet
	 * @author   Crack
	 * @brief    设置窗口样式表
	 * @date     2021/7/28 17:37
	 * @param    
	 * @return   
	*/
	virtual void SetWndSyleSheet(const QString& style) = 0;

	/**
	 * @fn       AppendMenuModule
	 * @author   Crack
	 * @brief       
	 * @date     2021/7/28 17:42
	 * @param    
	 * @return   
	*/
	virtual void AppendMenuModule(IQuiMenuModule* pMenuModule) = 0;

	/**
	 * @fn       SetBarBackGroundColor
	 * @author   Crack
	 * @brief       
	 * @date     2021/8/16 16:42
	 * @param    
	 * @return   
	*/
	virtual void SetBarBackGroundColor(const QColor& bgColor) = 0;

	/**
	 * @fn       SetBarSyleSheet
	 * @author   Crack
	 * @brief       
	 * @date     2021/8/16 16:44
	 * @param    
	 * @return   
	*/
	virtual void SetBarSyleSheet(const QString& strSyle) = 0;

	/**
	 * @fn       SetGeometryWidget
	 * @author   Crack
	 * @brief       
	 * @date     2021/8/17 18:26
	 * @param    
	 * @return   
	*/
	virtual void SetGeometryWidget(QWidget *widget) = 0;
	
};
#endif // IQuiWndBarModule_h__