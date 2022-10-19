
// exam2Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "exam2.h"
#include "exam2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Menu espresso;
Menu latte;
Menu americano;

Cexam2Dlg::Cexam2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cexam2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cexam2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEXT1, m_Text1);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(Cexam2Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cexam2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cexam2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cexam2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Cexam2Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Cexam2Dlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// Cexam2Dlg 메시지 처리기

BOOL Cexam2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	coffee = 10000;
	water = 10000;
	milk = 5000;

	espresso.cnt = 0;
	espresso.coffee = 100;
	espresso.milk = 0;
	espresso.water = 30;
	espresso.price = 4000;

	latte.cnt = 0;
	latte.coffee = 100;
	latte.milk = 30;
	latte.water = 70;
	latte.price = 5000;

	americano.cnt = 0;
	americano.coffee = 100;
	americano.milk = 0;
	americano.water = 100;
	americano.price = 4500;
	
	sum = 0;
	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void Cexam2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}


HCURSOR Cexam2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cexam2Dlg::OnBnClickedButton1()
{
	while (m_list.DeleteColumn(0));
	while (m_list.DeleteItem(0));

	m_list.InsertColumn(0, TEXT("원두"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(1, TEXT("물"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(2, TEXT("우유"), LVCFMT_LEFT, 100);

	CString strCoffee;
	strCoffee.Format(_T("%d"), coffee);

	CString strWater;
	strWater.Format(_T("%d"), water);

	CString strMilk;
	strMilk.Format(_T("%d"), milk);

	m_list.InsertItem(0, strCoffee);
	m_list.SetItemText(0, 1, strWater);
	m_list.SetItemText(0, 2, strMilk);
	
}


void Cexam2Dlg::OnBnClickedButton2()
{
	while (m_list.DeleteColumn(0));
	while (m_list.DeleteItem(0));

	m_list.InsertColumn(0, TEXT("총수익금"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(1, TEXT("제품별매출 통계"), LVCFMT_LEFT, 400);
	m_list.InsertColumn(2, TEXT("판매리스트"), LVCFMT_LEFT, 300);

	CString strSum;
	strSum.Format(_T("%d"), sum);

	CString strStatistics;
	strStatistics.Format(_T("espresso : %d, latte : %d, americano : %d"), espresso.cnt * espresso.price, latte.cnt * latte.price, americano.cnt * americano.price);

	CString strSell;
	strSell.Format(_T("espresso : %d Cnt, latte : %d Cnt, americano : %d Cnt"), espresso.cnt, latte.cnt, americano.cnt);

	m_list.InsertItem(0, strSum);
	m_list.SetItemText(0, 1, strStatistics);
	m_list.SetItemText(0, 2, strSell);
}


void Cexam2Dlg::OnBnClickedButton3()		// espresso
{
	orderCheck(&espresso);
}


void Cexam2Dlg::OnBnClickedButton4()		// latte
{
	orderCheck(&latte);
}


void Cexam2Dlg::OnBnClickedButton5()		// americano
{
	orderCheck(&americano);
}

void Cexam2Dlg::orderCheck(Menu* m)
{
	if (m->coffee > coffee){
		MessageBox(_T("fail"), _T("alarm"), MB_ICONINFORMATION | MB_OK);
	}
	else if (m->water > water){
		MessageBox(_T("fail"), _T("alarm"), MB_ICONINFORMATION | MB_OK);
	}
	else if (m->milk > milk){
		MessageBox(_T("fail"), _T("alarm"), MB_ICONINFORMATION | MB_OK);
	}
	else{
		MessageBox(_T("ok"), _T("alarm"), MB_ICONINFORMATION | MB_OK);
		m->cnt++;
		sum += m->price;
		coffee -= m->coffee;
		water -= m->water;
		milk -= m->milk;
	}

}