#include <stdio.h>
#include <math.h>

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
int main()
{
    int a[6] = {204, -102, 0, 0, 0, 0};
    printf("%d\n", energy_calculator(a));
    printf("%f\n", min(2340.234234, 3463.23480234));
    return 0;
}
