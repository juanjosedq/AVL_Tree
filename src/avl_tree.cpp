#include "../include/avl_tree.hpp"

avl_tree::avl_tree( void )
    : root( nullptr )
{
}

avl_tree::~avl_tree( void )
{
    delete root;
}

int avl_tree::Insert( string name, int id )
{
    node* nuevo = new node( name, id, nullptr);

    if( this->root == nullptr )
    {
        this->root = nuevo;
    }
    else
    {
        Compare( nuevo, this->root );
        Evaluate_k( nuevo );
    }
}

void avl_tree::Compare( node* new_node, node* current_node)
{
    if( new_node->id > current_node->id )
    {
        current_node->K_balance = ( current_node->K_balance ) + 1;
        if( current_node->Right_Child != nullptr )
        {
            Compare( new_node, current_node->Right_Child );
        }
        else
        {
            new_node->Parent = current_node;
            current_node->Right_Child = new_node;
            if( current_node->Left_Child != nullptr )
            {
                Fix_k( new_node->Parent );
            }
        }
    }
    else
    {
        current_node->K_balance = ( current_node->K_balance ) - 1;
        if(  current_node->Left_Child != nullptr )
        {
            Compare( new_node, current_node->Left_Child );
        }
        else
        {
            new_node->Parent = current_node;
            current_node->Left_Child = new_node;
            if( current_node->Right_Child != nullptr )
            {
                Fix_k( new_node->Parent );
            }
        }
    }
}

void avl_tree::Fix_k( node* new_node )
{
    if( new_node->Parent != nullptr )
    {
        if( new_node->Parent->Right_Child->id == new_node->id )
        {
            new_node->Parent->K_balance = ( new_node->Parent->K_balance ) -1;
        }
        else
        {
            new_node->Parent->K_balance = ( new_node->Parent->K_balance ) +1;
        }
        Fix_k( new_node->Parent );
    }
}

node* avl_tree::Evaluate_k( node* new_node )
{
    if( ( new_node->K_balance < -1 ) || ( new_node->K_balance > 1 ) )
    {
        cout << "Error de K" << endl;
        cout << new_node->name << new_node->id << endl;
        return nullptr;
    }
    else
    {
        if( new_node->Parent != nullptr )
        {
            Evaluate_k( new_node->Parent );
        }
        return nullptr;
    }
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

using namespace std;

int main()
{
    avl_tree my_tree;
    my_tree.Insert( "juan", 50 );
    cout << my_tree.root->K_balance << endl;
    my_tree.Insert( "jose", 25 );
    cout << my_tree.root->K_balance << endl;
    my_tree.Insert( "luis", 80 );
    cout << my_tree.root->K_balance << endl;
    my_tree.Insert( "ana", 10 );
    cout << my_tree.root->K_balance << endl;
    my_tree.Insert( "maria", 70 );
    cout << my_tree.root->K_balance << endl;
    my_tree.Insert( "paola", 90 );
    cout << my_tree.root->K_balance << endl;
    my_tree.Insert( "jazmin", 65 );
    cout << my_tree.root->K_balance << endl;
    my_tree.Insert( "valeria", 60 );
    cout << my_tree.root->K_balance << endl;
}