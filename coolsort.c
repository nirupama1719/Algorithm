#include<stdio.h>
#include<stdlib.h>
void sort(int array[20],int stepsize,int size){
int count=0,key;
for(int i=count+stepsize;i<size;i++){
key=array[i];
int j=i-stepsize;
while(j>=0&&array[j]>key){
array[j+stepsize]=array[j];
j=j-stepsize;
}
array[j+stepsize]=key;
i=i+stepsize;
if(i>=size&&count<=stepsize){
count++;
i=count+stepsize;
}
}
}
int main(){
int a[20],n,coolArray[10];
printf("Enter number of elements:");
scanf("%d",&n);
printf("Enter array elements:");
for(int i=0;i<n;i++){
scanf("%d",&a[i]);
}
printf("Enter the step array:");
for(int j=0;j<3;j++){
scanf("%d",&coolArray[j]);
}
for(int k=0;k<sizeof(coolArray);k++){
sort(a,coolArray[k],n);
}
for(int i=0;i<n;i++){
printf("Sorted Array:\n");
printf("%d",a[i]);
}
}
