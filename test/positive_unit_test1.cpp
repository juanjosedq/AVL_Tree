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
    my_tree.avl_tree_insert("name", 10);
    my_tree.avl_tree_insert("name", 70);
    my_tree.avl_tree_insert("name", 90);
    my_tree.avl_tree_insert("name", 65);

    //Imprimir arbol de forma horizontal
    my_tree.avl_tree_print(my_tree.root, 0);
    cout << "--------------------------------------------------------------------------------------------------" << endl;

    //Insertar elemento que causa desbalanceo
    my_tree.avl_tree_insert("name", 60);

    //Imprimir para comprobar rotaciones (auto-balanceo)
    my_tree.avl_tree_print(my_tree.root, 0);

}