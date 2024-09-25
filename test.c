#include <stdio.h>
int main(void)
{
    int dt_1, dt_2, sum;
    printf("Input number 1:");
    scanf("%d", &dt_1);
    printf("Input number 2:");
    scanf("%d", &dt_2);
    sum = dt_1 + dt_2;
    printf("SUM = %d\n", sum);
    return 0;
}