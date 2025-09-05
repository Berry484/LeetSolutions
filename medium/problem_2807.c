/**
 * Problem    : 2807
 * Difficulty : Medium
 * Language   : C
 * Time       : O(n * log(m))
 * Space      : O(n * log(m))
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {
    struct ListNode* current = head;
    struct ListNode* next_p = current->next;

    while(next_p != NULL) {
        struct ListNode* t = malloc(sizeof(struct ListNode));
        int s = gcd(current->val, next_p->val);

        t->val = s;
        t->next = next_p;
        current->next = t;
        current = next_p;
        next_p = current->next;

    }

    return head;
}

void navigateLinkedList(struct ListNode* head) {
    struct ListNode *temp_head;
    temp_head = head;
    int i = 0;

    while(temp_head != NULL) {
        if(i == 0)
            printf("%i", temp_head->val);
        else
            printf(", %i", temp_head->val);
        temp_head = temp_head->next;
        i++;
    }
}

int main() {
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* current = head;

    int values[4] = {18, 6, 10, 3};

    for(int i = 0; i < 4; i++) {
        current->val = values[i];

        if(i < 3) {
            current->next = malloc(sizeof(struct ListNode));
            current = current->next;
        } else{
            current->next = NULL;
        }
    }
    navigateLinkedList(head);
    insertGreatestCommonDivisors(head);
    printf("\nSolved!\n");
    navigateLinkedList(head);

    return 0;
}
