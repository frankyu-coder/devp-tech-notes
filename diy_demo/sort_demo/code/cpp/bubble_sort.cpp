
#include "bubble_sort.h"

class BubbleSort::PrivateData
{
    public:
        //
};

BubbleSort::BubbleSort()
{
    m_data = new PrivateData;
}

BubbleSort::~BubbleSort()
{
    delete m_data;
}

void BubbleSort::swap(double &num1, double &num2)
{
    double tmp = num1;
    num1 = num2;
    num2 = tmp;
}

void BubbleSort::sort(double *ptr, int num)
{
    for (int i = 0; i < num; ++i) {
	for (int j = num - 1; j > i; j--) {
	    if (ptr[j] < ptr[j-1])
		swap(ptr[j], ptr[j-1]);
    }
    }
} //冒泡排序（稳定，O(n^2)）

