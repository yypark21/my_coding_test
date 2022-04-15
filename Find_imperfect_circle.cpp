GaussianBlur(img, img_blur, Size(11, 11), 0);
Mat sharp_img = Sharpening_Funtion(img_blur);
threshold(sharp_img, binary_img, 27, 255, THRESH_BINARY);
Canny(binary_img, canny_img, 255 / 2, 255);
cv::imshow("Find_circle", My_GetCircle(canny_img));

Mat Cmy_test222222222Dlg::Sharpening_Funtion(Mat img) {
	float data[9] = { -1,-1,-1,-1,3,-1,-1,-1,-1 };
	Mat kernel(3, 3, CV_32FC1, data);

	Mat sharp;
	filter2D(img, sharp, -1, kernel, Point(-1, -1), 0);
	Mat dst;
	addWeighted(img, 0.75, sharp, 0.25, 0, dst);
	return dst;
}


Mat Cmy_test222222222Dlg::My_GetCircle(Mat img) {
	CRect rectResult;
	int radius = _ttoi(m_editnum2);
	vector<Vec3f> circles;
	string text_point = "";
	UpdateData(TRUE);
	int param1 = _ttoi(m_param1);
	int param2 = _ttoi(m_param2);
	HoughCircles(img, circles, HOUGH_GRADIENT, 1,
		12,  // change this value to detect circles with different distances to each other
		param1, param2, radius, radius +5 // change the last two parameters
	// (min_radius & max_radius) to detect larger circles
	);
	cvtColor(img, img, COLOR_GRAY2BGR);
	/////////////////////////////원본이미지///////////
	Mat img_main(m_BmpHeight, m_BmpWidth, CV_8UC1, Scalar(0));
	img_main.data = m_imgframe.m_pSrcImg;
	Mat img_main_color;
	cvtColor(img_main, img_main_color, COLOR_GRAY2BGR);
	/////////////////////////////
	int count_yy = 0;
	for (int i = 0; i < circles.size(); i++)
	{
		Vec3i c = circles[i];
		Point center(c[0], c[1]);
		Scalar color;
		int radius = c[2];
		if(c[0]>280 && c[0]<350 && c[1]>200 && c[1] < 280){
			if (count_yy == 0) {
				color = Scalar(0, 0, 255); 
				count_yy++; 		
			}
			/*
			else if(count_yy < 8){
				color = Scalar(0, 255, 255);
				count_yy++;
			}*/
			else
			{
				break;
			}
			text_point = string_format("x : %d, y : %d, radius: %d", c[0], c[1], c[2]);
			cv::putText(img_main_color, text_point, Point(c[0], c[1]), 1, 1, color, 1, 8);
			cv::circle(img_main_color, center, radius, color, 2);
			cv::circle(img_main_color, center, 2, color, 2);
		}
	}

	//threshold(img, img_binary, low, 255, THRESH_BINARY);
	//medianBlur(img, dst2, 1);
	return img_main_color;
}
