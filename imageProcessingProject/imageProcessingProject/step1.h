#include "opencv2/opencv.hpp"
#pragma once
class step1
{
public:
	/*INPUT: the function get image and pointers to results*/
	/*OUTPUT: the function return through the pointers the avarage of each of channels of the imag*/
	friend void averageOfChannels(const cv::Mat& img, float* avgB, float* avgG, float* avgR);
};

