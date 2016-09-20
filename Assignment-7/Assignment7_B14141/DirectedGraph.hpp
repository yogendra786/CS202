#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1
#include "AbstractGraph.hpp"
#include "AdjacencyMatrix.hpp"
#include "AdjacencyList.hpp"
#include "queue.hpp"
#include "stack.hpp"
#define INT_MAX 10000

using namespace pratap;

struct ex2{
        Color colour;
        int d;
        struct ex2* pred;
        int val;
};
struct ex3{
       Color colour;
       int dt;
       int df;
       struct ex3* pred;
       int val;
};

class DirectedGraph : public AbstractGraph {
  private:
         AdjacencyMatrix amd;
         AdjacencyList ald;
         GraphAdjacencyBase *grd;
         struct ex2 vertice[100];
         struct ex3 vertice1[100];
         int time;
         int s1;     
 public:
  
     	DirectedGraph(int numVertices,char rep){
        			if(rep=='m')
            			grd=&amd;
          			else if(rep=='l')
            			grd=&ald;
          			else 
            			cout<<"Enter Valid Graph Representation"<<endl;
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
  		void add(int i, int j) ;
  		void remove(int i, int j) ;
  		void dfs(int s);
  		void bfs(int s);
  		int degree(int i){
       			return grd->degree(i);
  		} 
  		int indegree(int i);  
  		int outdegree(int j);
  		void display();
};


int DirectedGraph::indegree(int i){
      return grd->indegree(i);
}

int DirectedGraph::outdegree(int j){
      return grd->outdegree(j);
}

bool DirectedGraph::edgeExits(int i, int j){
       return grd->edgeExits(i,j);
}

int DirectedGraph::edges(){
       return grd->edges();
}

int DirectedGraph::vertices(){
       return grd->vertices();
}

void DirectedGraph::add(int i, int j){
        grd->add(i,j);
}

void DirectedGraph::remove(int i, int j){
        grd->remove(i,j);
}

void DirectedGraph::bfs(int s){
           vertice[s].colour=GRAY;
           s1=s;
           vertice[s].d=0;
           queue<int> Q;
           Q.push(s);
           while(Q.size()!=0){
                  int u=Q.pop();
                   cout<<u<<" ";
                  int k=grd->outdegree(u);
                    int p=1;
                         while(p!=(k+1)){
                                 int v=grd->get(u,p);
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
    
void DirectedGraph::dfs(int s){
             stack<int> S;
             time =time +1;
             vertice1[s].colour=GRAY;
              vertice1[s].dt=time;
             S.Push(s);
             while(S.size()!=0){
                int u=S.Pop();
                if(vertice1[u].colour!=WHITE)
                 cout<<u<<" ";
                int k=grd->outdegree(u);
                 int p=1;
                 while(p!=(k+1)){
                                 time=time+1;
                                 int v=grd->get(u,p);
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

void DirectedGraph::display(){
            
        grd->display();
        cout<<endl;
   }
#endif /* ifndef DIRECTED_GRAPH */
