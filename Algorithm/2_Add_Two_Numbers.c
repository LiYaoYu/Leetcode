/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //TODO: runtime error
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	if (l1->val == 0)
		return l2;
	else if (l2->val == 0)
		return l1;

	int carry = 0;
	struct ListNode* ans;
	struct ListNode* tmp;

	//initiate ans
	ans = malloc(sizeof(struct ListNode));
	ans->val = 0;
	ans->next = NULL;

	tmp = ans;

	while (l1 || l2 || carry) {
		if (l1)
			tmp->val += l1->val;
		if (l2)
			tmp->val += l2->val;

		tmp->val += carry;

		//handle carry
		if (tmp->val > 9) {
			carry = 1;
			tmp->val = tmp->val % 10;
		}
	
		int flag = 0;

		l1 = l1->next;
		l2 = l2->next;

		if (l1->next || l2->next) 
			flag = 1;
		
		if (flag == 1) {
			tmp->next = malloc(sizeof(struct ListNode));
			tmp = tmp->next;
			tmp->val = 0;
			tmp->next = NULL;
		}
	}
	return ans;    
}
