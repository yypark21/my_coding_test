// 이미지를 받아온 후 bgr -> hsv 로 변경 하여 원하는 범위 내의 픽셀 값만 뽑아 냄 

void COpenCVcolorExtrationDlg::OnBnClickedBtnColor()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);
	Mat img = imread("..\\1.bmp");
	int iWidth = img.rows;
	int iHeight = img.cols;
	int HueMaxRange = 179;
	int HueMinRange = 0;
	Mat img_hsv, and_image;
	cvtColor(img, img_hsv, COLOR_BGR2HSV);
	Mat mask(img.cols, img.rows, CV_8UC1, Scalar(0));

	// m_RangeRed m_RangeGreen m_RangeBlue    HSV 인데 변수 선언을 잘못함.
	Scalar lower_hsv = Scalar(_ttoi(m_RangeRed), _ttoi(m_RangeGreen), _ttoi(m_RangeBlue));
	Scalar upper_hsv = Scalar(_ttoi(m_RangeEndRed), _ttoi(m_RangeEndGreen), _ttoi(m_RangeEndBlue));
	
	Scalar lower_h = Scalar(_ttoi(m_RangeRed));
	Scalar upper_h = Scalar(_ttoi(m_RangeEndRed));

	uchar* img_data = img_hsv.data;
	
	CString IMG_HSV;
	Mat hsvchannel[3];
	split(img_hsv, hsvchannel);
	//imshow("Image", img);
	//imshow("Hue", hsvchannel[0]);
	//imshow("Sat", hsvchannel[1]);
	//imshow("Val", hsvchannel[2]);
	//inRange(hsvchannel[0], _ttoi(m_RangeRed), _ttoi(m_RangeEndRed), mask);
	//imshow("mask", mask);
	uchar* h_data = hsvchannel[0].data;
	uchar* s_data = hsvchannel[1].data;
	Mat new_h_img(iWidth, iHeight, CV_8UC1, Scalar(255));
	Mat new_s_img(iWidth, iHeight, CV_8UC1, Scalar(0));
	uchar* new_h_data = new_h_img.data;
	uchar* new_s_data = new_s_img.data;

	int Range_min, Range_max;
	Range_max = _ttoi(m_RangeEndRed);
	if (_ttoi(m_RangeRed) < 0) {
		Range_min = HueMaxRange + _ttoi(m_RangeRed);
	}
	else
	{
		Range_min = _ttoi(m_RangeRed);
	}
	for (int y = 0; y < iHeight; y++) {
		for (int x = 0; x < iWidth; x++){
			if (_ttoi(m_RangeRed) < 0){
				if ( ((h_data[x + y * iWidth] >= Range_min) && (h_data[x + y * iWidth] <= HueMaxRange)) )
				{
					// new_h_data[x + y * iWidth] = h_data[x + y* iWidth];
				}
				else if ( ((h_data[x + y * iWidth] >= 0) && (h_data[x + y * iWidth] <= Range_max)) )
				{
					// new_h_data[x + y * iWidth] = h_data[x + y * iWidth];
				}
				else
				{
					new_h_data[x + y * iWidth] = 0;
				}
			}
			else
			{
				if (((h_data[x + y * iWidth] >= Range_min) && (h_data[x + y * iWidth] <= Range_max))) {

				}
				else
				{
					new_h_data[x + y * iWidth] = 0;
				}
			}
		}
	}

	for (int y = 0; y < iHeight; y++) {
		for (int x = 0; x < iWidth; x++) {
			if ( ((s_data[x + y * iWidth] >= _ttoi(m_RangeGreen)) && (s_data[x + y * iWidth] <= _ttoi(m_RangeEndGreen))) ){
				new_s_data[x + y * iWidth] = s_data[x + y * iWidth];
			}
		}
	}

	imshow("new_h_img", new_h_img);
	imshow("new_s_img", new_s_img);
	Mat new_img;
	bitwise_and(new_h_img, new_h_img, new_img, new_s_img);
	imshow("new_img", new_img);
	
	/*
	CString h_info;
	CString s_info;
	CString v_info;
	CString x_info;
	CString y_info;
	for (int y = 0 + _ttoi(m_iNUM2); y < 20 + _ttoi(m_iNUM2); y++)
	{
		for (int x = 0 + _ttoi(m_iNUM); x < 5 + _ttoi(m_iNUM); x++)
		{
			uchar h = img_data[y * img.cols * 3 + x * 3];
			uchar s = img_data[y * img.cols * 3 + x * 3 + 1];
			uchar v = img_data[y * img.cols * 3 + x * 3 + 2];
			h_info.Format(_T("h : %d "), h);
			s_info.Format(_T("s : %d "), s);
			v_info.Format(_T("v : %d "), v);
			x_info.Format(_T("x, y : ( %d, "), x);
			y_info.Format(_T("%d )|"), y);
			IMG_HSV += h_info + s_info + v_info + x_info + y_info;
		}
		IMG_HSV += _T("\n");
	}

	// x y 구조 
	// 
	// GetDlgItem(IDC_STATIC_COLOR)->SetWindowText(IMG_HSV);

	Mat img_median, img_median2, img_blur;
	inRange(img_hsv, lower_hsv, upper_hsv, mask);
	medianBlur(mask, img_median, 3);
	bitwise_and(img, img, and_image, img_median);
	//imshow("and_image", and_image);
	//imshow("img_median", img_median);
	//imshow("mask", mask);
	*/
}
