#include <stdio.h>

#define MAX_SIZE 10

int monotoneIncreasingDigits(int N){
    if(N < 10)
        return N;

    int nums[MAX_SIZE] = {0};
    int size;
    for(size=0; size<MAX_SIZE; size++) {
        nums[size] = N % 10;
        N /= 10;
        if(N == 0)
            break;
    }

    int i,j,k;
    for(j=size; j>0; j--) {
        if(nums[j-1] >= nums[j])
            continue;
        /* 向高位找到第一个要修改的位 */
        for(k=j; k<=size && nums[k] > nums[k-1]; k++)
            nums[k]--;
        for(k=k-2; k>=0; k--)
            nums[k] = 9;
        break;
    }

    int r = 0;
    for(int k=size; k>=0; k--) {
        r *= 10;
        r += nums[k];
    }
    return r;
}

int main(void) {
    int r = monotoneIncreasingDigits(668841);
    printf("%d\n", r);
    return 0;
}


