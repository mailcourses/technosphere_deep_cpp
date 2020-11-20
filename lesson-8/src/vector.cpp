#include <iostream>
#include <vector>

void print_vector_info(const std::vector<int> &v)
{
    std::cout << "vector size=" << v.size() << std::endl;
    std::cout << "vector capacity=" << v.capacity() << std::endl;
}

int main()
{
    std::vector<int> v;
    std::cout << "Round 1" << std::endl;
    print_vector_info( v );

    for (int i = 0; i < 100; ++i)
    {
        v.push_back(i);
    }

    std::cout << "Round 2" << std::endl;
    print_vector_info( v );

    v.reserve(512);
    std::cout << "Round 3" << std::endl;
    print_vector_info( v );
    std::cout << v[200] << std::endl;

    v.resize(600);
    std::cout << "Round 4" << std::endl;
    print_vector_info( v );

    v.resize(10);
    v.shrink_to_fit();
    std::cout << "Round 5" << std::endl;
    print_vector_info( v );

    using tricky_type = std::vector<double>;
    std::vector<tricky_type> v2(100500, tricky_type(10));

    return 0;
}
