
#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include "sort.h"

class ShellSort : public Sort
{
    public:
        ShellSort();
        virtual ~ShellSort();

        virtual void sort(double *, const int);
        void shellPass(double *, int, int);
};

#endif
