#include<stdio.h>
#include<stdlib.h>
struct stack
{
   int item;
   struct stack *next;
};

int main()
{  
    
    int V,i,j;
    int S[4], **graph;
    
    
    int DFS(int **G, int N, int Vs,int S[]);    
   int push(struct stack **top, int node);
    int pop(struct stack **top, int *node);
    
    
   
    
    graph=(int**)calloc(4,sizeof(int*));
    for(i=1;i<4;i++)
    {
       graph[i]=(int*)calloc(4,sizeof(int));
    }
    
    V=3;    
            
            
    for(i=1;i<=3;i++)
    {
      for(j=1;j<=3;j++)
      {
          printf("Enter 1 if there is egde between vertices %d,%d :",i,j);
          scanf("%d",&graph[i][j]);
      }
    }
 
    DFS( graph , 3, 1 , S);
    return 0;
}
//--------------------------------
int DFS(int **G, int N, int vs,int S[])
{
   struct stack *top;
   int i,u,v,j;
   
   int push(struct stack **top, int node);
   int pop(struct stack **top, int *node);
   
   top= NULL;
   push(&top, vs);
   
   i=1;
   while(i<=N)
   {
     S[i]=0;
     i=i+1;
   }
   S[vs]=1;
   
   while(top != NULL)
   {
      
      pop(&top,&u);
      printf("\n%d",u);
      
      v=1;
      while(v<=N)
      {
         if((G[u][v]!=0 )&& (S[v]==0))
         {
             S[v]=1;
             push(&top, v);
         }
         v=v+1;
      }
      
    }
    return(1);
 }
 //-----------------------------------
 int push(struct stack **top, int node)
 {
   struct stack *p;
   
   p=(struct stack*)malloc(sizeof(struct stack));
   p->item=node;
   p->next =NULL;
   
   if(*top == NULL)
   {
      *top=p;
   }
   else
   {
     p->next=(*top);
     *top=p;
   }
   return(1);
 }
 //----------------
 int pop(struct stack **top, int *node)
 {
 
    struct stack *p;
    
    if(*top== NULL)
    {
      	return(1);
    } 
    else
    {
       *node=(*top)->item;
       (*top)=(*top)->next;
    }
    return(1);
 }
 
    
    
           
  
   
