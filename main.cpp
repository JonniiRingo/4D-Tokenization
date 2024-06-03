#include <iostream>
#include <vector>
#include <matplot/matplot.h>
#include "Tensor4D.h"

using namespace std;
using namespace matplot;

void simulate_tokenization(Tensor4D<int>& tensor) {
    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            for (size_t k = 0; k < 10; ++k) {
                for (size_t l = 0; l < 10; ++l) {
                    tensor.at(i, j, k, l) = (i + j + k + l) % 10;
                }
            }
        }
    }  
}

void visualize_tensor(const Tensor4D<int>& tensor) {
    vector<vector<double>> data2D(10, vector<double>(10));
    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            data2D[i][j] = tensor.at(i, j, 0, 0); // Flatten the 4D tensor to 2D for visualization
        }
    }
    auto fig = figure();
    fig->size(800, 600);
    matplot::imshow(data2D);
    matplot::show();
}

int main() {
    Tensor4D<int> tensor(10, 10, 10, 10);
    simulate_tokenization(tensor);
    visualize_tensor(tensor);
    return 0;
}
