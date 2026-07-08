/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int lengthofLL(ListNode* head){
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) return NULL;
        int cnt = lengthofLL(head);
        cnt = cnt / 2 ;
        ListNode* temp = head;
        int traversal = 0;
        ListNode* prev = nullptr;
        while(traversal < cnt){
            traversal ++;
            prev = temp;
            temp = temp->next;
        } 

        prev->next = temp->next;
        temp->next = nullptr;
        delete temp;
        return head;
    }
};