#include <iostream>
#include <stdio.h>
using namespace std;

int array[]={34,65,12,43,67,5,78,10,3,70};

void bubbleSort(int a[], int size){
    int tmp = 0;
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(a[j]>a[j+1]){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    return;
}

void quickSort(int a[], int left, int right){
    if(left<right){
        int i = left, j = right, prikey = a[i];
        while(i<j){
            while(i<j && a[j]>=prikey) j--;
            if(i<j) a[i++] = a[j];
            while(i<j && a[i]<prikey) i++;
            if(i<j) a[j--] = a[i];
        }
        a[i] = prikey;
        quickSort(a, left, i - 1);
        quickSort(a, i + 1, right);
    }
    return;
}

void insertSort(int a[], int size){
    for(int i=1; i<size; i++){
        if(a[i-1]>a[i]){
            int tmpidx = i-1;
            int tmp = a[i];
            a[i] = a[i-1];
            while(tmp < a[tmpidx]){
                a[tmpidx+1] = a[tmpidx];
                tmpidx--;
            }
            a[tmpidx+1] = tmp;
        }
    }
    return;
}

void selectionSort(int a[], int size){
    int i, j, min, max, tmp;
    for(i = 1; i <= size/2; i++){
        min = i; max = i;
        for(j = i+1; j <= size - i; j++){
            if(a[j]>a[max]){
                max = j;
                continue;
            }
            if(a[j]<a[min]){
                min = j;
            }
        }
        tmp = a[i-1]; a[i-1] = a[min]; a[min] = tmp;
        tmp = a[size-i]; a[size-i] = a[max]; a[max] = tmp;
    }
}

int main()
{
    int k;
    int len=sizeof(array)/sizeof(int);
    cout<<"The orginal arrayare:"<<endl;
    for(k=0;k<len;k++)
        cout<<array[k]<<",";
    cout<<endl;
    selectionSort(array, len);
    //quicksort(array,0,len-1);
    cout<<"The sorted arrayare:"<<endl;
    for(k=0;k<len;k++)
        cout<<array[k]<<",";
    cout<<endl;
    return 0;
}
