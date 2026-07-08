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
    ListNode* middleNode(ListNode* head) {
        int cnt = lengthofLL(head);
        cnt = (cnt / 2) + 1;
        
        ListNode* temp = head;
        int traversal = 1;
        while(traversal < cnt){
            temp = temp->next;
            traversal++;
        }
        return temp;
    }
};