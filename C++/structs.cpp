/*
 * File: structs.cpp
 *
 * Download a C++ Compiler - MinGW and add the installation folder to path before running this program
 * or use command: g++ -o helloworld helloworld.cpp 
*/
#include <iostream>
using namespace std;

// Struct TemplateS
struct ViE {
    float salary;
    int age;
};

int main(void){

    // Instantiation of a Struct
    ViE Dennis = {6023.32, 25};
    ViE Chun_Keat;

    Chun_Keat = Dennis; // Memberwise copy

    cout<<"Struct Revision!\n"<<endl;

    cout<<"Dennis's Age: "<<Dennis.age<<" Dennis's Salary: "<<Dennis.salary<<"\n"<<endl;
    cout<<"Chun Keat's Age: "<<Chun_Keat.age<<" Chun Keat's Salary: "<<Chun_Keat.salary<<"\n"<<endl;

    return 0;
}