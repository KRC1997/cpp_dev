#ifndef _BINARY_TREE_HPP_
#define _BINARY_TREE_HPP_

/*
This file contains declarations of template classes for binary trees,
implemented from scratch.
*/

#include <vector>

namespace binary_tree
{
    template<class T>
    struct tree_data_node
    {
        T data;
        tree_data_node<T> *left;
        tree_data_node<T> *right;
    };

    template<class T>
    class basic_binary_tree
    {
        //Keeping all methods and attributes public for the time being
        public:

        //Memory Management Variables -----------------------------------------
        tree_data_node<T> *root_pointer;

        unsigned long long number_of_elements;

        tree_data_node<T> * __search(const T &);

        //Constructor Declarations --------------------------------------------

        basic_binary_tree();

        //Datastructure exposed interface methods -----------------------------

        void insert(const T &);
        bool search(const T &);
        void remove(const T &);
        

        unsigned long long size();

        std::vector<T> preorder_traversal();
        std::vector<T> ineorder_traversal();
        std::vector<T> postorder_traversal();
    };
}

#endif