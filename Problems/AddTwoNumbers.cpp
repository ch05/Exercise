/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = 0;
        ListNode * curr;
        int carry = 0;

        while(l1 != 0){
            int sum = l1->val + l2->val + carry;
            if(sum >= 10){
                sum -= 10;
                curr = new ListNode(sum);
                carry = 1;
            }
            else{
                curr = new ListNode(sum);
                carry = 0;
            }   
            
            l1 = l1->next;
            l2 = l2->next;
            curr->next = head;
            head = curr;
        }
        if(carry == 1){
            curr = new ListNode(1);
            curr->next = head;
            head = curr;
        }
        return head;
    }
};