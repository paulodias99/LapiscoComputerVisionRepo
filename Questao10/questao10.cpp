#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <stdio.h>

using namespace std;
using namespace cv;

int main() {
    Mat grayImage, img_limi;
    Mat image = imread("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/ImagemOriginal.jpg", 1);
    imshow("Imagem Original", image);

    cvtColor(image, grayImage, COLOR_RGB2GRAY);
    imshow("Imagem Cinza", grayImage);

    /* criando limiarizazção e escrevendo no arquivo
       O primeiro argumento é a imagem de origem, que deve ser uma imagem em tons de cinza. (grayImage)
       O segundo argumento é a imagem que irá receber as mudanças.
       O terceiro argumento é o valor limite que é usado para classificar os valores de pixel.
       O quarto argumento é o valor máximo atribuído a valores de pixel que excedem o limite.
    */
    threshold(/* 1°arg */grayImage, /* 2°arg */img_limi, /* 3°arg */120, /* 4°arg */220, CV_THRESH_BINARY);
    FILE* txtDocument = fopen("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/Results/q10_image.txt", "w");
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            image.at<uchar>(i, j) > 120 ? image.at<uchar>(i, j) = 220 : image.at<uchar>(i, j) = 0;
            fprintf(txtDocument, "%d ", image.at<uchar>(i, j));
        }
        fprintf(txtDocument, "\n");
    }
    fclose(txtDocument);

    imshow("Imagem após limiariazação", img_limi);

    waitKey(0);
}