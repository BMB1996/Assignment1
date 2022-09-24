#include <iostream>
#include <fstream>
#include <string>
#include "Methods.h"

using namespace std;

int main() {
	
	//Variable declaration beginning with constant variable for the array then the variables for reading the string
	//   read in the file name and the file stream that will come in.
	const unsigned int ARR_VAL = 100;
	string fileName;
	int arr[ARR_VAL];
	ifstream file;
	int index = 0;
	int value = 0;
	int arrElements = 0;
	int* elements = &arrElements;
	char userOption = 'c';

	//For loop assigns all values of the array with 0 instead of a NULL value.
	for (int i = 0; i < ARR_VAL; i++) {
		arr[i] = 0;
	}

	//Prompts user to input a .txt file name.
	cout << "Enter a .txt file that you would like to use.\n";

	//Assigns fileName to user input.
	cin >> fileName;

	//open the file of the given name, then while there is data remaining, assign it to the index of the array and post operation increment.
	file.open(fileName);
	while (file.good()) {
		file >> arr[index++];
		arrElements++;
	}
	while (userOption != 'E') {
		userOption = Menu();
		switch (userOption) {
		case 'C':
			index = ValueIndex(arr, ARR_VAL);
			break;
		case 'M':
			value = ReplaceValueAtIndex(arr, ARR_VAL);
			break;
		case 'A':
			AddElement(arr, ARR_VAL, elements);
			break;
		case 'R':
			RemoveIndex(arr, ARR_VAL, elements);
			break;
		default:
			break;
		}
	}
	return 1;
}