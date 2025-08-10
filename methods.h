/**
 * @file methods.h
 * @brief Declaration of image processing methods for BMP images.
 */

 #ifndef METHODS_H
 #define METHODS_H
 
 #include "bmp.h"
 #include <vector>
 
 /**
  * @class Methods
  * @brief Provides image processing functionalities like rotation and Gaussian filtering.
  */
 class Methods {
 public:
     /**
      * @brief Constructor to load BMP image from file.
      * @param filename Path to the BMP file.
      */
     Methods(const std::string &filename);
 
     /**
      * @brief Destructor to clean up memory.
      */
     ~Methods();
 
     /**
      * @brief Save current image to a BMP file.
      * @param filename Destination file name.
      */
     void Save(const std::string &filename);
 
     /**
      * @brief Rotate the image 90 degrees clockwise.
      */
     void Rotate90();
 
     /**
      * @brief Rotate the image 90 degrees counterclockwise.
      */
     void RotateCounter90();
 
     /**
      * @brief Apply Gaussian blur filter to the image.
      * @param kernelSize Size of the kernel (must be odd).
      * @param kernel 2D vector representing Gaussian kernel.
      */
     void GaussianFilter(int kernelSize, const std::vector<std::vector<float>> &kernel);
 
 private:
     BMPHeader header;
     BMPInfoHeader infoHeader;
     std::vector<std::vector<Pixel>> data;
 
     /**
      * @brief Allocate memory for image data.
      * @param height Height of the image.
      * @param width Width of the image.
      * @return True if memory was allocated successfully.
      */
     bool allocateMemory(int height, int width);
 };
 
 #endif // METHODS_H
 