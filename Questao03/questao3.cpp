#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <cmath>

using namespace std;
using namespace cv;

int main()
{
    /* ler imagem colorida e visualizar */
    Mat img = cv::imread("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/ImagemOriginal.jpg", 1);
    imshow("Original Image", img);

    Mat channel[3];
    split(img, channel);

    /* salvar imagem no canal 1 */
    namedWindow("Channel Red", 1);
    imshow("Channel Red", channel[0]);
    imwrite("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/Results/Channel_Red.jpg", channel[0]);

    /* salvar imagem no canal 2 */
    namedWindow("Channel Green", 1);
    imshow("Channel Green", channel[1]);
    imwrite("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/Results/Channel_Green.jpg", channel[1]);

    /* salvar imagem no canal 3 */
    namedWindow("Channel Blue", 1);
    imshow("Channel Blue", channel[2]);
    imwrite("C:/Users/User/Desktop/GIT/LapiscoComputerVisionRepo/images/Results/Channel_Blue.jpg", channel[2]);

    waitKey(0);
}