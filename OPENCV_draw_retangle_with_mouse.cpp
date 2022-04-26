struct initRoi {
	// on off
	int init;

	//initial coordination based on EVENT_LBUTTONDOWN
	int initX;
	int initY;

	// actual coordination 
	int actualX;
	int actualY;

	//Selected Rect
	Rect roiRect;

	//Selected Mat roi
	Mat takenRoi;
}SelectedRoi;

void on_mouse(int event, int x, int y, int flags, void *img)
{

	if (event == EVENT_RBUTTONDOWN)
	{
		return;
	}
	if (event == EVENT_LBUTTONDOWN)
	{
		SelectedRoi.initX = x;
		SelectedRoi.initY = y;
		SelectedRoi.init = 1;
		return;
	}

	if (event == EVENT_LBUTTONUP)
	{
		SelectedRoi.actualX = x;
		SelectedRoi.actualY = y;
		SelectedRoi.init = 2;
		return;
	}

	if (event == EVENT_MOUSEMOVE)
	{
		SelectedRoi.actualX = x;
		SelectedRoi.actualY = y;
		SelectedRoi.roiRect = Rect(SelectedRoi.initX, SelectedRoi.initY,
			SelectedRoi.actualX, SelectedRoi.actualY);
		return;
	}
}
//////////////////////////////////////////////////////////////////main/////////////////////////////
void Cmy_test222222222Dlg::OnBnClickedBtnsharp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Mat my_img(480, 640, CV_8UC1, Scalar(0));
	my_img.data = m_imgframe.m_pSrcImg;

	//imshow("sharpening_img",Sharpening_Funtion(img));
	SelectedRoi.init = 0;
	while(1)
	{
		Mat color_img;
		cvtColor(my_img, color_img, COLOR_GRAY2BGR);
		namedWindow("Video", WINDOW_AUTOSIZE);
		setMouseCallback("Video", on_mouse, 0);

		if (SelectedRoi.init == 1) {
			// draw the rectangle updated by mouse move
			rectangle(color_img, Rect(SelectedRoi.initX, SelectedRoi.initY,
				SelectedRoi.actualX - SelectedRoi.initX, SelectedRoi.actualY - SelectedRoi.initY),
				Scalar(0, 0, 255), 1, 8, 0);
		}
		else if (SelectedRoi.init == 2) {
			rectangle(color_img, Rect(SelectedRoi.initX, SelectedRoi.initY,
				SelectedRoi.actualX - SelectedRoi.initX, SelectedRoi.actualY - SelectedRoi.initY),
				Scalar(0, 0, 255), 1, 8, 0);
			imshow("Video", color_img);
			
			int key2 = waitKey();
			if (key2 == 13)
			{
				SelectedRoi.init = 0;
				continue;
			}
			else if(key2 == 27)
			{
				destroyWindow("Video");
				break;
			}
		}
		imshow("Video", color_img);
		
		if (waitKey(1) == 27)
		{
			destroyWindow("Video");
			break;
		}
	}
}
