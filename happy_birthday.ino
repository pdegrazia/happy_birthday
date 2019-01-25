const int speakerPin = 2;
const int buttonOne = 10;
const int buttonTwo = 7;
const int buttonThree = 4;

int buttonOneState = 1;
int buttonTwoState = 1;
int buttonThreeState = 1;


int speedOne = 5;

int speedTwo = 5;

int speedThree = 4;



int length = 28; // the number of notes

int lengthTwo = 34; // the number of notes

int lengthThree = 19;

char notes[] = "GGAGcB GGAGdc GGxecBA yyecdc";

char notesTwo[] = "DGGAGFEE EAABAGFD DBBcBAGE DDEAFGD";

char notesThree[] = "DDED BBcB BdcB ABAG";

int beats[] = { 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8,8, 16, 1, 2,2,8,8,8,8,16, 1,2,2,8,8,8,16 };

int beatsTwo[] = {4, 4, 2, 2, 2, 2, 4, 4, 1, 4, 4, 2, 2, 2, 2, 4, 4, 1, 4, 4, 2, 2, 2, 2, 4, 4, 1, 4, 4, 8, 8, 8, 8};

int beatsThree[] {4, 4, 2, 8, 1, 4, 4, 2, 8, 1, 4, 4, 2, 8, 1, 4, 4, 2, 8};

int tempo = 150;

int tempoTwo=150;

int tempoThree=200;

void playTone(int tone, int duration) {

for (long i = 0; i < duration * 1000L; i += tone * 2) {

   digitalWrite(speakerPin, HIGH);

   delayMicroseconds(tone);

   digitalWrite(speakerPin, LOW);

   delayMicroseconds(tone);

}

}

void playNote(char note, int duration, int SPEE) {

char names[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B',           

                 'c', 'd', 'e', 'f', 'g', 'a', 'b',

                 'x', 'y' };

int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014,

                 956,  834,  765,  593,  468,  346,  224,

                 655 , 715 };

//int SPEE = 5;

// play the tone corresponding to the note name

for (int i = 0; i < 17; i++) {

   if (names[i] == note) {
    int newduration = duration/SPEE;
     playTone(tones[i], newduration);

   }

}

}

void setup() {
  Serial.begin(9600);
  pinMode(speakerPin, OUTPUT);
  pinMode(buttonOne, INPUT);
  digitalWrite(buttonOne, HIGH);
  pinMode(buttonTwo, INPUT);
  digitalWrite(buttonTwo, HIGH);
  pinMode(buttonThree, INPUT);
  digitalWrite(buttonThree, HIGH);

}

void loop() {
  
  buttonOneState = digitalRead(buttonOne);
  buttonTwoState = digitalRead(buttonTwo);
  buttonThreeState = digitalRead(buttonThree);

  //Serial.println(buttonState);
  
  if (buttonOneState == LOW){
    for (int i = 0; i < length; i++) {
  
     if (notes[i] == ' ') {
  
       delay(beats[i] * tempo); // rest
  
     } else {
  
       playNote(notes[i], beats[i] * tempo, speedOne);
  
     }
  
     // pause between notes
  
     delay(tempo);
  
    }
  }

  if (buttonTwoState == LOW){
    for (int i = 0; i < lengthTwo; i++) {
  
     if (notesTwo[i] == ' ') {
  
       delay(beatsTwo[i] * tempoTwo); // rest
  
     } else {
  
       playNote(notesTwo[i], beatsTwo[i] * tempoTwo, speedTwo);
  
     }
  
     // pause between notes
  
     delay(tempo);
  
    }
  }

  if (buttonThreeState == LOW){
    for (int i = 0; i < lengthThree; i++) {
  
     if (notesThree[i] == ' ') {
  
       delay(beatsThree[i] * tempo); // rest
  
     } else {
  
       playNote(notesThree[i], beatsThree[i] * tempo, speedThree);
  
     }
  
     // pause between notes
  
     delay(tempo);
  
    }
  }
  
}
