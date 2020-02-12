#include <stdio.h>

/*
Intuition and Algorithm

At the end of the i-th day, we maintain cash, the maximum profit we could have if we did not have a share of stock, and hold, the maximum profit we could have if we owned a share of stock.

To transition from the i-th day to the i+1-th day, we either sell our stock cash = max(cash, hold + prices[i] - fee) or buy a stock hold = max(hold, cash - prices[i]). At the end, we want to return cash. We can transform cash first without using temporary variables because selling and buying on the same day can't be better than just continuing to hold the stock.
 */
int maxProfit(int* prices, int pricesSize, int fee){
    if(pricesSize == 0)
        return 0;

    int cash = 0, hold = -prices[0];
    for(int i=1; i<pricesSize; i++) {
        cash = cash > hold + prices[i] - fee ? cash : hold + prices[i] - fee ;
        hold = hold > cash - prices[i] ? hold : cash - prices[i];
        printf("i=%d cash=%d hold=%d\n", i, cash, hold);
    }
    return cash;
}

int main(void) {
    int prices[] = {1, 3, 2, 8, 4, 9};
    int pricesSize = sizeof(prices) / sizeof(int);
    int fee = 2;
    int profit = maxProfit(prices, pricesSize, fee);
    printf("%d\n", profit);
    return 0;
}
