선언
1) Mat img = imread(PATH);

2) Mat img(H,W, CV_8UC1, Scalar(0));

3) uchar* img_data = img.data;
``` 
 	// img에서 받은 데이터가 color일 때 접근법 (3개의 값)
	uchar b = img_data[y * img.cols * 3 + x * 3];
	uchar g = img_data[y * img.cols * 3 + x * 3 + 1];
	uchar r = img_data[y * img.cols * 3 + x * 3 + 2];
	// 흑백일 때 접근법
	pImgBuffer[x  + y * img.cols] = 128;
```


함수
```
선언
1) Mat img = imread(PATH);

2) Mat img(H,W, CV_8UC1, Scalar(0));

3) uchar* img_data = img.data;
	// img에서 받은 데이터가 color일 때 접근법 (3개의 값)
	uchar b = img_data[y * img.cols * 3 + x * 3];
	uchar g = img_data[y * img.cols * 3 + x * 3 + 1];
	uchar r = img_data[y * img.cols * 3 + x * 3 + 2];
	// 흑백일 때 접근법
	pImgBuffer[x  + y * img.cols] = 128;

함수

imshow("창이름", img);				     // 이미지 창으로 출력
resize(img, imgResize, Size(), 0.5, 0.5);   		// 이미지 사이지 줄이는 함수
cvtColor(img, ColorChange, COLOR_BGR2GRAY);		// 컬러를 흑백으로 하는 함수
			COLOR_BGR2HSV			// BGR -> HSV 로 변경
img.copyTo(img_circle);   				// copy하는 함수 (=으로 할 시 주소값이 복사되어서 copyTo사용)
inRange(img_hsv, lower_hsv, upper_hsv, mask);	 	// 범위 값 내의 픽셀만 뽑아서 저장하는 함수
bitwise_not(img, saved_img);				// not 흑색 -> 백색, 백색-> 흑색
bitwise_and(img, img, yellow_image, mask);		// and 연산자 img와 mask에서 겹치는 부분만 출력
threshold( img, saved_img, value1, value2, type)		// https://diyver.tistory.com/63 임계값 이상의 자료 변형 
Mat img_new(img, Rect(0, 0, width, height))		// img에서 원하는 부분 잘라내서 새롭게 저장
add(img1, img2, saved_img);				// 크기가 같은 img 2개를 합쳐줌 (어떻게 합쳐지는 지는 ...)	
Mat rgbchannel[3]; split(image, rgbchannel);	
circle(img_circle, Point(500, 100), 50, Scalar(255, 0, 255), 1, 8, 0);
rectangle(img, Rect(Point(200, 200), Point(300, 300)), Scalar(0, 0, 0), 1, 8, 0);
rectangle(img, Rect(200, 200, 300, 300), Scalar(255, 255, 255), 1, 8, 0); 
//사각형 그리기 맨 뒤 3개 값 중 첫 번 째는 선의 굵기 두 번째는 선의 타입(-1 안을 채워넣음) 세 번 째는 shift 주로 0으로 함

////필터 부분
각종 필터 적용
https://diyver.tistory.com/91?category=911404

GaussianBlur(img, img_blur, Size(7, 7), 0);   // 흐리게 ??
Mat emboss(3,3,CV_32FC1, kernel);
filter2D(src, dst, -1, emboss, Point(-1,-1), 128);   // emboss 선명한걸 더 선명하게?
blur(src,dst, Size(ksize,ksize));     //평균값 필터링 <- 가우시안 보다 느리고 효율이 떨어지는 듯? ksize가 클 때는 더 빠를지도
GaussianBlur(src,dst,Size(),double(sigma)); //가우시안 필터
bilateralFilter(src, dst2, -1, 10, 5);  // 가우시안 필터와 다르게 표준편차를 이용한다. 
medianBlur(src, dst2, 3);   // 소금, 후추 같은 부분이 있을때,

GaussianBlur(src, blurred, Size(), sigma);
float alpha = 1.f;
Mat dst = (1 + alpha)*src - alpha * blurred;  // 영상을 더 선명하게 해준다-> 원본에 가우시안블러를 적용한 이미지를 더해줌

Mat noise(src.size(), CV_32SC1);
randn(noise, 0, stddev);
add(src, noise, dst, Mat(), CV_8U);    // 영상에 랜덤 노이즈를 더해준다
////////////////////////////////////////필터/////////////

floodFill(im_clone, Point(0, 0), Scalar(255)); // point 부터 다른 색을 찾아가는 함수 ? 전체를 하기 때문에 속도에서 ... 구석에 채우고 싶은 부분이 있을 때?
Canny(img, img_edge, 50, 200);     			// 경계선을 뚜렷하게 해주는 함수? 
erode(img, dst, mask, Point(-1, -1), 3); 		// 침식
dilate(img, dst, mask, Point(-1, -1), 3);		// 팽창



// 원을 찾아주는 함수
vector<Vec3f> circles;
HoughCircles(img_houghC, circles, HOUGH_GRADIENT, 1, 100, 50, 35, 0, 0);
// circles 부분에 원에 대한 정보가 저장 됨. HOUGH_GRADIENT : 원을 검출하는 방법, 1: 픽셀값, 100: 검출할 원의 최소거리(원들 간의 거리?) 50, 35 Canny 엣지 검출에서 큰값과 작은 값 0, 검출될 원의 최소 반지름, 최대 반지름

// 같이 쓰면 좋은 함수 (원과 중심점을 그려준다.)
for (size_t i = 0; i < circles.size(); i++)
{
	Vec3i c = circles[i];
	Point center(c[0], c[1]);
	int radius = c[2];

	circle(img_houghC, center, radius, Scalar(0, 255, 0), 2);
	circle(img_houghC, center, 2, Scalar(0, 0, 255), 3);
}

```
