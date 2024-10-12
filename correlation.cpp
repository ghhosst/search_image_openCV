#include "correlation.h"
#include <iostream>

cv::Mat computeCorrelation(cv::Mat& mainImg, cv::Mat& referenceImg) 
{
	cv::Mat corrField; // �������������� ���� (�������) 

	int64 start = cv::getTickCount(); 
	matchTemplate(mainImg, referenceImg, corrField, cv::TM_CCOEFF_NORMED); // ���������� ������� ����������
	int64 end = cv::getTickCount(); 

	double duration = ((end - start) / cv::getTickFrequency()) * 1000; 

	std::cout << "����� ���������� ��������������� ����: "
			  << duration << " ��" << std::endl; 

	//cv::normalize(corrField, corrField, 0, 1, cv::NORM_MINMAX);	// ������������ ��������������� ����

	return corrField; 
}
