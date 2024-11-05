// File name: myGpioApp.cpp
// This program is used to teset the class MYGPIO
// We test the class by creating 2 objects, assigning one to be and input and
// the other to be an output. We then set the ouptut pin high for 3 seconds and
// then low. And finally, we read the value of P8.16

// Example Invocation: ./myGpioApp


#include"myGpio.h"
#include<iostream>
#include<unistd.h>
using namespace std;
#define P8_16 46
#define P9_12 60

int main() {

  // instantiate an object as an output gpio using pin p9.12
  MYGPIO outputGpio(P9_12);
  outputGpio.setDirection(OUTPUT);
  cout << "Creating an object as an output gpio using pin 9.12" << endl;
  //instantiate an object as an input gpio using p8.16
  MYGPIO inputGpio(P8_16);
  inputGpio.setDirection(INPUT);
  cout << "Creating an object as an input gpio using pin 8.18" << endl;

  // Set P9.12 high for 3 seconds, then set it low. Display value for both
  cout << "Setting P9.12 high" << endl;
 outputGpio.setValue(HIGH);
  cout << outputGpio.getValue() << endl;
  sleep(3);
  cout << "Setting P9.12 low" << endl;
  outputGpio.setValue(LOW);
  cout << outputGpio.getValue() << endl;

  // Read P8.16 and print out the value
  cout << "The value of P8.16 is: " << inputGpio.getValue() << endl;

}

