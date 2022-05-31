int led_pin = 9; // LED is attached to digital pin 9
int push_button = 2;
//variables to keep track of the timing of recent interrupts
volatile unsigned long button_time = 0;  
volatile unsigned long last_button_time = 0; 
volatile boolean state = LOW;
volatile int button_state = 0; 

void setup() {                
  //enable interrupt 0 which uses pin 2
  //jump to the increment function on falling edge
  pinMode(led_pin,OUTPUT);
  pinMode(push_button,INPUT);
  attachInterrupt(0, led_change, CHANGE);
  Serial.begin(9600);  //turn on serial communication
}

void loop() {
  digitalWrite(led_pin, state);
}

// Interrupt service routine for interrupt 0
void led_change() {
  
  button_time = millis();
  Serial.println(button_time, DEC);
  //check to see if led_change() was called in the last 100 milliseconds
  if (button_time-last_button_time > 100)
  {
    Serial.println(button_time-last_button_time, DEC);
    button_state = digitalRead(push_button);
    // check if the pushbutton is pressed.if it is, the buttonState is HIGH:
    if (button_state == HIGH)
        state = HIGH;
    else
        state = LOW;
    last_button_time = button_time;
  }
}
