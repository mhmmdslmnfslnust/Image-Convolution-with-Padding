#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include "matrix_ops.h"

// Convolution operation functions
void applyPadding(ImageMatrix* paddedMatrix, const ImageMatrix* originalMatrix);
void performConvolution(ImageMatrix* result, const ImageMatrix* paddedMatrix, const KernelMatrix* kernel);
KernelMatrix* selectKernel();

#endif
