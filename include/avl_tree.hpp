#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;

class node
{
    public: 
    int id;
    string name;
    int K_balance;
    int Height;
    node *Left_Child;
    node *Right_Child;
    node *Parent;

    node(string xname, int xid, node *P)
    {
        name = xname;
        id = xid;
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

    
    int height;

    node* R_Left_Left( node* y );
    node* R_Right_Right( node* y );
    node* R_Left_Right( node* z );
    node* R_Right_Left( node* z );

    void Compare( node* new_node, node* current_node );
    void Fix_k( node* new_node );
    node* Evaluate_k( node* new_node);

    int H_max( node* n );
    bool Calculate_K( node* n );

    public:

    node* root;

    avl_tree( void );
    ~avl_tree( void );

    int Insert( string name, int id );

};

#endif //AVL_TREE_H