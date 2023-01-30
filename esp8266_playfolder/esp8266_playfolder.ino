#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>

SoftwareSerial mySoftwareSerial(D2,D1);
DFRobotDFPlayerMini myVoice;
void printDetail(uint8_t type, int value);
void playFromMP3Folder(uint16_t trackNum);


void setup() {
  // put your setup code here, to run once:
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);

  Serial.println();
  Serial.println("==================================");
  Serial.println("Project ESP8266 with DFPlayer Mini");
  Serial.println("==================================");
  Serial.println();

  if (!myVoice.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }

  Serial.println("DFPlayer Ready to Use");

  myVoice.volume(20);
  myVoice.play(1);
  delay(5000);
  Serial.println("Play Intro Project");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (myVoice.available()) {
    myVoice.playFolder(1,1); // play 100gr
    Serial.println("Play 100gr");
    delay(5000);
    myVoice.playFolder(1, 2); // play 100gr
    Serial.println("Play 200gr");
    delay(5000);
    myVoice.playFolder(1, 7); // play 100gr
    Serial.println("Play 700gr");
    delay(5000);

    myVoice.playFolder(2, 1); // play 100gr
    Serial.println("Play 1Kg");
    delay(5000);
    myVoice.playFolder(2, 2); // play 100gr
    Serial.println("Play 1.5Kg");
    delay(5000);
    myVoice.playFolder(2, 4); // play 100gr
    Serial.println("Play 2.5Kg");
    delay(5000);    
  }

}
