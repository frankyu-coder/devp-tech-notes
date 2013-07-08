
#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "sort.h"

class QuickSort : public Sort
{
    public:
        QuickSort();
        virtual ~QuickSort();

    public:
        virtual void sort(double *, const int);

    private:
        int partition(double *, int, int);
        void quickSort(double *, int, int);
};

#endif
