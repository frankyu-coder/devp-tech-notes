
#include "stack.h"
#include <iostream>

using namespace std;
namespace _Stack
{/*
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
//                friend ostream& operator << (ostream& ost, Stack<Type>& src)
                {
                    StackNode<Type>* pNode = src.mpTop;
                    while(src.mpHead)
                    {
                        ost << *pNode << " ";
                        pNode = pNode->mpPrev;
                    }
                    return ost;
                }
                //

            protected:
                StackNode<Type> *createNode(const Type& element);

            protected:
                StackNode<Type> *mpHead;
                StackNode<Type> *mpTop;
        };
*/
    template<typename Type>
        Stack<Type>::Stack()
        {
            Type i = Type();
            // 创建一个带头节点的双链栈，这个节点不存入任何数据
            this->mpHead = this->createNode(i);
            this->mpTop = this->mpHead;
        }

    template<typename Type>
        Stack<Type>::~Stack()
        {
            this->clear();
            delete this->mpHead;
            this->mpHead = NULL;
            this->mpTop = NULL;
        }

    template<typename Type>
        StackNode<Type>* Stack<Type>::createNode(const Type& element)
        {
            StackNode<Type>* pNode = new StackNode<Type>;
            if (pNode) {
                pNode->mElement = element;
                pNode->mpNext = NULL;
                pNode->mpPrev = NULL;
            }

            return pNode;
        }

    template<typename Type>
        bool Stack<Type>::push(const Type& element)
        {
            StackNode<Type>* pNode = createNode(element);
            if (this->mpHead->mpNext == NULL) {
                this->mpHead->mpNext = pNode;
                pNode->mpPrev = this->mpHead;
            } else {
                this->mpTop->mpNext = pNode;
                pNode->mpPrev = this->mpTop;
            }
            this->mpTop = pNode;
            return true;
        }

    template<typename Type>
        Type Stack<Type>::pop()
        {
            if (this->mpTop != this->mpHead) {
                StackNode<Type>* pNode = this->mpTop;
                this->mpTop = this->mpTop->mpPrev;
                Type elem = pNode->mElement;
                pNode->mpNext = pNode->mpPrev = NULL;
                pNode = NULL;
                return elem;
            }

            return (Type)0;
        }

    template<typename Type>
        bool Stack<Type>::isEmpty()
        {
            return (this->mpHead == this->mpTop);
        }

    template<typename Type>
        bool Stack<Type>::clear()
        {
            StackNode<Type>* pNode = this->mpTop;
            while((pNode = this->mpTop) != this->mpHead)
            {
                this->mpTop = pNode->mpPrev;
                pNode->mpNext = NULL;
                pNode->mpPrev = NULL;
                delete pNode;
                pNode = NULL;
            }

            return true;
        }

    template<typename Type>
        int Stack<Type>::size()
        {
            int iCount = 0;
            StackNode<Type>* pNode = this->mpTop;
            while(pNode != this->mpHead)
            {
                iCount++;
                cout << iCount << "|";
                pNode = pNode->mpPrev;
            }
            cout << endl;
            cout << "iCount =" << iCount << endl;
            return iCount;
        }
/*
    template<typename Type>
        ostream& operator <<(ostream& ost, Stack<Type>& src)
        {
            StackNode<Type>* pNode = src.mpTop;

            while(src.mpHead)
            {
                //ost << *pNode << " ";
                pNode = pNode->mpPrev;
            }

            return ost;
        }
    */
}
