/*
PROGRAM DESCRIPTION

Write a program that first generates a 100 member integer array containing the numbers 1 to 100.  Then generate a random number between 1 and 100.  Next, use the binary search algorithm in your book to search for this number in the array.  Once the number is found display the number and the index of where it was found in the array.

Note:  The index should be one less than the number.

Paste your code (or share your github repo) and your program's output below as a comment
*/

#include <iostream>
#include <random>
using namespace std;
int numArray[101];
int randomnumber; // This is the random number variable.
int binarySearch(int arr[],int,int,int);
int result;

int main() {

  srand(time(NULL)); // This ensures the random function is more unpredictable each time the program is ran

  for (int i = 0;i<=99;++i)
  {
    numArray[i] = i+1; // The numbers(1-100) are added to the array here
    
  }
  int x = randomnumber = 1 + rand() % (100) + 1; // This generates the random number.
  cout << "Random Number is: " << randomnumber << endl;
  int n = sizeof(numArray) / sizeof(numArray[0]); 

  result = binarySearch(numArray, 1, n-1,  x);
  cout << "Index is: " << result;
  cout << "\nNumber is: " << numArray[result] << endl;
}

int binarySearch(int arr[], int l, int r, int x) 
{ 
  if (x == 1)
  {
    return 0;
  }
  else
  {
    while (l <= r) { 
        int m = l + (r - l) / 2; 
        // Check if x is present at mid 
        if (arr[m] == x) 
            return m; 
        // If x greater, ignore left half 
        if (arr[m] < x) 
            l = m + 1; 
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    } 
    // if we reach here, then element was 
    // not present 
    return -1; 
} 
}
