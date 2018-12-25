//interactive and automated mode
//takes in the algorithm, output mode, and file name.
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include "sortAlgs.h"

using namespace std;	

//function declaration for function that prints errors
void printError();

//function declaration for function that runs the whole program
void run(vector <int> x, string sortAlg, string mode, string filename);

//function declaration for function that prints out a vector
void printSorted(vector <int> x);


int main(int argc, char *argv[]){
	//check for command line arguments being satisfied
	if (argc != 3 && argc != 4){
		printError();
	}
	//check for right sort algo being selected
	if(strcmp(argv[1],"-s1") != 0 && strcmp(argv[1],"-s2") !=0
	 	  && strcmp(argv[1],"-s3") != 0){
		printError();
	}
	string sortAlg = argv[1];
	string outputMode = argv[2];
	
	//enter automated mode
	if(argc == 4){
		string filename = argv[3];
		vector <int> intFile;
		ifstream file_stream;
		file_stream.open(filename.c_str());
		if (file_stream.fail()){
			cerr << "The file failed to open" << endl;
		}
		int count = 0;	
		int content;
		while(!file_stream.eof()){
			file_stream >> content;
			intFile.push_back(content);
			count++;
		}
		run(intFile, sortAlg, outputMode, filename);
		file_stream.close();	
	}
	
		
	//enter interactive mode
	else{
		int content;
		vector <int> intFile;
		while (!cin.eof()){
			intFile.push_back(content);
			cin >> content;
		}
		string filename = "cin";
		run(intFile, sortAlg, outputMode, filename);
	}

	
return 0;
}

//function definition for printing errors
void printError(){
	cerr << "Usage: sorter sortAlgorithm outputMode [fileName] " << endl;
	cerr << "where: sortAlg is -s1, -s2, or -s3 and outputMode is ";
	cerr <<  "--print or --save " << endl;
	exit(1);
}
//This function takes in a vector to be sorted, a string that represents the 
//mode to be used and a filename that data is read from if applicable
//It returns nothing	
void run(vector <int> x, string sortAlg, string mode, string filename){
	string numSortAlg;
	if(sortAlg == "-s1"){
		insertionSort(x);
		numSortAlg = "1";
	}
		
	else if(sortAlg == "-s2"){
		quickSort(x);
		numSortAlg = "2";
	}
		
	else if(sortAlg == "-s3"){
		bucketSort(x);
		numSortAlg = "3";
	}
	
	if(mode == "--print"){
		printSorted(x);
	}
	
	else if(mode == "--save"){
		string listOrigin = filename;
		int sortedSize = x.size();
		string numElementsSorted = to_string(sortedSize);
		string fileName = listOrigin + "_" + numSortAlg + "_" + 
					      numElementsSorted + "_sorted.txt";
		ofstream saveSorted;
		cerr << fileName << endl;
		saveSorted.open(fileName);
		int content;
		for(size_t i = 0; i < x.size(); i++){
				content = x[i];
				saveSorted << content << endl;	
		}
		saveSorted.close();		
	}
	
	else{
		printError();
	}
}

//This function is used to print out all the elements in a vector. It takes 
//a vector as a parameter and returns nothing.
void printSorted(vector <int> x){
	for(size_t i = 0; i < x.size()-1; i++){
		cout << x[i] << endl;
	}
}
