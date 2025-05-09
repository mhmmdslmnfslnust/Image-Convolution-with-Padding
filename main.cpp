#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "matrix_ops.h"
#include "convolution.h"

using namespace std;

// Configuration constants
const int MIN_SIZE = 3;
const int MAX_SIZE = 12;

int main() {
    srand(time(0));

    // Get image size from user with validation
    int imageSize;
    do {
        cout << "Enter image size (" << MIN_SIZE << "-" << MAX_SIZE << "): ";
        cin >> imageSize;
    } while (imageSize < MIN_SIZE || imageSize > MAX_SIZE);

    // Create and initialize matrices
    ImageMatrix* originalImage = createImageMatrix(imageSize);
    ImageMatrix* paddedImage = createImageMatrix(imageSize + 2);
    ImageMatrix* resultImage = createImageMatrix(imageSize);
    
    // Generate random image
    generateRandomImage(originalImage);
    displayMatrix(originalImage, "Original Image");

    // Select and display kernel
    KernelMatrix* kernel = selectKernel();
    
    // Apply padding and perform convolution
    applyPadding(paddedImage, originalImage);
    performConvolution(resultImage, paddedImage, kernel);
    
    // Display result
    displayMatrix(resultImage, "Convolution Result");

    // Cleanup
    deleteImageMatrix(originalImage);
    deleteImageMatrix(paddedImage);
    deleteImageMatrix(resultImage);
    delete kernel;

    return 0;
}
