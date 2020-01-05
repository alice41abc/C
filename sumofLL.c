#include <stdio.h>
#include <stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
 };

void addnode(int num, struct ListNode* l){
    struct ListNode* temp = l->next;

    if(temp == NULL){
        struct ListNode* lnew = malloc(sizeof(struct ListNode));
        l-> next = lnew;
    lnew->val = num;
    lnew->next = NULL;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    struct ListNode* lnew = malloc(sizeof(struct ListNode));
    temp -> next = lnew;
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
    
    while (l1 != NULL || l2 != NULL){
        if(l1 != NULL && l2 != NULL){
            value = l1->val + l2->val;
            l1 = l1->next; 
            l2 = l2->next;
        }else if (l1 != NULL){
            value = l1->val;
            l1 = l1->next;
        }else if (l2 != NULL){
            value = l2->val;
            l2 = l2->next;
        }
        
        if(incre){
            value += incre;
            incre = 0;
        }
        
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

