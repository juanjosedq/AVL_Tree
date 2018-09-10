#include "../include/avl_tree.hpp"

avl_tree::avl_tree( void )
    : root( nullptr )
{
}

avl_tree::~avl_tree( void )
{
    delete root;
}

struct node* avl_tree::R_Right( struct node *y )
{
    struct node *x = y->Left_Child;
    x->Parent = y->Parent;
    y ->Left_Child = x->Right_Child;

    if(y->Left_Child != nullptr)
    {
        y->Left_Child->Parent = y;
    }

    x->Right_Child = y;
    y->Parent = x;

    if(x->Parent != nullptr)
    {
        if(x->Parent->Left_Child == y)
        {
            x->Parent->Left_Child = x;
        }
        else
        {
            x->Parent->Right_Child = x;
        }
    }

    return x;

}

void avl_tree::Calculate_height( struct node *n )
{
    n->height = 
}