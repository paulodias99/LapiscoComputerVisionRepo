#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <stdio.h>

using namespace std;
using namespace cv;

int main() {
    Mat grayImage;
    Mat image = imread("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/ImagemOriginal.jpg", 1);
    imshow("Imagem Original", image);

    cvtColor(image, grayImage, COLOR_RGB2GRAY);
    imshow("Imagem Cinza", grayImage);

   /* cria o arquivo .txt */
    FILE* txtDocument = fopen("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/Results/image.txt", "wt");
    /*cria as linhas da matriz da imagem*/
    for (int i = 0; i < grayImage.rows; ++i) {

        /* cria as colunas da matriz da iamgem */
        for (int j = 0; j < grayImage.cols; ++j) {
            /* escreve o documento = i linhas j colunas*/
            fprintf(txtDocument, "%d ", grayImage.at<uchar>(i, j));
        }

        fprintf(txtDocument, "\n");
    }
    fclose(txtDocument);

    waitKey(0);
}