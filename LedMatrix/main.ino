#define led_pin7 7
#define led_pin8 8
#define led_pin11 11
#define led_pin12 12

const int DELAY = 500;

void setup()
{
  pinMode(led_pin7, OUTPUT);
  pinMode(led_pin8, OUTPUT);
  pinMode(led_pin11, OUTPUT);
  pinMode(led_pin12, OUTPUT);
}

void loop()
{
  // single
  top_left();
  delay(DELAY);
  top_right();
  delay(DELAY);
  bottom_left();
  delay(DELAY);
  bottom_right();
  delay(DELAY);
  
  // pairs
  top_left_and_top_right();
  delay(DELAY);
  bottom_left_and_bottom_right();
  delay(DELAY);
  top_left_and_bottom_left();
  delay(DELAY);
  top_right_and_bottom_right();
  delay(DELAY);
  top_left_and_bottom_right();
  delay(DELAY);
  top_right_and_bottom_left();
  delay(DELAY);

  // triple
  blink123();
  delay(DELAY);
  blink234();
  delay(DELAY);
  blink341();
  delay(DELAY);
  blink412();
  delay(DELAY);
  
  // quad
  all();
  delay(DELAY);
  
  no_one();
  delay(DELAY);
}

void no_one(){
  digitalWrite(led_pin7, LOW);
  digitalWrite(led_pin8, LOW);
  digitalWrite(led_pin11, LOW);
  digitalWrite(led_pin12, LOW);
}

void top_left(){
  digitalWrite(led_pin7, HIGH);
  digitalWrite(led_pin8, LOW);
  digitalWrite(led_pin11, LOW);
  digitalWrite(led_pin12, HIGH);
}

void top_right(){
  digitalWrite(led_pin7, HIGH);
  digitalWrite(led_pin8, LOW);
  digitalWrite(led_pin11, HIGH);
  digitalWrite(led_pin12, LOW);
}
  
void bottom_left(){
  digitalWrite(led_pin7, LOW);
  digitalWrite(led_pin8, HIGH);
  digitalWrite(led_pin11, LOW);
  digitalWrite(led_pin12, HIGH);
}

void bottom_right(){
  digitalWrite(led_pin7, LOW);
  digitalWrite(led_pin8, HIGH);
  digitalWrite(led_pin11, HIGH);
  digitalWrite(led_pin12, LOW);
}


void top_left_and_top_right(){
  digitalWrite(led_pin7, HIGH);
  digitalWrite(led_pin8, LOW);
  digitalWrite(led_pin11, LOW);
  digitalWrite(led_pin12, LOW);
}

void bottom_left_and_bottom_right(){
  digitalWrite(led_pin7, LOW);
  digitalWrite(led_pin8, HIGH);
  digitalWrite(led_pin11, LOW);
  digitalWrite(led_pin12, LOW);
}

void top_left_and_bottom_left(){
  digitalWrite(led_pin7, HIGH);
  digitalWrite(led_pin8, HIGH);
  digitalWrite(led_pin11, LOW);
  digitalWrite(led_pin12, HIGH);
}

void top_right_and_bottom_right(){
  digitalWrite(led_pin7, HIGH);
  digitalWrite(led_pin8, HIGH);
  digitalWrite(led_pin11, HIGH);
  digitalWrite(led_pin12, LOW);
}

void top_left_and_bottom_right(){
  for (int i = 0; i < 150; i++) {
    top_left();
    delay(1);
    bottom_right();
    delay(1);
  }
  no_one();
}

void top_right_and_bottom_left(){
  for (int i = 0; i < 150; i++) {
    top_right();
    delay(1);
    bottom_left();
    delay(1);
  }
  no_one();
}

void blink123(){
  for (int i = 0; i < 100; i++) {
    top_left();
    delay(1);
    top_right();
    delay(1);
    bottom_left();
    delay(1);
  }
  no_one();
}

void blink234(){
  for (int i = 0; i < 100; i++) {
    top_right();
    delay(1);
    bottom_left();
    delay(1);
    bottom_right();
    delay(1);
  }
  no_one();
}

void blink341(){
  for (int i = 0; i < 100; i++) {
    bottom_left();
    delay(1);
    bottom_right();
    delay(1);
    top_left();
    delay(1);
  }
  no_one();
}

void blink412(){
  for (int i = 0; i < 100; i++) {
    bottom_right();
    delay(1);
    top_left();
    delay(1);
    top_right();
    delay(1);
  }
  no_one();
}

void all(){
  digitalWrite(led_pin7, HIGH);
  digitalWrite(led_pin8, HIGH);
  digitalWrite(led_pin11, LOW);
  digitalWrite(led_pin12, LOW);
}
