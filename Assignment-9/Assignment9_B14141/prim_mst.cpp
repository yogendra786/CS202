#include<iostream>
#include "Heap.hpp"
#include <fstream>
#include <sstream>
#include "AdjacencyList.hpp"
#define INT_MAX 100000

struct edge1{
    int src;
    int dest;
    int weight;
  
};

using namespace std;

 int main(int argc, char const *argv[])
{
	Heap H;
    AdjacencyList al;
    int l=1;
	string filename;
	int i=0,j=0,k=0;
	struct edge1 edge[100];
	int vertice[100];
    int parent[100];
	int key[100];
	int mst[100];int res[100];
	int gp[100][100];
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
    for(i=0;i<t;i++){
		
    	for(j=0;j<t;j++){ 
         	if(gp[i][j]!=0){

         		edge[c].src=i;
         		edge[c].dest=j;
         		edge[c].weight=gp[i][j];
         		c++;          
                al.add(i,j);
        	}
    	}
    }

    for(i=0;i<c;i++){
    	H.heap_insert(vertice,INT_MAX);
    	key[i]=INT_MAX;
    	mst[i]=0;
    }

    key[0]=0;
    H.heap_Decrease_key(vertice,0,0);
    int p;
    while(H.size()!=0){
    	int u=H.extract_min(vertice);
    	p=H.index(u);
        if((p>=0)&&(p<=t)){
    	   if(mst[p]==0){
    		  res[p]=u;
    		  k++;
              mst[p]=1;
    	   }    

    	   for(j=0;j<t;j++){ 
         	  if(gp[p][j]!=0){
         		 if(mst[j]==0){
         			    if((key[j]>gp[p][j])&&(gp[p][j]!=0)){
         				   key[j]=gp[p][j];
                            parent[j]=p;                      
         			    }                       
                        H.heap_Decrease_key(vertice,j,key[j]);      
         		 }      		
        	   }
    	   }
        
        }

    }

    cout<<"AdjacencyList Representation of Graph is\n"<<endl;
    al.display();

    cout<<"\n\n";
    cout<<"Prim's Algorithm for minimum spanning tree\n";
    cout<<"_____________________________________________\n"<<endl;
    for(i=1;i<k;i++){
        l++;
        cout<<"Step : "<<l-1<<endl;
        cout<<"_______\n"<<endl;
        for(j=1;j<l;j++)
            cout<<parent[j]<<"-----"<<j<<"  :  "<<res[j]<<endl;

        cout<<endl;
            
    }
    
	return 0;
}