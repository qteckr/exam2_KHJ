
// exam2.cpp : ���� ���α׷��� ���� Ŭ���� ������ �����մϴ�.
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


// Cexam2App ����

Cexam2App::Cexam2App()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	// InitInstance�� ��� �߿��� �ʱ�ȭ �۾��� ��ġ�մϴ�.
}

// �ּ��׽�Ʈ5
// ������ Cexam2App ��ü�Դϴ�.

Cexam2App theApp;


// Cexam2App �ʱ�ȭ

BOOL Cexam2App::InitInstance()
{
	CWinApp::InitInstance();


	Cexam2Dlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	return FALSE;
}

