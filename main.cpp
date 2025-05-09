#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Function prototypes
void input(int image[6][6]);
void kernel(int kernell[3][3]);
void padding(int padd[8][8]);
void padded(int padd[8][8], int paddedd[8][8], int image[6][6]);
void convolution(int result[6][6], int paddedd[8][8], int kernell[3][3]);

int main()
{
    // Seed the random number generator
    srand(time(0));

    int image[6][6]; // Assuming a 6x6 image for simplicity
    int padd[8][8];
    int paddedd[8][8];
    int kernell[3][3];

    // Call the input function
    input(image);
    cout<<endl;
    // Call the kernel function
    kernel(kernell);
    cout<<endl;
    // Call the padding function
    padding(padd);

    // Call the padded function
    padded(padd, paddedd, image);

    // Perform convolution
    int result[6][6];
    convolution(result, paddedd, kernell);

    // Display the result of convolution
    
    cout << "Convolution Result:" << endl;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout <<setw(5)<< result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

void input(int image[6][6])
{   cout<<"The original image matrix is:"<<endl;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            // Generate random values between 0 and 255 for grayscale image
            image[i][j] = rand() % 256;
            cout << setw(5)<< image[i][j];
        }cout << endl;
    }
}

void kernel(int kernell[3][3])
{
    // Assigning values to the kernel directly
    int values[3][3] = {
        {-1, 0, 1},
        {-1, 0, 1},
        {-1, 0, 1}
    };

    // Copying values to the kernell array
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            kernell[i][j] = values[i][j];
        }
    }
    cout<<"The kernel matrix is:"<<endl;

    // Accessing elements of the kernel
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << setw(5) << kernell[i][j];
        }cout<<endl;
    }
}

void padding(int padd[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            padd[i][j] = 0;
        }
    }
}

void padded(int padd[8][8], int paddedd[8][8], int image[6][6])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(i==0||i==7||j==0||j==7){
                paddedd[i][j] = padd[i][j]; // Corrected the indices
            }else{
                paddedd[i][j] = padd[i][j] + image[i-1][j-1]; // Corrected the indices
            }
            
        }
    }
}

void convolution(int result[6][6], int paddedd[8][8], int kernell[3][3])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            result[i][j] = 0;
            for (int ki = 0; ki < 3; ki++)
            {
                for (int kj = 0; kj < 3; kj++)
                {
                    result[i][j] += paddedd[i + ki][j + kj] * kernell[ki][kj];
                }
            }
        }
    }
}
