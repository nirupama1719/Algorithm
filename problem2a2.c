#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int power(int m, int n){
if(n==0)
	return 1;
else if(n%2==0)
	return power(m,n/2)*power(m,n/2);
else
	return m*power(m,n/2)*power(m,n/2);
}
int makeChange(int *denominations, int amount, int n){
if(amount<=0){
printf("Cannot make change!\n");
return 0;
}
for(int i=n;i>=1;i--){
if(amount>=denominations[i-1]){
printf("Change Used:%d\n",denominations[i-1]);
if((amount-denominations[i-1])>0){
return makeChange(denominations,(amount-denominations[i-1]),n);
}
else
return 0;
}
}
}
int main(){
int c,k,denominations[100],amount;
printf("Enter the base for currency(c):");
scanf("%d",&c);
printf("Enter the number of denominations:");
scanf("%d",&k);
for(int i=0;i<k;i++){
denominations[i]=power(c,i);
}
printf("Enter the amount for change:");
scanf("%d",&amount);
makeChange(denominations,amount,k);
}
