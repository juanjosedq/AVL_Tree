#include "avl_tree.hpp"
#include <ctime>

using namespace std;

int main()
{
    //Crear un arbol vacio
    avl_tree my_tree;

    //Insertar elementos
    my_tree.avl_tree_insert("name", 50);
    my_tree.avl_tree_insert("name", 25);
    my_tree.avl_tree_insert("name", 80);

    //Imprimir elemento repetido
    my_tree.avl_tree_insert("name", 50);
    my_tree.avl_tree_insert("name", 25);

}