
#ifndef SORT_H
#define SORT_H

class Sort
{
    public:
	Sort();
	virtual ~Sort();
	virtual void sort(double *arr, const int size) = 0;	
};

#endif
