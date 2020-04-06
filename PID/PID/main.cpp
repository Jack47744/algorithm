//
//  main.cpp
//  PID
//
//  Created by Metis Sotangkur on 4/3/20.
//  Copyright © 2020 Metis Sotangkur. All rights reserved.
//

#include <iostream>
using namespace std;
double accumulateError = 0;
double lastError = 0;
bool isStart = false;
double current(){
    return flowMeterValue; // return the value from the flow meter
}
double PID(double setPoint, double Kp, double Ki, double Kd){
    double error = setPoint - current(); //every time the current() is called it will return the current value
    if(!isStart){
        lastError = error;
        isStart = true; // the last error of the first loop will be the current error
    }
    double P = Kp * error;
    accumulateError += error;
    double I = Ki * accumulateError;
    double errorDiff = error - lastError;
    lastError = error;
    double D = Kd * errorDiff;
    return P+I+D;
}
double saturate(double input, double min, double max){
    if(input<min) return min;
    if(input>max) return max;
    return input;
}

int main(int argc, const char * argv[]) {
    bool isOpen = true;
    double setPoint;
    cin>>setPoint;   // input the value in Ohm from potention meter
    saturate(setPoint, 0, 10000);
    double newSetpoint = convert(setPoint); //convert is the function that change from Ohm to voltage
    while(isOpen){ //assume that every loop has the same time duration and that time duration is very small
        double pid = PID(newSetpoint, 15, 0.001, 30); //Assume that Kp, Ki, Kd is well tuned at 15 0.001 30
        pumpOutput(saturate(pid, 0, 10)); //Assume that pumpOutput() is a function for input the voltage to the pump
    }
    return 0;
}
