int ledPin = 9; // LED is attached to digital pin 9
int pushButton = 2;
//variables to keep track of the timing of recent interrupts
volatile unsigned long button_time = 0;  
volatile unsigned long last_button_time = 0; 
volatile boolean state = LOW; 

void setup() {                
  //enable interrupt 0 which uses pin 2
  //jump to the increment function on falling edge
  pinMode(ledPin,OUTPUT);
  pinMode(pushButton,INPUT);
  attachInterrupt(0, led_change, RISING);
  Serial.begin(9600);  //turn on serial communication
}

void loop() {
  digitalWrite(ledPin, state);
}

// Interrupt service routine for interrupt 0 (pin 2)
void led_change() {
  
  button_time = millis();
  Serial.println(button_time, DEC);
  //check to see if led_change() was called in the last 250 milliseconds
  if (button_time-last_button_time > 250)
  {
    Serial.println(button_time-last_button_time, DEC);
    state = !state;
    last_button_time = button_time;
  }
}
