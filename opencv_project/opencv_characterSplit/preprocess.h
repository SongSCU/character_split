/**************************************************************************
File:         preprocess.h
Author:       Song Xiaofeng
Date:         2016-12-07
**************************************************************************/

#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

namespace pre {
	//Ԥ����
	void PreProcess(const cv::Mat& src, cv::Mat& dst);
	//��������Ҷ�任-�����׷���
	void MaftSrMethod(const cv::Mat& src, cv::Mat& dst);
	//���ڸ���Ҷ�任����ת�ı�У��
	void RotationTextCorrection(const cv::Mat& src, cv::Mat& dst);
}
