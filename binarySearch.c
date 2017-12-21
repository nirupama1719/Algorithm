#include<stdio.h>
int main(){
int array[20],i,n;
printf("Enter number of elements in array:");
scanf("%d",&n);
printf("Enter array elements:");
for(i=1;i<=n;i++){
scanf("%d",&array[i]);
}
find_index(array,n);
}
void find_index(int *array,int size){
int mid;
int first=0,last=size;
//mid=(first+last)/2;
while(first<=last){
mid=(first+last)/2;
if(array[mid]==mid){
printf("Index matches element!\n");
return 0;
}
if(array[mid]<mid)
	first=mid+1;
else
	last=mid-1;
}
printf("No indexes match array elements\n");
}
