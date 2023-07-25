#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cost, count = 0, i;
    int inr[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int inr_count = sizeof(inr) / sizeof(inr[0]);

    printf("Enter the amount: ");
    scanf("%d", &cost);

    for (i = 0; i < inr_count; i++, count = 0) {
        while (inr[i] <= cost) {
            cost = cost - inr[i];
            count++;
        }
        printf("INR:\t%d\tNos:\t%d\n", inr[i], count);
    }

    return 0;
}
