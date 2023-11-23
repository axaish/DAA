#include <stdio.h>
#include <stdlib.h>
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
int maxSumOfEqualDigits(int nums[], int size)
{
    int maxSum = -1;
    for (int i = 0; i < size; i++)
	{
        for (int j = i + 1; j < size; j++)
		{
            if (sumOfDigits(nums[i]) == sumOfDigits(nums[j]))
			{
                int currentSum = nums[i] + nums[j];
                if (currentSum > maxSum)
				{
                    maxSum = currentSum;
                }
            }
        }
    }
    return maxSum;
}
int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int nums[size];
    printf("Enter %d positive integers: ", size);
    for (int i = 0; i < size; i++)
	{
        scanf("%d", &nums[i]);
    }
    int result = maxSumOfEqualDigits(nums, size);
    if (result == -1)
	{
        printf("No two numbers have the same sum of digits.\n");
    }
	else
	{
        printf("Maximum value of nums[i] + nums[j] with equal sum of digits: %d\n", result);
    }
    return 0;
}
