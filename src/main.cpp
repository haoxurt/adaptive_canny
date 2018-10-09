#include <stdio.h>
#include <fstream>
#include "CannyPF.h"
#include "ChainFromEdgeMap.h"

using namespace cv;
using namespace std;

int main(int argc, char* agrv[])
{
	string str = agrv[1];
	cv::Mat img = imread( str, 0 );
  
	// get edge map
	CannyPF cannyer;
	cv::Mat edgeMap;
	float VMGradient = 200;
	cannyer.cannyPF(dst_img, 3, VMGradient, edgeMap);
  

  
  
	// get edge chain
	ChainFromEdgeMap chainer;
	std::vector<std::vector<cv::Point> > edgeChains;
	chainer.run(dst_img, edgeMap, edgeChains );

	// show 
	cv::Mat imgShow( img.rows, img.cols, CV_8UC1, cv::Scalar( 0 ) );
	uchar* ptrS = (uchar*) imgShow.data;
	for ( int i=0; i<edgeChains.size(); ++i )
	{
		for ( int j=0; j<edgeChains[i].size(); ++j )
                {		
			int loc = edgeChains[i][j].y * img.cols + edgeChains[i][j].x;
			ptrS[loc] = 255;
		}
	}
 
  return 0;
}
