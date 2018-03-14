#include<stdio.h>
#include<iostream>
#include<string>
#include<chrono>
#include<thread>

#include<opencv2/core.hpp>
#include<opencv2/videoio.hpp>
#include<opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        printf("usage: VideoCapture <video_path>\n");
        return -1;
    }

    string source = argv[1];
    cout << source << endl;

    VideoCapture video(source);

    double fps = video.get(CV_CAP_PROP_FPS);
    cout << "FPS: " << fps << endl;
    
    if(!video.isOpened())
    {
        cout << "Failed to open video: " << source << endl;
        return -1;
    }

    int frameNum = -1;

    Size videoSize = Size((int) video.get(CAP_PROP_FRAME_WIDTH), (int) video.get(CAP_PROP_FRAME_HEIGHT));

    const char* WINDOW_NAME = "Video";
    namedWindow(WINDOW_NAME, WINDOW_AUTOSIZE);

    int key;
    
    chrono::high_resolution_clock::time_point t1;
    chrono::high_resolution_clock::time_point t2;
    
    Mat frame;
    for(;;)
    {
        t1 = chrono::high_resolution_clock::now();

        video >> frame;

        if(frame.empty())
        {
            printf("Video ended\n");
            break;
        }

        ++frameNum;
        //printf("Frame #%d\n", frameNum);

        imshow(WINDOW_NAME, frame);
        t2 = chrono::high_resolution_clock::now();

        chrono::duration<double, std::milli> time_span = t2 - t1;

        cout << "Elapsed time: " << time_span.count() << endl;
        double delay = 1000;
        waitKey((1000/fps) - time_span.count());
    }

    waitKey(0);

    return 0;
}
