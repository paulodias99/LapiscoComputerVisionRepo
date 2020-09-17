#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/imgproc/imgproc_c.h>
#include <cmath>

using namespace std;
using namespace cv;


int main() {
    Mat gray, canny;
    Mat image = imread("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/ImagemOriginal.jpg", 1);
    imshow("Imagem", image);

    cvtColor(image, gray, COLOR_RGB2GRAY);
    imshow("Imagem Cinza", gray);

    Canny(gray, canny, 170, 200, 3);
    imshow("Imagem Canny", canny);
    waitKey();
}