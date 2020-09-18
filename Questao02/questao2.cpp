#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <cmath>

using namespace std;
using namespace cv;

int main()
{
	Mat img = cv::imread("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/ImagemOriginal.jpg", IMREAD_GRAYSCALE);
	imshow("IMAGE", img);
	imwrite("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/ImagemComGrayscale.jpg", img);
	waitKey(0);
	return 0;
}