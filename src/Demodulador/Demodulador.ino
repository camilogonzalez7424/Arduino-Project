
#include "Adafruit_TCS34725.h"
Adafruit_TCS34725 tcs = Adafruit_TCS34725();
#define mainLux 6000
#define timeDelay 120
boolean estadoInicial;
boolean estadoFinal;

String bitWord;
String stopWord;

//PROTOCOLO DESCARTADO :( NUEVO - Encendido y apagado
//00 --->Rojo           (250,0,0)  
//01 --->Verde          (0,250,0) 
//10 --->Azul           (0,0,250)
//11 --->Magenta        (250,0,255)
//Vector para iniciar y acabar la transmisión(250,250,250)


void setup(){
  Serial.begin(9600);
  if (!tcs.begin()){
    Serial.println("Error al iniciar TCS34725");
    while (1) delay(1000);
    }
}


void loop(){ 
  bitWord = "";
  if(stopWord!="Stop"){
  estadoInicial = hayColor();//Compruebo que haya algun color
  //Serial.println("Espero el color");
  if(!estadoInicial && estadoFinal){
      obtenerByte();
   }
   estadoFinal = estadoInicial;
  }
}

  boolean hayColor(){
  boolean ambiente = false;
  uint16_t r, g, b, c, lux;
  tcs.getRawData(&r, &g, &b, &c);
  lux = tcs.calculateLux(r, g, b);
  //Serial.println(lux);
  if(lux > mainLux){
    ambiente = true;
    return ambiente;
  }else{
    return ambiente;
  }
}

void obtenerByte(){
  delay(timeDelay*1.5);//Aqui sincronizo el sensor con el led
  colorExists();
  bitToLetter();
}

void colorExists(){
  for(int i = 0 ; i < 8 ; i++){//Aqui leo los 8 colores
    if(hayColor()==true){
      bitWord += "1";
      //Serial.println(bitWord);
      delay(timeDelay);
    }else{
      bitWord += "0";
      //Serial.println(bitWord);
      delay(timeDelay);
    }
  }//Al leer cada color espero el delay normal
}

void bitToLetter(){
  if(bitWord == "01100001"){
    Serial.print("a");
  }else if(bitWord == "01100010"){
    Serial.print("b");
  }else if(bitWord == "01100011"){
    Serial.print("c");
  }else if(bitWord == "01100100"){
    Serial.print("d");
  }else if(bitWord == "01100101"){
    Serial.print("e");
  }else if(bitWord == "01100110"){
    Serial.print("f");
  }else if(bitWord == "01100111"){
    Serial.print("g");
  }else if(bitWord == "01101000"){
    Serial.print("h");
  }else if(bitWord == "01101001"){
    Serial.print("i");
  }else if(bitWord == "01101010"){
    Serial.print("j");
  }else if(bitWord == "01101011"){
    Serial.print("k");
  }else if(bitWord == "01101100"){
    Serial.print("l");
  }else if(bitWord == "01101101"){
    Serial.print("m");
  }else if(bitWord == "01101110"){
    Serial.print("n");
  }else if(bitWord == "01101111"){
    Serial.print("o");
  }else if(bitWord == "01110000"){
    Serial.print("p");
  }else if(bitWord == "01110001"){
    Serial.print("q");
  }else if(bitWord == "01110010"){
    Serial.print("r");
  }else if(bitWord == "01110011"){
    Serial.print("s");
  }else if(bitWord == "01110100"){
    Serial.print("t");
  }else if(bitWord == "01110101"){
    Serial.print("u");
  }else if(bitWord == "01110110"){
    Serial.print("v");
  }else if(bitWord == "01110111"){
    Serial.print("w");
  }else if(bitWord == "01111000"){
    Serial.print("x");
  }else if(bitWord == "01111001"){
    Serial.print("y");
  }else if(bitWord == "01111010"){
    Serial.print("z");
  }

  else if(bitWord == "01000001"){
    Serial.print("A");
  }else if(bitWord == "01000010"){
    Serial.print("B");
  }else if(bitWord == "01000011"){
    Serial.print("C");
  }else if(bitWord == "01000100"){
    Serial.print("D");
  }else if(bitWord == "01000101"){
    Serial.print("E");
  }else if(bitWord == "01000110"){
    Serial.print("F");
  }else if(bitWord == "01000111"){
    Serial.print("G");
  }else if(bitWord == "01001000"){
    Serial.print("H");
  }else if(bitWord == "01001001"){
    Serial.print("I");
  }else if(bitWord == "01001010"){
    Serial.print("J");
  }else if(bitWord == "01001011"){
    Serial.print("K");
  }else if(bitWord == "01001100"){
    Serial.print("L");
  }else if(bitWord == "01001101"){
    Serial.print("M");
  }else if(bitWord == "01001110"){
    Serial.print("N");
  }else if(bitWord == "01001111"){
    Serial.print("O");
  }else if(bitWord == "01010000"){
    Serial.print("P");
  }else if(bitWord == "01010001"){
    Serial.print("Q");
  }else if(bitWord == "01010010"){
    Serial.print("R");
  }else if(bitWord == "01010011"){
    Serial.print("S");
  }else if(bitWord == "01010100"){
    Serial.print("T");
  }else if(bitWord == "01010101"){
    Serial.print("U");
  }else if(bitWord == "01010110"){
    Serial.print("V");
  }else if(bitWord == "01010111"){
    Serial.print("W");
  }else if(bitWord == "01011000"){
    Serial.print("X");
  }else if(bitWord == "01011001"){
    Serial.print("Y");
  }else if(bitWord == "01011010"){
    Serial.print("Z");
  }
  
  
  
  
  else if(bitWord == "00100000"){
    Serial.print(" ");
  }else if(bitWord == "01000000"){
    Serial.print("@");
  }else if(bitWord == "00100001"){
    Serial.print("!");
  }else if(bitWord == "00101010"){
    Serial.print("\"");
  }else if(bitWord == "00101100"){
     Serial.print(",");
  }else if(bitWord == "00101110"){
    Serial.print(".");
  }else if(bitWord == "00111010"){
    Serial.print(":");
  }else if(bitWord == "00111011"){
    Serial.print(";");
  }else if(bitWord == "01011111"){
    Serial.print("_");
  }else if(bitWord == "00101101"){
    Serial.print("-");
    stopWord = "Stop";
  }else if(bitWord == "01111110"){
    Serial.println("");
  }

  else if(bitWord == "00110000"){
    Serial.print("0");
  }else if(bitWord == "00110001"){
    Serial.print("1");
  }else if(bitWord == "00110010"){
    Serial.print("2");
  }else if(bitWord == "00110011"){
    Serial.print("3");
  }else if(bitWord == "00110100"){
    Serial.print("4");
  }else if(bitWord == "00110101"){
    Serial.print("5");
  }else if(bitWord == "00110110"){
    Serial.print("6");
  }else if(bitWord == "00110111"){
    Serial.print("7");
  }else if(bitWord == "00111000"){
    Serial.print("8");
  }else if(bitWord == "00111001"){
    Serial.print("9");
  }
 
}
