#include "SerialCom.h"

void statusConnection(SerialPort &arduino){


    if(arduino.isConnected()){
        std::cout<<"Board is connected!"<<std::endl;
    }
    else{
       std::cerr<<"Error in port name of device is not connected!"<<std::endl;
    }
}