#include <iostream>
#include "binary_tree.hpp"


int main()
{
    binary_tree::basic_binary_tree<int> my_tree;

    int x = 56;

    std::cout << "Inserting value: " << x << " into tree!" << std::endl;
    my_tree.insert(x);

    return 0;
}