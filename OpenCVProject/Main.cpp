#include "Main.h"





int Main()
{
	

	VideoCapture capture("M.mp4");

	

	Mat frame;

	while (waitKey(24) != 27)
	{
		capture >> frame;
		imshow("°æ ”∆µ°ø", frame);
	}
	capture.release();
	frame.release();
	destroyAllWindows();
	
	

	system("pause");
	return 0;
}