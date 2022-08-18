#include <stdio.h>

//Function Declarations
void enqueue(int num);
int dequeue();
void bfs(int v, int graph[10][10], int start);
void adjMatrix(int G[10][10], int noOfVertices);

//global variables
int queue[10] = {0};
int front = -1, rear = -1;

int main()
{
    int noOfVertices = 0, i = 0, start = 0;
    int G[10][10] = {0};
    printf("Enter the number of vertices (less than 10): ");    //Taking number of vertices
    scanf("%d",&noOfVertices);
    printf("A null graph has been made with vertices: ");
    for(i = 0;i<noOfVertices; i++)
    {
        printf("v%d ",i);
    }
    adjMatrix(G, noOfVertices);
    
    printf("Enter the starting element for bfs: v");
    scanf("%d",&start);
    
    printf("BFS traversal: ");
    bfs(noOfVertices, G, start);
}
void bfs(int v, int graph[10][10], int start)       //breadth-first traversal of graph
{
    int i = 0, j = 0, num = 0;
    int visited[10] = {0};
    
    enqueue(start);
    visited[start] = 1;
    while(front<=rear)
    {
        num = dequeue();
        for(j=0;j<v;j++)
        {
            if(graph[num][j]==1 && visited[j]==0)
            {
                enqueue(j);
                visited[j] = 1;
            }
        }
    }
}
void enqueue(int num)       //insert element into queue[]
{
    if(rear==-1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = num;
}
int dequeue()               //delete element from queue[]
{
    int num = 0;
    num = queue[front];
    printf("v%d ",queue[front]);
    front++;
    return num;
}
void adjMatrix(int G[10][10], int noOfVertices)     //make adjacency matrix of directed graph by taking input from user
{
    int i = 0, j = 0;
    printf("\nEnter the adjacency matrix of directed graph: \n");
    
    for(i = 0;i<noOfVertices; i++)
    {
        printf("Enter the connected vertices for vertice v%d : ",i);
        for(j = 0;j<noOfVertices; j++)
        {
            scanf("%d",&G[i][j]);
        }
        printf("\n");
    }
    printf("The adjacency matrix is: \n");
    for(i = 0;i<noOfVertices; i++)
    {
        for(j = 0;j<noOfVertices; j++)
        {
            printf("%d ",G[i][j]);
        }
        printf("\n");
    }
}