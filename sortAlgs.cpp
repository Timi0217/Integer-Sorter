#include "sortAlgs.h"
#include <iostream>
#include <vector>

using namespace std;

//declaration of function to get the size of a vector
int vectorSize(vector <int> x);

void swap(int *y, int *x);

void print(vector <int> x);

unsigned int divideLabor(vector <int> &A, unsigned int left, 
			unsigned int right);

void quickSortHelp(vector<int> &A, unsigned int left, unsigned int right);


//function to get the size of the vector
int vectorSize(vector <int> x){
	return x.size();
}

//this function contains my quicksort algorithm. It takes in a reference to a 
//vector as a parameter and sorts it in ascending order.
void quickSort(vector <int> &vectorMine){
	unsigned int left, right;
	left = 0;
	right = vectorMine.size() - 1;
	quickSortHelp(vectorMine, left, right);	
} 

//this is a helper function to my quicksort function that takes in a reference 
//to a vector. It contains the recursive step for the quicksort, and uses a 
//pivot to identify the starting and ending positions and then recursively 
//sorts each part. It returns nothing.
void quickSortHelp(vector<int> &vectorMine, unsigned int left,
					unsigned int right) {
	if(vectorMine.empty()){
		return;
	}
		
	if (left < right){ 
		unsigned int pindex = divideLabor(vectorMine, left, right);
		if (pindex > 0){
			quickSortHelp(vectorMine, left, pindex -1);
		}
		quickSortHelp(vectorMine, pindex + 1, right);
		return;
	}
}

//this helper function for the quicksort chooses a pivot and then sorts the
//vector. it takes in a reference to a vector, and the starting and ending
//indexes. It returns an unsigned int that is the position of the vector.
unsigned int divideLabor(vector <int> &A, unsigned int left, unsigned int right){
	int pivot = A.at(right);
	unsigned int current = left;
	for(unsigned int i = left; i< right; i++){
		if(A.at(i) <= pivot){
			swap(A[i], A[current]);
			current+=1;
		}
	}d
	swap(A[current], A[right]);
	return current;
}

//Insertion sort
void print(vector <int> x){
	unsigned int size = x.size();
    	for (unsigned int i = 0; i < size; i++)
        	cout << x[i] << endl;
}

//This function contains my algorithm for insertion sort. it takes in a
//reference to a vector of integers. It returns nothing.
void insertionSort(vector <int> &integers){
	unsigned int size = integers.size();
	unsigned int sortedSize = 1;
	if(integers.empty()){
		return;
	}
	
	else{
		while(sortedSize < size){
			unsigned int iterate = sortedSize;
			for(int i = iterate - 1; i >= 0; i--){
				if(integers[iterate] < integers[i]){
					swap(integers[iterate], integers[i]);
				}
				iterate--;
			}
			sortedSize++;
		}
	
	}
}

//this helper function takes two pointers to integers and swaps their values.
//It returns nothing
void swap(int *y, int *x){
	int temp = *x;
	x = y;
	*y = temp;
}

//This function contains my algorithm for bucketSort. It takes in a reference to 
//a vector and returns nothing  
void bucketSort(vector <int> &myVector)
{
    if(myVector.empty()){
    	return;
    }
    int counter = 0;
    for(unsigned int i = 0; i < myVector.size(); i++){
    	if(counter < myVector.at(i)){
    		counter = myVector.at(i);
    	}
    }
    vector <int> temp;
    for(int i = 0; i < counter + 1; i++){
    	temp.push_back(0);
    }
    for(unsigned int i = 0; i < myVector.size(); i++){
    	temp[myVector.at(i)]++;
    }
    myVector.clear();
    for(unsigned int i = 0; i < temp.size(); i++){
    	if(temp.at(i) > 0){
    		for(int k = 0; k < temp.at(i); k++){
    			myVector.push_back(i);
    		}
    	}
    }    
}

