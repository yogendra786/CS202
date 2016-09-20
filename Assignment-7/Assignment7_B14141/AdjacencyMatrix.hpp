#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1
#include "GraphAdjacencyBase.hpp"
#include<iostream>

using namespace std;

class AdjacencyMatrix : public GraphAdjacencyBase {
         private:
              int adj[10][10];
              int c;
         public:
              AdjacencyMatrix();
              int get(int k,int p){
                       for(int j=0;j<10;j++){
                           if(adj[k][j]==1){
                                adj[k][j]=0;
                                    return j;
                            }
                       }
              }
              ~AdjacencyMatrix(){};
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
int AdjacencyMatrix::outdegree(int i){
          int k=0;
          for(int g=0;g<10;g++){
                 if(adj[i][g]==1)
                         k++;
           }
           return k;
}
int AdjacencyMatrix::indegree(int j){
          int k=0;
          for(int g=0;g<10;g++){
                 if(adj[g][j]==1)
                         k++;
           }
           return k;
          
}

AdjacencyMatrix::AdjacencyMatrix(){
             for(int i=0;i<10;i++){
                       for(int j=0;j<10;j++)
                              adj[i][j]=0;
              }
              c=0;
} 

void AdjacencyMatrix::add(int i,int j){
            if(adj[i][j]!=1){
                   adj[i][j]=1;
                   c++;
             }               
            else cout<<"Already present"<<endl;           
}
void AdjacencyMatrix::remove(int i,int j){
         if(adj[i][j]==1){
            adj[i][j]=0;
            c--;
          }
         else cout<<"Not Present"<<endl;
}
bool AdjacencyMatrix::edgeExits(int i, int j){
        if(adj[i][j]==1)
             return 1;
         else return 0;
}
int AdjacencyMatrix::edges(){
          return c;
}
int AdjacencyMatrix::degree(int i){
          return indegree(i)+outdegree(i);
}
int AdjacencyMatrix::vertices(){
         int k=0;
         for(int i=0;i<10;i++){
                       for(int j=0;j<10;j++){
                              if(adj[i][j]==1){
                                    k++;
                                    break;
                               }
                        }
         }
         return k;
}
void AdjacencyMatrix::display(){
          for(int i=0;i<10;i++){
                       for(int j=0;j<10;j++){
                              cout<<adj[i][j]<<" ";
                       }
          cout<<endl;
              }
}
   
      
                  
#endif /* ifndef ADJACENCY_MATRIX */
