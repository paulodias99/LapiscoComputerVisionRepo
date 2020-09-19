#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <stdio.h>

using namespace std;
using namespace cv;

int main() {
	Mat gray, frame, filter;
	VideoCapture cap(0); //Abrir a camera

	if (!cap.isOpened()) //Proteção para abertura da camera
		return 0;

	while (1)
	{

		cap >> frame; //Capturar a imagem 

		cvtColor(frame, gray, CV_RGB2GRAY); //Converter a imagem para tons de cinza
		Canny(gray, filter, 120, 100, 3);
		imshow("Video", filter); //Mostrar a imagem

		if (waitKey(30) >= 0) //Dúvida
			break;
	}

	return 0;
}