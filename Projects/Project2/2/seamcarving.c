#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "c_img.h"

int energy_calculator(int n[6]) // passing in an arraay of 6 numbers, calcualte the sum of each squared and take sqrt
{
    int ans = 0;
    for (int i = 0; i < 6; i++)
    {
        ans = ans + pow(n[i], 2);
    }
    ans = sqrt(ans);
    ans = ans / 10;
    return ans;
}

double min(double a, double b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void calc_energy(struct rgb_img *im, struct rgb_img **grad)
{
    int height = im->height;
    int width = im->width;
    (*grad) = (struct rgb_img *)malloc(sizeof(struct rgb_img));
    (*grad)->height = height;
    (*grad)->width = width;
    (*grad)->raster = (uint8_t *)malloc(height * width * 3);

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {

            if (h == 0 || w == 0 || h == height - 1 || w == width - 1)
            {
                if (h == 0 && w == 0)
                {
                    // top left corner // fixed
                    int num = 0;
                    int num_x_right_r = 3;                  // no change
                    int num_x_left_r = (width - 1) * 3 + 0; // wrapped around to the right most end
                    int x_r = (im->raster)[num_x_left_r] - (im->raster)[num_x_right_r];
                    int num_x_right_g = 4; // 4
                    int num_x_left_g = (width - 1) * 3 + 1;
                    int x_g = (im->raster)[num_x_left_g] - (im->raster)[num_x_right_g];
                    int num_x_right_b = 5; // 5
                    int num_x_left_b = (width - 1) * 3 + 2;
                    int x_b = (im->raster)[num_x_left_b] - (im->raster)[num_x_right_b];

                    int num_y_up_r = (height - 1) * width * 3 + 3 * w + 0; // to the bottom now
                    int num_y_down_r = (1 * width + w) * 3 + 0;            // no change
                    int y_r = (im->raster)[num_y_down_r] - (im->raster)[num_y_up_r];
                    int num_y_up_g = (height - 1) * width * 3 + 3 * w + 1; // to the bottom now
                    int num_y_down_g = (1 * width + w) * 3 + 1;            // no change
                    int y_g = (im->raster)[num_y_down_g] - (im->raster)[num_y_up_g];
                    int num_y_up_b = (height - 1) * width * 3 + 3 * w + 2; // to the bottom now
                    int num_y_down_b = (1 * width + w) * 3 + 2;            // no change // issues found
                    int y_b = (im->raster)[num_y_down_b] - (im->raster)[num_y_up_b];
                    int n[6] = {x_r, x_g, x_b, y_r, y_g, y_b};
                    (*grad)->raster[num * 3 + 0] = energy_calculator(n);
                    (*grad)->raster[num * 3 + 1] = energy_calculator(n);
                    (*grad)->raster[num * 3 + 2] = energy_calculator(n);
                }
                else if (h == height - 1 && w == width - 1)
                {
                    // bottom right corner // fixed
                    int num = h * width + w;
                    int num_x_right_r = (height - 1) * width * 3 + 0; // wrapped around to the left most end
                    int num_x_left_r = (h * width) * 3 + 3 * (w) + 0 - 3;
                    int x_r = (im->raster)[num_x_left_r] - (im->raster)[num_x_right_r];
                    int num_x_right_g = (height - 1) * width * 3 + 1;
                    int num_x_left_g = (h * width) * 3 + 3 * (w) + 1 - 3;
                    int x_g = (im->raster)[num_x_left_g] - (im->raster)[num_x_right_g];
                    int num_x_right_b = (height - 1) * width * 3 + 2;
                    int num_x_left_b = (h * width) * 3 + 3 * (w) + 2 - 3;
                    int x_b = (im->raster)[num_x_left_b] - (im->raster)[num_x_right_b];

                    int num_y_up_r = ((h - 1) * width + w) * 3 + 0;
                    int num_y_down_r = 3 * (width - 1) + 0; // wrapped around to the top most end
                    int y_r = (im->raster)[num_y_down_r] - (im->raster)[num_y_up_r];
                    int num_y_up_g = ((h - 1) * width + w) * 3 + 1;
                    int num_y_down_g = 3 * (width - 1) + 1; // wrapped around to the top most end
                    int y_g = (im->raster)[num_y_down_g] - (im->raster)[num_y_up_g];
                    int num_y_up_b = ((h - 1) * width + w) * 3 + 2;
                    int num_y_down_b = 3 * (width - 1) + 2; // wrapped around to the top most end
                    int y_b = (im->raster)[num_y_down_b] - (im->raster)[num_y_up_b];
                    int n[6] = {x_r, x_g, x_b, y_r, y_g, y_b};
                    (*grad)->raster[num * 3 + 0] = energy_calculator(n);
                    (*grad)->raster[num * 3 + 1] = energy_calculator(n);
                    (*grad)->raster[num * 3 + 2] = energy_calculator(n);
                }
                else if (h == height - 1 && w == 0)
                {
                    // bottom left corner // fixed
                    int num = h * width + w;
                    int num_x_right_r = h * width * 3 + 3 + 0;
                    int num_x_left_r = height * width * 3 - 3 + 0; // wrapped around to the right most end
                    int x_r = (im->raster)[num_x_left_r] - (im->raster)[num_x_right_r];
                    int num_x_right_g = h * width * 3 + 3 + 1;
                    int num_x_left_g = height * width * 3 - 3 + 1; // wrapped around to the right most end
                    int x_g = (im->raster)[num_x_left_g] - (im->raster)[num_x_right_g];
                    int num_x_right_b = h * width * 3 + 3 + 2;
                    int num_x_left_b = height * width * 3 - 3 + 2; // wrapped around to the right most end
                    int x_b = (im->raster)[num_x_left_b] - (im->raster)[num_x_right_b];

                    int num_y_up_r = ((height - 2) * width) * 3 + 0;
                    int num_y_down_r = 0; // wrapped around to the top most end
                    int y_r = (im->raster)[num_y_down_r] - (im->raster)[num_y_up_r];
                    int num_y_up_g = ((height - 2) * width) * 3 + 1;
                    int num_y_down_g = 1; // wrapped around to the top most end
                    int y_g = (im->raster)[num_y_down_g] - (im->raster)[num_y_up_g];
                    int num_y_up_b = ((height - 2) * width) * 3 + 2;
                    int num_y_down_b = 2; // wrapped around to the top most end
                    int y_b = (im->raster)[num_y_down_b] - (im->raster)[num_y_up_b];
                    int n[6] = {x_r, x_g, x_b, y_r, y_g, y_b};
                    (*grad)->raster[num * 3 + 0] = energy_calculator(n);
                    (*grad)->raster[num * 3 + 1] = energy_calculator(n);
                    (*grad)->raster[num * 3 + 2] = energy_calculator(n);
                }
                else if (h == 0 && w == width - 1)
                {
                    // top right corner // fixed
                    int num = h * width + w;
                    int num_x_right_r = 0; // wrapped around to the left most end
                    int num_x_left_r = (w - 1) * 3 + 0;
                    // int num_x_left_r = (width - 2) * 3 + 0;
                    int x_r = (im->raster)[num_x_left_r] - (im->raster)[num_x_right_r];
                    int num_x_right_g = 1;
                    int num_x_left_g = (w - 1) * 3 + 1;
                    // int num_x_left_g = (width - 2) * 3 + 1;
                    int x_g = (im->raster)[num_x_left_g] - (im->raster)[num_x_right_g];
                    int num_x_right_b = 2;
                    int num_x_left_b = (w - 1) * 3 + 2;
                    // int num_x_left_b = (width - 2) * 3 + 2;
                    int x_b = (im->raster)[num_x_left_b] - (im->raster)[num_x_right_b];

                    int num_y_up_r = (height - 1) * width * 3 + 3 * w + 0; // to the bottom now
                    int num_y_down_r = ((h + 1) * width + w) * 3 + 0;      // no change
                    int y_r = (im->raster)[num_y_down_r] - (im->raster)[num_y_up_r];
                    int num_y_up_g = (height - 1) * width * 3 + 3 * w + 1; // to the bottom now
                    int num_y_down_g = ((h + 1) * width + w) * 3 + 1;      // no change
                    int y_g = (im->raster)[num_y_down_g] - (im->raster)[num_y_up_g];
                    int num_y_up_b = (height - 1) * width * 3 + 3 * w + 2; // to the bottom now
                    int num_y_down_b = ((h + 1) * width + w) * 3 + 2;      // no change
                    int y_b = (im->raster)[num_y_down_b] - (im->raster)[num_y_up_b];
                    int n[6] = {x_r, x_g, x_b, y_r, y_g, y_b};
                    (*grad)->raster[num * 3 + 0] = energy_calculator(n);
                    (*grad)->raster[num * 3 + 1] = energy_calculator(n);
                    (*grad)->raster[num * 3 + 2] = energy_calculator(n);
                }
                else if (h == 0)
                {
                    // The top line // fixed
                    int num = h * width + w;
                    int num_x_right_r = (h * width + w) * 3 + 3 * 1 + 0;
                    int num_x_left_r = (h * width + w) * 3 + 3 * (-1) + 0;
                    int x_r = (im->raster)[num_x_left_r] - (im->raster)[num_x_right_r];
                    int num_x_right_g = (h * width + w) * 3 + 3 * 1 + 1;
                    int num_x_left_g = (h * width + w) * 3 + 3 * (-1) + 1;
                    int x_g = (im->raster)[num_x_left_g] - (im->raster)[num_x_right_g];
                    int num_x_right_b = (h * width + w) * 3 + 3 * 1 + 2;
                    int num_x_left_b = (h * width + w) * 3 + 3 * (-1) + 2;
                    int x_b = (im->raster)[num_x_left_b] - (im->raster)[num_x_right_b];
                    // only y_up has to  be fixed
                    int num_y_up_r = (height - 1) * width * 3 + 3 * w + 0; // to the bottom now // this needs to be fixed
                    int num_y_down_r = (width + w) * 3 + 0;                // no change
                    int y_r = (im->raster)[num_y_down_r] - (im->raster)[num_y_up_r];
                    int num_y_up_g = (height - 1) * width * 3 + 3 * w + 1; // to the bottom now
                    int num_y_down_g = (width + w) * 3 + 1;                // no change
                    int y_g = (im->raster)[num_y_down_g] - (im->raster)[num_y_up_g];
                    int num_y_up_b = (height - 1) * width * 3 + 3 * w + 2; // to the bottom now
                    int num_y_down_b = (width + w) * 3 + 2;                // no change
                    int y_b = (im->raster)[num_y_down_b] - (im->raster)[num_y_up_b];
                    int n[6] = {x_r, x_g, x_b, y_r, y_g, y_b};
                    (*grad)->raster[num * 3 + 0] = energy_calculator(n);
                    (*grad)->raster[num * 3 + 1] = energy_calculator(n);
                    (*grad)->raster[num * 3 + 2] = energy_calculator(n);
                }
                else if (h == height - 1)
                {
                    // the bottom line // fixed!!!
                    int num = h * width + w;
                    int num_x_right_r = (h * width + w) * 3 + 3 * 1 + 0;
                    int num_x_left_r = (h * width + w) * 3 + 3 * (-1) + 0;
                    int x_r = (im->raster)[num_x_left_r] - (im->raster)[num_x_right_r];
                    int num_x_right_g = (h * width + w) * 3 + 3 * 1 + 1;
                    int num_x_left_g = (h * width + w) * 3 + 3 * (-1) + 1;
                    int x_g = (im->raster)[num_x_left_g] - (im->raster)[num_x_right_g];
                    int num_x_right_b = (h * width + w) * 3 + 3 * 1 + 2;
                    int num_x_left_b = (h * width + w) * 3 + 3 * (-1) + 2;
                    int x_b = (im->raster)[num_x_left_b] - (im->raster)[num_x_right_b];

                    int num_y_up_r = ((h - 1) * width + w) * 3 + 0;
                    int num_y_down_r = w * 3 + 0; // wrapped around to the top most end
                    int y_r = (im->raster)[num_y_down_r] - (im->raster)[num_y_up_r];
                    int num_y_up_g = ((h - 1) * width + w) * 3 + 1;
                    int num_y_down_g = w * 3 + 1; // wrapped around to the top most end
                    int y_g = (im->raster)[num_y_down_g] - (im->raster)[num_y_up_g];
                    int num_y_up_b = ((h - 1) * width + w) * 3 + 2;
                    int num_y_down_b = w * 3 + 2; // wrapped around to the top most end
                    int y_b = (im->raster)[num_y_down_b] - (im->raster)[num_y_up_b];
                    int n[6] = {x_r, x_g, x_b, y_r, y_g, y_b};
                    (*grad)->raster[num * 3 + 0] = energy_calculator(n);
                    (*grad)->raster[num * 3 + 1] = energy_calculator(n);
                    (*grad)->raster[num * 3 + 2] = energy_calculator(n);
                }
                else if (w == 0)
                {
                    // the left line // when i finished off // fixed!!!
                    int num = h * width + w;
                    int num_x_right_r = (h * width + w) * 3 + 3 * 1 + 0;
                    int num_x_left_r = (h * width + w) * 3 + 3 * (width - 1) + 0; // wrapped around to the right most end
                    int x_r = (im->raster)[num_x_left_r] - (im->raster)[num_x_right_r];
                    int num_x_right_g = (h * width + w) * 3 + 3 * 1 + 1;
                    int num_x_left_g = (h * width + w) * 3 + 3 * (width - 1) + 1; // wrapped around to the right most end
                    int x_g = (im->raster)[num_x_left_g] - (im->raster)[num_x_right_g];
                    int num_x_right_b = (h * width + w) * 3 + 3 * 1 + 2;
                    int num_x_left_b = (h * width + w) * 3 + 3 * (width - 1) + 2; // wrapped around to the right most end
                    int x_b = (im->raster)[num_x_left_b] - (im->raster)[num_x_right_b];

                    int num_y_up_r = ((h + 1) * width + w) * 3 + 0;
                    int num_y_down_r = ((h - 1) * width + w) * 3 + 0;
                    int y_r = (im->raster)[num_y_down_r] - (im->raster)[num_y_up_r];
                    int num_y_up_g = ((h + 1) * width + w) * 3 + 1;
                    int num_y_down_g = ((h - 1) * width + w) * 3 + 1;
                    int y_g = (im->raster)[num_y_down_g] - (im->raster)[num_y_up_g];
                    int num_y_up_b = ((h + 1) * width + w) * 3 + 2;
                    int num_y_down_b = ((h - 1) * width + w) * 3 + 2;
                    int y_b = (im->raster)[num_y_down_b] - (im->raster)[num_y_up_b];
                    int n[6] = {x_r, x_g, x_b, y_r, y_g, y_b};
                    (*grad)->raster[num * 3 + 0] = energy_calculator(n);
                    (*grad)->raster[num * 3 + 1] = energy_calculator(n);
                    (*grad)->raster[num * 3 + 2] = energy_calculator(n);
                }
                else if (w == width - 1)
                {
                    // the right line
                    int num = h * width + w;

                    int num_x_right_r = h * width * 3 + 3 * 0 + 0; // wrapped around to the left most end
                    int num_x_left_r = (h * width + w) * 3 + 3 * (-1) + 0;
                    int x_r = (im->raster)[num_x_left_r] - (im->raster)[num_x_right_r];
                    // printf("x_r right line = %d\n", x_r);
                    int num_x_right_g = h * width * 3 + 3 * 0 + 1;
                    int num_x_left_g = (h * width + w) * 3 + 3 * (-1) + 1;
                    int x_g = (im->raster)[num_x_left_g] - (im->raster)[num_x_right_g];
                    // printf("x_g right line = %d\n", x_g);
                    int num_x_right_b = h * width * 3 + 3 * 0 + 2;
                    int num_x_left_b = (h * width + w) * 3 + 3 * (-1) + 2;
                    int x_b = (im->raster)[num_x_left_b] - (im->raster)[num_x_right_b];
                    // printf("x_b right line = %d\n", x_b);

                    int num_y_up_r = ((h + 1) * width + w) * 3 + 0;
                    int num_y_down_r = ((h - 1) * width + w) * 3 + 0;
                    int y_r = (im->raster)[num_y_down_r] - (im->raster)[num_y_up_r];
                    // printf("y_r right line = %d\n", y_r);
                    int num_y_up_g = ((h + 1) * width + w) * 3 + 1;
                    int num_y_down_g = ((h - 1) * width + w) * 3 + 1;
                    int y_g = (im->raster)[num_y_down_g] - (im->raster)[num_y_up_g];
                    // printf("y_g right line = %d\n", y_g);
                    int num_y_up_b = ((h + 1) * width + w) * 3 + 2;
                    int num_y_down_b = ((h - 1) * width + w) * 3 + 2;
                    int y_b = (im->raster)[num_y_down_b] - (im->raster)[num_y_up_b];
                    // printf("y_b right line = %d\n", y_b);
                    int n[6] = {x_r, x_g, x_b, y_r, y_g, y_b};
                    // printf("n_right line = %d\n", energy_calculator(n));
                    (*grad)->raster[num * 3 + 0] = energy_calculator(n);
                    (*grad)->raster[num * 3 + 1] = energy_calculator(n);
                    (*grad)->raster[num * 3 + 2] = energy_calculator(n);
                }
            }
            else
            {
                int num = h * width + w;

                int num_x_right_r = (h * width + w) * 3 + 3 * 1 + 0;
                int num_x_left_r = (h * width + w) * 3 + 3 * (-1) + 0;
                int x_r = (im->raster)[num_x_left_r] - (im->raster)[num_x_right_r];
                // printf("x_r = %d\n", x_r);
                int num_x_right_g = (h * width + w) * 3 + 3 * 1 + 1;
                int num_x_left_g = (h * width + w) * 3 + 3 * (-1) + 1;
                int x_g = (im->raster)[num_x_left_g] - (im->raster)[num_x_right_g];
                // printf("x_g = %d\n", x_g);
                int num_x_right_b = (h * width + w) * 3 + 3 * 1 + 2;
                int num_x_left_b = (h * width + w) * 3 + 3 * (-1) + 2;
                int x_b = (im->raster)[num_x_left_b] - (im->raster)[num_x_right_b];
                // printf("x_b = %d\n", x_b);

                int num_y_up_r = ((h + 1) * width + w) * 3 + 0;
                int num_y_down_r = ((h - 1) * width + w) * 3 + 0;
                int y_r = (im->raster)[num_y_down_r] - (im->raster)[num_y_up_r];
                // printf("y_r = %d\n", y_r);
                int num_y_up_g = ((h + 1) * width + w) * 3 + 1;
                int num_y_down_g = ((h - 1) * width + w) * 3 + 1;
                int y_g = (im->raster)[num_y_down_g] - (im->raster)[num_y_up_g];
                // printf("y_g = %d\n", y_g);
                int num_y_up_b = ((h + 1) * width + w) * 3 + 2;
                int num_y_down_b = ((h - 1) * width + w) * 3 + 2;
                int y_b = (im->raster)[num_y_down_b] - (im->raster)[num_y_up_b];
                // printf("y_b = %d\n", y_b);

                int n[6] = {x_r, x_g, x_b, y_r, y_g, y_b};
                // printf("n = %d\n", energy_calculator(n));
                (*grad)->raster[num * 3 + 0] = energy_calculator(n);
                (*grad)->raster[num * 3 + 1] = energy_calculator(n);
                (*grad)->raster[num * 3 + 2] = energy_calculator(n);
            }
        }
    }
}

void dynamic_seam(struct rgb_img *grad, double **best_arr)
{
    int height = grad->height;
    int width = grad->width;
    *best_arr = (double *)malloc(height * width * sizeof(double));
    // now *best_arr is itself a pointer
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            if (h == 0)
            {
                *((*best_arr) + w) = (grad->raster)[w * 3];
            }
            else if (w == 0)
            {
                double ans = (grad->raster)[h * width * 3 + w * 3] + min((*best_arr)[(h - 1) * width + w], (*best_arr)[(h - 1) * width + w + 1]);
                *((*best_arr) + h * width + w) = ans;
            }
            else if (w == width - 1)
            {
                double ans = (grad->raster)[h * width * 3 + w * 3] + min((*best_arr)[(h - 1) * width + w], (*best_arr)[(h - 1) * width + w - 1]);
                *((*best_arr) + h * width + w) = ans;
            }
            else
            {
                double ans = (grad->raster)[h * width * 3 + w * 3] + min(min((*best_arr)[(h - 1) * width + w], (*best_arr)[(h - 1) * width + w + 1]), min((*best_arr)[(h - 1) * width + w], (*best_arr)[(h - 1) * width + w - 1]));
                *((*best_arr) + h * width + w) = ans;
            }
        }
    }
}

int min_ptr(double *adr, int width) // Takes in a pointer, return the index of the min num
{
    double min = *adr;
    int min_index = 0;

    for (int i = 0; i < width; i++)
    {
        if (*(adr + i) < min)
        {
            min = *(adr + i);
            min_index = i;
        }
    }
    return min_index;
}

int min_in3(double *adr, int cur_hei, int width, int last_index) // pass in the ptr of the next row, lowest number, return the index lowest num
{
    double before = adr[(cur_hei)*width + last_index - 1];
    double middle = adr[(cur_hei)*width + last_index];
    double after = adr[(cur_hei)*width + last_index + 1];
    if (last_index == width - 1)
    {
        if (middle < before)
        {
            return width - 1;
        }
        else
        {
            return width - 2; // there migth be cases where they are equal
        }
    }
    else if (last_index == 0)
    {
        if (middle < after)
        {
            return 0;
        }
        else
        {
            return 1; // there migth be cases where they are equal
        }
    }
    else
    {
        if (before < middle & before <= after)
        {
            return last_index - 1;
        }
        else if (after < middle & after < before)
        {
            return last_index + 1;
        }
        else
        {
            return last_index;
        }
    }
}

void recover_path(double *best, int height, int width, int **path)
{
    *path = (int *)malloc(height * sizeof(int));
    for (int i = height - 1; i >= 0; i--)
    {
        if (i == height - 1)
        {
            (*path)[i] = min_ptr(best + i * width, width);
        }
        else
        {
            (*path)[i] = min_in3(best, i, width, (*path)[i + 1]);
        }
    }
}

void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path)
{
    int height = src->height;
    int width = src->width;
    *dest = (struct rgb_img *)malloc(sizeof(struct rgb_img));
    (*dest)->height = height;
    (*dest)->width = width - 1;
    (*dest)->raster = (uint8_t *)malloc(3 * height * (width - 1));
    int count = 0;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            if (w == path[h])
            {
                count++;
            }
            else
            {
                for (int k = 0; k < 3; k++)
                {
                    (*dest)->raster[h * width * 3 + w * 3 - count * 3 + k] = src->raster[h * width * 3 + w * 3 + k];
                }
            }
        }
    }
}
