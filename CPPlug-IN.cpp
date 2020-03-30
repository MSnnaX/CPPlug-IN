// CPPlug-IN.cpp: 定义 DLL 的初始化例程。
//

#include "pch.h"
#include "framework.h"
#include "CPPlug-IN.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO:  如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如: 
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。  这意味着
//		它必须作为以下项中的第一个语句:
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//

// CCPPlugINApp

BEGIN_MESSAGE_MAP(CCPPlugINApp, CWinApp)
END_MESSAGE_MAP()


// CCPPlugINApp 构造

CCPPlugINApp::CCPPlugINApp()
{
	// TODO:  在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的 CCPPlugINApp 对象

CCPPlugINApp theApp;


// CCPPlugINApp 初始化

BOOL CCPPlugINApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

static uiCmdAccessState AccessDefault(uiCmdAccessMode access_mode)
{
	return(ACCESS_AVAILABLE);
}
void Test1()
{
	AfxMessageBox(_T("测试按钮A"));
}
void Test2()
{
	AfxMessageBox(_T("测试按钮B"));
}
void Test3()
{
	AfxMessageBox(L"给我一杯忘情水");
}
extern "C" int user_initialize()
{
	ProError status;
	ProFileName  MsgFile;
	ProStringToWstring(MsgFile, "IconMessage.txt");  //注意此处的IconMessage与后面的text文件夹下的IconMessage.txt文件名必须相同 
	uiCmdCmdId PushButton1_cmd_id, PushButton2_cmd_id, PushButton3_cmd_id;
	status = ProMenubarMenuAdd("MainMenu", "Function", "Help", PRO_B_TRUE, MsgFile);
	ProCmdActionAdd("PushButton1_Act", (uiCmdCmdActFn)Test1, 12, AccessDefault, PRO_B_TRUE, PRO_B_TRUE, &PushButton1_cmd_id);
	ProMenubarmenuPushbuttonAdd("MainMenu", "PushButton", "FirstButton", "this button will show a message", NULL, PRO_B_TRUE, PushButton1_cmd_id, MsgFile);
	ProCmdActionAdd("PushButton2_Act", (uiCmdCmdActFn)Test2, uiCmdPrioDefault, AccessDefault, PRO_B_TRUE, PRO_B_TRUE, &PushButton2_cmd_id);
	ProMenubarmenuPushbuttonAdd("MainMenu", "PushButton2", "SecondButton", "this button will show a message", NULL, PRO_B_TRUE, PushButton2_cmd_id, MsgFile);
	ProCmdActionAdd("PushButton3_Act", (uiCmdCmdActFn)Test3, uiCmdPrioDefault, AccessDefault, PRO_B_TRUE, PRO_B_TRUE, &PushButton3_cmd_id);
	ProMenubarmenuPushbuttonAdd("MainMenu", "PushButton3", "Thirdbutton", "this button will show a message", NULL, PRO_B_TRUE, PushButton3_cmd_id, MsgFile);
	return status;
}
extern  "C" void user_terminate()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
}
