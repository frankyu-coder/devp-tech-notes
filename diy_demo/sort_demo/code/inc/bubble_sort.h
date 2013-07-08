
#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "sort.h"

class BubbleSort : public Sort
{
    public:
	BubbleSort();
	virtual ~BubbleSort();

    public:
	void swap(double &, double &);
	virtual void sort(double *, int); // ц╟ещеепР

    private:
	class PrivateData;
	PrivateData *m_data;

};

#endif
