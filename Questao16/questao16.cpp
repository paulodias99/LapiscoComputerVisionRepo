#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <stdio.h>

using namespace std;
using namespace cv;

Mat img; //Imagem de entrada
Mat gray; //Imagem em tons de cinza
Mat equalized; //Imagem equalizada
Mat hist_gray;
Mat hist_equalized;

Mat histograma(Mat& imagem)
{

    // Definir as barras do histograma
    int bins = 256; //Quantidade de barras
    int histSize[] = { bins }; //Tamanho do histograma

    // O intervalo do histograma
    float lranges[] = { 0, 256 };
    const float* ranges[] = { lranges };

    Mat hist;
    int channels[] = { 0 }; //Numeros de canais, como a imagem de entrada й sу de um canal, vem 0

    int const hist_height = 256;
    Mat3b hist_image = Mat3b::zeros(hist_height, bins);

    calcHist(&imagem, 1, channels, Mat(), hist, 1, histSize, ranges, true, false); //Funзгo para criar o histograma

    double max_val = 0;
    minMaxLoc(hist, 0, &max_val);

    // Visualizar cada barra
    for (int b = 0; b < bins; b++)
    {
        float const binVal = hist.at<float>(b);
        int   const height = cvRound(binVal * hist_height / max_val);
        line(hist_image, Point(b, hist_height - height), Point(b, hist_height), Scalar::all(255));
        //    imagem      ponto inicial                 ponto final            
    }
    return hist_image;
}

int main()
{

    //Imagem de entrada
    img = imread("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/ImagemOriginal.jpg");
    imshow("Imagem Original", img);
    //Converter pra cinza
    cvtColor(img, gray, CV_RGB2GRAY);

    //Funзгo para equalizar
    equalizeHist(gray, equalized);

    imshow("Imagem Cinza", gray);
    Mat hist_gray = histograma(gray);
    imshow("name1", hist_gray);

    Mat hist_equalized = histograma(equalized);
    imshow("name2", hist_equalized);

    imshow("Equalized Image", equalized);
    
    imwrite("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/ImagemOriginal.jpg/Results/imagementrada.jpg", gray);

    imwrite("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/ImagemOriginal.jpg/Results/Histogramaentrada.jpg", hist_gray);

    imwrite("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/ImagemOriginal.jpg/Results/imagemsaida.jpg", equalized);

    imwrite("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/ImagemOriginal.jpg/Results/histrogramasaida.jpg", hist_equalized);

    waitKey(0);
    return 0;
}