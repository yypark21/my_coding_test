	static taxt 에 CString 메세지 출력
  
  ```
  GetDlgItem(IDC_STATIC_INFO)->SetWindowText(strMsg);
  ```
  
  시간 재는 방법
  ```
  	INT64 result;
	  INT64 dTick1, dTick2;
  	dTick1 = GetTickCount();
  	dTick2 = GetTickCount();
	  result = (dTick2 - dTick1);
    ```
