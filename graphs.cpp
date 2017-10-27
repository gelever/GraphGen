/* A simple example of using linalgcpp
 */

#include "linalgcpp.hpp"
#include "src/graphs.hpp"

using namespace linalgcpp;


int main(int argc, char** argv)
{
    CooMatrix<int> coo;

    coo.AddSym(0, 0, 1.0);
    coo.AddSym(0, 1, -1.0);
    coo.AddSym(1, 1, 1.0);

    BarabasiAlbertExpand(coo, 5000);

    SparseMatrix<int> sparse =  coo.ToSparse();
    WriteAdjList(sparse, "Barabasi.adj");

    return EXIT_SUCCESS;
}
