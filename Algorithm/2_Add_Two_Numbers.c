/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	if (l1->val == 0 && !l1->next)
		return l2;
	else if (l2->val == 0 && !l2->next)
		return l1;

	int carry = 0;
	struct ListNode* ans;
	struct ListNode* tmp;

	//initiate ans
	ans = malloc(sizeof(struct ListNode));
	tmp = ans;

	while (l1 || l2 || carry) {
		tmp->val = 0;
		tmp->next = NULL;

		if (l1)
			tmp->val += l1->val;
		if (l2)
			tmp->val += l2->val;

		tmp->val += carry;

		if (tmp->val > 9) {
			carry = 1;
			tmp->val = tmp->val % 10;
		} else {
			carry = 0;
		}

		if (l1) {
			l1 = l1->next;
		}
		if (l2) {
			l2 = l2->next;
		}

		if (l1 || l2 || carry) {
			tmp->next = malloc(sizeof(struct ListNode));
			tmp = tmp->next;
		}
	}
	return ans;    
}

//time: O(n)
