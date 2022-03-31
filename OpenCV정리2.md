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

imshow("창이름", img);				// 이미지 창으로 출력
resize(img, imgResize, Size(), 0.5, 0.5);   		// 이미지 사이지 줄이는 함수
cvtColor(img, ColorChange, COLOR_BGR2GRAY);		// 컬러를 흑백으로 하는 함수
			COLOR_BGR2HSV		// BGR -> HSV 로 변경
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
각종 필터 적용
https://diyver.tistory.com/91?category=911404
```
