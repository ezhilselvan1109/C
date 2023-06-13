#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

struct Vertex {
   char label;
   bool visited;
};
int stack[MAX];
int top = -1;
struct Vertex* lstVertices[MAX];
int adjMatrix[MAX][MAX];
int vertexCount = 0;
void push(int item) {
   stack[++top] = item;
}
int pop() {
   return stack[top--];
}
int peek() {
   return stack[top];
}
bool isStackEmpty() {
   return top == -1;
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
   for(i = 0; i < vertexCount; i++) {
      if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false) {
         return i;
      }
   }
   return -1;
}

void depthFirstSearch() {
   int i;
   lstVertices[0]->visited = true;
   displayVertex(0);
   push(0);

   while(!isStackEmpty()) {
      int unvisitedVertex = getAdjUnvisitedVertex(peek());
      if(unvisitedVertex == -1) {
         pop();
      } else {
         lstVertices[unvisitedVertex]->visited = true;
         displayVertex(unvisitedVertex);
         push(unvisitedVertex);
      }
   }
}

int main() {
       int i, j,n,r,c,e;;
       printf("Enter the number of Vertex :\n");
       scanf("%d",&n);
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
            scanf("%d%d",&r,&c);
            addEdge(r,c);
        }
       printf("Depth First Search: ");
       depthFirstSearch();
       return 0;
}

/*
Enter the number of Vertex :
5
Enter the 5 Vertex :
0 1 2 3 4
Enter the number of Edge :
5
Enter Row :
0 1
Enter Row :
0 2
Enter Row :
0 3
Enter Row :
2 1
Enter Row :
2 4
Depth First Search: 0 1 2 4 3

*/
