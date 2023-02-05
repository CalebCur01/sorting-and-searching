//sorting and searching.c - Implementing a few sort and search algorithims for fun and practice
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5
//declaring functions
int getRandom();
void printArray(int arr[],int size);
void arraySwap();
void selectionSort(int arr[], int size);
void insertionSort(int arr[],int size);
void bubbleSort(int arr[],int size);
int linearSearch(int arr[],int size,int val);
int binarySearch(int arr[],int size,int val);

int main(){
    //First we make an array of length SIZE, fill with random numbers, and then we copy it (to sort the same list diffrent ways)
    srand(time(0));
    int numbers1[SIZE];
    int numbers2[SIZE];
    int numbers3[SIZE];
    
    for(int i = 0;i<SIZE;i++){
      numbers1[i] = getRandom(0,99);
      numbers3[i] = numbers2[i] = numbers1[i];
    }
    //we print the unsorted arrays, then we run each sorting algorithim 
    printf("SelectionSort: ");
    printArray(numbers1,SIZE);
    selectionSort(numbers1,SIZE);
    
    printf("BubleSort: ");
    printArray(numbers2,SIZE);
    bubbleSort(numbers2,SIZE);
    
    printf("InsertionSort: ");
    printArray(numbers3,SIZE);
    insertionSort(numbers3,SIZE);

    return 0;
}

int getRandom(int lower, int upper){ //returns a random number within range [lower,upper]
    int num = rand() % (upper - lower + 1) + lower;
    return num;
}
void insertionSort(int arr[],int size){ //we find and insert the minimum element one at a time until we have a sorted list
    int key,j;
    for(int i = 1;i<size;i++){
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key){		//this while loop is iteraing backwards and "pushing"
            arr[j+1] = arr[j];				//the array elements forward, until we reach 0 or we find a elements less than
            j--;							//or equal to "key"
        }
        arr[j+1] = key;					//now we add our key value in at the front
        printArray(arr,size);
    }
}
void selectionSort(int arr[],int size){ //we iterate through the array and place each element into the proper place at each step
    int min,mindx,temp;
    for(int i = 0;i<size-1;i++){		//we iterate through the list, finding the minimum element
        min = arr[i];					
        for(int j = i+1;j<size;j++){
            if(arr[j] < min){
                min = arr[j];
                mindx = j;
            }
        }
        temp = arr[i];		//now that we found the min element, we swap it into the sorted list
        arr[i] = min;		//for each step, we have a sorted list of length n, so at the 3rd step the first 3 elements
        arr[mindx] = temp;	//are in guaranteed to be in order
        printArray(arr,size);
    }
}
void bubbleSort(int arr[],int size){ 	//we iterate thorugh the array and compare each element to the one in front of it
    for(int i = 0;i<size;i++){			//and swap accordingly. The highest value "bubbles" to the top. 
        for(int j = 0;j<size-1;j++){	//at the nth step, the nth largest element is in place. Very simple
            if(arr[j]>arr[j+1])
                arraySwap(arr,j+1,j);
        }   printArray(arr,size);
    }
}
void printArray(int arr[],int size){ //print all elements of the array
    for(int i = 0;i<size;i++)
        (i == size-1) ? printf("%d\n",arr[i]): printf("%d,",arr[i]);
}
void arraySwap(int arr[],int indx1, int indx2){// swap values of indx1 and indx2
    int temp = arr[indx1];
    arr[indx1] = arr[indx2];
    arr[indx2] = temp;
}
int linearSearch(int arr[],int size,int val){ //the most basic search 
	for(int i = 0;i<size;i++)		  //we iterate through the list one element at a time
		if(arr[i] == val)			  //returns index of the earliest occurence of searched value, or -1 if it doesn't find it
			return i;
	return -1;
}
int binarySearch(int arr[],int size, int val){ //works only on a sorted list. We split the array in half until we find value
    int leftEnd = 0;                          
    int rightEnd = size-1;               
    int middle;
    while(leftEnd <= rightEnd){    
        middle = (leftEnd+rightEnd)/2;
        if(arr[middle] == val)
            return middle;
        if(arr[middle] < val)
            leftEnd = middle + 1;
        else
            rightEnd = middle;
    }
    return -1;
}
