#include <stdio.h>
#include <stdbool.h>

#define MAX 10

struct Vertex {
       char label;
       bool visited;
};

int queue[MAX];
int rear = -1;
int front = 0;
int queueItemCount = 0;

struct Vertex* lstVertices[MAX];
int adjMatrix[MAX][MAX];
int vertexCount = 0;

int main() {
       int i, j,n,r,c,e;;
       printf("Enter the number of Vertex :\n");
       scanf(" %d",&n);
       int adjMatrix[n][n];
       char ch;
       for(i = 0; i<n; i++)
          for(j = 0; j<n; j++)
             adjMatrix[i][j] = 0;
       printf("Enter the %d Vertex :\n",n);
       for(i=0;i<n;i++){
            scanf(" %c",&ch);
            addVertex(ch);
       }
       printf("Enter the number of Edge :\n");
       scanf(" %d",&e);
       for(i=0;i<e;i++){
            printf("Enter Row :\n");
            scanf(" %d%d",&r,&c);
            addEdge(r,c);
        }
       printf("\nANS: ");
       breadthFirstSearch();
       return 0;
}

void insert(int data) {
       queue[++rear] = data;
       queueItemCount++;
}
int removeData() {
       queueItemCount--;
       return queue[front++];
}
bool isQueueEmpty() {
       return queueItemCount == 0;
}
void addVertex(char label) {
       struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
       vertex->label = label;
       vertex->visited = false;
       lstVertices[vertexCount++] = vertex;
}
void addEdge(int start,int end) {
       adjMatrix[start][end] = 1;
       adjMatrix[end][start] = 1;
}
void displayVertex(int vertexIndex) {
       printf("%c ",lstVertices[vertexIndex]->label);
}
int getAdjUnvisitedVertex(int vertexIndex) {
       int i;
       for(i = 0; i<vertexCount; i++) {
          if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false)
             return i;
       }
       return -1;
}

void breadthFirstSearch() {
       int i;
       lstVertices[0]->visited = true;
       displayVertex(0);
       insert(0);
       int unvisitedVertex;
       while(!isQueueEmpty()) {
          int tempVertex = removeData();
          while((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1) {
             lstVertices[unvisitedVertex]->visited = true;
             displayVertex(unvisitedVertex);
             insert(unvisitedVertex);
          }
       }
}


