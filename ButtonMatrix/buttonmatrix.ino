const int numRows = 2;
const int numCols = 2;
const int rowPins[numRows] = {8, 9};
const int colPins[numCols] = {10, 11};

bool currButtonState[numRows][numCols];
bool prevButtonState[numRows][numCols];
char pushed[numRows][numCols];

void setup() {

  for (int i = 0; i < numRows; i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH);
  }

  for (int j = 0; j < numCols; j++) {
    pinMode(colPins[j], INPUT_PULLUP);
  }

  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      currButtonState[i][j] = false;
      prevButtonState[i][j] = false;
      pushed[i][j] = '0'; 
    }
  }

  Serial.begin(9600);
}

void loop() {

  bool stateChanged = false;

  for (int i = 0; i < numRows; i++) {
    digitalWrite(rowPins[i], LOW);
    delay(30);
    for (int j = 0; j < numCols; j++) {
      currButtonState[i][j] = digitalRead(colPins[j]);

      if (currButtonState[i][j] != prevButtonState[i][j]) {
        stateChanged = true;

        if (!currButtonState[i][j]) {
          pushed[i][j] = '1'; 
        } else {
          pushed[i][j] = '0'; 
        }
      }
      prevButtonState[i][j] = currButtonState[i][j];
    }
    digitalWrite(rowPins[i], HIGH);
  }

  if (stateChanged && !(pushed[0][0] == '0' && pushed[0][1] == '0' && pushed[1][0] == '0' && pushed[1][1] == '0')) {
    
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
        Serial.print(pushed[i][j]);
      }
    }
    Serial.println(); 
  }
  delay(100); 
}
