#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

using namespace cv;
using namespace cv;

int main(int argc, char** argv) {

    // Define constants describing video metadata
    Size resolution(1920, 1080);
    char fname[] = "Output.mp4";
    int fps = 24;

    // Create a new capture object
    VideoCapture cam(0);

    // Checks if the capture object is a connected device camera
    if (cam.isOpened()){
        
        std::cout << "Cam opened successfully";

        // Loop control and counting frames
        int run = 1;
        int f = 0;

        // Write object for creating the output video
        VideoWriter vid(fname, cv::VideoWriter::fourcc('H','2','6','4'), fps, resolution);

        while (run){

            // Get the last key pressed, cast to a single char
            char key = (char)waitKey(1);

            // Capture the current frame
            Mat frame;
            cam >> frame;
            
            // If the frames not empty and the user hasn't pressed escape
            if (!frame.empty() && key != 27){

                // Write the frame to the output file
                vid.write(frame);
                
                // Increment the frame counter, display on screen
                f++;                
                imshow("Live Feed", frame);
            }
            else{
                run = 0;
            }

        }

        // Release the writer object
        vid.release();
    }

    else {
        std::cout << "Error - Cam could not be opened";
    }

    // Release the capture object
    cam.release();

    return 0;
}
