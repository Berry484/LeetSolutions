/**
 * Problem    : 19
 * Difficulty : Medium
 * Language   : C
 * Time       : O(n)
 * Space      : O(1)
 */


#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* temp = head;
    int end = 0;

    while(temp != NULL) {
        temp = temp->next;
        end++;
    }

    if(end == n) {
        struct ListNode* newHead = head->next;
        free(head);
        return newHead;
    }

    struct ListNode* newHead = head;
    for(int i = 0; i < end - n - 1; i++){
        newHead = newHead->next;
    }

    newHead->next = newHead->next->next;
    return head;
}

struct ListNode* createListNode(int len, int* values) {
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* current = head;

    for(int i = 0; i < len; i++) {
        current->val = values[i];
        if(i < len - 1) {
            current->next = malloc(sizeof(struct ListNode));
            current = current->next;
        } else 
            current->next = NULL;
    }

    return head;
}

void printNodeAmmount(struct ListNode* head) {
    struct ListNode* current = head;
    struct ListNode* nextNode = current->next;
    int i = 1;

    while(nextNode != NULL) {
        if(i == 1)
            printf("%i", i);
        else
            printf(", %i", i);
        
        head = head->next;
        nextNode = head->next;
        i++;
    }
}

int main() {
    int* values = malloc(5 * sizeof(int));
    int tempValues[5] = {1, 2, 3, 4, 5};

    for(int i = 0; i < 5; i++)
        values[i] = tempValues[i];

    struct ListNode* head = createListNode(6, values); 
    printNodeAmmount(head);
    head = removeNthFromEnd(head, 2);
    
    free(values);
    return 0;
}
