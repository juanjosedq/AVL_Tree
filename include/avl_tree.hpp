#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <algorithm>
#include <string.h>
#include <iostream>
#include <list>

using namespace std;

class node
{
    public: 
    int id;
    string name;
    int L_max_height;
    int R_max_height;
    node *Left_Child;
    node *Right_Child;
    node *Parent;

    node(string xname, int xid, node *P)
    {
        name = xname;
        id = xid;
        Parent = P;
        Left_Child = nullptr;
        Right_Child = nullptr;
        R_max_height = 0;
        L_max_height = 0;

    }

};

class avl_tree
{
    private:
    
    list<int> buffer;

    node* R_Left_Left( node* y );
    node* R_Right_Right( node* y );
    node* R_Left_Right( node* z );
    node* R_Right_Left( node* z );

    void Compare( node* new_node, node* current_node );
    void Fix_k( node* new_node );
    node* Evaluate_k( node* new_node);

    public:

    node* root;

    avl_tree( void );
    ~avl_tree( void );
    int Insert( string name, int id );
    void Print( node* start, int contador);

};

#endif //AVL_TREE_H