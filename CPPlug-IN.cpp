#include "pch.h"
#include "framework.h"
#include "CPPlug-IN.h"

BEGIN_MESSAGE_MAP(CCPPlugINApp, CWinApp)
END_MESSAGE_MAP()

CCPPlugINApp::CCPPlugINApp()
{

}

CCPPlugINApp theApp;

BOOL CCPPlugINApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

static uiCmdAccessState UICmdAccessDefault(uiCmdAccessMode access_mode)
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
	ProStringToWstring(MsgFile, "IconMessage.txt");
	uiCmdCmdId PushButton1_cmd_id, PushButton2_cmd_id, PushButton3_cmd_id;

	status = ProMenubarMenuAdd("MainMenu", "Function", "Help", PRO_B_TRUE, MsgFile);

	ProCmdActionAdd("PushButton1_Act",
		(uiCmdCmdActFn)Test1, 12, UICmdAccessDefault, PRO_B_TRUE, PRO_B_TRUE, &PushButton1_cmd_id);
	ProMenubarmenuPushbuttonAdd("MainMenu",
		"PushButton", "FirstButton", "this button will show a message", NULL, PRO_B_TRUE, PushButton1_cmd_id, MsgFile);

	ProCmdActionAdd("PushButton2_Act",
		(uiCmdCmdActFn)Test2, uiCmdPrioDefault, UICmdAccessDefault, PRO_B_TRUE, PRO_B_TRUE, &PushButton2_cmd_id);
	ProMenubarmenuPushbuttonAdd("MainMenu",
		"PushButton2", "SecondButton", "this button will show a message", NULL, PRO_B_TRUE, PushButton2_cmd_id, MsgFile);

	ProCmdActionAdd("PushButton3_Act",
		(uiCmdCmdActFn)Test3, uiCmdPrioDefault, UICmdAccessDefault, PRO_B_TRUE, PRO_B_TRUE, &PushButton3_cmd_id);
	ProMenubarmenuPushbuttonAdd("MainMenu",
		"PushButton3", "Thirdbutton", "this button will show a message", NULL, PRO_B_TRUE, PushButton3_cmd_id, MsgFile);
	return status;
}
extern  "C" void user_terminate()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
}
