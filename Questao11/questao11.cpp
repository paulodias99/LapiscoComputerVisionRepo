#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <stdio.h>

using namespace std;
using namespace cv;

int main() {
    Mat grayImage, img_limi;
    Mat image = imread("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/ImagemT11.jpg", 1);
    imshow("Imagem Original", image);

    cvtColor(image, grayImage, COLOR_RGB2GRAY);
    imshow("Imagem Cinza", grayImage);

    Mat_<Vec3b> imageWithCenterDot(grayImage.rows, grayImage.cols, CV_8UC3);

    for (int i = 0; i < grayImage.rows; ++i) {
        for (int j = 0; j < grayImage.cols; ++j) {
            if ((i == grayImage.rows / 2) && (j == grayImage.cols / 2)) {
                imageWithCenterDot(i, j)[0] = 255;
                imageWithCenterDot(i, j)[1] = 255;
                imageWithCenterDot(i, j)[2] = 255;
            }
            else {
                imageWithCenterDot(i, j)[0] = grayImage.at<uchar>(i, j);
                imageWithCenterDot(i, j)[1] = grayImage.at<uchar>(i, j);
                imageWithCenterDot(i, j)[2] = grayImage.at<uchar>(i, j);
            }
        }
    }

    imwrite("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/Results/ImagemTopicio11.jpg", imageWithCenterDot);
    imshow("Imagem Gerada", imageWithCenterDot);
    waitKey(0);
}