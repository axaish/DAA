#include <stdio.h>
#include <stdbool.h>
int sumOfDigits(int num)
{
    int sum = 0;
    while (num > 0)
	{
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int maxSum(int nums[], int size)
{
    int max_sum = 0;
    bool pair_found[size];
    for (int i = 0; i < size; i++)
	{
        pair_found[i] = false;
    }
    for (int i = 0; i < size; i++)
	{
        int sum1 = sumOfDigits(nums[i]);
        for (int j = i + 1; j < size; j++)
		{
            int sum2 = sumOfDigits(nums[j]);
            if (sum1 == sum2 && !pair_found[j])
			{
                max_sum = nums[i] + nums[j];
                pair_found[j] = true;
            }
        }
    }
    return max_sum;
}
int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int nums[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
	{
        scanf("%d", &nums[i]);
    }
    int max_sum = maxSum(nums, size);
    printf("The maximum sum of the two numbers that have the same sum of digits is: %d\n", max_sum);
    return 0;
}
