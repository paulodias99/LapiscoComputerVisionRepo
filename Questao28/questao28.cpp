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
	   imagem de saída
	   valor diferente de zero atribuída aos pixels para que a condição é satisfeita
	   algoritmo de limiar adaptativo de usar
	   tipo: observação bem interessante
	   tamanho para vizinhança para o calculo do pixel
	   constante subtraida da media e da media ponderada */

	imshow("IMAGEM COM LIMIARIZAÇÃO AUTOMATICA", imagem);

	waitKey(0);

	return 0;
}