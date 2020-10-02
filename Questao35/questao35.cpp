#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <stdio.h>

using namespace std;
using namespace cv;

int main() {
    Mat img, grayImg, otsuThresholdImg, dilatedImg;

    img = imread("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/ImagemOriginal.jpg");

    cvtColor(img, grayImg, CV_RGB2GRAY);

    GaussianBlur(grayImg, grayImg, Size(3, 3), 1);

    threshold(grayImg, otsuThresholdImg, 0, 255, THRESH_OTSU);

    dilate(otsuThresholdImg, dilatedImg, Mat(), Point(-1, -1), 3, BORDER_CONSTANT, morphologyDefaultBorderValue());

    imshow("original image", img);
    imshow("Otsu's threshold image", otsuThresholdImg);
    imshow("dilated image", dilatedImg);

    waitKey(0);
    return 0;
}