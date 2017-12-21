#include<stdio.h>
int makeChange(int *denominations,int amount,int n){
if(amount<=0){
printf("Cannot make change for amount!\n");
return 0;
}
for(int i=n;i>=1;i--){
if(amount>=denominations[i-1]){
printf("Changes used:%d\n",denominations[i-1]);
if((amount-denominations[i-1])>0){
return makeChange(denominations,(amount-denominations[i-1]),n);
}
else
return 0;
}
}
}
int main(){
int denominations[4]={1, 5, 10, 25};
int amount;
printf("Enter the amount for calculating change:");
scanf("%d",&amount);
makeChange(denominations,amount,4);
}

