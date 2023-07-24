#include "pch.h"
//#include "opencv2/opencv.hpp"
#include "../imageProcessingProject/step1.h"
using namespace cv;
using namespace std;

TEST(TestCaseName, TestName) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

TEST(averageOfChannelsTest, theTruesAvgTest) {
    uint8_t data[] = { 2,3,1,2,2,2,3,3,3,2,
                        4,4,4,5,5,5,6,6,6,
                        7,7,7,8,8,8,9,9,9 };
    Mat* img = new Mat(3, 3, CV_8UC3, data);
    float* avgB = new float(0);
    float* avgG = new float(0);
    float* avgR = new float(0);
    float realAvgB, realAvgG, realAvgR;
    realAvgB = 46 / 9.0;
    realAvgG = 47 / 9.0;
    realAvgR = 5;
    averageOfChannels(*img, avgB, avgG, avgR);
    averageOfChannels(*img, avgB, avgG, avgR);
    ASSERT_TRUE(*avgB == realAvgB);
    ASSERT_TRUE(*avgG == realAvgG);
    ASSERT_TRUE(*avgR == realAvgR);
}