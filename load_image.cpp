#include "load_image.h"

using std::string;

void load_image(cv::Mat& mainImg, cv::Mat& ownImg, cv::Mat& foreignImg)
{
	// пути к изображениям
	string pathMainImg = "C:/forStudy/labsAPDD/lab1/main11.jpg";
	string pathOwnImg = "C:/forStudy/labsAPDD/lab1/own_11_11.jpg";
	string pathForeignImg = "C:/forStudy/labsAPDD/lab1/foreign_11.jpg";

	// считываем изображения по указанным путям
	mainImg = cv::imread(pathMainImg);
	ownImg = cv::imread(pathOwnImg);
	foreignImg = cv::imread(pathForeignImg);

	// проверка на считывание изображений
	if (mainImg.empty() || ownImg.empty() || foreignImg.empty())
	{
		std::cerr << "Ошибка: не удалось открыть одно или несколько изображений" << std::endl;
	}
}