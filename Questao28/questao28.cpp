#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <stdio.h>

using namespace std;
using namespace cv;

int main()
{
	Mat color = imread("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/ImagemOriginal.jpg");
	Mat gray;
	Mat imagem;

	cvtColor(color, gray, COLOR_RGB2GRAY);

	//adaptiveThreshold ( imagem , imagem , 255 , ADAPTIVE_THRESH_GAUSSIAN_C , CV_THRESH_BINARY , 15 , - 5 );

	adaptiveThreshold(gray, imagem, 255, ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY_INV, 7, -5);
	/* imagem de entrada
	   imagem de sa�da
	   valor diferente de zero atribu�da aos pixels para que a condi��o � satisfeita
	   algoritmo de limiar adaptativo de usar
	   tipo: observa��o bem interessante
	   tamanho para vizinhan�a para o calculo do pixel
	   constante subtraida da media e da media ponderada */

	imshow("IMAGEM COM LIMIARIZA��O AUTOMATICA", imagem);

	waitKey(0);

	return 0;
}