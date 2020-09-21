#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <stdio.h>

using namespace std;
using namespace cv;

int main()
{
	Mat color = imread("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/ImagemOriginal.jpg", 1);
	Mat_<uchar> gray(240, 320, 1);
	Mat dst;

	GaussianBlur(color, color, Size(3, 3), 0, 0, BORDER_DEFAULT);

	cvtColor(color, gray, COLOR_RGB2GRAY);
	Mat abs_dst;
	Laplacian(gray, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(dst, abs_dst);

	int max = gray.at<uchar>(0, 0);
	int min = gray.at<uchar>(0, 0);
	int x, y;
	for (y = 0; y < 240; y++)
	{
		for (x = 0; x < 320; x++)
		{
			if (gray.at<uchar>(y, x) < max)
				max = gray.at<uchar>(y, x);
			if (gray.at<uchar>(y, x) > min)
				min = gray.at<uchar>(y, x);
		}
	}

	Mat_<uchar> equalizada(240, 320, 1);
	for (y = 0; y < 240; y++)
	{
		for (x = 0; x < 320; x++)
		{
			// determinando a intensidade da borda
			equalizada.at<uchar>(y, x) = (gray.at<uchar>(y, x) - max) * 255 / (min - max);
		}
	}

	imshow("IMAGEM EQUALIZADA", equalizada);
	imshow("Imagem", abs_dst);
	waitKey(0);
	return 0;
}