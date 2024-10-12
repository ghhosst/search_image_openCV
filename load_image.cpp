#include "load_image.h"

using std::string;

void load_image(cv::Mat& mainImg, cv::Mat& ownImg, cv::Mat& foreignImg)
{
	// ���� � ������������
	string pathMainImg = "C:/forStudy/labsAPDD/lab1/main11.jpg";
	string pathOwnImg = "C:/forStudy/labsAPDD/lab1/own_11_11.jpg";
	string pathForeignImg = "C:/forStudy/labsAPDD/lab1/foreign_11.jpg";

	// ��������� ����������� �� ��������� �����
	mainImg = cv::imread(pathMainImg);
	ownImg = cv::imread(pathOwnImg);
	foreignImg = cv::imread(pathForeignImg);

	// �������� �� ���������� �����������
	if (mainImg.empty() || ownImg.empty() || foreignImg.empty())
	{
		std::cerr << "������: �� ������� ������� ���� ��� ��������� �����������" << std::endl;
	}
}