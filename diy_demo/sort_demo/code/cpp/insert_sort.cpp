
#include "insert_sort.h"

InsertSort::InsertSort()
{

}

InsertSort::~InsertSort()
{

}

void InsertSort::sort(double *arr, const int size)
{
    if (!arr)
	return;

    for (int i = 1; i < size; ++i) {
	int tmp = arr[i];
	int low = 0;
	int high = i - 1;
	int mid;
	while (low <= high)
	{
	    mid = (low + high) / 2;
	    if (arr[i] < arr[mid])
		high = mid - 1;
	    else 
		low = mid + 1;
	}

	for (int j = i -1; j >= low; j--) {
	    arr[j+1] = arr[j];
	}

	arr[low] = tmp;
    }
} // 二分插入排序

void InsertSort::directInsertSort(double *arr, const int size)
{
    if (!arr)
	return;
    
    for (int i = 1; i < size; ++i) {
	int tmp = arr[i];
    int j = 0;
	for (j = i - 1; j >= 0 && tmp < arr[j]; j--) {
	    arr[j+1] = arr[j];
	}
	    arr[j] = tmp;
    }
} // 直接插入排序（稳定，时间复杂度：Θ(n^2)）
