#include "HX711.h" //Download here: https://electronoobs.com/images/Arduino/tut_115/HX711-master.zip

// HX711.DOUT - pin #D3
// HX711.PD_SCK - pin #D2

HX711 scale(6, 5); 

void setup() {
 Serial.begin(9600);
 Serial.println("HX711 Demo");

 Serial.println("Before setting up the scale:");
 Serial.print("read: tt");
 Serial.println(scale.read()); 

 Serial.print("read average: tt");
 Serial.println(scale.read_average(20)); 

 Serial.print("get value: tt");
 Serial.println(scale.get_value(5)); 

 Serial.print("get units: tt");
 Serial.println(scale.get_units(5), 1); 

 scale.set_scale(2280.f); 
 scale.tare(); 

 Serial.println("After setting up the scale:");

 Serial.print("read: tt");
 Serial.println(scale.read()); 

 Serial.print("read average: tt");
 Serial.println(scale.read_average(20)); 

 Serial.print("get value: tt");
 Serial.println(scale.get_value(5)); 

 Serial.print("get units: tt");
 Serial.println(scale.get_units(5), 1); 
 Serial.println("Readings:");
}

void loop() {
 Serial.print("one reading:t");
 Serial.print(scale.get_units(), 1);
 Serial.print("t| average:t");
 Serial.println(scale.get_units(10), 1);

 scale.power_down(); 
 delay(5000);
 scale.power_up();
}
