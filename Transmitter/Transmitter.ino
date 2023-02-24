#include <LoRa.h> //ESP8266
#include <SPI.h>
 
#define ss 15 //slave pin
#define rst 16
#define dio0 2 // interup callbacks
 
int counter = 0;
 
void setup() 
{
  Serial.begin(115200); 
  while (!Serial);
  Serial.println("LoRa Sender");
 
  LoRa.setPins(ss, rst, dio0);    //setup LoRa transceiver module
  
  while (!LoRa.begin(433E6))     //433E6 - Asia, 866E6 - Europe, 915E6 - North America
  {
    Serial.println(".");
    delay(500);
  }
  LoRa.setSyncWord(0x63);
  Serial.println("LoRa Initializing OK!");
}

void loop()
{
  Serial.println("Feed the fish ? (y/n)");
  while (Serial.available() == 0)
  {  
  }

  String input = Serial.readString();

  if (input == 'y'){
    Serial.println("Feeding . . .");
    LoRa.beginPacket();
    LoRa.print("Feed");
    LoRa.endPacket();
  }
  else
  Serial.println("Not Feeding");
  
}
// Original void loop
//void loop() 
//{
//  Serial.print("Sending packet: ");
//  Serial.println(counter);
// 
//  LoRa.beginPacket();   //Send LoRa packet to receiver
//  LoRa.print("hello ");
//  LoRa.print(counter);
//  LoRa.endPacket();
// 
//  counter++;
// 
//  delay(10000);
//}
