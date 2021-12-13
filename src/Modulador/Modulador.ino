#define redColor  6
#define timeDelay 120

//char* text = "_Escribi un cuento de cien palabras perfecto. La gente lo leia con avidez, y lo enviaban entusiasmados~a sus amigos. Me llamaron para hablar sobre el cuento en la tele, y desde Hollywood querian~adaptarlo. Entonces alguien descubrio que habia escrito *porque*, en vez de *por que*, asi que~ahora sobraba una palabra. Pero quitar cualquiera de ellas desmontaba el delicado mecanismo de~relojeria que habia conseguido construir. Finalmente elimine un articulo, pero ya no es lo mismo.~Los criticos literarios me ignoran, han cancelado el programa al que tenia que ir, y Scorsese ya no~me coge el telefono. -";

char* text = "_FELIZ NAVIDAD!-";
             
int textSize;
String stopWord = "";

//PROTOCOLO DESCARTADO :( NUEVO - Encendido y apagado
//00 --->Rojo           (250,0,0)  
//01 --->Verde          (0,250,0) 
//10 --->Azul           (0,0,250)
//11 --->Magenta        (250,0,255)

void setup() {
  Serial.begin(9600); 
  pinMode(redColor,OUTPUT);
  digitalWrite(redColor,LOW);
  delay(3000);
  textSize = strlen(text);
}
 

void loop() {
  // Solo si llegaron datos los lee
  if(stopWord != "Stop"){
    for(int i = 0 ; i < textSize ; i++){//Aqui imprimo letra por letra
      wordToBinary(text[i]);
    }
    delay(timeDelay);
  }
  digitalWrite(redColor,LOW);
}

void wordToBinary(char wordToUse){//Convierte cada letra a binario
  
  digitalWrite(redColor,LOW);
  delay(timeDelay);//Aqui envia la señal de inicio de letra
  
  if(wordToUse == 'a'){
    binaryToColor("01100001");//Cambiar, solo prueba
    Serial.print("a");
  }else if(wordToUse == 'b'){
    binaryToColor("01100010");
    Serial.print("b");
  }else if(wordToUse == 'c'){
    binaryToColor("01100011");
    Serial.print("c");
  }else if(wordToUse == 'd'){
    binaryToColor("01100100");
    Serial.print("d");
  }else if(wordToUse == 'e'){
    binaryToColor("01100101");
    Serial.print("e");
  }else if(wordToUse == 'f'){
     binaryToColor("01100110");
     Serial.print("f");
  }else if(wordToUse == 'g'){
     binaryToColor("01100111");
     Serial.print("g");
  }else if(wordToUse == 'h'){
     binaryToColor("01101000");
     Serial.print("h");
  }else if(wordToUse == 'i'){
     binaryToColor("01101001");
     Serial.print("i");
  }else if(wordToUse == 'j'){
     binaryToColor("01101010");
     Serial.print("j");
  }else if(wordToUse == 'k'){
     binaryToColor("01101011");
     Serial.print("k");
  }else if(wordToUse == 'l'){
     binaryToColor("01101100");
     Serial.print("l");
  }else if(wordToUse == 'm'){
     binaryToColor("01101101");
     Serial.print("m");
  }else if(wordToUse == 'n'){
     binaryToColor("01101110");
     Serial.print("n");
  }else if(wordToUse == 'o'){
     binaryToColor("01101111");
     Serial.print("o");
  }else if(wordToUse == 'p'){
     binaryToColor("01110000");
     Serial.print("p");
  }else if(wordToUse == 'q'){
     binaryToColor("01110001");
     Serial.print("q");
  }else if(wordToUse == 'r'){
     binaryToColor("01110010");
     Serial.print("r");
  }else if(wordToUse == 's'){
     binaryToColor("01110011");
     Serial.print("s");
  }else if(wordToUse == 't'){
     binaryToColor("01110100");
     Serial.print("t");
  }else if(wordToUse == 'u'){
     binaryToColor("01110101");
     Serial.print("u");
  }else if(wordToUse == 'v'){
     binaryToColor("01110110");
     Serial.print("v");
  }else if(wordToUse == 'w'){
     binaryToColor("01110111");
     Serial.print("w");
  }else if(wordToUse == 'x'){
     binaryToColor("01111000");
     Serial.print("x");
  }else if(wordToUse == 'y'){
     binaryToColor("01111001");
     Serial.print("y");
  }else if(wordToUse == 'z'){
     binaryToColor("01111010");
     Serial.print("z");
  }

  else if(wordToUse == 'A'){
     binaryToColor("01000001");
     Serial.print("A");
  }else if(wordToUse == 'B'){
     binaryToColor("01000010");
     Serial.print("B");
  }else if(wordToUse == 'C'){
     binaryToColor("01000011");
     Serial.print("C");
  }else if(wordToUse == 'D'){
     binaryToColor("01000100");
     Serial.print("D");
  }else if(wordToUse == 'E'){
     binaryToColor("01000101");
     Serial.print("E");
  }else if(wordToUse == 'F'){
     binaryToColor("01000110");
     Serial.print("F");
  }else if(wordToUse == 'G'){
     binaryToColor("01000111");
     Serial.print("G");
  }else if(wordToUse == 'H'){
     binaryToColor("01001000");
     Serial.print("H");
  }else if(wordToUse == 'I'){
     binaryToColor("01001001");
     Serial.print("I");
  }else if(wordToUse == 'J'){
     binaryToColor("01001010");
     Serial.print("J");
  }else if(wordToUse == 'K'){
     binaryToColor("01001011");
     Serial.print("K");
  }else if(wordToUse == 'L'){
     binaryToColor("01001100");
     Serial.print("L");
  }else if(wordToUse == 'M'){
     binaryToColor("01001101");
     Serial.print("M");
  }else if(wordToUse == 'N'){
     binaryToColor("01001110");
     Serial.print("N");
  }else if(wordToUse == 'O'){
     binaryToColor("01001111");
     Serial.print("O");
  }else if(wordToUse == 'P'){
     binaryToColor("01010000");
     Serial.print("P");
  }else if(wordToUse == 'Q'){
     binaryToColor("01010001");
     Serial.print("Q");
  }else if(wordToUse == 'R'){
     binaryToColor("01010010");
     Serial.print("R");
  }else if(wordToUse == 'S'){
     binaryToColor("01010011");
     Serial.print("S");
  }else if(wordToUse == 'T'){
     binaryToColor("01010100");
     Serial.print("T");
  }else if(wordToUse == 'U'){
     binaryToColor("01010101");
     Serial.print("U");
  }else if(wordToUse == 'V'){
     binaryToColor("01010110");
     Serial.print("V");
  }else if(wordToUse == 'W'){
     binaryToColor("01010111");
     Serial.print("W");
  }else if(wordToUse == 'X'){
     binaryToColor("01011000");
     Serial.print("X");
  }else if(wordToUse == 'Y'){
     binaryToColor("01011001");
     Serial.print("Y");
  }else if(wordToUse == 'Z'){
     binaryToColor("01011010");
     Serial.print("Z");
  }


  else if(wordToUse == ' '){
     binaryToColor("00100000");
     Serial.print(" ");
  }else if(wordToUse == '@'){
     binaryToColor("01000000");
     Serial.print("@");
  }else if(wordToUse == '!'){
     binaryToColor("00100001");
     Serial.print("!");
  }else if(wordToUse == '*'){
     binaryToColor("00101010");
     Serial.print("\"");
  }else if(wordToUse == ','){
     binaryToColor("00101100");
     Serial.print(",");
  }else if(wordToUse == '.'){
     binaryToColor("00101110");
     Serial.print(".");
  }else if(wordToUse == ':'){
     binaryToColor("00111010");
     Serial.print(":");
  }else if(wordToUse == ';'){
     binaryToColor("00111011");
     Serial.print(";");
  }else if(wordToUse == '_'){ //Inicio texto
     binaryToColor("01011111");
     Serial.print("_");
  }else if(wordToUse == '-'){ //Fin texto
     binaryToColor("00101101");
     Serial.print("-");
     stopWord = "Stop";
  }else if(wordToUse == '~'){ //Salto de linea trampa :v
     binaryToColor("01111110");
     Serial.println("");
  }

  else if(wordToUse == '0'){
     binaryToColor("00110000");
     Serial.print("0");
  }else if(wordToUse == '1'){
     binaryToColor("00110001");
     Serial.print("1");
  }else if(wordToUse == '2'){
     binaryToColor("00110010");
     Serial.print("2");
  }else if(wordToUse == '3'){
     binaryToColor("00110011");
     Serial.print("3");
  }else if(wordToUse == '4'){
     binaryToColor("00110100");
     Serial.print("4");
  }else if(wordToUse == '5'){
     binaryToColor("00110101");
     Serial.print("5");
  }else if(wordToUse == '6'){
     binaryToColor("00110110");
     Serial.print("6");
  }else if(wordToUse == '7'){
     binaryToColor("00110111");
     Serial.print("7");
  }else if(wordToUse == '8'){
     binaryToColor("00111000");
     Serial.print("8");
  }else if(wordToUse == '9'){
     binaryToColor("00111001");
     Serial.print("9");  
  }
  
}

void binaryToColor(String bitToColor){
  for(int i = 0; i < 8 ; i++){//Lee numero por numero e imprime su color
    if(bitToColor[i]=='1'){
      digitalWrite(redColor,HIGH);
      delay(timeDelay);
    }else{
      digitalWrite(redColor,LOW);
      delay(timeDelay);
    }
  }
  digitalWrite(redColor,HIGH);
  delay(timeDelay);//Aqui indico que ya acabe de transmitir esa letra
}
