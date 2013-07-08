
// queue.h
// 双链表队列数据结构C++模块的实现

#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

namespace _Queue
{
    // 队列中的数据元素
    template<typename T>
        class QueueNode
        {
            public:
                QueueNode()
                {
                    this->mElement = 0;
                    this->mpNext = NULL;
                    this->mpPrev = NULL;
                }

                T mElement;
                QueueNode *mpNext;
                QueueNode *mpPrev;
        };

    template<typename T>
        class Queue
        {
            public:
                Queue()
                {
                    QueueNode<T> *pNode = new QueueNode<T>;
                    pNode->mElement = T(-1);
                    pNode->mpNext = NULL;
                    pNode->mpPrev = NULL;
                    this->mpHead = this->mpTail = pNode;
                }

                ~Queue()
                {
                    this->clear();
                    delete this->mpHead;
                    this->mpHead = this->mpTail = NULL;
                }

                bool insert(T element);
                T front();
                T back();
                bool isEmpty();
                bool clear();
                int size();

                friend ostream& operator << (ostream& ostr, const Queue<T>& q)
                {
                    QueueNode<T>* pNode = q.mpHead->mpNext;
                    while(pNode != NULL)
                    {
                        ostr << pNode->mElement << ",";
                        pNode = pNode->mpNext;
                    }

                    return ostr;
                }
            private:
                QueueNode<T>* mpHead;
                QueueNode<T>* mpTail;
        };

    template<typename T>
        bool Queue<T>::insert(T element)
        {
            QueueNode<T> *pNode = new QueueNode<T>;
            if (pNode == NULL)
                return false;

            pNode->mElement = element;

            this->mpTail->mpNext = pNode;
            pNode->mpPrev = this->mpTail;
            this->mpTail = this->mpTail->mpNext;

            return true;
        }

    template<typename T>
        T Queue<T>::front()
        {
            T element = T();
            QueueNode<T>* pNode = NULL;
            if (!this->isEmpty()) {
                pNode = this->mpHead->mpNext;
                element = pNode->mElement;
                this->mpHead->mpNext = pNode->mpNext;
                if (pNode->mpNext)
                    pNode->mpNext->mpPrev = this->mpHead;
                if (pNode == this->mpTail)
                    this->mpTail = this->mpHead;
                delete pNode;
            }
            
            return element;
        }

    template<typename T>
        T Queue<T>::back()
        {
            T element = T();
            QueueNode<T>* pNode = NULL;
            if (!this->isEmpty()) {
                pNode = this->mpTail;
                element = pNode->mElement;
                this->mpTail = this->mpTail->mpPrev;
                this->mpTail->mpNext = NULL;
                delete pNode;
            }

            return element;
        }

    template<typename T>
        bool Queue<T>::isEmpty()
        {
            return (this->mpTail == this->mpHead);
        }

    template<typename T>
        bool Queue<T>::clear()
        {
            while(!this->isEmpty())
                this->back();
            return true;
        }

    template<typename T>
        int Queue<T>::size()
        {
            int iCount = 0;
            if (!this->isEmpty()) {
                QueueNode<T>* pNode = this->mpTail;
                while(pNode != this->mpHead)
                {
                    iCount++;
                    pNode = pNode->mpPrev;
                }
            }

            return iCount;
        }
/*
    template<typename T>
        ostream& operator << <>(ostream& ostr, const Queue<T>& q)
        {
            QueueNode<T>* pNode = q.mpHead->mpNext;
            while(pNode != NULL)
            {
                ostr << pNode->mElement << ",";
                pNode = pNode->mpNext;
            }

            return ostr;
        }
        */
}

#endif
