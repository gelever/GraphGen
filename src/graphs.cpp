/*! @file */
#include "graphs.hpp"

namespace linalgcpp
{

void BarabasiAlbertExpand(CooMatrix<int>& graph, int num_nodes)
{
    assert(graph.Rows() == graph.Cols());
    assert(graph.Rows() > 0);

    size_t size = graph.Rows();

    std::vector<double> probs(size, 0);
    std::vector<int> degree(size, 0);
    int total_degree = 0;

    for (size_t i = 0; i < size; ++i)
    {
        degree[i] = graph(i, i);
        total_degree += degree[i];
    }

    std::random_device r;
    std::default_random_engine dev(r());
    std::uniform_real_distribution<double> gen(0.0, 1.0);

    for (int i = 0; i < num_nodes; ++i)
    {
        for (size_t j = 0; j < size; ++j)
        {
            probs[j] = degree[j] / (double)total_degree;
        }

        int local_degree = 0;

        for (size_t j = 0; j < size; ++j)
        {
            const double random_val = gen(dev);

            const double prob = probs[j];

            if (random_val <= prob)
            {
                graph.Add(j, j, 1);
                graph.Add(j, size, -1);
                graph.Add(size, j, -1);
                graph.Add(size, size, 1);

                degree[j]++;
                local_degree++;
                total_degree += 2;
            }
        }

        if (local_degree > 0)
        {
            size++;
            degree.push_back(local_degree);
            probs.push_back(0);
        }
    }
}

} // namespace linalgcpp
