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

	use a array with size (target - bias)
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

//TODO: run -1 -2 -3 -4 -5 with target -8 will cause runtime error
int* twoSum(int* nums, int numsSize, int target)
{
	int i;
	int bias;
	int* ans;
	ans = malloc(sizeof(int) * 2);

	bias = nums[0];

	//find the smallest number
	for (i = 1; i < numsSize; i++) {
		if (nums[i] < bias)
			bias = nums[i];
	}

	int sub;
	int record[target - bias + 1];
	memset(record, -1, sizeof(record));

	for (i = 0; i < numsSize; i++) {
		if (record[nums[i]] != -1) {
			break;
		} else {
			sub = target - nums[i];
			record[sub] = i;
		}
	}

	ans[0] = record[nums[i]];
	ans[1] = i;

	return ans;
}
//time: O(n)
