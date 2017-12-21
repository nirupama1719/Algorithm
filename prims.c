#include<stdio.h>
#include<stdlib.h>
struct treenode{
int value;
int distance;
struct treenode *nextnode;
};
struct treeedge{
int distance;
int x,y;
};
struct treenode * addEdge(struct treenode *start,int number,int distance){
struct treenode *current=(struct treenode *)malloc(sizeof(struct treenode));
current->value=number;
current->nextnode=start;
current->distance=distance;
start=current;
return current;
}
void deleteTreeNode(struct treeedge[],int,int);
void heaptree(struct treeedge current[],int treesize,int treeindex){
int k=treeindex;
struct treeedge temp;
while((2*k)<treesize){
if((2*k)+1>=treesize){
if(current[k].distance>current[2*k].distance){
temp=current[k];
current[k]=current[2*k];
current[2*k]=temp;
break;
}
}
if (current[k].distance>current[2*k].distance||current[k].distance>current[2*k+1].distance){
if(current[2*k].distance<=current[(2*k)+1].distance){
temp=current[2*k];
current[2*k]=current[k];
current[k]=temp;
k=2*k;
} 
else if(current[2*k].distance>current[(2*k)+1].distance){
temp=current[(2*k)+1];
current[(2*k)+1]=current[k];
current[k]=temp;
k=(2*k)+1;
}
}
else{
break;
}
}
}
void enterQueue(struct treeedge current[], int treesize, struct treeedge value){
current[treesize]=value;
int k=treesize;
struct treeedge temp;
while(k>=1){
if(current[k/2].distance>current[k].distance){
temp=current[k/2];
current[k/2]=current[k];
current[k]=temp;
k=k/2;
}
else{
break;
}
}
}
struct treeedge extractMin(struct treeedge current[], int treesize){
struct treeedge minimum=current[0];
deleteTreeNode(current,treesize,0);
return minimum;
}
void deleteTreeNode(struct treeedge current[], int treesize, int treeindex){
struct treeedge temp=current[treeindex];
current[treeindex]=current[treesize-1];
current[treesize-1]=temp;
int k=treeindex;
--treesize;
heaptree(current,treesize,k);
}
void primsMinTree(struct treenode * adjacencyMatrix[],int vertices,int treeedge,int startNode,struct treenode * minSpanTree[]){
int current=startNode,nextNode;
int visited[vertices+1];
struct treenode *temp;
struct treeedge curedge;
struct treeedge pQueue[2*treeedge];
int qSize=0;
int k;
for(k=0;k<=vertices;++k)
	visited[k]=0;
k=0;
while(k<vertices){
if(visited[current]==0){
visited[current]=1;
temp=adjacencyMatrix[current];
while(temp!=NULL){
curedge.x=current;
curedge.y=temp->value;
curedge.distance=temp->distance;
if(!visited[curedge.y]){
enterQueue(pQueue,qSize,curedge);
++qSize;
}
temp=temp->nextnode;
}
curedge=extractMin(pQueue,qSize);
--qSize;
nextNode=curedge.y;
current=curedge.x;
if(visited[nextNode]==0){
minSpanTree[current]=addEdge(minSpanTree[current],nextNode,curedge.distance);
minSpanTree[nextNode]=addEdge(minSpanTree[nextNode],current,curedge.distance);
}
current=nextNode;
++k;
}
else{
curedge=extractMin(pQueue,qSize);
--qSize;
nextNode=curedge.y;
current=curedge.x;
if(visited[nextNode]==0){
minSpanTree[current]=addEdge(minSpanTree[current],nextNode,curedge.distance);
minSpanTree[nextNode]=addEdge(minSpanTree[nextNode],current,curedge.distance);
}
current=nextNode;
}
}
} 
int main(){
int vertices,treeedges,i,j,k,l,distance;
printf("Enter the number of vertices:\n");
scanf("%d",&vertices);
printf("Enter the number of edges:\n");
scanf("%d",&treeedges);
printf("Enter the edges along with vertices:\n");
struct treenode * adjacencyMatrix[vertices+1];
struct treenode * minSpanTree[vertices+1];
for(i=0;i<=vertices;i++){
adjacencyMatrix[i]=NULL;
minSpanTree[i]=NULL;
}
for(i=1;i<=treeedges;i++){
scanf("%d%d%d",&k,&l,&distance);
adjacencyMatrix[k]=addEdge(adjacencyMatrix[k],l,distance);
adjacencyMatrix[l]=addEdge(adjacencyMatrix[l],k,distance);
}
int startNode;
printf("\nEnter a start node:");
scanf("%d",&startNode);
primsMinTree(adjacencyMatrix,vertices,treeedges,startNode,minSpanTree);
printf("\n Minimum Spanning Tree:\n");
for(i=1;i<=vertices;i++){
printf("From Node %d",i);
struct treenode * temp=minSpanTree[i];
while(temp!=NULL){
printf(" to Node %d with distance %d",temp->value,temp->distance);
temp=temp->nextnode;
}
printf("\n");
}
return 0;	
}
