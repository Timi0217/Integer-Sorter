#include <iostream>
#include <vector>
#include "sortAlgs.h"
#include <cstdlib>
#include <time.h>
using namespace std;

void printCheck(vector <int> x, int y);
void populateVector(int testcase, vector<int>&toPopulate);

int main(){
	vector <int> test;
	int populateType;
	populateType = 3;
	//populateType = 2;
	//populateType = 3;
	populateVector(populateType, test);
	int max = test.size();
	
	//testing each algorithm
	bucketSort(test);
	//quickSort(test);
	//insertionSort(test);
	
	//print out sorted list and check that it's all sorted properly
	printCheck(test, max);
	
return 0;
}

void printCheck(vector <int> test, int max){
	for(int i = 0; i < max; i++){
		cout << test[i] << endl;
		if(test[i] > test[i+1]){
		}
	}
}

void populateVector(int testCase, vector<int>&toPopulate){
	if (testCase == 1){
		//populating vector with with numbers in ascending order
		for(int i = 0; i < 10000; i++){
			toPopulate.push_back(i);
		}
	}
	
	else if (testCase == 2){
		//populating vector with with numbers in descending order
		for(int i = 10000; i > 0; i--){
			toPopulate.push_back(i);
		}
	}
	
	else if (testCase == 3){
		//populating vector with random numbers
		srand(time(NULL));
		int random = 0;
		for(int i = 0; i < 10000; i++){
			random = rand() % 10000 + 1;
			toPopulate.push_back(random);
		}
	}
}








