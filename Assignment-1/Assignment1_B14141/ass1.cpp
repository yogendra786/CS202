#include "resV.h" 
#include <iostream> 
#include<cstring> 
using namespace pratap;
using namespace std;
 
void output_array(vector<int> &array) 
{ 
	for(unsigned int i=0; i<array.getsize(); i++) 
		cout << array[i] << ", ";
 
	cout << endl; 
} 
 
int main(void) 
{ 
	vector<int> array1;
    vector<int> array2(20);
	 vector<int> array3(5,5);
	array1.push_back(11);
	array1.push_back(8);
	array1.push_back(14);
	array1.push_back(3);
	array1.push_back(18);

	 array2.push_back(18);
        array2.push_back(15);
        array2.push_back(16);
        array2.push_back(10);
	
        array3.push_back(7);
        array3.push_back(98);
        array3.push_back(1);
        array3.push_back(6);



	std::cout << "First array is ";
	output_array(array1);
        cout << "\n";
	std::cout << "Second array is ";
	output_array(array2);
        cout << "\n";
	std::cout << "Third array is ";
	output_array(array3);
	std::cout << "  ";

 

	output_array(array1);			
        cout << "\n";
	if(array1.empty())
	std::cout << "ARRAY IS FULL\n\n";
	else
	std::cout << "NOT EMPTY\n\n";
	int size;
	size=array1.getsize();
	std::cout << "The size of the array is "<< size <<"\n";
	output_array(array1);
	return 0;
} 
 

