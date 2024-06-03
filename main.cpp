#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Tensor4D.h"

void visualize_tensor_slice(const Tensor4D<int>& tensor, size_t k, size_t l) {
    // Write the data to a temporary file
    std::ofstream dataFile("data.txt");
    for (size_t i = 0; i < tensor.dim1_; ++i) {
        for (size_t j = 0; j < tensor.dim2_; ++j) {
            dataFile << i << ' ' << j << ' ' << tensor.at(i, j, k, l) << '\n';
        }
        dataFile << '\n'; // Gnuplot expects a blank line between rows
    }
    dataFile.close();

    // Create a Gnuplot script
    std::ofstream scriptFile("script.gp");
    scriptFile << "set terminal pngcairo\n";
    scriptFile << "set output 'output.png'\n";
    scriptFile << "splot 'data.txt' matrix with lines\n";
    scriptFile.close();

    // Run the Gnuplot script
    system("gnuplot script.gp");
}

int main() {
    // Create a Tensor4D object
    Tensor4D<int> tensor(10, 10, 10, 10);

    // Fill the tensor with data...
    // For example, fill it with random data
    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            for (size_t k = 0; k < 10; ++k) {
                for (size_t l = 0; l < 10; ++l) {
                    tensor.at(i, j, k, l) = rand() % 100;
                }
            }
        }
    }

    // Visualize a slice of the tensor
    visualize_tensor_slice(tensor, 0, 0);

    return 0;
}