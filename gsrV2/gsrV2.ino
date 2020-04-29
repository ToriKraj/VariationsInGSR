const int LED=13;
const int GSR=A2;
int threshold=0;
int sensorValue;

void setup() {
  
  long sum=0;
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  //turn on LED to show program is running
  digitalWrite(LED,HIGH);
  delay(1000);
  
  for(int i=0;i<500;i++) {
    sensorValue=analogRead(GSR);
    sum += sensorValue;
    delay(5);
  }
  
  threshold = sum/500;
  Serial.print("gsrstartvalue: "); 
  Serial.println(threshold); 
}

void loop() {
  sensorValue=analogRead(GSR);
  Serial.println(sensorValue);
}
