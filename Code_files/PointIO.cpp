#include <fstream>
#include <iostream>
#include "SectionPoint.h"

using namespace std;
// function of creating *.scv table with title. return ofstream class
std::ofstream &createCSV(const std::string& pathAndName) {
    //create scv file
    std::ofstream dataCSV(pathAndName + ".csv");
    //Check of existing file
    if(!dataCSV) std::cout << "error" << std::endl;
    // Writing header
    dataCSV << "#," << "Distance," << "Angle Rot," << "Speed" << std::endl;
    //return file
    return  dataCSV;
}
//run python script in path
std::string runPythonFile(std::string& filePath) {
    std::cout << "Enter path to open python file:";
    filePath = "python " + filePath;
    system(filePath.c_str());
    return filePath;
}