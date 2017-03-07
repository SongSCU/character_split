/**************************************************************************
File:         main.h
Author:       Song Xiaofeng
Date:         2016-12-07
**************************************************************************/
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "character_split.h"
#include "preprocess.h"

using namespace cv;
using namespace std;

bool bRotationCorrection = false;
bool bMaftSr = false;

int main(int argc, char** argv) {

	if ((argc % 2) != 1) {
		cerr << "param error!" << endl;
		exit(0);
	}
	string src = "";
	string dst = "";

	for (int i = 1; i < argc; i += 2) {
		char * s1 = argv[i];
		char * s2 = argv[i + 1];
		if (0 == strcmp(s1, "-s")) {
			src = s2;
		}
		else if (0 == strcmp(s1, "-d")) {
			dst = s2;
		}
		else if (0 == strcmp(s1, "-r")) {
			bRotationCorrection = (bool)atoi(s2);
		}
		else if (0 == strcmp(s1, "-f")) {
			bMaftSr = (bool)atoi(s2);
		}
	}

	//��ȡԴͼ��
	Mat imgSrc = imread("src", 1);
	imshow("sourceImg", imgSrc);

	//��ԭͼ�����Ԥ�����õ������ĻҶ�ͼ��
	Mat imgGray;
	cvtColor(imgSrc, imgGray, CV_RGB2GRAY);
	imshow("grayImg", imgGray);

	if (bRotationCorrection) {
		//��ת�ı�У��
		pre::RotationTextCorrection(imgGray, imgGray);
		imshow("rotateImg", imgGray);
	}

	if (bMaftSr) {
		//��������Ҷ�任
		pre::MaftSrMethod(imgGray, imgGray);
		imshow("grayImg1", imgGray);
	}

	////����ֱ��ͼ���⻯
	//equalizeHist(imgGray, imgGray);
	//imshow("grayImg2", imgGray);

	////�����
	//Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	////������̬ѧ����
	//morphologyEx(imgGray, imgGray, MORPH_OPEN, element);
	//imshow("grayImg3", imgGray);

	//���Ҷ�ͼ���ֵ��
	Mat imgBin;
	threshold(imgGray, imgBin, 50, 255, CV_THRESH_BINARY_INV);
	imshow("binImg", imgBin);

	//�ַ��ָ�
	spt::CharacterSplit(imgBin, imgSrc);

	waitKey(0);
	return 0;
}

