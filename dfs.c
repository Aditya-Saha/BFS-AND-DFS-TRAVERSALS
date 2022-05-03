#include<stdio.h>
#include<stdlib.h>

struct stack
{
  int items[10];
  int top;
  
};

// A structure to represent an adjacency list nod
typedef struct adjacencylistnode
{
   int vertex;
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
    
    //prototypes
    void DFS(graph *G , int startVertex);
    node* newAdjListNode(int v);
    graph*  create_Graph(int v);
    int addEdge(graph *G , int src , int dst);
    struct stack* createstack() ;
    void push(struct stack* q, int value) ;
    int pop(struct stack* q) ;
 
   
    
    
    // create the graph given in above fugure
    int V = 8;
    G = create_Graph(V);
    addEdge(G, 0, 1);
    addEdge(G, 0, 2);
    addEdge(G, 1, 3);
    addEdge(G, 1, 4);
    addEdge(G, 2, 3);
    addEdge(G, 2, 7);
    addEdge(G, 3, 4);
    addEdge(G, 3, 7);
    addEdge(G, 4, 5);
    addEdge(G, 5, 6);
    addEdge(G, 6, 7);
    
    
 
    DFS( G , 0);
    return 0;
}
//---------------------------------------------------------------

 void DFS(graph *G , int startVertex)
{
   struct stack  *q;
   node *ptr;
   int currentvertex, adjVertex;
   
   //prototype
   struct stack* createstack() ;
   
   void push(struct stack* q, int value) ;
   int pop(struct stack* q) ;
   
   
   q = createstack();
   
   G->visited[startVertex]=1;
   push(q, startVertex);

   while (q->top != -1)
   {
      
      currentvertex = pop(q);
      printf("Visited %d\n", currentvertex);

      ptr=G->arr[currentvertex].head;
      
      while(ptr != NULL)
      {
         
         adjVertex = ptr->vertex;
        
         
         if (G->visited[adjVertex] == 0) 
         {
            G->visited[adjVertex] = 1;
            push(q, adjVertex);
            
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
   
   node *ptr;
   node  *newNode;   
   
   // Add an edge from src to dest.  A new node is
    // added to the adjacency list of src.  The node
    // is added at the beginning
   newNode=newAdjListNode(dst);
   
   if (G->arr[src].head == NULL)
   {
        newNode->next = G->arr[src].head;
        G->arr[src].head = newNode;
    }
    else 
    {
 
        ptr = G->arr[src].head;
        while (ptr->next != NULL) 
        {
            ptr = ptr->next;
        }
        // graph->array[src].head = newNode;
        ptr->next = newNode;
    }
 
    // Since graph is undirected, add an edge from
    // dest to src also
    newNode = newAdjListNode(src);
    if (G->arr[dst].head == NULL)
    {
        newNode->next = G->arr[dst].head;
        G->arr[dst].head = newNode;
    }
    else 
    {
        ptr = G->arr[dst].head;
        while (ptr->next != NULL) 
        {
            ptr= ptr->next;
        }
        ptr->next = newNode;
    }

   return(1);

}
//----------------------------------------------------------------
// Create a stack
struct stack* createstack() 
{
  struct stack* q = malloc(sizeof(struct stack));
  q->top = -1;
  
  return q;
}


// Adding elements into stack
void push(struct stack* q, int value) 
{
  int SIZE=10;
  if (q->top == (SIZE - 1))
    printf("\nstack is Full!!");
  else 
  {
    q->top++;
    q->items[q->top] = value;
  }
}

// Removing elements from stack
int pop(struct stack* q) 
{
  int item;
  if (q->top == -1)
  {
    printf("Stack  is empty");
    item = -1;
  } 
  else
  {
    item=q->items[q->top];
    q->top--;
  }
  return item;
}

//-----------------------------------------------------------------









