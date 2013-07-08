
#ifndef INSERT_SORT_H
#define INSERT_SORT_H

#include "sort.h"

class InsertSort : public Sort
{
    public:
	InsertSort();
	virtual ~InsertSort();

	virtual void sort(double *arr, const int size);
	void directInsertSort(double *arr, const int size);
};

#endif
