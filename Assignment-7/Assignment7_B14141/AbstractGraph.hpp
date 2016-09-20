#ifndef ABSTRACT_GRAPH
#define ABSTRACT_GRAPH 1
/*
 * An interface to represent any type of Graph
 */
class AbstractGraph {
 public:
  /* Destructor:
   * releases all resources acquired by the class
   */
 // virtual ~AbstractGraph();
  /*
   * Function: edgeExists
   * Returns true if an edge exists between vertices i and j, false otherwise.
   */
  virtual bool edgeExits(int i, int j) = 0;
  /*
   * Function: edges
   * Returns the number of edges in the adjacency structure.
   */
  virtual int edges() = 0;
  /*
   * Function: vertices
   * Returns the number of vertices in the adjacency structure.
   */
  virtual int vertices() = 0;
  /*
   * Function add:
   * Adds an edge between vertices i and j
   */
  virtual void add(int i, int j) = 0;
  /*
   * Function: remove
   * Deleted the edge between vertices i and j
   */
  virtual void remove(int i, int j) = 0;
  /*
   * Function dfs:
   * Does a depth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
  virtual void dfs(int s) = 0;
  virtual int degree(int i) =0;
  virtual int outdegree(int i) =0;
  virtual int indegree(int i) =0;
  /*
   * Function bfs:
   * Does a breadth first traversal of the entire graph.
   * Runs the given function work, with the value of each vertex.
   */
  virtual void bfs(int s) = 0;
  virtual void display()=0;
};
#endif /* ifndef ABSTRACT_GRAPH */
