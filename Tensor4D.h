#ifndef TENSOR4D_H
#define TENSOR4D_H

#include <vector>
#include <iostream>

template <typename T>
class Tensor4D {
public:
    Tensor4D(size_t dim1, size_t dim2, size_t dim3, size_t dim4);
    T& at(size_t i, size_t j, size_t k, size_t l);
    const T& at(size_t i, size_t j, size_t k, size_t l) const;

private:
    size_t dim1_, dim2_, dim3_, dim4_;
    std::vector<T> data_;
};

template <typename T>
Tensor4D<T>::Tensor4D(size_t dim1, size_t dim2, size_t dim3, size_t dim4)
    : dim1_(dim1), dim2_(dim2), dim3_(dim3), dim4_(dim4), data_(dim1 * dim2 * dim3 * dim4) {}

template <typename T>
T& Tensor4D<T>::at(size_t i, size_t j, size_t k, size_t l) {
    return data_[((i * dim2_ + j) * dim3_ + k) * dim4_ + l];
}

template <typename T>
const T& Tensor4D<T>::at(size_t i, size_t j, size_t k, size_t l) const {
    return data_[((i * dim2_ + j) * dim3_ + k) * dim4_ + l];
}

#endif // TENSOR4D_H
