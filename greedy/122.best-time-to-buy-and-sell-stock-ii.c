#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize){
    if(pricesSize <= 1)
        return 0;

    int profit = 0, i = 1;
    /* bad case: 处理相邻元素升降序时，要考虑相等的情况 */
    while(i < pricesSize) {
        for(; i<pricesSize && prices[i] <= prices[i-1]; i++)
            ;
        profit -= prices[i - 1];  /* buy */
        for(; i<pricesSize && prices[i] > prices[i-1]; i++)
            ;
        profit += prices[i-1];   /* sell */
    }
    return profit;
}



int main(void) {
    int prices[] = {3,3};
    int profit = maxProfit(prices, sizeof(prices)/sizeof(int));
    printf("%d\n", profit);
    return 0;
}
