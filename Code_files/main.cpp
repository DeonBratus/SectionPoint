#include <iostream>			//input, output
#include "SectionPoint.h"	// Header file with Point and Section classes
#include <string>           //string class
#include <fstream>

using namespace std;

int main() {
    string pathToFile;
    cin >> pathToFile;

    ifstream readingFile(pathToFile);

    if(!readingFile) {
        std::cerr <<"Error! File not found!" << std::endl;
        return 1;
    }
    std::string str;
    while (std::getline(readingFile, str)) {
        std::cout << str <<std::endl;
    }
    readingFile.close();


    return 0;
}