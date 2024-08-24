#include "c_img.h"
#include "c_img.c"
#include "seamcarving.h"
#include <stdio.h>
#include <math.h>

int main()
{
    struct rgb_img *grad;
    struct rgb_img *im;
    read_in_img(&im, "6x5.bin");
    calc_energy(im, &grad);

    print_grad(grad);
    return 0;
}