/************************************************************
 * Purpose: A class with methods for different sorting algorithms
 *
 * Version : 1.0
 *
 * Date of Creation : 07/03/2016
 *
 * Bugs : 
 *************************************************************/

#ifndef SORTER_HPP
#define SORTER_HPP

#include "vector.hpp"

namespace /*write your namespace name here*/ {
    template<class Item>
        class sorter
        {
            public:
            void insertion_sort(vector<Item>& a, int lo, int hi);
            void merge_sort(vector<Item>& a, int lo, int hi);
            void rank_sort(vector<Item>& a, int lo,int hi);
            void selection_sort(vector<Item>& a,int lo,int hi);
            void quick_sort(vector<Item>& a,int lo,int hi);
            void bubble_sort(vector<Item>& a,int lo,int hi);
        };
}

/*************************************************************
 * Implement your methods here.
 * You may add any number of methods in addition to the above ones.
 * However, the above methods must be implemented.
 * DO NOT name your methods or classes differently in any case.
 * Parameter details :
 * a : the vector to sort
 * lo : the lower index of the vector from where to sort
 * hi : the higher index of the vector till where to sort
 * e.g,
 * insertion_sort(a,2,10) will sort the vector a
 * from index 2, i.e, the third element,
 * till index 10, i.e, the eleventh element.
*************************************************************/