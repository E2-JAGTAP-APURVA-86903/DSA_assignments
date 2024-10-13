#include<stdio.h>
#define SIZE 10
#define SWAP(a,b) {temp=a; a=b; b=temp;}
int temp;

int iterations, comparisions;

void display(int arr[SIZE]);
void selection_sort(int arr[SIZE]);
void bubble_sort(int arr[SIZE]);
void insertion_sort(int arr[SIZE]);


int main()
{
    int arr1[SIZE] = {22,11,44,33,21,45,67,89,12,21};
    printf("\n before bubble sort:\n");
    display(arr1);
    bubble_sort(arr1);
    printf("\n after bubble sort\n");
    display(arr1);
    printf("\n iterations = %d  comparisions = %d", iterations, comparisions);



    int arr2[SIZE]= {21,12,32,23,43,34,54,45,65,56};
    printf("\n before selection sort:\n");
    display(arr2);
    selection_sort(arr2);
    printf("\n after selection sort :\n");
    display(arr2);
    printf("\n iterations = %d  comparisions = %d\n", iterations, comparisions);



    int arr3[SIZE]={98,89,76,78,65,67,54,32,12,34};
    printf("\n before insertion sort:\n");
    display(arr3);
    insertion_sort(arr3);
    printf("\nafter insertion sort:\n");
    display(arr3);
    printf("\n iterations = %d comparisions= %d\n",iterations,comparisions);

    return 0;

}

// selection sort
void selection_sort(int arr[SIZE])
{
    iterations=0;
    comparisions=0;
    int sel_pos,pos;

    for(sel_pos=0;sel_pos<SIZE-1;sel_pos++) {
        iterations++;
        for(pos=sel_pos+1;pos<SIZE;pos++) {
            comparisions++;
            if(arr[sel_pos]>arr[pos]) {
                SWAP(arr[sel_pos],arr[pos]);
            }
        }
    }
}

// bubble sort
void bubble_sort(int arr[SIZE])
{
    iterations=0;
    comparisions=0;
    int i,pos;
    for(i=0;i<SIZE-1;i++) {
        iterations++;
        for(pos=0;pos<SIZE-1-i;pos++) {
            comparisions++;
            if(arr[pos]>arr[pos+1]) {
                SWAP(arr[pos],arr[pos+1]);
            }
        }
    }

}

// insertion sort
void insertion_sort(int arr[SIZE])
{
    iterations=0;
    comparisions=0;
    int i,j,temp;
    for(i=1;i<SIZE;i++) {
        iterations++;
        temp=arr[i];
        for(j=i-1;j>=0 &&arr[j]>temp; j--) {
            comparisions++;
            arr[j+1] = arr[j];

        }
        arr[j+1]= temp;
    }
}

//display
void display(int arr[SIZE])
{
    for(int i=0;i<SIZE;i++)
    {
        printf("%4d",arr[i]);
    }
    printf("\n");
}