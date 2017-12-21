#include<stdio.h>
#include<string.h>
int max(int a, int b){
if(a>b)
	return a;
else
	return b;
}
void lcs(char a[100], int n, char b[100], int m){
int sub[n+1][m+1];
for(int i=0;i<=n;i++){
for(int j=0;j<=m;j++){
if(i==0||j==0)
	sub[i][j]=0;
else if(a[i-1]==b[j-1])
	sub[i][j]=sub[i-1][j-1]+1;
else
	sub[i][j]=max(sub[i-1][j],sub[i][j-1]);
}
}
int subLength=sub[n][m];
printf("Length of the longest subsequence is:%d\n",subLength);
char substring[subLength+1];
substring[subLength]='\0';
int i=n;
int j=m;
while(i>0&&j>0){
if(a[i-1]==b[j-1]){
substring[subLength-1]=a[i-1];
i=i-1;
j=j-1;
subLength=subLength-1;
}
else if(sub[i-1][j]>sub[i][j-1]){
i=i-1;
}
else
j=j-1;
}
printf("Longest common subsequence:%s\n",substring);
}
int main(){
char a[100], b[100];
printf("Enter the first string:");
scanf("%s",&a);
printf("Enter the second string:");
scanf("%s",&b);
lcs(a,strlen(a),b,strlen(b));
return 0;
}
