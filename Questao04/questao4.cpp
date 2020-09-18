#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <cmath>

using namespace std;
using namespace cv;

int main()
{
    Mat img_rgb, img_hsv;
    img_rgb = cv::imread("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/ImagemOriginal.jpg", 1);
    imshow("Image RGB", img_rgb);

    cvtColor(img_rgb, img_hsv, COLOR_RGB2HSV);
    imshow("Image HSV", img_hsv);
    imwrite("/Users/wellcome/Dropbox/WELL_LAB/OpenCvLista/Results/Image_HSV.jpg", img_hsv);

    Mat channel[3];
    split(img_hsv, channel);

    imshow("Channel H", channel[0]);
    imwrite("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/Results/Channel_H(Tonalidade).jpg", channel[0]);
    imshow("Channel S", channel[1]);
    imwrite("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/Results/Channel_S(Saturação).jpg", channel[1]);
    imshow("Channel V", channel[2]);
    imwrite("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/Results/Channel_V(Brilho).jpg", channel[2]);

    waitKey(0);
}