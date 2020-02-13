#include <stdlib.h>
#include <stdio.h>


int maxProfit(int* prices, int pricesSize){
    if(pricesSize <= 1)
        return 0;
    int min = prices[0];
    int profit = 0;
    for(int i=1; i<pricesSize; i++) {
        if(prices[i] - min > profit)
            profit = prices[i] - min;
        if(prices[i] < min)
            min = prices[i];
    }
    return profit;
}


int main(void) {
    int prices[] = {7,1,5,3,6,4};
    int n = sizeof(prices) / sizeof(int);
    int profit = maxProfit(prices, n);
    printf("%d\n", profit);
    return EXIT_SUCCESS;
}
