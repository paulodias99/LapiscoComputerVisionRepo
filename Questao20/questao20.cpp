#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <stdio.h>

using namespace std;
using namespace cv;

Mat getRegionGrowing(Mat image, Mat regionGrowing) {
    int current = 0;
    int previous = 0;
    do {
        previous = current;
        current = 0;
        for (int i = 0; i < regionGrowing.rows; i++) {
            for (int j = 0; j < regionGrowing.cols; j++) {
                if (regionGrowing.at<uchar>(i, j) == 255) {
                    for (int x = i - 1; x < i + 2; x++) {
                        for (int y = j - 1; y < j + 2; y++) {
                            if (image.at<uchar>(x, y) < 127) {
                                regionGrowing.at<uchar>(x, y) = 255;
                                current++;
                            }
                        }
                    }
                }
            }
        }
    } while (current != previous);

    return regionGrowing;
}

Mat getCentralRegionGrowing(Mat image) {
    Mat regionGrowing(image.rows, image.cols, CV_8UC3);

    cvtColor(regionGrowing, regionGrowing, CV_RGB2GRAY);

    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++) {
            if ((i == image.rows / 2) && (j == image.cols / 2)) {
                regionGrowing.at<uchar>(i, j) = 255;
            }
            else {
                regionGrowing.at<uchar>(i, j) = 0;
            }
        }
    }

    regionGrowing = getRegionGrowing(image, regionGrowing);

    return regionGrowing;
}

int main() {
    Mat img, grayImage, centralRegionGrowing;

    img = imread("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/imagem2.jpg");

    cvtColor(img, grayImage, COLOR_RGB2GRAY);

    centralRegionGrowing = getCentralRegionGrowing(grayImage);

    imshow("Imagem Original", img);
    imshow("Imagem Gerada", centralRegionGrowing);

    waitKey(0);
    return 0;
}