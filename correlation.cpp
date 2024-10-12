#include "correlation.h"
#include <iostream>

cv::Mat computeCorrelation(cv::Mat& mainImg, cv::Mat& referenceImg) 
{
	cv::Mat corrField; // коррел€ционное поле (матрица) 

	int64 start = cv::getTickCount(); 
	matchTemplate(mainImg, referenceImg, corrField, cv::TM_CCOEFF_NORMED); // вычисление функции коррел€ции
	int64 end = cv::getTickCount(); 

	double duration = ((end - start) / cv::getTickFrequency()) * 1000; 

	std::cout << "¬рем€ вычислени€ коррел€ционного пол€: "
			  << duration << " мс" << std::endl; 

	//cv::normalize(corrField, corrField, 0, 1, cv::NORM_MINMAX);	// нормализаци€ коррел€ционного пол€

	return corrField; 
}
