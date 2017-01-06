/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target)
{
	int i, j;
	int* ans = malloc(sizeof(int) * 2);
	for (i = 0; i < numsSize; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if ((nums[i] + nums[j]) == target) {
				ans[0] = i;
				ans[1] = j;
				return ans;
			}
		}
	}
	return ans;
}

//time: O(n^2)

/* Draft 
int* twoSum(int* nums, int numsSize, int target)
{
	find the smallest number "bias"

	if smallest number < 0
	all the number in nums add the bias
	to make sure all the number > 0
	(maybe this is no need)

	use a array with size (bias + target)
	initiate it with all -1

	for each number nums[i]
		find the diverse btw target and nums
		if (array[diverse] != -1)
			the answer is nums index and array[diverse]
		else 
			array[diverse] = i (i is the index of the current number)
}
*/
//time: O(n)
