#include "../include/avl_tree.hpp"

avl_tree::avl_tree( void )
    : root( nullptr )
{
}

avl_tree::~avl_tree( void )
{
    delete root;
}

node* avl_tree::R_Left_Left( node *y )
{
    node *x = y->Right_Child;
    x->Parent = y->Parent;
    y->Right_Child = x->Left_Child;

    if(y->Right_Child != nullptr)
    {
        y->Right_Child->Parent = y;
    }

    x->Left_Child = y;
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

    //Calculate_K( root );

    return x;

}

node* avl_tree::R_Right_Right( node *y )
{
    node *x = y->Left_Child;
    x->Parent = y->Parent;
    y->Left_Child = x->Right_Child;

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

    //Calculate_K( root );

    return x;

}

node* avl_tree::R_Right_Left( node *z )
{
      z->Right_Child = R_Right_Right( z->Right_Child );
      return R_Left_Left( z );
}

node* avl_tree::R_Left_Right( node *z )
{
      z->Left_Child = R_Left_Left( z->Left_Child );
      return R_Right_Right( z );
}

bool avl_tree::Calculate_K( node *n )
{
    n->K_balance = H_max( n->Right_Child ) - H_max( n->Left_Child );
    if( n->Left_Child != nullptr || n->Right_Child != nullptr )
    {
        Calculate_K( n->Left_Child );
        Calculate_K( n->Right_Child );
    }
    else
    {
        n->K_balance = 0;
        return true;
    }
}

int avl_tree::H_max( node *n )
{
    if( n->Left_Child != nullptr || n->Right_Child != nullptr)
    {
        return max(H_max(n->Left_Child), H_max(n->Left_Child));
    }
    else
    {
        return n->Height;
    }
}