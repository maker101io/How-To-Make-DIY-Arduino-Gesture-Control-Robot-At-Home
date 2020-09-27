#include <SPI.h>
#include "RF24.h"

const int x_out = A0;
const int y_out = A1;
RF24 radio(8,10);
const byte address[6] = "00001";
struct data{
  int xAxis;
  int yAxis;

};
data send_data;



void setup() {
  // put your setup code here, to run once:
radio.begin();
radio.openWritingPipe(address);
radio.stopListening();
}

void loop() {
  // put your main code here, to run repeatedly:
send_data.xAxis = analogRead(x_out);
send_data.yAxis = analogRead(y_out);
radio.write(&send_data, sizeof(data));
}
