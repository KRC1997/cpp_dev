// @Author: Kunal Roychoudhury

#include "binary_tree.hpp"

/*
This file contains definitions for classes and methods defined in 
'binary_tree.hpp'
*/

template<class T>
binary_tree::tree_data_node<T> * binary_tree::basic_binary_tree<T>::__search(const T & ob)
{
    return nullptr;
}

template<class T>
binary_tree::basic_binary_tree<T>::basic_binary_tree()
{
    // memory management initializations --------------------------------------
    this->root_pointer = nullptr;
    this->number_of_elements = 0;
}

template<class T>
void binary_tree::basic_binary_tree<T>::insert(const T & ob)
{
    
}

template<class T>
bool binary_tree::basic_binary_tree<T>::search(const T & ob)
{
    return false;
}

template<class T>
void binary_tree::basic_binary_tree<T>::remove(const T & ob)
{
    
}

template<class T>
unsigned long long binary_tree::basic_binary_tree<T>::size()
{
    return this->number_of_elements;
}
