#include "BluetoothSerial.h" 

BluetoothSerial ESP_BT; //Object for Bluetooth

int incoming;
int LED = 2;

void setup() {
  Serial.begin(115200); //Start Serial monitor in 115200
  ESP_BT.begin("ESP32_LED_CONTROL"); //Name of your Bluetooth 
  
  Serial.println("Bluetooth Device is Ready to Pair");
  
  pinMode (LED, OUTPUT); //Specify that LED pin is output
}

void loop() {
  
  if (ESP_BT.available()) { //Check if we receive anything from Bluetooth
  
    incoming = ESP_BT.read(); //Read what we recevive 
    Serial.print("Received: "); 
    Serial.println(incoming);

    switch(incoming) {
      case 49:
        digitalWrite(LED, HIGH);
        ESP_BT.println("LED turned ON");
        break;
        
      case 48:
        digitalWrite(LED, LOW);
        ESP_BT.println("LED turned OFF");
        break;
        
      default:
        break;
    }     
  }
  delay(20);
}
