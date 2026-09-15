#include<stdint.h>
#include<stdio.h>

void insert_sort(int32_t* arr, int32_t n)
{
	for (int32_t i = 1;i < n;i++)
	{
		int32_t temp = arr[i];
		int32_t j = i - 1;
		for (j;j >= 0;j--)
		{
			if (temp<arr[j])
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j + 1] = temp;
	}
}

void shell_sort(int32_t* arr, int32_t n)
{
	for (int32_t gap = n / 2;gap > 0;gap /= 2)
	{
		for (int32_t i = gap;i < n;i++)
		{
			int32_t temp = arr[i];
			int32_t j = i - gap;
			for (j;j >= 0;j -= gap)
			{
				if (temp < arr[j])
				{
					arr[j + gap] = arr[j];
				}
				else
				{
					break;
				}
			}
			arr[j + gap] = temp;
		}
	}
}

void bubble_sort(int32_t* arr, int32_t n)
{
	for (int32_t i = 0;i < n - 1;i++)
	{
		for (int32_t j = 0;j < n - 1 - i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int32_t temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void quick_sort(int32_t* arr, int32_t left, int32_t right)
{
	
	if (left >= right)
	{
		return;
	}
	int32_t l = left;
	int32_t r = right;
	int32_t base = arr[left];
	while (l < r)
	{
		for (;arr[r] >= base && r > l;r--);
		arr[l] = arr[r];
		for (;arr[l] <= base && r > l;l++);
		arr[r] = arr[l];
	}
	arr[l] = base;

	quick_sort(arr, left, l - 1);
	quick_sort(arr, l + 1, right);
}


int32_t main()
{
	int32_t arr[10] = { 5,3,8,6,2,7,4,1,9,0 };
	quick_sort(arr, 0,9);
	for (uint32_t i = 0;i < 10;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}