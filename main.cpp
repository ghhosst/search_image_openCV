#include <opencv2/opencv.hpp>
#include "correlation.h"
#include "load_image.h"
#include "showAll.h"

using std::string;

int main()
{
	setlocale(LC_ALL, "ru");

	cv::Mat mainImg, ownImg, foreignImg;
	load_image(mainImg, ownImg, foreignImg); // ��������� ��� �����������

	// ��������� ����������
	cv::Mat correlation1 = computeCorrelation(mainImg, ownImg); 
	cv::Mat correlation2 = computeCorrelation(mainImg, foreignImg); 

	// ������� ��� ����������
	showAll(mainImg, ownImg, foreignImg, correlation1, correlation2);

	cv::waitKey(0);

	return 0;
}