int Buzzer = 8;       // choose the pin for the LED
int PIRpin = 5;       // choose the input pin for PIR sensor
int PIRstate = 0;     // set PIR state for no motion
int led = 13;         // for LED
int serialState = LOW;              // for serial output

void setup() {
  pinMode(Buzzer, OUTPUT);          // initialize the LED pin as an output:
  pinMode(PIRpin, INPUT);           // initialize the PIR sensor pin as an input:
  pinMode(led, OUTPUT);             // initialize led light
  Serial.begin(9600);               // initalize serial monitor
}

void loop() {
    PIRSensor();
}


void PIRSensor(){
    PIRstate = digitalRead(PIRpin);   // read the state of the pushbutton value:

// if PIR sensor is triggered, buzzer will buzz, LED will light up
  if (PIRstate == HIGH) {
    tone(Buzzer, 500, 100); //adjusts the frequency and duration
    digitalWrite(led,HIGH);
    
      if(serialState == LOW){

//output in serial if alarm triggered
        Serial.println("ALARM TRIGGERED"); 
        serialState = HIGH;
      }
      
  } else {

// if PIR sensor is not triggered, buzzer will stop buzzing, LED will not light up
    noTone(Buzzer);
    digitalWrite(led,LOW);

// no output in serial if alarm is not triggered
      if(serialState == HIGH){   
        serialState = LOW;
      }
  }  
}
