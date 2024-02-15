#define PIN_D8 8 
#define PIN_D9 9 
#define PIN_D10 10 
#define PIN_D11 11 

char pushed[2][2] = {{0, 0}, {0, 0}}; // массив нажатых кнопок
int k = 0; // счетчик нажатий
const int rows[2] = {PIN_D8, PIN_D9};
const int cols[2] = {PIN_D10, PIN_D11};
bool currButtonState[2][2] = {{false, false}, {false, false}};
bool prevButtonState[2][2] = {{false, false}, {false, false}};

void setup()
{
  pinMode(PIN_D8, OUTPUT);
  pinMode(PIN_D9, OUTPUT);
  pinMode(PIN_D10, INPUT_PULLUP);
  pinMode(PIN_D11, INPUT_PULLUP);

  digitalWrite(PIN_D8, HIGH);
  digitalWrite(PIN_D9, HIGH);


  
  Serial.begin(9600);
}

void loop()
{
  bool stateChanged = false;

  for (int i = 0; i < 2; i++) {
    digitalWrite(rows[i], LOW);
    
    for (int j = 0; j < 2; j++) {
      currButtonState[i][j] = digitalRead(cols[j]);
      if (currButtonState[i][j] != prevButtonState[i][j]) {
        stateChanged = true;
        if (!currButtonState[i][j]) {
          pushed[i][j] = '0'; 
        } else {
          pushed[i][j] = '1';
        }
      }
      prevButtonState[i][j] = currButtonState[i][j];
    }
    digitalWrite(rows[i], HIGH);
  }
    
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        Serial.print(pushed[i][j]);
      }
    }
    Serial.println();
  }
  delay(100);
}
}
