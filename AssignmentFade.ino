const int ledPin = 9; //red LED connected to digital pin 9 for fade
const int yellow = 4; // yellow LED connected to digital pin 4
const int white = 5; // white LED connected to digital pin 5
const int green = 6; // green LED connected to digital pin 6
const int button = 2; // button connected to digital pin 2



int ledState = HIGH;        // the current state of the output pin
int buttonState;            // the current reading from the input pin
int lastButtonState = LOW;  // the previous reading from the input pin

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  // 
  pinMode(button, INPUT); //initialize the button pin as an input
  pinMode(ledPin, OUTPUT); // initialize the ledPin pin as an output
   pinMode(yellow, OUTPUT); // initialize the yellow pin as an output
    pinMode(green, OUTPUT); // initialize the green pin as an output
     pinMode(white, OUTPUT); // initialize the white pin as an output

  digitalWrite(ledPin, ledState); // set the ledPin to ledState
   digitalWrite(yellow, ledState); // set the yellow to ledState
    digitalWrite(green, ledState); // set the green to ledState
     digitalWrite(white, ledState); // set the white to ledState

     
}
// loop for fading the ledPin with PMW 
void loop(){
  //fade the brightness from 0 to 255 with 30ms delay
for (int fadeValue = 0; fadeValue <= 255; fadeValue += 5) {
       analogWrite(ledPin, fadeValue);
      buttonLoop (); // run the buttonLoop
       delay(30);
     }
    // //fade the brightness from 255 to 0 with 30ms delay
     for (int fadeValue = 255; fadeValue >= 0; fadeValue -=5) {

       analogWrite(ledPin, fadeValue);
        buttonLoop (); //run the buttonLoop
       delay (30);
     }

}
// loop for the button connected to 3 LEDs
void buttonLoop() {
  
 int reading = digitalRead(button); // // read the state of the switch into a local variable:

 if (reading != lastButtonState) { // // If the switch changed, due to noise or pressing:
    // reset the debouncing timer
    lastDebounceTime = millis(); //reset the debouncing timer
  }
  if ((millis() - lastDebounceTime) > debounceDelay) { // // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    if (reading != buttonState) { // if the button state has changed
      buttonState = reading;

       if (buttonState == HIGH) { // toggle the ledPin if the new button state is HIGH
        ledState = !ledState;
      }
    }
  }

  
     // set the LEDs
    digitalWrite(yellow, ledState);
      digitalWrite(green, ledState);
        digitalWrite(white, ledState);
        
  lastButtonState = reading; //save the reading. Next time through the loop, it'll be the lastButtonState
}
