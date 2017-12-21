#include <stdio.h>
int main()
{
	    int array[20],i,n;
	    printf("Enter the number of elements in array:");
            scanf("%d",&n);
            printf("Enter the array elements:");
            for(i=0;i<n;i++){
	    scanf("%d",&array[i]);
	    }
	    SelectionSort(array,n);
	    //for(i=0;i<n;i++){
            //printf("%d\n",array[i]);
	    if((n%2)==0){
	    printf("Median:%0.3f\n",(array[n/2]+array[n/2-1])/2.0);
	    }
	    else{
	    printf("Median:%d\n",array[n/2]);
	    } 
}

void SelectionSort(int *array,int size){
	    int i, j, min, temp;
            for (i = 0; i < size - 1; i++) {
	    min = i;
            for (j = i + 1; j < size; j++){
	        if (array[j] < array[min])
	            min = j;
	    }
	    if (min != i) {
	        temp = array[i];
	        array[i] = array[min];
	        array[min] = temp;
	    }
	 }
}





