#include <ColorConverterLib.h>


#include <Adafruit_TCS34725.h>



Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X);

#define pinLedR 11 // pin 6 a Blue
#define pinLedG 10 // pin 5 a Green
#define pinLedB 9 // pin 3 a Red

float redColor,greenColor,blueColor;//Estos valores contienen los bytes de cada color
String bitWord, wordToPrint, stopBit;
char letterToUse;

int blancoRojo = 40;int blancoVerde = 50;int blancoAzul = 110;//Comprobacion colores blanco


//00 ---> (255,0,0)
//01 ---> (0,255,0)   
//10 ---> (0,0,255)
//11 ---> (255,0,255)
//Vector para iniciar y acabar la transmisión(250,250,250)


void setup(){
  pinMode(pinLedR,OUTPUT);
  pinMode(pinLedG,OUTPUT);
  pinMode(pinLedB,OUTPUT);
  
  Serial.begin(9600);
  if (!tcs.begin()){
    Serial.println("Error al iniciar TCS34725");
    while (1) delay(1000);
    }
}


void loop(){ 
  bitWord = "";
  stopBit ="";
  
  if (Serial.available() > 0){// Solo si llegaron datos los lee
      letterToUse = Serial.read(); 
      initColor();
       
  // Hacer rgb medición relativ
 // if(redColor>=blancoRojo && greenColor >=blancoVerde && blueColor >=blancoAzul){
      while(stopBit!="stop"){
          wordToBinary();
          finalColor();
        }
    //}
  }
}


//********** EMISOR **********

void wordToBinary(){
  if(letterToUse == 'a'){
    binaryToColor("01"); binaryToColor("10"); binaryToColor("00"); binaryToColor("01");
    wordToPrint += "a";
  }else if(letterToUse == 'b'){
    binaryToColor("01"); binaryToColor("10"); binaryToColor("00"); binaryToColor("10");
    wordToPrint += "b";
  }else if(letterToUse == 'c'){
    binaryToColor("01"); binaryToColor("10"); binaryToColor("00"); binaryToColor("11");
    wordToPrint += "c";
  }else if(letterToUse == 'd'){
    binaryToColor("01"); binaryToColor("10"); binaryToColor("01"); binaryToColor("00");
    wordToPrint += "d";
  }else if(letterToUse == 'e'){
    binaryToColor("01"); binaryToColor("10"); binaryToColor("01"); binaryToColor("01");
    wordToPrint += "e";
  }
  
}

//EMITE EL COLOR Y HACE QUE EL SENSOR LEA

void binaryToColor(String bits){
   if(bits == "00"){
    tcs.setInterrupt(false);
    color(255,0,0);
    delay(100);
    tcs.getRGB(&redColor,&greenColor,&blueColor);
    tcs.setInterrupt(true);
    Serial.println("********************");
    Serial.print("Rojo Sensor: ");Serial.println(redColor);
    Serial.print("Verde Sensor: ");Serial.println(greenColor);
    Serial.print("Azul Sensor: ");Serial.println(blueColor);

   colorToBit();//Se transforman los colores a bits
   /*Serial.print("Codigo Binario");Serial.println(bitWord);
   Serial.println("");*/
   String comprobateBits = "";
   comprobateBits = String(bitWord);
   if(comprobateBits.length()==8){//Compruebo que la cadena ya contenga un byte para transformarla
       bitToLetter();//Se transforman los bits a letras
    }
  }
  
  else if(bits == "01"){
    tcs.setInterrupt(false);
    color(0,255,0);
    delay(100);
    tcs.getRGB(&redColor,&greenColor,&blueColor);
    tcs.setInterrupt(true);
    /*Serial.print("Rojo Sensor: ");Serial.println(redColor);
    Serial.print("Verde Sensor: ");Serial.println(greenColor);
    Serial.print("Azul Sensor: ");Serial.println(blueColor);*/
    colorToBit();//Se transforman los colores a bits
    /*Serial.print("Codigo Binario");Serial.println(bitWord);
    Serial.println("");*/
    String comprobateBits = "";
    comprobateBits = String(bitWord);
    if(comprobateBits.length()==8){//Compruebo que la cadena ya contenga un byte para transformarla
       bitToLetter();//Se transforman los bits a letras
    }
  }
  
  else if(bits == "10"){
    tcs.setInterrupt(false);
    color(0,0,255);
    delay(100);
    tcs.getRGB(&redColor,&greenColor,&blueColor);
    tcs.setInterrupt(true);
   /* Serial.print("Rojo Sensor: ");Serial.println(redColor);
    Serial.print("Verde Sensor: ");Serial.println(greenColor);
    Serial.print("Azul Sensor: ");Serial.println(blueColor);*/
    colorToBit();//Se transforman los colores a bits
   /* Serial.print("Codigo Binario");Serial.println(bitWord);
    Serial.println("");*/
    String comprobateBits = "";
    comprobateBits = String(bitWord);
    if(comprobateBits.length()==8){//Compruebo que la cadena ya contenga un byte para transformarla
       bitToLetter();//Se transforman los bits a letras
    }
  }
  
  else if(bits == "11"){
    tcs.setInterrupt(false);
    color(255,0,255);
    delay(100);
    tcs.getRGB(&redColor,&greenColor,&blueColor);
    tcs.setInterrupt(true);
    /*Serial.print("Rojo Sensor: ");Serial.println(redColor);
    Serial.print("Verde Sensor: ");Serial.println(greenColor);
    Serial.print("Azul Sensor: ");Serial.println(blueColor);*/
    colorToBit();//Se transforman los colores a bits
   /* Serial.print("Codigo Binario");Serial.println(bitWord);
    Serial.println("");*/
    String comprobateBits = "";
    comprobateBits = String(bitWord);
    if(comprobateBits.length()==8){//Compruebo que la cadena ya contenga un byte para transformarla
       bitToLetter();//Se transforman los bits a letras
    }
  }
 
}

void initColor(){
  tcs.setInterrupt(false);
    color(255,255,255);
    delay(100);
  tcs.getRGB(&redColor,&greenColor,&blueColor);
  tcs.setInterrupt(true);
}

void finalColor(){
  tcs.setInterrupt(false);
    color(255,255,255);
    delay(100);
  tcs.getRGB(&redColor,&greenColor,&blueColor);
  tcs.setInterrupt(true);
  colorToBit();
}

void color(int red, int green, int blue){
  analogWrite(pinLedR, red);
  analogWrite(pinLedG, green);
  analogWrite(pinLedB, blue);  
}

//********** RECEPTOR ***********
void colorToBit(){
  if(redColor >= blancoRojo && greenColor>=blancoVerde && blueColor>=blancoAzul){
    stopBit = "stop";
  }else if(redColor>=180){
    bitWord += "00";
  }else if(greenColor>=120){
    bitWord += "01";
  }else if(blueColor>=160){
    bitWord += "10";
  }else if(redColor >= 80 && blueColor >= 60){
    bitWord += "11";
    }
}

void bitToLetter(){
  if(bitWord == "01100001"){
    Serial.println("a");
  }else if(bitWord == "01100010"){
    Serial.println("b");
  }else if(bitWord == "01100011"){
    Serial.println("c");
  }else if(bitWord == "01100100"){
    Serial.println("d");
  }else if(bitWord == "01100101"){
    Serial.println("e");
  }
}
