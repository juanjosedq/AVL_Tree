#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <algorithm>

using namespace std;

class node
{
    public: 
    int Data;
    int K_balance;
    int Height;
    node *Left_Child;
    node *Right_Child;
    node *Parent;

    node(int data, node *P)
    {
        Data = data;
        Parent = P;
        K_balance = 0;
        Left_Child = nullptr;
        Right_Child = nullptr;

        if(Parent == nullptr)
        {
            Height = 0;
        }
        else
        {
            Height = P->Height - 1;
        }

    }

};

class avl_tree
{
    private:

    node *root;
    int height;

    node* R_Left_Left( node *y );
    node* R_Right_Right( node *y );
    node* R_Left_Right( node *y );
    node* R_Right_Left( node *y );

    int H_max( node *n );
    bool Calculate_K( node *n );

    public:

    avl_tree( void );
    ~avl_tree( void );

    bool Insert( int data );

};

#endif //AVL_TREE_H