#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <stdio.h>

using namespace std;
using namespace cv;

int main() {
    Mat img, grayImg, otsuThresholdImg, structuringElement;

    img = imread("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/ImagemOriginal.jpg");

    cvtColor(img, grayImg, COLOR_RGB2GRAY);

    GaussianBlur(grayImg, grayImg, Size(3, 3), 1);

    threshold(grayImg, otsuThresholdImg, 0, 255, THRESH_OTSU);

    structuringElement = getStructuringElement(MORPH_RECT, Size(1, 3), Point(-1, -1));

    imshow("Otsu's threshold image", otsuThresholdImg);

    for (int i = 0; i < 5; ++i) {
        erode(otsuThresholdImg, otsuThresholdImg, structuringElement, Point(-1, -1), i);
        imshow("eroded image with vertical structuring element", otsuThresholdImg);
    }

    waitKey(0);
    return 0;
}
