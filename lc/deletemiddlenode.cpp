#include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int n = 1;
        ListNode* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
            ++n; 
        }
        if (n==1) return NULL;
        if (n==2){
            ListNode* x = new ListNode(head->val);
            return x;
        }
        n = n/2;
        temp = head;
        for(int i=0;i<n-1;i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
        
    }
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};