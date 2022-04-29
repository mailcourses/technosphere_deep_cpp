#include "vector.hpp"

namespace my
{


template<typename T>
void vector<T>::push_back(const T& elem)
{
    data_[size_++] = elem;
}

template class vector<int>;
template class vector<std::string>;

} // namespace my
