
#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H
#include "sort.h"

class SelectionSort : public Sort
{
    public:
        SelectionSort();
        virtual ~SelectionSort();

        virtual void sort(double *, const int);
};

#endif
