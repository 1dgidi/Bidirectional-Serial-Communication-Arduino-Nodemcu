
// variables to hold data received from nodemcu
int receivedIndex = -1;
int receivedPayload = -1;

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial2.begin(115200);
  
  while(!Serial) continue;
  while(!Serial1) continue;
  while(!Serial2) continue;
}


void loop() {
  // send data to nodemcu
  String msg = "02,1\n";
  toESP(msg);

  // receive message from nodemcu
  fromESP();

//  delay(2000);  // wait 2 seconds
  delay(50);  // delay 50 milli seconds
}

void fromESP() {
  // from node

  // check if data is available
  if(Serial1.available() > 0) {
    
    // extract variables from data received and store
    receivedIndex = Serial1.parseInt();
    receivedPayload = Serial1.parseInt();

    // print data to serial monitor if end of data sent is reached
    if(Serial1.read() == '\n') {
      Serial.println(receivedIndex);
      Serial.println(receivedPayload);
    }
  }
}

void toESP(String msg) {
  // send data to nodemcu
  Serial2.println(msg);
}
