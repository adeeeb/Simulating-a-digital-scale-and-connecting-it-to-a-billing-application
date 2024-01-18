#include <Arduino.h>
#include "HX711.h"
#include <SoftwareSerial.h>

const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

HX711 scale;

SoftwareSerial SerialBT(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  SerialBT.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(3606.50);
}

void loop() {
  // انتظر حتى يتم ارسال اسم المادة من الـ Virtual Terminal
  while (Serial.available() == 0) {}
  String materialName = Serial.readStringUntil('\n');
  if(materialName=="tomato"){
    // انتظر حتى يتم إدخال الوزن
    Serial.println("Please place item on scale...");
    while (scale.is_ready() == false) {}
    float weightInGrams = scale.get_units(1) / 10.0;

    // حساب السعر
    float price = weightInGrams * 300;
    
    // إرسال المعلومات إلى التطبيق
    Serial.print("Material Name: ");
    Serial.print(materialName);
    Serial.print(", Weight: ");
    Serial.print(weightInGrams);
    Serial.println(" kg");
    Serial.print(", price: ");
    Serial.print(price);
    Serial.println(" sp");
  //-----------------------------------------
   /* SerialBT.print("Material Name: ");
    SerialBT.print(materialName);
    SerialBT.print(", Weight: ");
    SerialBT.print(weightInGrams);
    SerialBT.print(" kg, Price: ");
    SerialBT.print(price);
    SerialBT.println(" sp");*/
    SerialBT.print(""+materialName+":"+weightInGrams+":"+price+"\n");
  }


  else if(materialName=="cucumber"){
   // انتظر حتى يتم إدخال الوزن
    Serial.println("Please place item on scale...");
    while (scale.is_ready() == false) {}
    float weightInGrams = scale.get_units(1) / 10.0;

    // حساب السعر
    float price = weightInGrams * 200;
    
    // إرسال المعلومات إلى التطبيق
        Serial.print("Material Name: ");
    Serial.print(materialName);
    Serial.print(", Weight: ");
    Serial.print(weightInGrams);
    Serial.println(" kg");
    Serial.print(", price: ");
    Serial.print(price);
    Serial.println(" sp");
  //-----------------------------------------
   /* SerialBT.print("Material Name: ");
    SerialBT.print(materialName);
    SerialBT.print(", Weight: ");
    SerialBT.print(weightInGrams);
    SerialBT.print(" kg, Price: ");
    SerialBT.print(price);
    SerialBT.println(" sp");*/
    SerialBT.print(""+materialName+":"+weightInGrams+":"+price+"\n");
  }

 else if(materialName=="carrot"){
    // انتظر حتى يتم إدخال الوزن
    Serial.println("Please place item on scale...");
    while (scale.is_ready() == false) {}
    float weightInGrams = scale.get_units(1) / 10.0;

    // حساب السعر
    float price = weightInGrams * 100;
    
    // إرسال المعلومات إلى التطبيق
    Serial.print("Material Name: ");
    Serial.print(materialName);
    Serial.print(", Weight: ");
    Serial.print(weightInGrams);
    Serial.println(" kg");
    Serial.print(", price: ");
    Serial.print(price);
    Serial.println(" sp");
  //-----------------------------------------
   /* SerialBT.print("Material Name: ");
    SerialBT.print(materialName);
    SerialBT.print(", Weight: ");
    SerialBT.print(weightInGrams);
    SerialBT.print(" kg, Price: ");
    SerialBT.print(price);
    SerialBT.println(" sp");*/
    SerialBT.print(""+materialName+":"+weightInGrams+":"+price+"\n");
  }

  else {
    Serial.println(" error");
  }
}
