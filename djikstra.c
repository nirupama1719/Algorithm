#include<stdio.h>
#include<stdbool.h>
int minimumDistance(int graph[],bool visited[],int vertices){
int minimum=999,minimum_position;
for(int i=0;i<vertices;i++){
if(visited[i]==false&&graph[i]<=minimum){
	minimum=graph[i];
	minimum_position=i;
}
}
return minimum_position;
}
void djikstra(int startNode,int vertices,int graph[vertices][vertices]){
int distance[vertices];
bool visited[vertices];
for(int i=0;i<vertices;i++){
distance[i]=999;
visited[i]=false;
}
distance[startNode]=0;
for(int i=0;i<vertices-1;i++){
int mD=minimumDistance(distance,visited,vertices);
visited[mD]=true;
for(int j=0;j<vertices;j++){
if(!visited[j]&&graph[mD][j]&&distance[mD]!=999&&distance[mD]+graph[mD][j]<distance[j])
distance[j]=distance[mD]+graph[mD][j];
printf("%d\t\t",distance[j]);
}
printf("\n");
}
}
int main(){
int vertices,startNode;
printf("Enter the number of vertices:\n");
scanf("%d",&vertices);
int graph[vertices][vertices];
printf("Enter the adjacency matrix:\n");
for(int i=0;i<vertices;i++){
for(int j=0;j<vertices;j++){
scanf("%d",&graph[i][j]);
}
}
printf("Enter the start node:\n");
scanf("%d",&startNode);
printf("Dijkstra's table is given as:\n");
djikstra(startNode,vertices,graph);
return 0;
}
