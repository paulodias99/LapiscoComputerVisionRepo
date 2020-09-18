#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/imgproc/imgproc_c.h>
#include <cmath>

using namespace std;
using namespace cv;


int main() {
    Mat image, image_gray, image_limi;
    image = imread("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/ImagemOriginal.jpg", 1);
    imshow("Imagem Original de Entrada", image);

    cvtColor(image, image_gray, COLOR_RGB2GRAY);
    imshow("Imagem Cinza", image_gray);

    threshold(image_gray, image_limi, 100, 200, CV_THRESH_BINARY);
    imshow("Imagem Thresholded", image_limi);
    imwrite("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/Results/Image_Thresholded.jpg", image_limi);

    waitKey();
}