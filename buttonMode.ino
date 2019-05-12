/* LED have 5 settings changed by a push button. Settings are:  off, low, medium,
  high and flashing
 */

const int buttonPin = 2; //num of pin connected to button
const  int ledPin = 6; //num of pin connected to led

int buttonState = 0; //is button pressed
int brightMode = 0; //mode of brightness of LED, counts up 0-5 every time button pressed
int didLift = 1;

void setup() {

pinMode(ledPin, OUTPUT);
pinMode(buttonPin, INPUT);
}

void loop() {
 //read state of button
  buttonState = digitalRead(buttonPin);

  if((buttonState==HIGH)&&(didLift==1)){
    if(brightMode==4){
      brightMode=0;
    }else{
       brightMode++;
    }
    didLift = 0;
  }
  switch(brightMode){
    case 0:
      digitalWrite(ledPin, LOW); //mode off
    break;
    case 1:
      analogWrite(ledPin, 1); //mode low
    break;
    case 2:
      analogWrite(ledPin, 100); //mode medium
    break;
    case 3:
      digitalWrite(ledPin, HIGH); //mode high
    break;
    case 4:
      buttonState = digitalRead(buttonPin);
      digitalWrite(ledPin, LOW); //mode flash
      delay(200);
      buttonState = digitalRead(buttonPin); //makes  sure a quick press is picked up
      digitalWrite(ledPin, HIGH);
      delay(200);
    break;
  }
  buttonState = digitalRead(buttonPin);
  if(buttonState==LOW){
    didLift = 1; //makes sure the butten has been pressed not held
  }
}
