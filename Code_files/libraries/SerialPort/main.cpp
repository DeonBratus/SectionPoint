#include<iostream>
#include <string>
#include <stdlib.h>
#include "SerialPort.h"
using namespace std;

char output[MAX_DATA_LENGTH];
char incomingData[MAX_DATA_LENGTH];

char *port = "\\\\.\\COM4";

int main(){
    SerialPort arduino(port);
    if(arduino.isConnected()){
        std::cout<<"Connection made"<<std::endl<<std::endl;
    }
    else{
        std::cout<<"Error in port name"<<std::endl<<std::endl;
    }
	while(arduino.isConnected()){
		cout<<"Enter your command: " << endl;
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
