#include<stdio.h>
#include<stdlib.h>


struct queue 
{
  int item;
  struct queue *next;
};

// Driver program to test above functions
int main()
{  
    
    int V,i,j;
    int S[9], **graph;
    
    
    int BFS(int **G, int N, int Vs,int S[]);    
    int enqueue(struct queue **front, struct queue **rear , int node);
    int dequeue(struct queue **front, struct queue **rear , int *node) ;
    int display(int v);
    
   
    
    graph=(int**)calloc(9,sizeof(int*));
    for(i=1;i<9;i++)
    {
       graph[i]=(int*)calloc(9,sizeof(int));
    }
    
    V=5;    
            
            
    for(i=1;i<=8;i++)
    {
      for(j=1;j<=8;j++)
      {
          printf("Enter 1 if there is egde between vertices %d,%d :",i,j);
          scanf("%d",&graph[i][j]);
      }
    }
 
    BFS( graph , 8, 1 , S);
    return 0;
}
//---------------------------------------------------------------

int BFS(int **G, int N, int Vs, int S[])
{ 
   struct queue *front, *rear;
   int i, u ,v;
   
   int enqueue(struct queue **front, struct queue **rear , int node);
   int dequeue(struct queue **front, struct queue **rear , int *node);
   int display(int v);
  
  
   front=NULL;
   rear=NULL;
   
   enqueue(&front , &rear, Vs);
   
   i=1;
   while(i<=N)
   {
     S[i]= 0;
     i=(i+1);
   }
   S[Vs]=1;
   
   
   while(front != NULL)
   {  
     
      dequeue(&front , &rear, &v);
      
    
      display(v);
      
      u=1;
      while(u<=N)
      {
         if((G[v][u] != 0) && (S[u] == 0))
         {
            S[u]=1;
            enqueue(&front , &rear, u);
           
         }
          
     
         
         u=(u+1);
      }
   }
   
   return(1);
}
//---------------------------------------------------------------------------
int enqueue(struct queue **front, struct queue **rear , int node)
{
  struct queue *p;
  
  p=(struct queue*)malloc(sizeof(struct queue));
  p->item = node;
  p->next= NULL;
  
  if((*front == NULL) && (*rear== NULL))
  {
     *front = p;
     *rear= p;
  }
  else
  {
     (*rear)->next =p;
     (*rear)= p;
  }
  
  return(1);
}
//----------------------------------------------------------------------------  
int dequeue(struct queue **front, struct queue **rear , int *node)  
{
  struct queue *p;
  
  if((*front == NULL))
  {
     return (1);
  }
  
  else
  {  
    p=(*front);
    
    *node=p->item;
    
    *front =(*front)->next;
    if(*front == NULL)
    {
      *rear=NULL;
      }
    
    free(p);
  }
  return(1);
}
//-----------------------
int display(int v)
{
  printf("\n%d\n",v);
  return(1);
}








