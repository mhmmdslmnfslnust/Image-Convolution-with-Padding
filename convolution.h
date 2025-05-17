#ifndef CONVOLUTION_H
#define CONVOLUTION_H
// Kernel types
enum KernelType {
    VERTICAL_EDGE_DETECTION = 1,
    HORIZONTAL_EDGE_DETECTION = 2,
    SHARPEN = 3,
    BLUR = 4
};

// Function to select a kernel type
int selectKernelType();

// Function to initialize a kernel based on type
void initializeKernel(int kernel[3][3], int kernelType);

// Functions for convolution operations
void applyPadding(int** paddedMatrix, int paddedSize, int** originalMatrix, int originalSize);
void performConvolution(int** result, int resultSize, int** paddedMatrix, int paddedSize, int kernel[3][3]);
void displayKernel(int kernel[3][3]);

#endif // CONVOLUTION_H
