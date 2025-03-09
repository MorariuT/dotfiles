int addr_pins[16] = {20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50};
int data_pins[8] = {21, 23, 25, 27, 29, 31, 33, 35};

void setup() 
{
  Serial.begin(115200);

  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), read_data, RISING);

  for(int i = 0;i < 15;i++) pinMode(addr_pins[i], INPUT);
  for(int i = 0;i < 7;i++) pinMode(data_pins[i], INPUT);
}

void loop()
{
  
}

void read_data()
{
  int val = 0;
  
  for(int i = 0;i <= 15;i++)
  {
    int val_pin = digitalRead(addr_pins[i]);
    val += (1 << i) * val_pin;
    Serial.print(digitalRead(addr_pins[i]));
  }
  Serial.print(' ');
  Serial.print(val, HEX);
  val = 0;
  Serial.print("      ");
  for(int i = 0;i <= 7;i++)
  {
    int val_pin = digitalRead(data_pins[i]);
    val += (1 << i) * val_pin;
    Serial.print(digitalRead(data_pins[i]));
  }
  Serial.print(' ');
  Serial.print(val, HEX);
  

  Serial.println();
  Serial.println();
  
}
