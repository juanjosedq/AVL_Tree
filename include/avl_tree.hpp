#ifndef AVL_TREE_H
#define AVL_TREE_H

struct node
{
    int data;
    int height;
    node *Left_Child;
    node *Right_Child;
    node *Parent;

    node(int data, node *P)
        : data( data )
        ; Parent( P )
        ; height( 0 )
        ; Left_Child( NULL )
        ; Right_Child( NULL )
    {
    }

};

class avl_tree
{
    private:

    struct node *root;
    int height;

    struct node* R_Left( struct node *y );
    struct node* R_Right( struct node *y );

    struct node* R_Left_Left( struct node *y );
    struct node* R_Right_Right( struct node *y );
    struct node* R_Left_Right( struct node *y );
    struct node* R_Right_Left( struct node *y );

    void Calculate_height( struct node *n );

    public:

    avl_tree( void );
    ~avl_tree( void );

    bool Insert( int data );

}

#endif // AVL_TREE_H