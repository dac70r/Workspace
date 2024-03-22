#include <iostream>
using namespace std;


int main() { bool x = true; bool y = false; 

/* File: boolalpha.cpp */ 
// Default output format of booleans 
cout << x << " && " << y << " = " << (x && y) << endl << endl; 

cout << boolalpha; // To print booleans in English 
cout << x << " && " << y << " = " << (x && y) << endl << endl; 

cout << noboolalpha; // To print booleans in 1 or 0 
cout << x << " && " << y << " = " << (x && y) << endl; 

char small_y, big_y; 

cin >> small_y; 
// Character in small case 
big_y = small_y + 'A'- 'a'; // Character in big case

cout << big_y << endl;

return 0; }