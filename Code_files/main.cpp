#include <iostream>			//input, output
#include <fstream>          //writing to file
#include "SectionPoint.h"	// Header file with Point and Section classes
#include <string>           //string class
#include <cstdlib>          //system
#include "stdio.h"

using namespace std;
void StrCat(char *to,  char *from) {
    char *p = to;
    for(;*p != '\0'; ++p) {  }
    *p = *from;
    for(;*p !='\0';++p) *p = *from++;
}
int main() {

    cout << "Enter <your_path_to_file> : " ;
    string inputCom;
    cin >> inputCom;
    inputCom = "python " + inputCom;
    system(inputCom.c_str() );
    return 0;
}