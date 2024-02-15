#define PIN_D8 8 
#define PIN_D9 9 
#define PIN_D10 10 
#define PIN_D11 11 

char pushed[3]; // массив нажатых кнопок
int k = 0; // счетчик нажатий

void setup()
{
  pinMode(PIN_D8, OUTPUT);
  pinMode(PIN_D9, OUTPUT);
  pinMode(PIN_D10, INPUT_PULLUP);
  pinMode(PIN_D11, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(PIN_D8, LOW);
  digitalWrite(PIN_D9, HIGH);
  if (digitalRead(PIN_D10) == LOW)
  {
    pushed[0] = true; //btn 1
  }
  digitalWrite(PIN_D8, HIGH);
  digitalWrite(PIN_D9, LOW);
  if (digitalRead(PIN_D10) == LOW)
  {
    pushed[2] = true; //btn 3
  }
}
