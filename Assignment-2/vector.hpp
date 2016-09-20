/*
 * vector.hpp
 *
 * A template file for implementing a resizable vector. 
 */

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

namespace /*write your namespace name here*/ {
template<class Item>
class vector {
public:

    /*Default constructor. Should create an empty vector that
     * not contain any elements*/
	vector();

    /*This constructor should create a vector containing isize elements. You can intialize the elements with any values.*/
	vector(const int& isize);

    /* This contructor also creates a vector containing isize elements.
     * All the elements must be initialized with the value ival.
     * */
	vector(const int& isize, const Item& ival);

    /*Destructor.
     * Must free all the memory contained by the vector*/
	~vector();
    
    /*Indexing operator.
     * It should behave the same way array indexing does. i.e,
     * vector<type> vec;
     * vec[0] should refer to the first element;
     * vec[1] to the second element and so on.
     * */
	inline Item& operator[](const int& i);
    
    /* This push_back functions add the given element at the end of the vector
     * It should increase the vector size by 1.
     * Example :
     * After the givn operations:
     * vector<int> vec;
     * vec.push_back(1);
     * vec.push_back(1);
     * vec.push_back(1);
     * vec.push_back(4);
     *
     * The vector should not contains the elements {1,2,3,4}, in that order.
     * */
	void push_back(const Item& item);

    /*Returns true if the vector is empty, false otherwise.
     * */
	bool empty();

    /* Returns the number of elements in the vector.
     * */
	int size();
    
    /* This function "fills" the vector with the given value, i.e,
     * sets every element of the vector equal to the given value.
     * */
	void fill(const Item& item);
};
}
