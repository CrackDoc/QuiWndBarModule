#ifndef IQuiMenuModule_h__
#define IQuiMenuModule_h__


#include <string>
#include <QBoxLayout>
#include <QMenu>
#include <QtWidgets/QWidget>

class IQuiMenuModule
{
public:
	virtual ~IQuiMenuModule(){}
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
	 * @fn       GetMenu
	 * @author   Crack
	 * @brief       
	 * @date     2021/8/2 10:44
	 * @param    
	 * @return   
	*/
	virtual QMenu* GetMenu() = 0;

	/**
 	 * @fn       SetMenu
 	 * @author   Crack
 	 * @brief       
 	 * @date     2021/8/2 10:45
 	 * @param    
 	 * @return   
	*/
	virtual void SetMenu(QMenu* pQMenu) = 0;

	/**
	 * @fn       GetWidget
	 * @author   Crack
	 * @brief       
	 * @date     2021/8/2 10:57
	 * @param    
	 * @return   
	*/
	virtual QWidget* GetWidget() = 0;

	/**
	 * @fn       SetWidget
	 * @author   Crack
	 * @brief       
	 * @date     2021/8/2 10:46
	 * @param    
	 * @return   
	*/
	virtual void SetWidget(QWidget *widget) = 0;
};
#endif // IQuiMenuModule_h__