#include <iostream>
using namespace std;

// Function to print "hi"
void printhi() {
    cout << "hi" << endl;
}

// Function to print the sum of two integers
void printsum(int a, int b) {
    cout << "sum is " << a + b << endl;
}

int main() {
    // Call printhi function to print "hi"
    printhi();
    
    // Call printsum function with arguments 5 and 6
    printsum(5, 6);
    
    return 0;
}