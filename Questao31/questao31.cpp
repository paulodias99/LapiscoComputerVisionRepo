#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <stdio.h>

using namespace std;
using namespace cv;

Mat imagem, gray;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);
int cont = 0;


int main()
{
	imagem = imread("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/variosobjetos.jpg", 1);

	cvtColor(imagem, gray, COLOR_BGR2GRAY);

	blur(gray, gray, Size(3, 3));

	imshow("IMAGEM ORIGINAL", imagem);

	Mat canny_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	Canny(gray, canny_output, thresh, thresh * 2, 3);

	findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
	/*     ANALISAR
		1- Imagem que saiu do canny
		2- Detectas os contornos (vao ser tratados como um vetor de pontos)
		3- Disposicao dos contornos
		4- Modo
		5- Metodo  */


		/* Observe que os contornos, linhas... sao tratados como um vetor de pontos */

	vector<vector<Point> > contours_poly(contours.size());
	vector<Rect> boundRect(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
		boundRect[i] = boundingRect(Mat(contours_poly[i]));
	}

	/* Observação, esses retangulos são os menores possiveis que podem ser feitos na imagem */


	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		{
			Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));  //A cor dos contornos
			drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point()); //Funcao pra desenhar contornos
			rectangle(drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0); //	Funcao pra desenhar o retangulo
		}
	}

	imshow("Contours", drawing);

	waitKey(0);
	return(0);
}