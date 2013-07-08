
#include "quick_sort.h"

QuickSort::QuickSort()
{

}

QuickSort::~QuickSort()
{

}

void QuickSort::sort(double *arr, const int size)
{
    if (!arr)
        return;
    quickSort(arr, 0, size-1);
}

void QuickSort::quickSort(double *arr, int low, int high)
{
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
} //快速排序（时间复杂度(O(n^2)),不稳定）

int QuickSort::partition(double *arr, int low, int high)
{
    int pivot = arr[low];
    while(low < high) {
        while(low < high && arr[high] >= pivot)
            high --;
        arr[low] = arr[high];
        while(low < high && arr[low] <= pivot)
            low ++;
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}
