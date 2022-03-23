
// calculatorDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <sstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CcalculatorDlg 대화 상자



CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_editaaaaa(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_editaaaaa);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CcalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CcalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CcalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CcalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CcalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CcalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CcalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CcalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CcalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CcalculatorDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CcalculatorDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON13, &CcalculatorDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON12, &CcalculatorDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON14, &CcalculatorDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CcalculatorDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CcalculatorDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CcalculatorDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CcalculatorDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CcalculatorDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CcalculatorDlg::OnBnClickedButton20)
END_MESSAGE_MAP()


// CcalculatorDlg 메시지 처리기

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	m_editaaaaa = _T("");

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}


int j = 0;

struct Struct_CalVal {
	CString cal;
	double val[20];
	int index;
	int length;
};

double Function_cal(Struct_CalVal Str_CalVal) {
	double answer = 0;

	for (int i = 0; i < Str_CalVal.index; i++) {
		if (Str_CalVal.cal[i] == '*' || Str_CalVal.cal[i] == '/') {
			switch (Str_CalVal.cal[i])
			{
			case '*':
				answer = Str_CalVal.val[i] * Str_CalVal.val[i + 1];
				Str_CalVal.val[i] = 0;
				Str_CalVal.val[i + 1] = answer;
				if (i - 1 >= 0 && Str_CalVal.cal[i - 1] == '-')
					Str_CalVal.cal.SetAt(i, '-');
				else
					Str_CalVal.cal.SetAt(i, '+');
				break;
			case '/':
				answer = Str_CalVal.val[i] / Str_CalVal.val[i + 1];
				Str_CalVal.val[i] = 0;
				Str_CalVal.val[i + 1] = answer;
				if (i - 1 >= 0 && Str_CalVal.cal[i - 1] == '-')
					Str_CalVal.cal.SetAt(i, '-');
				else
					Str_CalVal.cal.SetAt(i, '+');
				break;
			default:
				break;
			}
		}
	}
	for (int i = 0; i < Str_CalVal.index; i++) {
		switch (Str_CalVal.cal[i])
		{
		case '+':
			answer = Str_CalVal.val[i] + Str_CalVal.val[i + 1];
			Str_CalVal.val[i] = 0;
			Str_CalVal.val[i + 1] = answer;
			break;
		case '-':
			answer = Str_CalVal.val[i] - Str_CalVal.val[i + 1];
			Str_CalVal.val[i] = 0;
			Str_CalVal.val[i + 1] = answer;
			break;
		default:
			break;
		}
	}

	return answer;
};

Struct_CalVal Div_CalVal(CString Mathematical, char a) {
	Struct_CalVal Str_CalVal;
	CString strNumber(_T(""));
	
	int index = 0;
	if (Mathematical[0] == '-')
		Mathematical = '0' + Mathematical;
	Str_CalVal.length = Mathematical.GetLength();
	int i = 0;
	while (1)
	{
		char ch = Mathematical.GetAt(i);
		if (a == '(' && ch == ')') {
			j = i;
			break;
		}
		if (ch == '(') {
			CString c;
			if (Mathematical.GetAt(i + 1)) {
				AfxMessageBox(_T("빈 괄호가 존재하면 안됩니다."));
				Str_CalVal.cal = "";
				return Str_CalVal;
			}
			c.Format(_T("%f"), Function_cal(Div_CalVal(Mathematical.Mid(i + 1), ch)));
			Mathematical = Mathematical.Left(i) + c + Mathematical.Mid(i + j + 2);
			ch = c[0];
		}
		if ((ch >= '0' && ch <= '9') || ch == '.') {
			if (strNumber == "0" && ch != '.') {
				AfxMessageBox(_T("식에 잘못된 수가 들어가 있습니다."));
				Str_CalVal.cal = "";
				return Str_CalVal;
			}
			strNumber += ch;
		}
		else
		{
			Str_CalVal.val[index] = _ttof(strNumber);
			Str_CalVal.cal += ch;

			strNumber = _T("");
			index++;
		}
		i++;
		if (i > Mathematical.GetLength()) {
			break;
		}
	}
	Str_CalVal.val[index] = _ttof(strNumber);
	Str_CalVal.index = index;

	return Str_CalVal;
};

int GetFindCharCount(CString parm_string, char parm_find_char)
{
	int length = parm_string.GetLength(), find_count = 0;
	for (int i = 0; i < length; i++)
	{
		if (parm_string[i] == parm_find_char)
		{
			find_count++;
		}
	}
	return find_count;
}

CString error_a(CString m_editaaaaa) {
	if (m_editaaaaa.GetLength() > 1 && m_editaaaaa.GetAt(m_editaaaaa.GetLength() - 2) == ')') {
		m_editaaaaa.Delete(m_editaaaaa.GetLength() - 1);
		return m_editaaaaa;
	}
	else
		return m_editaaaaa;
}

/*
CString error_b(CString m_editaaaaa) {
	if (m_editaaaaa.GetLength() > 1 && (m_editaaaaa.GetAt(m_editaaaaa.GetLength() - 2) == '+' || m_editaaaaa.GetAt(m_editaaaaa.GetLength() - 2) == '-' || m_editaaaaa.GetAt(m_editaaaaa.GetLength() - 2) == '*' || m_editaaaaa.GetAt(m_editaaaaa.GetLength() - 2) == '/')) {
		m_editaaaaa.Delete((m_editaaaaa.GetLength() - 1));
		return m_editaaaaa;
	}
	return m_editaaaaa;
}
*/

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CcalculatorDlg::OnPaint()
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
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CcalculatorDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_editaaaaa += _T('1');
	m_editaaaaa=error_a(m_editaaaaa);
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_editaaaaa += _T('2');
	m_editaaaaa = error_a(m_editaaaaa);
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_editaaaaa += _T('3');
	m_editaaaaa = error_a(m_editaaaaa);
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_editaaaaa += _T('4');
	m_editaaaaa = error_a(m_editaaaaa);
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_editaaaaa += _T('5');
	m_editaaaaa = error_a(m_editaaaaa);
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_editaaaaa += _T('6');
	m_editaaaaa = error_a(m_editaaaaa);
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_editaaaaa += _T('7');
	m_editaaaaa = error_a(m_editaaaaa);
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_editaaaaa += _T('8');
	m_editaaaaa = error_a(m_editaaaaa);
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_editaaaaa += _T('9');
	m_editaaaaa = error_a(m_editaaaaa);
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_editaaaaa += _T('0');
	m_editaaaaa = error_a(m_editaaaaa);
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	
	if (m_editaaaaa.Right(1) == '+' || m_editaaaaa.Right(1) == '-' || m_editaaaaa.Right(1) == '*' || m_editaaaaa.Right(1) == '/') {
		m_editaaaaa.Delete((m_editaaaaa.GetLength() - 1));
	}
	m_editaaaaa += _T('+');
	if (m_editaaaaa[0] == '+') {
		m_editaaaaa = _T("");
	}
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton13()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (m_editaaaaa.Right(1) == '+' || m_editaaaaa.Right(1) == '-' || m_editaaaaa.Right(1) == '*' || m_editaaaaa.Right(1) == '/') {
		m_editaaaaa.Delete((m_editaaaaa.GetLength() - 1));
	}
	m_editaaaaa += _T('*');
	if (m_editaaaaa[0] == '*') {
		m_editaaaaa = _T("");
	}
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (m_editaaaaa.Right(1) == '+' || m_editaaaaa.Right(1) == '-' || m_editaaaaa.Right(1) == '*' || m_editaaaaa.Right(1) == '/') {
		m_editaaaaa.Delete((m_editaaaaa.GetLength() - 1));
	}
	m_editaaaaa += _T('-');
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton14()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (m_editaaaaa.Right(1) == '+' || m_editaaaaa.Right(1) == '-' || m_editaaaaa.Right(1) == '*' || m_editaaaaa.Right(1) == '/') {
		m_editaaaaa.Delete((m_editaaaaa.GetLength() - 1));
	}
	m_editaaaaa += _T('/');
	if (m_editaaaaa[0] == '/') {
		m_editaaaaa = _T("");
	}
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton15()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	char a = ' ';
	Struct_CalVal Str_CalVal = Div_CalVal(m_editaaaaa, a);
	// if (GetFindCharCount(m_editaaaaa, '(') != GetFindCharCount(m_editaaaaa, ')'))
		// AfxMessageBox(_T("괄호의 갯수가 다릅니다"));
	m_editaaaaa.Format(_T("%f"), Function_cal(Str_CalVal));
	UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButton16()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_editaaaaa.Delete(m_editaaaaa.GetLength()-1) ;
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton17()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_editaaaaa += _T('.');
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton18()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	BOOL error = FALSE;
	if (m_editaaaaa.Right(1) >= _T("0") && m_editaaaaa.Right(1) <= _T("9")) {
		error = TRUE;
	}
	m_editaaaaa += _T('(');
	if (error == TRUE) {
		m_editaaaaa.Delete((m_editaaaaa.GetLength() - 1));
	}

	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton19()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (GetFindCharCount(m_editaaaaa, '(') > GetFindCharCount(m_editaaaaa, ')')) {
		m_editaaaaa += _T(')');
		if (m_editaaaaa.GetLength() > 1 && (m_editaaaaa.GetAt(m_editaaaaa.GetLength() - 2) == '+' || m_editaaaaa.GetAt(m_editaaaaa.GetLength() - 2) == '-'|| m_editaaaaa.GetAt(m_editaaaaa.GetLength() - 2) == '*'|| m_editaaaaa.GetAt(m_editaaaaa.GetLength() - 2) == '/')) {
			m_editaaaaa.Delete((m_editaaaaa.GetLength() - 1));
		}
	}
	else
	{
		m_editaaaaa += _T('(');
	}
	UpdateData(FALSE);
}

void error_1(CString a) {
	
}

void CcalculatorDlg::OnBnClickedButton20()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_editaaaaa = _T("");
	UpdateData(FALSE);
}
