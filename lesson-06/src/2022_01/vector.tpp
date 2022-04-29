template<typename T>
void vector<T>::push_back(const T& elem)
{
    data_[size_++] = elem;
}
