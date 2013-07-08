
#include "bst.h"
#include <iostream>

using namespace std;
namespace _Bst
{
    template<typename Element>
        bool Bst<Element>::empty()
        {
            return root == NULL;
        }

    template<typename Element>
        bool Bst<Element>::insertNode(Element& value)
        {   
            BstNode<Element>* p = root;
            BstNode<Element>* q = NULL;
            while(p != NULL)
            {
                q = p;
                if (value < p->key)
                    p = p->lchild;
                else
                    p = p->rchild;
            }

            if (NULL == q) {
                root = new BstNode<Element>(value);
                return true;
            } else if (value < q->key) {
                q->lchild = new BstNode<Element>(value);
                return true;
            } else{
                q->rchild = new BstNode<Element>(value);
                return true;
            }

            return false;
        }

    template<typename Element>
        void Bst<Element>::inOrder(BstNode<Element>* root)
        {
            if (root != NULL) {
                inOrder(root->lchild);
                cout << root->key << endl;
                inOrder(root->rchild);
            }
        }

    template<typename Element>
        BstNode<Element>* Bst<Element>::search(Element& value)
        {
            BstNode<Element>* p = root;
            while(p != NULL && p->key != value)
            {
                if (value < p->key)
                    p = p->lchild;
                else
                    p = p->rchild;
            }

            return p;
        }

    template<typename Element>
        BstNode<Element>* Bst<Element>::parent(BstNode<Element>* child)
        {
            BstNode<Element>* p = root;
            BstNode<Element>* q = NULL;
            while(p != NULL && p->key != child->key)
            {
                q = p;
                if (p->key > child->key) {
                    p = p->lchild;
                } else {
                    p = p->rchild;
                }
            }

            return q;
        }

    template<typename Element>
        BstNode<Element>* Bst<Element>::minNode(BstNode<Element>* root)
        {
            BstNode<Element> *p = root;
            while(p->lchild != NULL)
            {
                p = p->lchild;
            }

            return p;
        }

    template<typename Element>
        BstNode<Element>* Bst<Element>::maxNode(BstNode<Element>* root)
        {
            BstNode<Element>* p = root;
            while(p->rchild != NULL)
            {
                p = p->rchild;
            }

            return p;
        }

    template<typename Element>
        BstNode<Element>* Bst<Element>::postNode(BstNode<Element>* node)
        {
            if (node->rchild != NULL)
                return minNode(node->rchild);

            BstNode<Element>* p = node;
            BstNode<Element>* pare = parent(p);
            while(pare != NULL && pare->rchild == p)
            {
                p = pare;
                pare = parent(p);
            }

            return pare;
        }

    template<typename Element>
        bool Bst<Element>::deleteNode(Element& value)
        {
            BstNode<Element>* p = search(value);
            BstNode<Element>* q = NULL; // 要删除的节点
            BstNode<Element>* s = NULL; // 要删除节点的父节点
            if (p->lchild == NULL || p->rchild == NULL) {
                q = p;
            } else {
                q = postNode(p); // 第三种情况，左右子树都不为NULL
            }

            s = parent(q);
            if (q->lchild != NULL) {
                if (s != NULL && s->lchild == q)
                    s->lchild = q->lchild;
                else if (s != NULL && s->rchild == q)
                    s->rchild = q->lchild;
            } else {
                if (s != NULL && s->lchild == q)
                    s->lchild = q->rchild;
                else if (s != NULL && s->rchild == q)
                    s->rchild = q->rchild;
            }

            if (s == NULL)
                root->key = q->key;

            if (q != p)
                p->key = q->key;

            delete q;
            return true;
        }

}
