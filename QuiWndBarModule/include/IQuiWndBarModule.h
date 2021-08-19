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
	 * @fn       AppendMenuModule
	 * @author   Crack
	 * @brief       
	 * @date     2021/7/28 17:42
	 * @param    
	 * @return   
	*/
	virtual void AppendMenuModule(IQuiMenuModule* pMenuModule) = 0;

	/**
	 * @fn       SetBarWndWidget
	 * @author   Crack
	 * @brief       
	 * @date     2021/8/19 11:16
	 * @param    
	 * @return   
	*/
	virtual void SetBarWndWidget(QWidget* widget) = 0;

	/**
	 * @fn       GetBarWndWidget
	 * @author   Crack
	 * @brief       
	 * @date     2021/8/19 11:17
	 * @param    
	 * @return   
	*/
	virtual QWidget* GetBarWndWidget() = 0;
};
#endif // IQuiWndBarModule_h__