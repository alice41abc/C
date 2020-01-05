#include <stdio.h>
#include <stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
};

void addnode(int num, struct ListNode* l){
    struct ListNode* lnew = malloc(sizeof(struct ListNode));
    if(l->next != NULL){
    }
    l-> next = lnew;
    lnew->val = num;
    lnew->next = NULL;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int incre = 0;
    int value = 0;
    struct ListNode* lans = malloc(sizeof(struct ListNode));

    value = l1->val + l2->val;
    if(value >= 10){
        value -= 10;
        incre = 1;
    }
    lans->val = value;
    lans->next = NULL;
    l1 = l1->next;
    l2 = l2->next;

    while(l1 != NULL || l2 != NULL){
        if(l1 != NULL && l2 != NULL){
            value = l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
        }else if (l1 == NULL){
            value = l2->val;
            l2 = l2->next;
        }else if (l2 == NULL){
            value = l1->val;
            l1 = l1->next;
        }

        if(incre){
            value += incre;
            incre = 0;
        }
        printf(value);
        if(value >= 10){
            value -= 10;
            incre = 1;
        }
        addnode(value,lans);
    }

    if(incre){
        addnode(incre,lans);
    }

    return lans;
}

int main(void){
    struct ListNode *l = malloc(sizeof(struct ListNode));
    l->val=8;
    l->next = NULL;
    addnode(9,l);
    addnode(9,l);

    struct ListNode *l2 = malloc(sizeof(struct ListNode));
    l2->next = NULL;
    l2->val = 2;
    addTwoNumbers(l,l2);
return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int t=target;
    int index=0;
    returnSize=0;
    for(int i = 0; i < numsSize;i++){
        if(*(nums+i)==target){
            returnSize=1;
            int q[1]={i};
            return  q;
        }
    }
    int*q[numsSize] = malloc(sizeof(int)*numsSize);

    for(int i = 0; i < numsSize;i++){
        if(*(num+i) > t){
            break;
        }
        if(*(num+i) < t){
            t -= *(nums+i);
            returnSize++;
            *(q+index)=i;
            index++;
        }
        if(*(num+i) == t){
            returnSize++;
            *(q+index)=i;
            return q;
        }
    }
}
