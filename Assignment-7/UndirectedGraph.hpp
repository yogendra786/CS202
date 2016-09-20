#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1
#include "AbstractGraph.hpp"
#include "AdjacencyMatrix.hpp"
#include "AdjacencyList.hpp"
#include "queue.hpp"
#include "stack.hpp"
#define INT_MAX 10000

using namespace pratap;

enum Color{WHITE,GRAY,BLACK};
struct ex{
        Color colour;
        int d;
        struct ex* pred;
        int val;
};
struct ex1{
       Color colour;
       int dt;
       int df;
       struct ex1* pred;
       int val;
};

class UndirectedGraph : public AbstractGraph {
 private:
         AdjacencyMatrix amu;
         AdjacencyList alu;
         GraphAdjacencyBase *gru;
         struct ex vertice[100];
         struct ex1 vertice1[100];
         int s1;
         int time;     
 public:
         UndirectedGraph(int vertices,char rep){
          if(rep=='m')
             gru=&amu;
            else if(rep=='l')
              gru=&alu;
            else
               cout<<"Enter valid Graph representation\n";
               time=0;
          for(int i=0;i<100;i++){
                  vertice[i].colour=WHITE;
                  vertice[i].pred=NULL;
                  vertice[i].d=INT_MAX;
                  vertice[i].val=i;
          }
          for(int j=0;j<100;j++){
                vertice1[j].colour=WHITE;
                vertice1[j].pred=NULL;
                vertice1[j].val=j;
           }
        }
        bool edgeExits(int i, int j);
  		int edges();
  		int vertices() ;
  		int indegree(int i){
    	cout<<"Not Defined for Undirected Graph";
    	return INT_MAX;

  		}
  		int outdegree(int j){
    	cout<<"Not Defined for Undirected Graph";
    	return INT_MAX;
  		}
  		void add(int i, int j) ;
  		void remove(int i, int j) ;
  		void dfs(int s);
  		void bfs(int s);
  		int degree(int i){
       			return gru->degree(i);
  		}
  		void display();
};

bool UndirectedGraph::edgeExits(int i, int j){
             return gru->edgeExits(i,j);
}

int UndirectedGraph::edges(){
             return gru->edges();
}

int UndirectedGraph::vertices(){
             return gru->vertices();
}

void UndirectedGraph::add(int i, int j){
             gru->add(i,j);
}

void UndirectedGraph::remove(int i, int j){
            gru->remove(i,j);
}

void UndirectedGraph::bfs(int s){
           vertice[s].colour=GRAY;
           s1=s;
           vertice[s].d=0;
           queue<int> Q;
           Q.push(s);
           while(Q.size()!=0){
                  int u=Q.pop();
                   cout<<u<<" ";
                  int k=gru->degree(u);
                  int p=1;
                         while(p!=(k+1)){
                                 int v=gru->get(u,p);
                                   if(vertice[v].colour==WHITE){
                                               vertice[v].colour=GRAY;
                                               vertice[v].d=vertice[u].d+1;
                                               vertice[v].pred=&vertice[u];
                                               Q.push(v);
                                    }
                                    p++;
                           }
                   vertice[u].colour=BLACK;
           }
}
void UndirectedGraph::dfs(int s){
             stack<int> S;
             time =time +1;
             vertice1[s].colour=GRAY;
              vertice1[s].dt=time;
             S.Push(s);
             while(S.size()!=0){
                int u=S.Pop();
                cout<<u<<" ";
                //work(u);
                int k=gru->degree(u);
                 int p=1;
                         while(p!=(k+1)){
                                 time=time+1;
                                 int v=gru->get(u,p);
                                   if(vertice1[v].colour==WHITE){
                                               vertice1[v].colour=GRAY;
                                               vertice1[v].pred=&vertice1[u];
                                               vertice1[v].dt=time;
                                               S.Push(v);
                                    }
                                    p++;
                           }
                   vertice1[u].colour=BLACK;
                   time =time+1;
                   vertice1[u].df=time;
           }
         
           
}

void UndirectedGraph::display(){
            
        gru->display();
        cout<<endl;
}
             
#endif /* ifndef UNDIRECTED_gruAPH */
