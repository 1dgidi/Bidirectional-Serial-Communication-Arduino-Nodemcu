#include <SoftwareSerial.h>

// serial port to receive message from arduino
SoftwareSerial arduino(D2, D1);

// variables to hold data received from arduino
int receivedIndex = -1;
int receivedPayload = -1;

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  arduino.begin(115200);
  
  while(!Serial) continue;
  while(!Serial1) continue;
  while(!arduino) continue;
}

void loop() {

  // receive message from arduino
  fromArduino();

  // send message to arduino
  String msg = "01,0\n";
  toArduino(msg);

//  delay(2000);  // wait 2 seconds
  delay(50);  // delay 50 milli seconds
}

void fromArduino() {
  // from arduino
  
  // check if data is available
  if(arduino.available() > 0) {
    
    // extract variables from data received and store
    receivedIndex = arduino.parseInt();
    receivedPayload = arduino.parseInt();

    // print data to serial monitor if end of data sent is reached
    if(arduino.read() == '\n') {
      Serial.println(receivedIndex);
      Serial.println(receivedPayload);
    }
  }
}

void toArduino(String msg) {
  // to arduino
  Serial1.println(msg);
}
