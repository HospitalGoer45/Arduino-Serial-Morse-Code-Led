/*
  Morse Code Android Robot
 */

//Variables
int led = 13;
int once = 200;
String inputString;
String message = "Hello World";
static const char *codes[] = {
  "10",             // A, codes[0]
  "0111",           // B, codes[1]
  "0101",           // C
  "011",            // D
  "1",              // E
  "1101",           // F
  "001",            // G
  "1111",           // H
  "11",             // I
  "1000",           // J
  "010",            // K
  "1011",           // L
  "00",             // M
  "01",             // N
  "000",            // O
  "1001",           // P
  "0010",           // Q
  "101",            // R
  "111",            // S
  "0",              // T
  "110",            // U
  "1110",           // V
  "100",            // w
  "0110",           // x
  "0100",           // y
  "0011",           // z
  "00000",          // 0
  "10000",          // 1
  "11000",          // 2
  "11100",          // 3
  "11110",          // 4
  "11111",          // 5
  "01111",          // 6
  "00111",          // 7
  "00011",          // 8
  "00001",          // 9
  "101010",         // .
  "001100",         // ,
  "110011",         // ?
  "100001",         // '
  "010100",         // !
  "01101",          // /
  "01001",          // (
  "010010",         // )
  "10111",          // &
  "000111",         // :
  "010101",         // ;
  "01110",          // =
  "10101",          // +
  "01110",          // -
  "110010",         // _
  "101101",         // "
  "1110110",        // $
  "100101",         // @, codes[54]
};

//morse code stuff
void on() {
  digitalWrite(led,HIGH);
}

void off() {
  digitalWrite(led,LOW);
}

void dot(){
  on();
  delay(once);
}

void dash(){
  on();
  delay(once*3);
}

void gap(){
  off();
  delay(once);
}

void gapLetter(){
  off();
  delay(once*3);
}

void gapWord(){
  off();
  delay(once*7);
}

void blinkCodeSequence(int j) {
  int i;

  for( i=0; i < strlen(codes[j]); ++i ) {
    if( i>0 ) gap();
                                     
    if( codes[j][i] == '0' ) dash();
    if( codes[j][i] == '1' ) dot();
  }
}
void wordToSeq(String word){
  int i;
  for(i=0;i<word.length();i++){
    Serial.print(word[i]);
    if(int(word[i]) != 32){
    blinkCodeSequence(word[i]-97);
    gapLetter();
    }else{
    gapWord();}
  }
  i = 0;
  Serial.print("\n");
  gapWord();
}

//Check for new message
void checkSerial(){
  if (Serial.available() > 0) {
                 message=Serial.readString();
        }
}

//Fade Led Mode
void fade(){
}

//What to mess with

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  checkSerial();
  morseCode();
}
//Functions that put together prevoius functions
void morseCode(){
  pinMode(led, OUTPUT);
  wordToSeq(message);
}
