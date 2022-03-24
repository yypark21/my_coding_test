OpenCV 정리 

맨 처음 환경 설정

속성 -> 모든 구성 / x64

C/C++-일반 추가 포함 디렉터리에  C:\opencv\build\include 추가

링커 - 일반 - 추가 라이브러리 디렉터리 에 C:\opencv\build\x64\vc15\lib 추가

링커 - 입력 - 추가 종속성  opencv_world---d.lib; 추가 (버전에 맞춰서)
///////////////////////////////////////////////

Mat img =  imread(PATH);

Mat imgResize; 

resize(img, imgResize, Size(), 0.5, 0.5);   // 이미지 사이지 줄이는 함수

imshow("이름", img);     // 이미지 보여주는 함수


Mat ColorChange;

cvtColor(img, ColorChange, COLOR_BGR2GRAY); // 컬러를 흑백으로 하는 함수

img 안에 Circle 그리기
img.copyTo(img_circle);   // copy하는 함수
circle(img_circle, Point(500, 100),     50,           Scalar(255, 0, 255),    1,           		  8,      0);
                        중심 위치      반지름 길이        선 색깔          선 굵기(-1일 채워넣기)      선 타입  이동

waitKey(0);                                      // 콘솔할 때, 이미지 바로 사라지지 않게 하기 위해서
waitKey() == 27                                을 사용하여 'esc'를 눌러 종료


//unsined char 로 받아서 사용하는 방법
	Mat imgGray(960, 1280, CV_8UC1, Scalar(0)); //8bit
	Mat imgGray(960, 1280, CV_8UC3, Scalar(0)); //24bit
	//imgGray를 1280x960,8Bit 할당, 
	//imgGrayf를 픽셀 0으로 세팅
	
	uchar* pImgBuffer = imgGray.data;
	for (int row = 0; row < 100; row++)
	{
		for (int col = 0; col < 100; col++)
		{
			uchar b = pImgBuffer[row * imgGray.cols * 3 + col * 3] = 128;
			uchar g = pImgBuffer[row * imgGray.cols * 3 + col * 3 + 1] = 128;
			uchar r = pImgBuffer[row * imgGray.cols * 3 + col * 3 + 2] = 128;
		}
	}

	Mat imgGray2(960, 1280, CV_8UC3);
	imgGray2.data = pImgBuffer;

	imshow("imgGray", imgGray);
	imshow("imgGray2", imgGray);

///
	Mat MatGray(iImgHeight, iImgWidth, CV_8UC1, Scalar(0)); // 세로, 가로  imgGray를 1280x960, 8Bit  0으로 세팅


	uchar* pImgBuffer = MatGray.data;
	start = NULL;
	for (int y = 200; y < 300; y++)
	{
		for (int x = 100; x < 200; x++)
		{
			pImgBuffer[x  + y * iImgWidth] = 128;
		}
	}
	
	int iRadius = 100; // 반지름
	int iCx, iCy;
	iCx = iImgWidth / 2;
	iCy = iImgHeight / 2;

	for (int y = -iRadius; y <= iRadius; y++)
	{
		for (int x = -iRadius; x <= iRadius; x++)
		{
			if (y * y + x * x <= iRadius * iRadius)
			{
				pImgBuffer[x + iCx + (y + iCy) * 1280 ] = 128;
			}
		}
	}

