

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//11:48
// 3 pointers

struct ListNode* reverseList(struct ListNode* head){
    
    if(head == NULL) return NULL;
    struct ListNode* pres = head;
    struct ListNode* prev = NULL;
    struct ListNode* rest = NULL;
    
    while(pres != NULL) {
        rest = pres-> next;
        pres -> next = prev;
        prev = pres;
        pres = rest;
    }
    
    return prev;
}


//via recursion
struct ListNode* reverseList(struct ListNode* head){
    
    if(head == NULL) return NULL;
    struct ListNode* pres = head;
    struct ListNode* rest = pres-> next;

    
    //fix head
    if(rest == NULL) {
        return pres;
    }
    head = reverseList(pres->next);
    pres->next = NULL;
    rest->next =  pres;
    return head;
}













