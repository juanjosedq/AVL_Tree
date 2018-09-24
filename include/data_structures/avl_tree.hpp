#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <list>
#include <fstream>

using namespace std;

class node
{
    public: 
    unsigned int id; //TODO: Chechk 32bits
    string name;
    int L_max_height;
    int R_max_height;
    node* Left_Child;
    node* Right_Child;
    node* Parent;

    node(string xname, int xid, node* P)
    {
        name = xname;
        id = xid;
        Parent = P;
        Left_Child = nullptr;
        Right_Child = nullptr;
        R_max_height = 0;
        L_max_height = 0;

    }

    ~node( void )
    {
        if( Left_Child != nullptr )
        {
           Left_Child = nullptr;
           delete Left_Child;
        }
        if( Right_Child != nullptr )
        {
            Right_Child = nullptr;
            delete Right_Child;
        }
        if( Parent != nullptr )
        {
            Parent = nullptr;
            delete Parent;
        }
    }

};

class avl_tree
{
    private:
    
    list<int> buffer;
    int size;

    void R_Left_Left( node* y );
    void R_Right_Right( node* y );
    void R_Left_Right( node* z );
    void R_Right_Left( node* z );

    int Compare( node* new_node, node* current_node );
    void Fix_k( node* new_node );
    node* Evaluate_k( node* new_node);

    public:

    node* root;

    avl_tree( void );
    avl_tree( string path );
    ~avl_tree( void );

    void avl_tree_empty( node* root );

    int avl_tree_insert( string name, int id );
    void avl_tree_print( node* start, int contador);
    int avl_tree_get_size( void );
    int avl_tree_get_max_height( void );
    node* avl_tree_find_max( node* root );
    node* avl_tree_find_min( node* root );
};

#endif //AVL_TREE_H
