#include "avl_tree.hpp"
#include <ctime>

using namespace std;

int main()
{
    //Crear un arbol vacio
    avl_tree my_tree;

    //Insertar 10 elementos
    my_tree.avl_tree_insert("name", 50);
    my_tree.avl_tree_insert("name", 25);
    my_tree.avl_tree_insert("name", 80);
    my_tree.avl_tree_insert("name", 10);
    my_tree.avl_tree_insert("name", 70);
    my_tree.avl_tree_insert("name", 90);
    my_tree.avl_tree_insert("name", 65);
    my_tree.avl_tree_insert("name", 60);
    my_tree.avl_tree_insert("name", 102);
    my_tree.avl_tree_insert("name", 2);

    //consultar el tamaño del arbol
    cout << "Numero de elementos: " << my_tree.avl_tree_get_size() << endl;

    //Obtener el máximo
    cout << "El maximo elemento es: " << my_tree.avl_tree_find_max( my_tree.root )->id << endl;

    //Obtener el minimo
    cout << "El minimo elemento es: " << my_tree.avl_tree_find_min( my_tree.root )->id << endl;

}