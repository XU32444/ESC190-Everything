#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "c_img.h"
#include "seamcarving.h"
#include "seamcarving.c"
#include "c_img.c"

int main()
{
    struct rgb_img *im;
    struct rgb_img *cur_im;
    struct rgb_img *grad;
    double *best;
    int *path;

    read_in_img(&im, "3x4.bin");
    calc_energy(im, &grad);
    print_grad(grad);

    // for (int i = 0; i < 5; i++)
    // {
    //     printf("i = %d\n", i);
    //     calc_energy(im, &grad);
    //     print_grad(grad);
    // dynamic_seam(grad, &best);
    // recover_path(best, grad->height, grad->width, &path);
    // remove_seam(im, &cur_im, path);

    // char filename[200];
    // sprintf(filename, "img%d.bin", i);
    // write_img(cur_im, filename);

    // destroy_image(im);
    // destroy_image(grad);
    // free(best);
    // free(path);
    // im = cur_im;
    // }
    // destroy_image(im);

    return 0;
}