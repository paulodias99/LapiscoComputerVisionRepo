#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/imgproc/imgproc_c.h>
#include <cmath>

using namespace std;
using namespace cv;


int main() {
    Mat image, image_gray, redimens1, redimens2;
    image = imread("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/Imagem320x240.jpg", 1);
    imshow("Imagem Original de Entrada", image);

    cvtColor(image, image_gray, COLOR_RGB2GRAY);
    imshow("Imagem Cinza", image_gray);

    /* Redimensionando */
    resize(image, redimens1, Size(160, 120));
    imshow("Redimensionada 160x120", redimens1);
    imwrite("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/Results/Redimensionada160x120.jpg", redimens1);

    resize(image, redimens2, Size(640, 480));
    imshow("Redimensionada 640x480", redimens1);
    imwrite("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/Results/Redimensionada640x480.jpg", redimens2);

    waitKey();
}