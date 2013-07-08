
// stack.h
// 双链表数据结构C++模块的实现

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;
namespace _Stack
{
    template<typename Type>
        class Stack;
    // 栈中的元素
    template<typename Type>
        class StackNode
        {
            public:
                StackNode()
                {
                    this->mElement = 0;
                    this->mpNext = NULL;
                    this->mpPrev = NULL;
                }

                ~StackNode()
                {
                    this->mElement = 0;
                    this->mpNext = NULL;
                    this->mpPrev = NULL;
                }

                Type& getElement()
                {
                    return mElement;
                }

                /*
                friend ostream& operator << (ostream &ost, StackNode<Type> &src)
                {
                    ost << src.mElement;
                    return ost;
                }
                */

            protected:
                Type mElement;
                StackNode<Type> *mpNext;
                StackNode<Type> *mpPrev;
                friend class Stack<Type>;
        };

    template<typename Type>
        class Stack
        {
            public:
                Stack();
                ~Stack();
                bool push(const Type& element);
                Type pop();
                bool isEmpty();
                bool clear();
                int size();
/*                friend ostream& operator << (ostream& ost, Stack<Type>& src)
                {
                    StackNode<Type>* pNode = src.mpTop;
                    while(src.mpHead)
                    {
                        ost << *pNode << " ";
                        pNode = pNode->mpPrev;
                    }
                    return ost;
                }
                */

            protected:
                StackNode<Type> *createNode(const Type& element);

            protected:
                StackNode<Type> *mpHead;
                StackNode<Type> *mpTop;
        };

}

#endif
