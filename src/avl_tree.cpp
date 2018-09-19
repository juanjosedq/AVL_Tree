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
        node* Evaluator = Evaluate_k( nuevo );

        if( Evaluator != nullptr )
        {
            int var = *this->buffer.begin();
            switch(var)
            {
                case 1:
                    this->buffer.pop_front();
                    if( *this->buffer.begin() == 1 )
                    {
                        R_Right_Right( Evaluator );
                    }
                    else
                    {
                        R_Right_Left( Evaluator );
                    }
                    this->buffer.erase( this->buffer.begin(), this->buffer.end() );
                    break;
                case 0:
                    this->buffer.pop_front();
                    if( *this->buffer.begin() == 0 )
                    {
                        R_Left_Left( Evaluator );
                    }
                    else
                    {
                        R_Left_Right( Evaluator );
                    }
                    this->buffer.erase( this->buffer.begin(), this->buffer.end() );
                    break;
            }
        }
    }
    return 0;
}

void avl_tree::Compare( node* new_node, node* current_node)
{
    if( new_node->id > current_node->id )
    {
        if( current_node->Right_Child != nullptr )
        {
            Compare( new_node, current_node->Right_Child );
        }
        else
        {
            new_node->Parent = current_node;
            current_node->Right_Child = new_node;
            current_node->R_max_height = current_node->R_max_height + 1;
            if( current_node->Left_Child == nullptr )
            {
                Fix_k( new_node->Parent );
            }
        }
    }
    else
    {
        if(  current_node->Left_Child != nullptr )
        {
            Compare( new_node, current_node->Left_Child );
        }
        else
        {
            new_node->Parent = current_node;
            current_node->Left_Child = new_node;
            current_node->L_max_height = current_node->L_max_height + 1;
            if( current_node->Right_Child == nullptr )
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
        if( new_node->Parent->Right_Child != nullptr )
        {
            if( new_node->Parent->Right_Child->id == new_node->id )
            {
                new_node->Parent->R_max_height = max( new_node->R_max_height, new_node->L_max_height ) + 1;
            }
        }
        if( new_node->Parent->Left_Child != nullptr )
        {
            if( new_node->Parent->Left_Child->id == new_node->id )
            {
                new_node->Parent->L_max_height = max( new_node->R_max_height, new_node->L_max_height ) + 1;
            }
        }
        Fix_k( new_node->Parent );
    }
}

node* avl_tree::Evaluate_k( node* new_node )
{
    int k = (new_node->R_max_height) - (new_node->L_max_height);
    if( ( k < -1 ) || ( k > 1 ) )
    {
        cout << "Error de K" << endl;
        cout << new_node->name << new_node->id << endl;
        return new_node;
    }
    else
    {
        if( new_node->Parent != nullptr )
        {
            if( new_node->Parent->Right_Child == new_node )
            {
                this->buffer.push_front(1);
            }
            else{
                this->buffer.push_front(0);
            }
            Evaluate_k( new_node->Parent );
        }
    }
}

node* avl_tree::R_Right_Right( node* y )
{
    node* x = y->Right_Child;
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

    if( y->Right_Child == nullptr )
    {
        y->R_max_height = 0;
    }
    else
    {
        y->R_max_height = max( y->Right_Child->L_max_height, y->Right_Child->R_max_height ) + 1;
    }

    Fix_k( y );
    return x;
}

node* avl_tree::R_Left_Left( node *y )
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

    if( y->Left_Child == nullptr )
    {
        y->L_max_height = 0;
    }
    else
    {
        y->L_max_height = max( y->Left_Child->L_max_height, y->Left_Child->R_max_height ) + 1;
    }

    Fix_k( y );
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

void avl_tree::Print( node* start, int contador)
{
    if( start == nullptr )
    {
        for(int i = 0; i < contador; i++ )
        {
            cout << "      ";
        }
        cout << "null" << endl;
        return;
    }
    else
    {
        Print( start->Right_Child, contador + 2 );
        for(int i = 0; i < contador; i++ )
        {
            cout << "        ";
        }
        int temp = start->R_max_height - start->L_max_height;
        cout << start->name << "-" << start->id << "(" << temp << ")" << endl;
        Print( start->Left_Child, contador + 2 );
    }
}

using namespace std;

int main()
{
    avl_tree my_tree;
    my_tree.Insert( "juan", 50 );
    my_tree.Insert( "jose", 25 );
    my_tree.Insert( "luis", 80 );
    my_tree.Insert( "ana", 10 );
    my_tree.Insert( "maria", 70 );
    my_tree.Insert( "paola", 90 );
    my_tree.Insert( "jazmin", 65 );
    my_tree.Print( my_tree.root, 0 );
    my_tree.Insert( "valeria", 60 );
    //my_tree.Insert( "Marco", 100 );
    //my_tree.Insert( "Giselle", 110 );
    my_tree.Print( my_tree.root, 0 );
}