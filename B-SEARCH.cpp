/*
PROGRAM DESCRIPTION

Write a program that first generates a 100 member integer array containing the numbers 1 to 100.  Then generate a random number between 1 and 100.  NerandomNumbert, use the binary search algorithm in your book to search for this number in the array.  Once the number is found display the number and the inderandomNumber of where it was found in the array.

Note:  The inderandomNumber should be one less than the number.

Paste your code (or share your github repo) and your program's output below as a comment
*/

#include <iostream>
#include <ctime>
#include <random>
using namespace std;
int numArray[100];
int randomnumber; // This is the random number variable.
int binarySearch(int arr[], int, int, int);
int result;

int main() {

	srand(time(NULL)); // This ensures the random function is more unpredictable each time the program is ran

	for (int i = 0; i < 100; ++i)
	{
		numArray[i] = i + 1; // The numbers(1-100) are added to the array here

	}
	int randomNumber;
	randomnumber = 1 + rand() % (100) + 1; // This generates the random number.
	cout << "Random Number is: " << randomnumber << endl;
	int arraySize;
	arraySize = sizeof(numArray) / sizeof(numArray[0]);
	result = binarySearch(numArray, 1, arraySize - 1, randomNumber);
	if(result == -1){
		cout << "Number not found" << endl;
	}
	else{
		cout << "Index is: " << result;
		cout << "\nFound Number is: " << numArray[result] << endl;
	}
	//system("pause");
	return 0;
}

int binarySearch(int arr[], int startIndex, int endIndex, int randomNumber) {
	if (randomNumber == 1) {
    		return 0;
  	}
	while (startIndex <= endIndex) {
		int middle = startIndex + (endIndex - startIndex) / 2;
		// Check if randomNumber is present at mid 
		if (arr[middle] == randomNumber)
			return middle;
		// If randomNumber greater, ignore left half 
		if (arr[middle] < randomNumber)
			startIndex = middle + 1;
		// If randomNumber is smaller, ignore right half 
		else
			endIndex = middle - 1;
	}
	// if we reach here, then element was 
	// not present 
	return -1;

}
