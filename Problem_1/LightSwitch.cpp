// File Name: Problem_1.cpp
// This program functions to turn on an LED when a push button is pressed.

#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;

#define BUTTON_PATH "/sys/class/gpio/gpio46/value"
#define BUTTON_DIR "/sys/class/gpio/gpio46/direction"
#define LED_PATH "/sys/class/gpio/gpio60/value"
#define LED_DIR "/sys/class/gpio/gpio60/direction"

int main() {
  // Set button GPIO to input
  ofstream directionButton(BUTTON_DIR);
  directionButton << "in";
  directionButton.close();
  
  // Set LED GPIO to output
  ofstream directionLED(LED_DIR);
  directionLED << "out";
  directionLED.close();


  while (true) {
    // Open the file and read the value of the input GPIO
    ifstream buttonFile(BUTTON_PATH);
    int buttonValue;
    buttonFile >> buttonValue;
    buttonFile.close();

    // Check if button is pressed and turn on LED if it is
    if (buttonValue == 0) {
      ofstream valueLED(LED_PATH);
      valueLED << "1";
      valueLED.close();
    }
    // Turn off LED if button is not pressed
    else {
      ofstream valueLED(LED_PATH);
      valueLED << "0";
      valueLED.close();
    }
  }
}
