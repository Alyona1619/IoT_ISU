#define sensor_pin A0
#define led_pin 2

bool streaming = false;
bool send_one_value = false;
long previous_send_time = 0;
long send_count = 0;

bool isAuto = false;
bool isAlarm = false;

int sensor_limit = 500;
int interval = 500;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  long current_time = millis();
  data_reading();
  

  if (streaming == true and current_time / 100 != send_count){
    send_photo_data();
    //previous_send_time = current_time;
    previous_send_time = previous_send_time + 100;
    send_count = current_time / 100;
    Serial.print("Time in millis ");
    Serial.print(millis());
  }
  if (send_one_value == true){
    send_photo_data();
    send_one_value = false;
  }


  if (isAuto){
    int sensor_value = analogRead(sensor_pin);
    if (sensor_value < sensor_limit) 
    {
      digitalWrite(led_pin, HIGH);
    }
    else 
    {
      digitalWrite(led_pin, LOW);
    }
  }


  if (isAlarm) {
    if (current_time - previous_send_time >= interval) {
      previous_send_time = current_time;

      digitalWrite(led_pin, !digitalRead(led_pin));
    }
  }
}

void data_reading()
{
  if (Serial.available() > 0)
    {
        char command = Serial.read();
        switch (command)
        {
        case 'p': // for Photo sensor
            streaming = true;
            break;
        case 's': // single value
            streaming = false;
            send_one_value = true;
            break;
        case 'i': // illumination level (auto mode)
            isAlarm = false;
            isAuto = true;
            break;
        case 'n': // on (hand mode)
            isAuto = false;
            isAlarm = false;
            digitalWrite(led_pin, HIGH);
            break;
        case 'f': // off (hand mode)
            isAuto = false;
            isAlarm = false;
            digitalWrite(led_pin, LOW);
            break;
        case 'a': // alarm system
            isAuto = false;
            isAlarm = true;
            break;
        }
    }
}

void send_photo_data()
{
  int val = analogRead(sensor_pin);
  Serial.print("Sensor value: ");
  Serial.println(val);
}
