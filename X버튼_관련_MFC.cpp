void Cmy_test222222222Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else if(nID == SC_CLOSE)
	{
		if (MessageBox(L"프로그램 종료", L"Software EXIT", MB_YESNO) == IDYES) {
			AfxGetMainWnd()->PostMessageW(WM_CLOSE);
		}
		else
		{

		}
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}
