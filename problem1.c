#include<stdio.h>
int max(int a, int b){
if(a>b)
return a;
else
return b;
}
void knapsack(int weight[],int value[], int n, int capacity){
int knap[n+1][capacity+1];
int i,j;
for(i=0;i<=n;i++){
for(j=0;j<=capacity;j++){
if(i==0||j==0)
knap[i][j]=0;
else if(weight[i-1]<=j)
knap[i][j]=max(value[i-1]+knap[i-1][j-weight[i-1]],knap[i-1][j]);
else
knap[i][j]=knap[i-1][j];
}
}
printf("The knapsack Table:\n");
for(i=0;i<=n;i++){
for(j=0;j<=capacity;j++){
printf("%d\t",knap[i][j]);
}
printf("\n");
}
for(i=n;i>0;i--){
for(j=capacity;j>0;j--){
while(knap[i][j]>0){
if(knap[i][j]!=knap[i-1][j]){
printf("Selected Items:%d\n",i);
i=i-1;
j=j-weight[i];
}
else
i=i-1;
}
}
}
printf("The maximum value for given capacity:%d\n",knap[n][capacity]);
}
int main(){
int n,value[100],weight[100],capacity;
printf("Enter the number of objects:");
scanf("%d",&n);
printf("Enter the weights:");
for(int i=0;i<n;i++){
scanf("%d",&weight[i]);
}
printf("Enter the values:");
for(int i=0;i<n;i++){
scanf("%d",&value[i]);
}
printf("Enter the maximum capacity:");
scanf("%d",&capacity);
knapsack(weight,value,n,capacity);
}
