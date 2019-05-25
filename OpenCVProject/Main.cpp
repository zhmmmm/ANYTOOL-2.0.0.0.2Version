#include "Main.h"


int Main()
{

	VideoCapture capture("M.mp4");

	Mat frame;

	while (waitKey(33) != 27)
	{
		capture >> frame;
		imshow("°æ ”∆µ°ø", frame);
	}





	system("pause");
	return 0;
}