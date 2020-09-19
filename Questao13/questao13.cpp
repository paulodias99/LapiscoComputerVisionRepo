#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <stdio.h>

using namespace std;
using namespace cv;

int main() {
    Mat img, gray, grad;

    img = imread("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/ImagemOriginal.jpg", 1);
    imshow("Imagem colorida", img);

    cvtColor(img, gray, COLOR_RGB2GRAY);
    imshow("Imagem Cinza", gray);

    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;

    /// Gradient X
    Sobel(gray, grad_x, CV_16S, 1, 0, 3, 1, 0, BORDER_DEFAULT);
    convertScaleAbs(grad_x, abs_grad_x);

    /// Gradient Y
    Sobel(gray, grad_y, CV_16S, 0, 1, 3, 1, 0, BORDER_DEFAULT);
    convertScaleAbs(grad_y, abs_grad_y);

    addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);

    imshow("Imagem Sobel", grad);
    imwrite("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/Results/ImgemSobel.jpg", grad);

    waitKey(0);
}