#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/imgproc/imgproc_c.h>
#include <cmath>

using namespace std;
using namespace cv;


int main()
{
    Mat image_rgb, image_gray, image_median, image_blur;

    image_rgb = imread("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/ImagemOriginal.jpg", 1);
    imshow("Image RGB", image_rgb);

    cvtColor(image_rgb, image_gray, COLOR_RGB2GRAY);
    imshow("Image Gray", image_gray);

    medianBlur(image_gray, image_median, CV_MEDIAN);
    imshow("Image Median", image_median);
    imwrite("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/ImagemBaixaMediana.jpg", image_median);

    blur(image_gray, image_blur, Size(3, 3), Point(-1, -1));
    imshow("Image Blur", image_blur);
    imwrite("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/ImagemBlur.jpg", image_blur);

    waitKey(0);

}