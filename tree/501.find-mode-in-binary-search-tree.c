#include <stdlib.h>

#define MAX_SIZE 1000
#define MAX(a,b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void findMaxFreq(struct TreeNode *root, int *maxFreq, int *preVal, int *cnt) {
    if(root == NULL)
        return;

    findMaxFreq(root->left, maxFreq, preVal, cnt);
    *cnt = root->val == *preVal ? *cnt + 1 : 1;
    *maxFreq = MAX(*maxFreq, *cnt);
    *preVal = root->val;
    findMaxFreq(root->right, maxFreq, preVal, cnt);
}

void findModes(struct TreeNode *root, int maxFreq, int *preVal, int *cnt, int *modes, int *returnSize) {
    if(root == NULL)
        return;

    findModes(root->left, maxFreq, preVal, cnt, modes, returnSize);
    *cnt = root->val == *preVal ? *cnt + 1 : 1;
    if(*cnt == maxFreq)
        modes[(*returnSize)++] = root->val;
    *preVal = root->val;
    findModes(root->right, maxFreq, preVal, cnt, modes, returnSize);
}

int* findMode(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int *modes = malloc(sizeof(int) * MAX_SIZE);
    int maxFreq = 0, preVal = -1, cnt = 0;

    /* 注意：中序遍历的 preVal 可能不是临接节点 */
    findMaxFreq(root, &maxFreq, &preVal, &cnt);
    
    preVal = -1;
    cnt = 0;
    findModes(root, maxFreq, &preVal, &cnt, modes, returnSize);
    return modes;
}


