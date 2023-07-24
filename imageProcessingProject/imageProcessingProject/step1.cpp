#include "step1.h"
#include"opencv2/opencv.hpp"
using namespace std;
using namespace cv;
#include <vector>

#ifdef _DEBUG
// the debug version that corresponds to the opencv_world420d.dll:
#pragma comment(lib, "opencv_world480d.lib")
#else
// the release version that corresponds to the opencv_world420.dll:
#pragma comment(lib, "opencv_world480.lib")
#endif


void averageOfChannels(const cv::Mat& img, float* avgB, float* avgG, float* avgR)
{
    vector<Mat> channels;
    split(img, channels);
    *avgB = 0;
    *avgG = 0;
    *avgR = 0;
    for (int j = 0; j < img.rows; j++)
    {
        auto rowB = channels[0].ptr<uchar>(j);
        auto rowG = channels[1].ptr<uchar>(j);
        auto rowR = channels[2].ptr<uchar>(j);
        for (int k = 0; k < img.cols; k++)
        {
            *avgB += rowB[k];
            *avgG += rowG[k];
            *avgR += rowR[k];
        }
    }
    *avgB = *avgB / (img.cols * img.rows);
    *avgG = *avgG / (img.cols * img.rows);
    *avgR = *avgR / (img.cols * img.rows);
}


