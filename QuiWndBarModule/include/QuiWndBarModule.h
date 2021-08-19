#ifndef QtWndBarModule_h__
#define QtWndBarModule_h__
#include "IQuiWndBarModule.h"
#include <QtWidgets/QWidget>
#include "PublicMarco.h"
#include <QMap>

class QMenu;
class IQuiMenuModule;
class CQuiBaseWndBar;
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
	* @fn       AppendMenuModule
	* @author   Crack
	* @brief
	* @date     2021/7/28 17:42
	* @param
	* @return
	*/
	virtual void AppendMenuModule(IQuiMenuModule* pMenuModule);

	/**
 	* @fn       SetBarWndWidget
 	* @author   Crack
 	* @brief       
 	* @date     2021/8/19 11:16
 	* @param    
 	* @return   
	*/
	virtual void SetBarWndWidget(QWidget* widget);

	/**
	 * @fn       GetBarWndWidget
	 * @author   Crack
	 * @brief       
	 * @date     2021/8/19 11:17
	 * @param    
	 * @return   
	*/
	virtual QWidget* GetBarWndWidget();

private:
	// 存储Menu菜单
	QMap<QString, IQuiMenuModule*> m_MenuModuleMap;

	CQuiBaseWndBar* m_pQuiBaseWndBar;
};
DECLARE_MODULE(QuiWndBar, extern)
#endif // QtWndBarModule_h__