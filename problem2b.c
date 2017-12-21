#include<stdio.h>
void makeChange(int deno[], int amount, int n){
int table[amount+1],position[amount+1],minimum,temp;
table[0]=0;
position[0]=0;
for(int i=1;i<=amount;i++){
minimum=999;
for(int j=0;j<n;j++){
if(deno[j]<=i){
if(1+table[i-deno[j]]<minimum){
minimum=1+table[i-deno[j]];
position[i]=j;
}
}
}
table[i]=minimum;
}
printf("Minimum number of coins used for change:%d\n",table[amount]);
while(amount>0){
printf("Changes Used:%d\n",deno[position[amount]]);
amount=amount-deno[position[amount]];
}
}
int main(){
int n,deno[100],amount;
printf("Enter the number of denominations:");
scanf("%d",&n);
printf("Enter the denominations:");
for(int i=0;i<n;i++){
scanf("%d",&deno[i]);
}
printf("Enter the amount:");
scanf("%d",&amount);
makeChange(deno,amount,n);
}
