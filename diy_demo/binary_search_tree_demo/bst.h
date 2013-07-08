
#ifndef _BST_H
#define _BST_H

namespace _Bst
{
    template<typename Element>
        class Bst;
    template<typename Element>
        class BstNode
        {
            public:
                //Element key;
                //BstNode<Element>* lchild;
                //BstNode<Element>* rchild;
                BstNode(Element value) : key(value),lchild(NULL),rchild(NULL){};
                ~BstNode(){lchild = NULL; rchild = NULL;}
            protected:
                Element key;
                BstNode<Element>* lchild;
                BstNode<Element>* rchild;
                friend class Bst<Element>;
        };

    template<typename Element>
        class Bst
        {
            public:
                Bst(){root = NULL;}
                ~Bst(){root = NULL;}

            public:
                bool empty();
                bool insertNode(Element& value);
                void inOrder(BstNode<Element>* root);
                BstNode<Element>* minNode(BstNode<Element>* root);
                BstNode<Element>* maxNode(BstNode<Element>* root);
                BstNode<Element>* search(Element& value);
                bool deleteNode(Element& value);
                BstNode<Element>* parent(BstNode<Element>* child);
                BstNode<Element>* postNode(BstNode<Element>* node);

            public:
                BstNode<Element>* root;
        };
}

#endif
