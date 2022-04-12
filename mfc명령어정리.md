GetDlgItem(IDC_STATIC_INFO)->SetWindowText(strMsg);


// 임의로 적은 텍스트 내용을 받아와 버튼을 누르면 내용이 메세지 박스에 뜬다.

CString str = _T("");
GetDlgItemText(IDC_EDIT1, str);
MessageBox(str);



// 버튼을 누르면 관련된 정보들이 안보이게 하는 code 어딘가 문제 있음
UpdateData(TRUE);
GetDlgItem(IDC_BUTTON1)->ShowWindow(FALSE);



SetDlgItemText(IDC_STATIC1,"블럭 번호");

AfxMessageBox(Format(_T("I am the %d years old"), nYear));


// 버튼을 누르면 현재 연도와 시간이 뜸 , 쓰레기 값이 뜸

	CTime cTime = CTime::GetCurrentTime();
	CString strDate, strTime;
	strDate.Format(_T("%04d년 %02d월 %02d일", cTime.GetYear(), cTime.GetMonth(), cTime.GetDay()));
	strTime.Format(_T("%02d시 %02d분 %02d초", cTime.GetHour(), cTime.GetMinute(), cTime.GetSecond()));
	MessageBox(strTime);


CRect rImgRect;
rImgRect.left = 0;
rImgRect.top = 0;
rImgRect.right = 319;
rImgRect.bottom = 239;
MoveWindow(0, 0, 640, 480, true);
GetDlgItem(IDC_STATIC_IMG)->MoveWindow(rImgRect, true);
GetDlgItem(IDC_STATIC_IMG)->MoveWindow(1, 1, 640, 480, true);
