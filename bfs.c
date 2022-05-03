#include<stdio.h>
#include<stdlib.h>

struct queue 
{
  int items[10];
  int front;
  int rear;
};

// A structure to represent an adjacency list nod
typedef struct adjacencylistnode
{
   int vertex;
   //int color;//for color codeto manage bfs algo 0=white;1=grey;2=black
   //int dist;//for distance from source vertex
   
   struct adjacencylistnode *parent;
   struct adjacencylistnode *next;
}node;


// A structure to represent an adjacency list
typedef struct adjacencylist
{
   
   node *head;
   
}adjlist;

// A structure to represent a graph. A graph
// is an array of adjacency lists.
// Size of array will be V (number of vertices
// in graph)
typedef struct graph
{
   //thsi variablre is for number of vertices in the graph
   int V;
   adjlist *arr;
   int* visited;
   
   
}graph;


// Driver program to test above functions
int main()
{  
    graph *G;
    
    void BFS(graph *G , int startVertex);
    node* newAdjListNode(int v);
    graph*  create_Graph(int v);
    int addEdge(graph *G , int src , int dst);
    struct queue* createQueue() ;
    int isEmpty(struct queue* q);
    void enqueue(struct queue* q, int value) ;
    int dequeue(struct queue* q) ;
    void printQueue(struct queue* q) ;
   
    
    
    // create the graph given in above fugure
    int V = 8;
    G = create_Graph(V);
    addEdge(G, 0, 1);
    addEdge(G, 0, 2);
    addEdge(G, 1, 3);
    addEdge(G, 1, 4);
    addEdge(G, 2, 7);
    addEdge(G, 2, 3);
    addEdge(G, 3, 4);
    addEdge(G, 3, 7);
    addEdge(G, 4, 5);
    addEdge(G, 5, 6);
    addEdge(G, 6, 7);
    
    // print the adjacency list representation of the above
    // graph
   //printGraph(graph);
 
 
    BFS( G , 0);
    return 0;
}
//---------------------------------------------------------------

 void BFS(graph *G , int startVertex)
{
   struct queue  *q;
   node *ptr;
   int currentvertex, adjVertex;
   
   //prototype
   struct queue* createQueue() ;
   int isEmpty(struct queue* q);
   void enqueue(struct queue* q, int value) ;
   int dequeue(struct queue* q) ;
   void printQueue(struct queue* q) ;
   
   q = createQueue();
   
   G->visited[startVertex]=1;
   enqueue(q, startVertex);

   while (!isEmpty(q))
   {
      printQueue(q);
      currentvertex = dequeue(q);
      printf("Visited %d\n", currentvertex);

      ptr=G->arr[currentvertex].head;
      
      while(ptr != NULL)
      {
         
         adjVertex = ptr->vertex;
        // printf("\n%d",adjVertex);
         
         if (G->visited[adjVertex] == 0) 
         {
            G->visited[adjVertex] = 1;
            enqueue(q, adjVertex);
            
         }
         ptr=ptr->next;
      }
   }
}
     
//---------------------------------------------------------------
node* newAdjListNode(int v)
{
   node *newnode;
   
   newnode=(node*)malloc(sizeof(node));
   
    newnode->vertex = v;
    newnode->next = NULL;
    
   return newnode;
}

//-----------------------------------------------------------------
graph*  create_Graph(int v)//v=no. of vertices to create graph
{
    graph *ptr;
    int i;
    
    ptr=(graph*) malloc(sizeof(graph));
    
    ptr->V = v;
    
    // Create an array of adjacency lists and visited vertex list.  Size of
    // array will be V
    ptr->arr=(adjlist*) malloc (v*sizeof(adjlist));
    
    ptr->visited= (int*) malloc (v*sizeof(int));
    
    
    
    // Initialize each adjacency list as empty by
    // making head as NULL
    i=0;
    while(i<v)
    {
       ptr->arr[i].head =NULL;
       ptr->visited[i]=0;
       
       i=i+1;
    }
    
    return ptr;
}
//-------------------------------------------------------------------

//below function will add edge to an undirected graph
int addEdge(graph *G , int src , int dst)
{
   
   //adjlist *ptr;
   node  *newnode;   
   
   // Add an edge from src to dest.  A new node is
    // added to the adjacency list of src.  The node
    // is added at the beginning
   newnode=newAdjListNode(dst);
   
   newnode->next = G->arr[src].head;
   G->arr[src].head = newnode;
  
   // Since graph is undirected, add an edge from
    // dest to src also
    
   newnode=newAdjListNode(src);
   
   newnode->next = G->arr[dst].head;
   G->arr[dst].head = newnode;

   return(1);

}
//----------------------------------------------------------------
// Create a queue
struct queue* createQueue() 
{
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

// Check if the queue is empty
int isEmpty(struct queue* q) 
{
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

// Adding elements into queue
void enqueue(struct queue* q, int value) 
{
  int SIZE=10;
  if (q->rear == (SIZE - 1))
    printf("\nQueue is Full!!");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

// Removing elements from queue
int dequeue(struct queue* q) 
{
  int item;
  if (isEmpty(q)) {
    printf("Queue is empty");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      printf("Resetting queue ");
      q->front = q->rear = -1;
    }
  }
  return item;
}

// Print the queue
void printQueue(struct queue* q) {
  int i = q->front;

  if (isEmpty(q)) {
    printf("Queue is empty");
  } else {
    printf("\nQueue contains \n");
    for (i = q->front; i < q->rear + 1; i++) {
      printf("%d ", q->items[i]);
    }
  }
}

//-----------------------------------------------------------------









