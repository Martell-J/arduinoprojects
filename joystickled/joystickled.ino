
 int ledPin = 13;
 int joyPin1 = A0;                 // slider variable connecetd to analog pin 0
 int joyPin2 = A1;                 // slider variable connecetd to analog pin 1
 int value1 = 0;                  // variable to read the value from the analog pin 0
 int value2 = 0;                  // variable to read the value from the analog pin 1

 void setup() {
  Serial.begin(9600);
  delay(25);
  Serial.println("Test!");
  for (int i = 0; i < 8; i++) {
     pinMode(i, OUTPUT);  
  }
 }

 int treatValue(int data) {
  return (data * 9 / 1024) / 4;
 }

 void loop() {
  value1 = treatValue(analogRead(joyPin1));  
  value2 = treatValue(analogRead(joyPin2));    
  Serial.println("X: ");
  Serial.print(value1);
  Serial.println("Y: ");
  Serial.print(value2);
  delay(20);
  
 }

 void looptwo() {
  // reads the value of the variable resistor 
  value1 = treatValue(analogRead(joyPin1));   
  // this small pause is needed between reading
  // analog pins, otherwise we get the same value twice
  delay(1000);             
  // reads the value of the variable resistor 
  value2 = treatValue(analogRead(joyPin2));   
  analogWrite(value1, HIGH);
  delay(100);
  analogWrite(value2, LOW);
  delay(100);
 }
