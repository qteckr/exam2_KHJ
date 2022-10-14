
// exam2.cpp : 응용 프로그램에 대한 클래스 동작을 정의합니다.
//

#include "stdafx.h"
#include "exam2.h"
#include "exam2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexam2App

BEGIN_MESSAGE_MAP(Cexam2App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// Cexam2App 생성

Cexam2App::Cexam2App()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}

// 주석테스트5
// 유일한 Cexam2App 개체입니다.

Cexam2App theApp;


// Cexam2App 초기화

BOOL Cexam2App::InitInstance()
{
	CWinApp::InitInstance();


	Cexam2Dlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	return FALSE;
}

