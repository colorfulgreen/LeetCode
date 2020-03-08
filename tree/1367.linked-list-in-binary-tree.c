#include <stdbool.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool isSamePath(struct ListNode *head, struct TreeNode *root) {
    if(head == NULL)
        return true;
    if(root != NULL && root->val == head->val) {
        if(isSamePath(head->next, root->left))
            return true;
        if(isSamePath(head->next, root->right))
            return true;
    }
    return false;
}

bool isSubPath(struct ListNode* head, struct TreeNode* root){
    if(head == NULL)
        return true;
    else if(root == NULL)
        return false;
    else if(root->val == head->val && isSamePath(head, root)) {
        return true;
    }
    else if(isSubPath(head, root->left))
        return true;
    else if(isSubPath(head, root->right))
        return true;
    return false;
}


