#include<iostream>
#include "disjoint_set.hpp"


using namespace std;


int main(){

	Disjoint d;
	d.make_set(1);
	d.make_set(2);
	d.make_set(3);
	d.make_set(4);
	d.make_set(5);
	d.make_set(6);
	d.make_set(7);
	d.make_set(8);
	d.make_set(9);

	cout<<d.find_set(1)<<endl;
	cout<<d.find_set(2)<<endl;
	cout<<d.find_set(3)<<endl;
	cout<<d.find_set(4)<<endl;
	cout<<d.find_set(5)<<endl;
	cout<<d.find_set(6)<<endl;
	cout<<d.find_set(7)<<endl;
	cout<<d.find_set(8)<<endl;
	cout<<d.find_set(9)<<endl;

	d.make_union(1,2);
	cout<<d.find_set(1)<<endl;
	d.make_union(1,3);
	cout<<d.find_set(3)<<endl;
	cout<<d.find_set(2)<<endl;
	d.make_union(1,9);
	cout<<d.find_set(9)<<endl;


}