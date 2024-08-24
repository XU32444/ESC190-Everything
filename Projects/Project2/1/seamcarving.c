#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "c_img.h"

int energy_calculator(int n[6]);

void calc_energy(struct rgb_img *im, struct rgb_img **grad)
{
    int height = im->height;
    int width = im->width;
    (*grad) = (struct rgb_img *)malloc(sizeof(struct rgb_img));
    (*grad)->height = height;
    (*grad)->width = width;
    (*grad)->raster = (uint8_t *)malloc(3 * height * width);

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {

            if (h == 0 || w == 0 || h == height - 1 || w == width - 1)
            {
                if (h == 0 && w == 0)
                {
                    // top left corner
                    int num = 0;
                    int num_x_right_r = h * w * 3 + 3 * (w + 1) + 0; // no change
                    int num_x_left_r = h * w * 3 + 3 * width + 0;    // wrapped around to the right most end
                    int x_r = num_x_left_r - num_x_right_r;
                    int num_x_right_g = h * w * 3 + 3 * (w + 1) + 1;
                    int num_x_left_g = h * w * 3 + 3 * width + 1;
                    int x_g = num_x_left_g - num_x_right_g;
                    int num_x_right_b = h * w * 3 + 3 * (w + 1) + 2;
                    int num_x_left_b = h * w * 3 + 3 * width + 2;
                    int x_b = num_x_left_b - num_x_right_b;

                    int num_y_up_r = (height)*w * 3 + 3 * w + 0;    // to the bottom now
                    int num_y_down_r = (h + 1) * w * 3 + 3 * w + 0; // no change
                    int y_r = num_y_down_r - num_y_up_r;
                    int num_y_up_g = (height)*w * 3 + 3 * w + 1;    // to the bottom now
                    int num_y_down_g = (h + 1) * w * 3 + 3 * w + 1; // no change
                    int y_g = num_y_up_g - num_y_down_g;
                    int num_y_up_b = (height)*w * 3 + 3 * w + 2;    // to the bottom now
                    int num_y_down_b = (h + 1) * w * 3 + 3 * w + 2; // no change
                    int y_b = num_y_up_b - num_y_down_b;
                    int n[6] = {x_r, x_g, x_b, y_r, y_g, y_b};
                    (*grad)->raster[num] = energy_calculator(n);
                }
                else if (h == height - 1 && w == width - 1)
                {
                    // bottom right corner
                    int num = h * width + w;
                    int num_x_right_r = h * w * 3 + 3 * 0 + 0; // wrapped around to the left most end
                    int num_x_left_r = h * w * 3 + 3 * (w - 1) + 0;
                    int x_r = num_x_left_r - num_x_right_r;
                    int num_x_right_g = h * w * 3 + 3 * 0 + 1;
                    int num_x_left_g = h * w * 3 + 3 * (w - 1) + 1;
                    int x_g = num_x_left_g - num_x_right_g;
                    int num_x_right_b = h * w * 3 + 3 * 0 + 2;
                    int num_x_left_b = h * w * 3 + 3 * (w - 1) + 2;
                    int x_b = num_x_left_b - num_x_right_b;

                    int num_y_up_r = (h - 1) * w * 3 + 3 * w + 0;
                    int num_y_down_r = 0 * w * 3 + 3 * w + 0; // wrapped around to the top most end
                    int y_r = num_y_down_r - num_y_up_r;
                    int num_y_up_g = (h - 1) * w * 3 + 3 * w + 1;
                    int num_y_down_g = 0 * w * 3 + 3 * w + 1; // wrapped around to the top most end
                    int y_g = num_y_up_g - num_y_down_g;
                    int num_y_up_b = (h - 1) * w * 3 + 3 * w + 2;
                    int num_y_down_b = 0 * w * 3 + 3 * w + 2; // wrapped around to the top most end
                    int y_b = num_y_up_b - num_y_down_b;
                    int n[6] = {x_r, x_g, x_b, y_r, y_g, y_b};
                    (*grad)->raster[num] = energy_calculator(n);
                }
                else if (h == height - 1 && w == 0)
                {
                    // bottom left corner
                    int num = h * width + w;
                    int num_x_right_r = h * w * 3 + 3 * (w + 1) + 0;
                    int num_x_left_r = h * w * 3 + 3 * (width - 1) + 0; // wrapped around to the right most end
                    int x_r = num_x_left_r - num_x_right_r;
                    int num_x_right_g = h * w * 3 + 3 * (w + 1) + 1;
                    int num_x_left_g = h * w * 3 + 3 * (width - 1) + 1; // wrapped around to the right most end
                    int x_g = num_x_left_g - num_x_right_g;
                    int num_x_right_b = h * w * 3 + 3 * (w + 1) + 2;
                    int num_x_left_b = h * w * 3 + 3 * (width - 1) + 2; // wrapped around to the right most end
                    int x_b = num_x_left_b - num_x_right_b;

                    int num_y_up_r = (h - 1) * w * 3 + 3 * w + 0;
                    int num_y_down_r = 0 * w * 3 + 3 * w + 0; // wrapped around to the top most end
                    int y_r = num_y_down_r - num_y_up_r;
                    int num_y_up_g = (h - 1) * w * 3 + 3 * w + 1;
                    int num_y_down_g = 0 * w * 3 + 3 * w + 1; // wrapped around to the top most end
                    int y_g = num_y_up_g - num_y_down_g;
                    int num_y_up_b = (h - 1) * w * 3 + 3 * w + 2;
                    int num_y_down_b = 0 * w * 3 + 3 * w + 2; // wrapped around to the top most end
                    int y_b = num_y_up_b - num_y_down_b;
                    int n[6] = {x_r, x_g, x_b, y_r, y_g, y_b};
                    (*grad)->raster[num] = energy_calculator(n);
                }
                else if (h == 0 && w == width - 1)
                {
                    // top right corner
                    int num = h * width + w;
                    int num_x_right_r = h * w * 3 + 3 * 0 + 0; // wrapped around to the left most end
                    int num_x_left_r = h * w * 3 + 3 * (w - 1) + 0;
                    int x_r = num_x_left_r - num_x_right_r;
                    int num_x_right_g = h * w * 3 + 3 * 0 + 1;
                    int num_x_left_g = h * w * 3 + 3 * (w - 1) + 1;
                    int x_g = num_x_left_g - num_x_right_g;
                    int num_x_right_b = h * w * 3 + 3 * 0 + 2;
                    int num_x_left_b = h * w * 3 + 3 * (w - 1) + 2;
                    int x_b = num_x_left_b - num_x_right_b;

                    int num_y_up_r = (height)*w * 3 + 3 * w + 0;    // to the bottom now
                    int num_y_down_r = (h + 1) * w * 3 + 3 * w + 0; // no change
                    int y_r = num_y_down_r - num_y_up_r;
                    int num_y_up_g = (height)*w * 3 + 3 * w + 1;    // to the bottom now
                    int num_y_down_g = (h + 1) * w * 3 + 3 * w + 1; // no change
                    int y_g = num_y_up_g - num_y_down_g;
                    int num_y_up_b = (height)*w * 3 + 3 * w + 2;    // to the bottom now
                    int num_y_down_b = (h + 1) * w * 3 + 3 * w + 2; // no change
                    int y_b = num_y_up_b - num_y_down_b;
                    int n[6] = {x_r, x_g, x_b, y_r, y_g, y_b};
                    (*grad)->raster[num] = energy_calculator(n);
                }
                else if (h == 0)
                {
                    // The part in the middle
                    int num = h * width + w;
                    int num_x_right_r = h * w * 3 + 3 * (w + 1) + 0;
                    int num_x_left_r = h * w * 3 + 3 * (w - 1) + 0;
                    int x_r = num_x_left_r - num_x_right_r;
                    int num_x_right_g = h * w * 3 + 3 * (w + 1) + 1;
                    int num_x_left_g = h * w * 3 + 3 * (w - 1) + 1;
                    int x_g = num_x_left_g - num_x_right_g;
                    int num_x_right_b = h * w * 3 + 3 * (w + 1) + 2;
                    int num_x_left_b = h * w * 3 + 3 * (w - 1) + 2;
                    int x_b = num_x_left_b - num_x_right_b;

                    int num_y_up_r = (height)*w * 3 + 3 * w + 0;    // to the bottom now
                    int num_y_down_r = (h + 1) * w * 3 + 3 * w + 0; // no change
                    int y_r = num_y_down_r - num_y_up_r;
                    int num_y_up_g = (height)*w * 3 + 3 * w + 1;    // to the bottom now
                    int num_y_down_g = (h + 1) * w * 3 + 3 * w + 1; // no change
                    int y_g = num_y_up_g - num_y_down_g;
                    int num_y_up_b = (height)*w * 3 + 3 * w + 2;    // to the bottom now
                    int num_y_down_b = (h + 1) * w * 3 + 3 * w + 2; // no change
                    int y_b = num_y_up_b - num_y_down_b;
                    int n[6] = {x_r, x_g, x_b, y_r, y_g, y_b};
                    (*grad)->raster[num] = energy_calculator(n);
                }
                else if (h == height - 1)
                {
                    // the bottom line
                    int num = h * width + w;
                    int num_x_right_r = h * w * 3 + 3 * (w + 1) + 0;
                    int num_x_left_r = h * w * 3 + 3 * (w - 1) + 0;
                    int x_r = num_x_left_r - num_x_right_r;
                    int num_x_right_g = h * w * 3 + 3 * (w + 1) + 1;
                    int num_x_left_g = h * w * 3 + 3 * (w - 1) + 1;
                    int x_g = num_x_left_g - num_x_right_g;
                    int num_x_right_b = h * w * 3 + 3 * (w + 1) + 2;
                    int num_x_left_b = h * w * 3 + 3 * (w - 1) + 2;
                    int x_b = num_x_left_b - num_x_right_b;

                    int num_y_up_r = (h - 1) * w * 3 + 3 * w + 0;
                    int num_y_down_r = 0 * w * 3 + 3 * w + 0; // wrapped around to the top most end
                    int y_r = num_y_down_r - num_y_up_r;
                    int num_y_up_g = (h - 1) * w * 3 + 3 * w + 1;
                    int num_y_down_g = 0 * w * 3 + 3 * w + 1; // wrapped around to the top most end
                    int y_g = num_y_up_g - num_y_down_g;
                    int num_y_up_b = (h - 1) * w * 3 + 3 * w + 2;
                    int num_y_down_b = 0 * w * 3 + 3 * w + 2; // wrapped around to the top most end
                    int y_b = num_y_up_b - num_y_down_b;
                    int n[6] = {x_r, x_g, x_b, y_r, y_g, y_b};
                    (*grad)->raster[num] = energy_calculator(n);
                }
                else if (w == 0)
                {
                    // the left line
                    int num = h * width + w;
                    int num_x_right_r = h * w * 3 + 3 * (w + 1) + 0;
                    int num_x_left_r = h * w * 3 + 3 * width + 0; // wrapped around to the right most end
                    int x_r = num_x_left_r - num_x_right_r;
                    int num_x_right_g = h * w * 3 + 3 * (w + 1) + 1;
                    int num_x_left_g = h * w * 3 + 3 * width + 1; // wrapped around to the right most end
                    int x_g = num_x_left_g - num_x_right_g;
                    int num_x_right_b = h * w * 3 + 3 * (w + 1) + 2;
                    int num_x_left_b = h * w * 3 + 3 * width + 2; // wrapped around to the right most end
                    int x_b = num_x_left_b - num_x_right_b;

                    int num_y_up_r = (h - 1) * w * 3 + 3 * w + 0;
                    int num_y_down_r = (h + 1) * w * 3 + 3 * w + 0;
                    int y_r = num_y_down_r - num_y_up_r;
                    int num_y_up_g = (h - 1) * w * 3 + 3 * w + 1;
                    int num_y_down_g = (h + 1) * w * 3 + 3 * w + 1;
                    int y_g = num_y_up_g - num_y_down_g;
                    int num_y_up_b = (h - 1) * w * 3 + 3 * w + 2;
                    int num_y_down_b = (h + 1) * w * 3 + 3 * w + 2;
                    int y_b = num_y_up_b - num_y_down_b;
                    int n[6] = {x_r, x_g, x_b, y_r, y_g, y_b};
                    (*grad)->raster[num] = energy_calculator(n);
                }
                else if (w == width - 1)
                {
                    // the right line
                    int num = h * width + w;
                    int num_x_right_r = h * w * 3 + 3 * 0 + 0; // wrapped around to the left most end
                    int num_x_left_r = h * w * 3 + 3 * (w - 1) + 0;
                    int x_r = num_x_left_r - num_x_right_r;
                    int num_x_right_g = h * w * 3 + 3 * 0 + 1;
                    int num_x_left_g = h * w * 3 + 3 * (w - 1) + 1;
                    int x_g = num_x_left_g - num_x_right_g;
                    int num_x_right_b = h * w * 3 + 3 * 0 + 2;
                    int num_x_left_b = h * w * 3 + 3 * (w - 1) + 2;
                    int x_b = num_x_left_b - num_x_right_b;

                    int num_y_up_r = (h - 1) * w * 3 + 3 * w + 0;
                    int num_y_down_r = (h + 1) * w * 3 + 3 * w + 0;
                    int y_r = num_y_down_r - num_y_up_r;
                    int num_y_up_g = (h - 1) * w * 3 + 3 * w + 1;
                    int num_y_down_g = (h + 1) * w * 3 + 3 * w + 1;
                    int y_g = num_y_up_g - num_y_down_g;
                    int num_y_up_b = (h - 1) * w * 3 + 3 * w + 2;
                    int num_y_down_b = (h + 1) * w * 3 + 3 * w + 2;
                    int y_b = num_y_up_b - num_y_down_b;
                    int n[6] = {x_r, x_g, x_b, y_r, y_g, y_b};
                    (*grad)->raster[num] = energy_calculator(n);
                }
            }
            else
            {
                int num = h * width + w;
                int num_x_right_r = h * w * 3 + 3 * (w + 1) + 0;
                int num_x_left_r = h * w * 3 + 3 * (w - 1) + 0;
                int x_r = num_x_left_r - num_x_right_r;
                int num_x_right_g = h * w * 3 + 3 * (w + 1) + 1;
                int num_x_left_g = h * w * 3 + 3 * (w - 1) + 1;
                int x_g = num_x_left_g - num_x_right_g;
                int num_x_right_b = h * w * 3 + 3 * (w + 1) + 2;
                int num_x_left_b = h * w * 3 + 3 * (w - 1) + 2;
                int x_b = num_x_left_b - num_x_right_b;

                int num_y_up_r = (h - 1) * w * 3 + 3 * w + 0;
                int num_y_down_r = (h + 1) * w * 3 + 3 * w + 0;
                int y_r = num_y_down_r - num_y_up_r;
                int num_y_up_g = (h - 1) * w * 3 + 3 * w + 1;
                int num_y_down_g = (h + 1) * w * 3 + 3 * w + 1;
                int y_g = num_y_up_g - num_y_down_g;
                int num_y_up_b = (h - 1) * w * 3 + 3 * w + 2;
                int num_y_down_b = (h + 1) * w * 3 + 3 * w + 2;
                int y_b = num_y_up_b - num_y_down_b;

                int n[6] = {x_r, x_g, x_b, y_r, y_g, y_b};
                (*grad)->raster[num] = energy_calculator(n);
            }
        }
    }
}

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

void dynamic_seam(struct rgb_img *grad, double **best_arr)
{
    *best_arr = (double *)malloc(grad->height * grad->width * sizeof(double));
}
void recover_path(double *best, int height, int width, int **path)
{
}
void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path)
{
}