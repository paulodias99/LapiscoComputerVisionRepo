#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <stdio.h>

using namespace std;
using namespace cv;

int main() {
    FILE*arquivo;
    arquivo = fopen("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/Results/image.txt", "r");
    char val[5000];
    int  val2, linhas = -1, colunas = -1;
    int x, y;

    //Pegar quantidade de Linhas//
    while (!feof(arquivo)) {
        fgets(val, 5000, arquivo);
        linhas++;
    }
    fclose(arquivo);
    //Pegar quantidade de Colunas//
    arquivo = fopen("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/Results/image.txt", "r");
    while (!feof(arquivo)) {
        fscanf(arquivo, "%d", &val2);
        colunas++;
    }
    colunas = colunas / linhas;
    fclose(arquivo);
    //Pegar do arquivo e criar imagem//
    arquivo = fopen("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/Results/image.txt", "r");
    Mat_<uchar> img(linhas, colunas, 1);
    for (y = 0; y < linhas; y++)
    {
        for (x = 0; x < colunas; x++)
        {
            fscanf(arquivo, "%d", &val2);
            img.at<uchar>(y, x) = val2;
        }
    }
    imshow("Imagem_Lida", img);
    imwrite("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/Results/imageLida.jpg", img);
    fclose(arquivo);

    waitKey(0);
}
