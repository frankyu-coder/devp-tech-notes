
#include "selection_sort.h"

SelectionSort::SelectionSort()
{

}

SelectionSort::~SelectionSort()
{

}

void SelectionSort::sort(double *arr, const int size)
{
    if (!arr)
        return;

    for (int i = 0; i < size; i++) {
        int pos = i;
        for (int j = i; j < size; j++) {
            if (arr[pos] > arr[j])
                pos = j;
        }

        double tmp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = tmp;

    }
} //简单选择排序（不稳定，时间复杂度(O(n^2))）
