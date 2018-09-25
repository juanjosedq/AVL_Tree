#include "avl_tree.hpp"
#include <ctime>

using namespace std;

int main()
{
    unsigned t0, t1;
    t0=clock();

    avl_tree my_tree( "../misc/input/lista_10.txt" );

    ofstream fs( "../misc/output/max_and_min_10.txt" );
    node* temp = my_tree.avl_tree_find_max( my_tree.root );
    fs << "Mayor cédula: " << temp->id;
    fs << " Nombre: " << temp->name << endl;
    temp = my_tree.avl_tree_find_min( my_tree.root );
    fs << "Menor cédula: " << temp->id;
    fs << " Nombre: " << temp->name << endl;
    fs.close();

    my_tree.~avl_tree();

    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);

    ofstream fs2( "../misc/data/run_time_10.txt" );
    fs2 << "Execution Time 10 nodos: " << time << endl;
    fs2.close();
}
