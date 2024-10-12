#include "showAll.h"


void showAll(cv::Mat& mainImg, cv::Mat& ownImg, cv::Mat& foreignImg, cv::Mat& corr1, cv::Mat& corr2) 
{
	cv::Mat copyMainImg = mainImg.clone();

	cv::namedWindow("correlation_1", cv::WINDOW_NORMAL);
	cv::resizeWindow("correlation_1", 600, 600);
	cv::imshow("correlation_1", corr1); 

	cv::namedWindow("correlation_2", cv::WINDOW_NORMAL);
	cv::resizeWindow("correlation_2", 600, 600);
	cv::imshow("correlation_2", corr2);


	// Находим положение с максимальной корреляцией
	double minVal1, maxVal1;
	cv::Point minLoc1, maxLoc1;
	minMaxLoc(corr1, &minVal1, &maxVal1, &minLoc1, &maxLoc1);

	// Рисуем прямоугольник в области лучшего совпадения
	rectangle(mainImg, maxLoc1,
	cv::Point(maxLoc1.x + ownImg.cols, maxLoc1.y + ownImg.rows),
	cv::Scalar(0, 255, 0), 2);


	// Находим положение с максимальной корреляцией
	double minVal2, maxVal2;
	cv::Point minLoc2, maxLoc2;
	minMaxLoc(corr2, &minVal2, &maxVal2, &minLoc2, &maxLoc2);  

	// Рисуем прямоугольник в области лучшего совпадения
	rectangle(copyMainImg, maxLoc2,  
	cv::Point(maxLoc2.x + foreignImg.cols, maxLoc2.y + foreignImg.rows),   
	cv::Scalar(0, 255, 0), 2); 

	cv::imshow("own_11", ownImg);
	cv::imshow("foreign_11", foreignImg);

	cv::namedWindow("result_1", cv::WINDOW_NORMAL);
	cv::resizeWindow("result_1", 600, 600);
	cv::imshow("result_1", mainImg); 

	cv::namedWindow("result_2", cv::WINDOW_NORMAL);
	cv::resizeWindow("result_2", 600, 600);
	cv::imshow("result_2", copyMainImg); 
}