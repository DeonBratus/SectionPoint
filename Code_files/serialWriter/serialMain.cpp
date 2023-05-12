#include "../readcoord/SectionPoint.h"
#include "../libraries/SerialPort/SerialPort.h"
#include "SerialCom.h"
#include <string>
#include <iostream>


char *port = "\\\\.\\COM4";

using namespace std;
int main() {

    char output[MAX_DATA_LENGTH];
    char incomingData[MAX_DATA_LENGTH];

//    int const quantPoint = 20;                                   //Quantity of point and coordinates
//    string strArray[quantPoint + 1];                             //create array string more by one
//    Point points[quantPoint];                                    // create points
//
//    cout << "Enter path to data of route:";
//    string pathToFile; std::cin >> pathToFile;                  //Take path to *.csv file
//    scanLineReading(pathToFile, strArray);
//
//    for(int i = 1; i != quantPoint;i++) {
//        cout << strArray[i] << endl;
//    }


    SerialPort arduino(port);

    statusConnection(arduino);

    while(arduino.isConnected()){
        cout<<"Enter your command: "<<endl;
        string data;
        cin>>data;

        char *charArray = new char[data.size() + 1];
        copy(data.begin(), data.end(), charArray);
        charArray[data.size()] = '\n';

        arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
        arduino.readSerialPort(output, MAX_DATA_LENGTH);

        cout<<">> "<<output<<endl;

        delete [] charArray;
    }

    return 0;
}