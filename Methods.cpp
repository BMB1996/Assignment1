
#include <iostream>
#include <fstream>
#include <string>
#include "Methods.h"

using namespace std; 

int ValueExists(int a[], const int aLength)
{
	//This function will ask for a value to check for then search the given array for the value
	//  and return the index of the requested value.
	int value;
	cout << "Enter a value to check for: ";
	cin >> value;
	for (int i = 0; i < aLength; i++) {
		if (a[i] == value) {
			return i;
		}
	}

	//If the value is not found in the array, the number -1 will be returned to indicate it was not in the array

	return -1;
}


int ReplaceValueAtIndex(int a[], const int aLength)
{
	//This function gets an index for replacement and the value to replace the current value
	//  and returns the value that has been replaced.
	int index;
	int newValue;

	cout << "Enter an index and a value seperated by a space: ";
	cin >> index >> newValue;
	int oldValue = a[index];
	cin >> newValue;

	a[index] = newValue;
	
	return oldValue;
}

void AddElement(int a[], int aLength, int* totalElements)
{
	//This function gets a new value from the user to add to the end of the list of integers of the users list
	//and adds one to the value of the total user elements.
	int newValue;

	cout << "Enter a new value to add to the array: ";
	cin >> newValue;

	a[*totalElements + 1] = newValue;
	*totalElements = *totalElements + 1;
}

void RemoveValue(int a[], const int aLength, int *totalElements)
{
	//This function gets the index that the user would like to remove then the indicies greater than that
	//  one, all elements get shifted to the right one space and the total elements gets decremented by one
	int index;
	cout << "Enter the index of the value you want to remove: ";
	cin >> index;
	for (int i = index; i < aLength; i++) {
		if (i == aLength - 1) {
			a[i] = 0;
			break;
		}
		a[index] = a[index + 1];
	}
	*totalElements = *totalElements - 1;
}

char Menu()
{
	char userOption;

	cout << "How would you like to interact with the array?:\n"
		<< "   (C)heck for a value\n"
		<< "   (M)odify a value\n"
		<< "   (A)dd a value\n"
		<< "   (R)emove a value\n";
	cin >> userOption;

	return userOption;
}