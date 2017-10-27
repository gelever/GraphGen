/*! @file */

#ifndef GRAPHS_HPP__
#define GRAPHS_HPP__

#include "coomatrix.hpp"

namespace linalgcpp
{

/*! Expands a graph by adding nodes and randomly
    connecting them to existing nodes with probability
    p(i) = degree_i / sum(degrees)
    @param graph the initial graph to expand
    @param num_nodes the number of nodes to expand by
*/
 void BarabasiAlbertExpand(CooMatrix<int>& graph, int num_nodes);

} // namespace linalgcpp

#endif // GRAPHS_HPP__
