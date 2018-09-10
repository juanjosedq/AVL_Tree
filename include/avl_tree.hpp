#ifndef AVL_TREE_H
#define AVL_TREE_H

struct node
{
    int data;
    int height;
    node *Left_Child;
    node *Right_Child;
    node *Parent_Child;

    node(int data, node *P)
        : data( data )
        ; Parent_Child( P )
        ; height( 0 )
        ; Left_Child( NULL )
        ; Right_Child( NULL )
    {
    }

};

class avl_tree
{
    private:

    public:

}

#endif // AVL_TREE_H