/*
HoughCircles(img, circles, HOUGH_GRADIENT, dp, minDist, pram1, param2, min_radius, max_radius);
img = 이미지
HOUGH_GRADIENT = method 방법 중 하나 (HOUGH_GRADIENT_ALT 이 메소드는 더 정확한 원을 잡는 방법? dp를 1.5로 하는 것을 권장)
dp = 이미지 품질 1이 원본 상태 
minDist = 구하는 원들의 중심점 간의 거리의 최소값
param1 = HoughCircles는 Canny Funtion을 사용하는데 이 Canny Funtion에 들어가는 threshold 의 higher 값이다. lower 값은 param1 / 2 이다.
param2 = 원을 구할 때 민감도? 낮으면 낮을 수록 많은 원을 구해줌.
min_radius = 구하는 원의 반지름의 최소값
max_radius = 구하는 원의 반지름의 최대값 (음수를 넣으면 중심점의 좌표만 찾아준다고 하는데 잘 못 찾는듯??)
*/

// 그냥 string 유용함 함수 copy code
template<typename ... Args>
std::string string_format(const std::string& format, Args ... args)
{
	size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
	if (size <= 0) { throw std::runtime_error("Error during formatting."); }
	std::unique_ptr<char[]> buf(new char[size]);
	snprintf(buf.get(), size, format.c_str(), args ...);
	return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
}

Mat Cmy_test222222222Dlg::My_GetCircle(Mat img) {
	CRect rectResult;
	int radius = _ttoi(m_editnum2);
	vector<Vec3f> circles;
	string text_point = "";
	UpdateData(TRUE);
	int param1 = _ttoi(m_param1);
	int param2 = _ttoi(m_param2);
	HoughCircles(img, circles, HOUGH_GRADIENT, 1, 12, param1, param2, radius, radius +5);

	cv::cvtColor(img, img, COLOR_GRAY2BGR);
	/////////////////////////////원본이미지///////////
	Mat img_main(m_BmpHeight, m_BmpWidth, CV_8UC1, Scalar(0));
	img_main.data = m_imgframe.m_pSrcImg;
	Mat img_main_color;
	cv::cvtColor(img_main, img_main_color, COLOR_GRAY2BGR);
	/////////////////////////////
	int count_yy = 0;
	///// 가장 뚜렷한 원에서 중심점을 찾아준다//////////
	Point circle_center = FindCenterPoint();
	text_point= string_format("cx : %d, cy : %d", circle_center.x, circle_center.y);
	cv::putText(img_main_color, text_point, Point(10,10), 1, 1, Scalar(0, 255, 0), 1, 8);
  
	for (int i = 0; i < circles.size(); i++)
	{
		Vec3i c = circles[i];
		Point center(c[0], c[1]);
		Scalar color = Scalar(0, 0, 0);
		int radius = c[2];

		if (//count_yy == 0 )//&&
			   (c[0] <= circle_center.x + 5 && c[0] >= circle_center.x - 5)
			&& (c[1] <= circle_center.y + 5 && c[1] >= circle_center.y - 5) ) 
		{
			color = Scalar(0, 0, 255);
			text_point = string_format("x : %d, y : %d, radius: %d", c[0], c[1], c[2]);
			cv::putText(img_main_color, text_point, Point(c[0], c[1]), 1, 1, color, 1, 8);
			cv::circle(img_main_color, center, radius, color, 2);
			cv::circle(img_main_color, center, 2, color, 2);
		}
	}
	return img_main_color;
}
