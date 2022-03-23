
// MFC_calendarDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFC_calendar.h"
#include "MFC_calendarDlg.h"
#include "afxdialogex.h"
#include <ctime> 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCcalendarDlg 대화 상자



CMFCcalendarDlg::CMFCcalendarDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_CALENDAR_DIALOG, pParent)
	, m_curdate(_T("현재 날짜 :"))
	, m_year(_T("0"))
	, m_month(_T("0"))
	, m_day(_T("0"))
	, m_aftdate(_T("계산 후 날짜 :"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCcalendarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_CURDATE, m_curdate);
	DDX_Text(pDX, IDC_EDIT_YEAR, m_year);
	DDX_Text(pDX, IDC_EDIT_MONTH, m_month);
	DDX_Text(pDX, IDC_EDIT_DAY, m_day);
	DDX_Text(pDX, IDC_STATIC_AFTDATE, m_aftdate);
}

BEGIN_MESSAGE_MAP(CMFCcalendarDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_YEAR, &CMFCcalendarDlg::OnEnChangeEditYear)
	ON_STN_CLICKED(IDC_STATIC_CURDATE, &CMFCcalendarDlg::OnStnClickedStaticCurdate)
	ON_STN_CLICKED(IDC_STATIC_AFTDATE, &CMFCcalendarDlg::OnStnClickedStaticAftdate)
	ON_BN_CLICKED(IDC_BTNCHK, &CMFCcalendarDlg::OnBnClickedBtnchk)
	ON_EN_CHANGE(IDC_EDIT_MONTH, &CMFCcalendarDlg::OnEnChangeEditMonth)
	ON_EN_CHANGE(IDC_EDIT_DAY, &CMFCcalendarDlg::OnEnChangeEditDay)
END_MESSAGE_MAP()


// CMFCcalendarDlg 메시지 처리기

BOOL CMFCcalendarDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCcalendarDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCcalendarDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCcalendarDlg::OnEnChangeEditYear()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMFCcalendarDlg::OnEnChangeEditMonth()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCcalendarDlg::OnEnChangeEditDay()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCcalendarDlg::OnStnClickedStaticCurdate()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

}


void CMFCcalendarDlg::OnStnClickedStaticAftdate()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

CString CalculatorDate(int current_year, int current_month, int current_day, int plus_year, int plus_month, int plus_day) {
	CString aftDate;
	int day[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	current_year += plus_year;
	current_month += plus_month;
	if (current_month > 12) {
		current_year += current_month / 12;
		current_month %= 12;
		if (current_month == 0)
			current_month = 12;
	}
	if (current_year % 4 == 0) { 
		day[2] = 29; 
	}
	current_day += plus_day;
	while(current_day > day[current_month]){
		current_day -= day[current_month];
		current_month += 1;
	}
	aftDate.Format(_T("계산 후 날짜: %d년 %2d월 %2d일"), current_year, current_month, current_day);

	return aftDate;
}

void CMFCcalendarDlg::OnBnClickedBtnchk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);
	m_curdate.Format(_T("현재 날짜 : %d년 %2d월 %2d일"), t->tm_year+1900, t->tm_mon+1, t->tm_mday);
	m_aftdate = CalculatorDate(t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, _wtoi(m_year), _wtoi(m_month), _wtoi(m_day));
	UpdateData(FALSE);
}


