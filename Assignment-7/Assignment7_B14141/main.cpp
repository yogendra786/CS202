#include<iostream>
#include<cstring>
#include "UndirectedGraph.hpp"
#include "DirectedGraph.hpp"
#include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"
#include "GraphAdjacencyBase.hpp"
#include "AbstractGraph.hpp"
#include <fstream>
#include <sstream>
#define INT_MAX 10000

using namespace std;

int main(){
 	
 	AdjacencyMatrix am;
 	AdjacencyList al;
 	GraphAdjacencyBase *gab;
 	AbstractGraph *ag;
 	string filename;
 	ifstream Myfile (filename.c_str ());
 	int c,gp[100][100],i=0,j=0,t1,n,m=0;
 	char p;
 	cout<<"                          GRAPH TYPE                                     "<<endl;
    cout<<"\n1.UndirectedGraph\n2.DirectedGraph\n";
    cin>>n;
    cout<<"Enter Number of vertices and mode of graph representation(m for AdjacencyMatrix or l for AdjacencyList)"<<endl;
    cin>>t1>>p;
    DirectedGraph gd(t1,p);
 	UndirectedGraph gu(t1,p);
    if(n==1)
    	ag=&gu;
    else if(n==2)
    	ag=&gd;
    else cout<<"Enter valid Choice"<<endl;
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
	for(i=0;i<t;i++){
    	for(j=0;j<t;j++){ 
         	if(gp[i][j]==1){
                ag->add(i,j);
        	}
    	}
    }
    while(m!=1){		
 	cout<<"Graph Operations : \n";
 	cout<<"1.Add Edge \n2.Remove Edge \n3.Edge Exists?? \n4.No.of vertices?\n5.Degree of Vertice\n6.BFS Traversal\n7.DFS Traversal\n";
 	cout<<"8.Indegree of Vertice(Only for directed graphs)\n9.Outdegree of Vertice(Only for undirected graphs)\n10.Display\n11.Exit\n GIVE CHOICE : "<<endl;
 	cin>>c;
 	cout<<endl;
 	while(cin.fail()){
            cout << "Error!" <<endl;
            cin.clear();
            cin.ignore(256,'\n');
            cout<<"Enter your choice"<<endl;
            cin >> c;
    }
 	switch(c){
 		case 1 :
 				cout<<"Give two vertices"<<endl;
 				cin>>i>>j;
 				ag->add(i,j); 				
                break;            
 		case 2 :
 				cout<<"Give  vertices for existing edge to be removed"<<endl;
                                cin>>i>>j;
 				ag->remove(i,j);
 		        break;
 		case 3:
 		       cout<<"Give Vertices of edge to be searched"<<endl;
 		       cin>>i>>j;
 		       if(ag->edgeExits(i,j))
 		       	 cout<<"Exists\n";
 		       	else cout<<"Not Exists\n";
 		       break;
 		case 4:
 		       cout<<ag->vertices()<<endl;
 		       break;
 		case 5:
 		       cout<<"Enter Vertice\n";
 		       cin>>i;
 		       cout<<ag->degree(i)<<endl;
 		       break;
 		case 6:
 		       cout<<"Give Source Node for BFS Traversal"<<endl;
 		       cin>>i;
 		       ag->bfs(i);
 		       break;

 		case 7:
 		       cout<<"Give Source Node for DFS traversal"<<endl;
 		       cin>>i;
 		       ag->dfs(i);
 		       break;          

 		case 8:
 		       cout<<"Enter Vertice\n";
 		       cin>>i;
 		       if(ag->indegree(i)!=INT_MAX)
 		         cout<<ag->indegree(i)<<endl;
 		       break;
 		case 9:
 		       cout<<"Enter Vertice\n";
 		       cin>>i;
 		       if(ag->outdegree(i)!=INT_MAX)
 		       cout<<ag->outdegree(i)<<endl;
 		       break;
        case 10:
                ag->display();
                break;

        case 11:
                m=1;
                break;
        default:
                cout<<"Enter valid Choice\n";
                break;                

 	}

    }
 	
 	
return 0;
}
