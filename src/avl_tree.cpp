#include "avl_tree.hpp"

avl_tree::avl_tree( void )
    : root( nullptr )
{
}

avl_tree::avl_tree( string path )
{
    root = nullptr;
    string linea;
    ifstream ficheroEntrada;

    string name = "X0X";
    string id = "X0X";
    int number;

    ficheroEntrada.open( path );
    while( std::getline( ficheroEntrada, linea ) )
    {
        std::stringstream stream(linea);
        string frase;

        while( getline(stream, frase, ','))
        {
            if( name == "X0X" )
            {
                name = frase;
            }
            else
            {
                id = frase;
                if( id.size() < 11 )
                {
                    number = stoi( id );
                    this->avl_tree_insert( name, number );
                }
                else
                {
                    cout << "Error, id inválido" << endl;
                }
                name = "X0X";
                id = "X0X";
            }
        }
    }

    ficheroEntrada.close();
}

avl_tree::~avl_tree( void )
{
    if( this->root->Right_Child != nullptr || this->root->Left_Child != nullptr )
    {

    }
    else
    {
        avl_tree_empty( this->root );
        delete root;
    }
}

void avl_tree::avl_tree_empty( node* x )
{
    if( x != nullptr )
    {
        avl_tree_empty( x->Right_Child );
        avl_tree_empty( x->Left_Child );
        delete x;
    }
}

int avl_tree::avl_tree_get_max_height( void )
{
    return max( root->R_max_height, root->L_max_height ) + 1;
}

int avl_tree::avl_tree_get_size( void )
{
    return size;
}

int avl_tree::avl_tree_insert( string name, int id )
{
    node* nuevo = new node( name, id, nullptr);

    if( this->root == nullptr )
    {
        this->root = nuevo;
        size = size + 1;
    }
    else
    {
        if( Compare( nuevo, this->root ) )
        {
            cout << "Error id ya existe" << endl;
            return 1;
        }
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
                default: {}
            }
        }
        size = size + 1;
    }
    return 0;
}

int avl_tree::Compare( node* new_node, node* current_node)
{
    if( new_node->id > current_node->id )
    {
        if( current_node->Right_Child != nullptr )
        {
            if( Compare( new_node, current_node->Right_Child ) )
            {
                return 1;
            }
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
    else if( new_node->id < current_node->id )
    {
        if(  current_node->Left_Child != nullptr )
        {
            if( Compare( new_node, current_node->Left_Child ) )
            {
                return 1;
            }
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
    else
    {
        return 1;
    }
    return 0;
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
            else
            {
                this->buffer.push_front(0);
            }
            return Evaluate_k( new_node->Parent );
        }
        else
        {
            return nullptr;
        }
    }
}

void avl_tree::R_Right_Right( node* z )
{
    node* y = z->Right_Child;
    y->Parent = z->Parent;
    z->Right_Child = y->Left_Child;

    if(z->Right_Child != nullptr)
    {
        z->Right_Child->Parent = z;
    }

    y->Left_Child = z;
    z->Parent = y;

    if(y->Parent != nullptr)
    {
        if(y->Parent->Left_Child == z)
        {
            y->Parent->Left_Child = y;
        }
        else
        {
            y->Parent->Right_Child = y;
        }
    }
    else
    {
        this->root = y;
    }

    if( z->Right_Child == nullptr )
    {
        z->R_max_height = 0;
    }
    else
    {
        z->R_max_height = max( z->Right_Child->L_max_height, z->Right_Child->R_max_height ) + 1;
    }

    y->L_max_height = max( z->R_max_height, z->L_max_height ) + 1;

    Fix_k( z ); //TODO: Check if it is necessary
}

void avl_tree::R_Left_Left( node* z )
{
    node* y = z->Left_Child;
    y->Parent = z->Parent;
    z->Left_Child = y->Right_Child;

    if(z->Left_Child != nullptr)
    {
        z->Left_Child->Parent = z;
    }

    y->Right_Child = z;
    z->Parent = y;

    if(y->Parent != nullptr)
    {
        if(y->Parent->Left_Child == z)
        {
            y->Parent->Left_Child = y;
        }
        else
        {
            y->Parent->Right_Child = y;
        }
    }
    else
    {
        this->root = y;
    }

    if( z->Left_Child == nullptr )
    {
        z->L_max_height = 0;
    }
    else
    {
        z->L_max_height = max( z->Left_Child->L_max_height, z->Left_Child->R_max_height ) + 1;
    }

    y->R_max_height = max( z->R_max_height, z->L_max_height ) + 1;

    Fix_k( z ); //TODO: Check if it is necessary
}

void avl_tree::R_Right_Left( node* z )
{   
      R_Left_Left( z->Right_Child );
      R_Right_Right( z );
}

void avl_tree::R_Left_Right( node* z )
{
      R_Right_Right( z->Left_Child );
      R_Left_Left( z );
}

void avl_tree::avl_tree_print( node* start, int contador)
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
        avl_tree_print( start->Right_Child, contador + 2 );
        for(int i = 0; i < contador; i++ )
        {
            cout << "        ";
        }
        int temp = start->R_max_height - start->L_max_height;
        cout << start->name << "-" << start->id << "(" << temp << ")" << endl;
        avl_tree_print( start->Left_Child, contador + 2 );
    }
}

node* avl_tree::avl_tree_find_max( node* x )
{
    if( x == nullptr )
    {
        return nullptr;
    }
    else if( x->Right_Child == nullptr )
    {
        return x;
    }
    else
    {
        return avl_tree_find_max(x->Right_Child);
    }
}

node* avl_tree::avl_tree_find_min( node* x )
{
    if( x == nullptr )
    {
        return nullptr;
    }
    else if( x->Left_Child == nullptr )
    {
        return x;
    }
    else
    {
        return avl_tree_find_min(x->Left_Child);
    }
}
