#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <cmath>

using namespace std;
using namespace cv;

int main()
{
	Mat img = cv::imread("C:/Users/User/Desktop/LapiscoComputerVisionC-/images/ImagemOriginal.jpg", 1);
	imshow("IMAGE", img);
	imwrite("C:/Users/User/Desktop/LapiscoComputerVisionC-/images/ImagemGerada.jpg", img);
	waitKey(0);
	return 0;
}