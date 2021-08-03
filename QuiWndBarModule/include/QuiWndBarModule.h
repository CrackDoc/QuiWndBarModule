#ifndef QtWndBarModule_h__
#define QtWndBarModule_h__
#include "IQuiWndBarModule.h"
#include <QtWidgets/QWidget>
#include "PublicMarco.h"
#include <QMap>

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
	* @brief    ��ȡģ������
	* @date     2021/4/11 22:10
	* @param
	* @return
	*/
    virtual std::string GetName() const;
	/**
	 * @fn       GetCompany
	 * @author   Crack
	 * @brief    ��ȡ��˾����
	 * @date     2021/7/29 9:57
	 * @param
	 * @return
	*/
	virtual std::string GetCompany() const;
	/**
	 * @fn       GetVersion
	 * @author   Crack
	 * @brief     ��ȡ�汾��
	 * @date     2021/7/29 9:57
	 * @param
	 * @return
	*/
	virtual std::string GetVersion() const;
	/**
	 * @fn       GetDescription
	 * @author   Crack
	 * @brief    ������Ϣ
	 * @date     2021/7/29 9:58
	 * @param
	 * @return
	*/
	virtual std::string GetDescription() const;
	/**
	 * @fn       Initialise
	 * @author   Crack
	 * @brief    ��ʼ��
	 * @date     2021/7/29 9:58
	 * @param
	 * @return
	*/
	virtual bool Initialise();
	/**
	 * @fn       Uninitialise
	 * @author   Crack
	 * @brief    ж����Ϣ
	 * @date     2021/7/29 9:59
	 * @param
	 * @return
	*/
	virtual bool Uninitialise();
	/**
	 * @fn       SetModuleParent
	 * @author   Crack
	 * @brief    ���ô��ڸ�����
	 * @date     2021/7/29 9:59
	 * @param
	 * @return
	*/
	virtual void SetModuleParent(QWidget* widget);

	/**
	 * @fn       EnableAcceptMouseEvent
	 * @author   Crack
	 * @brief    ��������¼�
	 * @date     2021/7/29 9:56
	 * @param
	 * @return
	*/
	virtual void EnableAcceptMouseEvent();
	/**
	 * @fn       UnEnableAcceptMouseEvent
	 * @author   Crack
	 * @brief    �رս�������¼�
	 * @date     2021/7/29 9:56
	 * @param
	 * @return
	*/
	virtual void UnEnableAcceptMouseEvent();
	/**
	 * @fn       SetWndSylesheet
	 * @author   Crack
	 * @brief    ���ô�����ʽ��
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

protected:
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void mouseDoubleClickEvent(QMouseEvent* event);

signals:
	/**
	 * @fn       SignalShowMaxWindow
	 * @author   Crack
	 * @brief     ��󻯴���  
	 * @date     2021/7/29 14:59
	 * @param    
	 * @return   
	*/
	void SignalShowMaxWindow();
	/**
	 * @fn       SignalShowMinWindow
	 * @author   Crack
	 * @brief    ��С������   
	 * @date     2021/7/29 14:59
	 * @param    
	 * @return   
	*/
	void SignalShowMinWindow();
	/**
	 * @fn       SignalCloseWindow
	 * @author   Crack
	 * @brief    �رմ���  
	 * @date     2021/7/29 14:59
	 * @param    
	 * @return   
	*/
	void SignalCloseWindow();

public slots:
	/**
	 * @fn       SlotMenuClicked
	 * @author   Crack
	 * @brief     menu ����¼�  
	 * @date     2021/7/29 14:57
	 * @param    
	 * @return   
	*/
	void SlotMenuClicked();

private:
    Ui::QuiWndBarModuleClass *ui;
	// ����ϴ��ƶ���ʼʱ�����Ļ��λ��
	QPoint m_PntStart;
	// ����Ƿ��������
	bool m_bKeepPressed;
	// ������ʽ
	QString m_WndStyle;
	// QMouseEnable
	bool m_bMouseEvent;
	// �洢Menu�˵�
	//QMap<QString, QMenu*> m_MenuModuleMap;
	QMap<QString, IQuiMenuModule*> m_MenuModuleMap;
	
};
DECLARE_MODULE(QuiWndBar, extern)
#endif // QtWndBarModule_h__