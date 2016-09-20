#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1
#include "GraphAdjacencyBase.hpp"
#include "list.hpp"
#include<iostream>
using namespace std;
using namespace pratap;
class AdjacencyList : public GraphAdjacencyBase {
        
         private:
              list<int> adj[100];
              int c;
              int p;
         public:
              AdjacencyList();
              int get(int k,int p){
                             //p++;
                       return adj[k].next2(p);
              }
              ~AdjacencyList();
               bool edgeExits(int i, int j);	
               int vertices() ;	
             int edges() ;	
             void add(int i, int j) ;	
             void remove(int i, int j);	
             int degree(int i);
             void display();
             int indegree(int j);
             int outdegree(int i);
};
AdjacencyList::~AdjacencyList(){
            for(int i=0;i<100;i++){
                 while(adj[i].length()!=0){
                            adj[i].remove(1);
        
                 }
             }
}
AdjacencyList::AdjacencyList(){
            c=0;
            p=0;
}

bool AdjacencyList::edgeExits(int i, int j){
         return adj[i].has(j);

}

int AdjacencyList::vertices(){
   int k;
for(int i=0;i<=100;i++){
     if(adj[i].empty()!=0)
            k++;
 }
return k;

}


int AdjacencyList::edges(){
    return c;

}

void AdjacencyList::add(int i, int j){
       if(adj[i].has(j)!=1){
            adj[i].append(j);
            c++;
        }
        else cout<<"Already Present\n";
}

void AdjacencyList::remove(int i, int j){
       if(adj[i].has(j)){
         int p=adj[i].pos(j);
         adj[i].remove(p);
         c--;
       }
       else cout<<"Not Present\n";
}


int AdjacencyList::outdegree(int i){
     return adj[i].length();
}
int AdjacencyList::indegree(int j){
            int k=0;
       for(int p=0;p<100;p++)
            {
                 if(adj[p].has(j))
                      k++;
            }
     return k;
}
int AdjacencyList::degree(int i){
     return adj[i].length();
}
void AdjacencyList::display(){
       for(int i=0;i<100;i++){
              if(adj[i].length()!=0){
                   cout<<i<<"=>";
                   adj[i].dump();
               }
       }

}
#endif /* ifndef ADJACENCY_LIST */
