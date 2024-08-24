#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "c_img.h"
#include "seamcarving.h"
#include "seamcarving.c"
#include "c_img.c"
// Function to print a 2D array of doubles
void print2DArray(double *arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // Printing each element with fixed width; adjust the width as needed
            printf("%8.2f ", *(arr + i * cols + j));
        }
        printf("\n");
    }
}

void printNumbers(int *array, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%d\n", array[i]);
    }
}

int main()
{
    struct rgb_img *im;
    struct rgb_img *cur_im;
    struct rgb_img *grad;
    double *best;
    int *path;

    // read_in_img(&im, "6x5.bin");
    read_in_img(&im, "image.bin");
    // read_in_img(&im, "jack.bin");
    // read_in_img(&im, "test_im1.bin");

    for (int i = 0; i < 260; i++)
    {
        printf("i = %d\n", i);
        calc_energy(im, &grad);
        dynamic_seam(grad, &best);
        recover_path(best, grad->height, grad->width, &path);
        remove_seam(im, &cur_im, path);

        if (i == 149)
        {
            char filename[200];
            sprintf(filename, "img%d.bin", i);
            write_img(cur_im, filename);
        }

        for (int i = 1; i < grad->height * grad->width + 1; i++)
        {
            // printf("%d\n", 11);
            // printf("%f ", best[i-1]);
            if (i % (grad->width) == 0)
            {
                // printf("\n");
            }
        }
        // printf("\n");

        if (i < 10)
        {
            for (int i = 0; i < grad->height; i++)
            {
                // printf("%d ", path[i]);
            }
        }

        // printf("\n");

        destroy_image(im);
        destroy_image(grad);
        free(best);
        free(path);
        im = cur_im;
    }
    destroy_image(im);
}