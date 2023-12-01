#include <opencv2\core.hpp>
#include <opencv2\imgcodecs.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    // Paths to the input and output images
    string image_path1 = "Image.png";
    string image_path2 = "Image.png";

    // Read the input images
    Mat image1 = imread(image_path1, IMREAD_COLOR);
    Mat image2 = imread(image_path2, IMREAD_COLOR);

    // Check if images were successfully loaded
    if (image1.empty() || image2.empty())
    {
        cout << "Could not read the image" << endl;
        return 1;
    }

    // Rotate the second image 90 degrees counterclockwise
    rotate(image2, image2, ROTATE_90_COUNTERCLOCKWISE);

    // Resize the second image to 500x500
    resize(image2, image2, Size(500, 500));

    // Convert the second image to grayscale
    for (int i = 0; i < image2.rows; i++)
    {
        for (int j = 0; j < image2.cols; j++)
        {
            // Get the BGR values of each pixel in the second image
            Vec3b bgrPixel = image2.at<Vec3b>(i, j);

            // Calculate the grayscale value using the average of the BGR values
            unsigned char grayScale = (bgrPixel[2] + bgrPixel[1] + bgrPixel[0]) / 3;

            // Set the grayscale value to all channels of the pixel
            image2.at<Vec3b>(i, j) = { grayScale, grayScale, grayScale };

            // Not used: creating a Vec3b variable for the grayscale pixel but not using it
            Vec3b grayPixel = image2.at<Vec3b>(i, j);
        }
    }

    // Display the original and processed images
    imshow("First", image1);
    imshow("Second", image2);

    // Wait for a key press
    int k = waitKey(0);

    // Save the grayscale image if 's' key is pressed
    if (k == 's')
    {
        imwrite("New Image.png", image2);
    }

    return 0;
}
