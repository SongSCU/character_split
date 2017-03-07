/**************************************************************************
File:         character_split.h
Author:       Song Xiaofeng
Date:         2016-12-08
**************************************************************************/

#include "character_split.h"

#define AREA_THRESHOLD 200

void spt::CharacterSplit(const cv::Mat& bin, const cv::Mat& src) {

	vector<vector<Point> > contours; //��ż�⵽������
	vector<Vec4i> hierarchy; //���ͼ���������Ϣ
	  
	//Ѱ��ͼ��������������⵽����������contours�����������Ϣ����hierarchy
	findContours(bin, contours, hierarchy, RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

	//��ԭͼ���л��������� �������contoursImg
	Mat dst = src.clone();
	vector<Mat> vecResult;
	for (int i = 0; i < contours.size(); ++i)
	{
		Rect rect = boundingRect(Mat(contours[i]));
		if (rect.width * rect.height < AREA_THRESHOLD) {
			continue;
		}
		rectangle(dst, rect.tl(), rect.br(), Scalar(255, 0, 0));
		Mat tmp = src(rect);
		vecResult.push_back(tmp);
	}
	imshow("contoursImg", dst);

	//���ָ�������ַ�ͼ��淶��24*32�Ĵ�С,��д��ͼ��
	int i = 0;
	for (vector<Mat>::iterator it = vecResult.begin(); it != vecResult.end(); ++it, ++i) {
		resize(*it, *it, Size(24, 32));
		char buf[4];
		itoa(i, buf, 10);
		string path = string("images/10/") + buf + ".jpg";
		imwrite(path, *it);
	}
}