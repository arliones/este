// Pins mapping
static const int led1 = 8;
static const int led2 = 9;
static const int button1 = 2;
static const int button2 = 3;

void setup()
{
    // put your setup code here, to run once:

    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
}

void loop()
{
    // put your main code here, to run repeatedly:

    if (digitalRead(button1) == LOW)
    {
        digitalWrite(led1, HIGH);
    }
    else
    {
        digitalWrite(led1, LOW);
    }
  
    if (digitalRead(button2) == HIGH)
    {
        digitalWrite(led2, HIGH);
    }
    else
    {
        digitalWrite(led2, LOW);
    }
}
