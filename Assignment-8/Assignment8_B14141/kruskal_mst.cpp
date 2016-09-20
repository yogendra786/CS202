#include<iostream>
#include "disjoint_set.hpp"
#include "AdjacencyList.hpp"
#include <fstream>
#include <sstream>

using namespace std;

struct edge1{
	int src;
	int dest;
	int weight;
  
};

int main(){
	AdjacencyList al;
	Disjoint D;
	string filename;
	int i,j,num,gp[100][100];
	struct edge1 edge[100];
 	ifstream Myfile (filename.c_str ());
 	cout<<"Enter filename : \n";
 	cin>>filename;
 	Myfile.open (filename.c_str ());
 	if (Myfile.good()){
    			string str;
    			while(getline(Myfile, str)){
        			istringstream ss(str);
        			int num;
        			while(ss >> num){
            			gp[i][j]=num;
            			j++;
        			}
       				i++;
       				j=0;
    			}
    }
    int t=i;
    int c=0;
    int p;
	for(i=0;i<t;i++){
		p=0;
    	for(j=0;j<t;j++){ 
         	if(gp[i][j]!=0){
         		if(p!=1){
         			D.make_set(i);
              
         			p=1;
         		}
            
         		edge[c].src=i;
         		edge[c].dest=j;
         		edge[c].weight=gp[i][j];
         		c++;

          
                al.add(i,j);
        	}
    	}
    }

    for(i=0;i<t;i++){}

    int min,temp_weight,temp_src,temp_dest;
    for(i=0;i<c;i++){
       min=i;
       for(j=i+1;j<c;j++){
           if(edge[j].weight < edge[min].weight)
                min=j;
       }
       temp_weight=edge[min].weight;
       temp_src=edge[min].src;
       temp_dest=edge[min].dest;
       edge[min].weight=edge[i].weight;
       edge[min].src=edge[i].src;
       edge[min].dest=edge[i].dest;
       edge[i].weight=temp_weight;
       edge[i].src=temp_src;
       edge[i].dest=temp_dest;
	}

	cout<<"Linked List Representation of graph"<<endl;
	cout<<"___________________________________\n"<<endl;
	al.display();
	cout<<endl;

	int m=0,a[100],l=0;
	for(i=0;i<c;i++){
    
		if(D.find_set(edge[i].src)!=D.find_set(edge[i].dest)){
			D.make_union(edge[i].src,edge[i].dest);
			a[m]=i;
			m++;
		}
	}

	cout<<"Kruskal Algorithm for minimum spanning tree\n";
	cout<<"_____________________________________________\n"<<endl;
	for(i=0;i<m;i++){
		l++;
		cout<<"Step : "<<l<<endl;
		cout<<"_______\n"<<endl;
		for(j=0;j<l;j++)
			cout<<edge[a[j]].src<<"-----"<<edge[a[j]].dest<<"  :  "<<edge[a[j]].weight<<endl;

		cout<<endl;
			
	}


}