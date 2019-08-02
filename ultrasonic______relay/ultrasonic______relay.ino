    #define trigPin 10
#define echoPin 11

int led = 6;
int buzer = 7;
int relay = 8;

int sound = 10;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);

 pinMode(led, OUTPUT);
 pinMode(buzer, OUTPUT);
 pinMode(relay, OUTPUT);
 digitalWrite(relay, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
 long duration, distance;
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = duration / 29 / 2;

 if(distance <= 10)
 {
  digitalWrite(led, HIGH);
  digitalWrite(buzer, HIGH);  
  Serial.println("kurang dari sama dengan 10");
  delay(100);
  sound = 10;
  digitalWrite(led, LOW);
  digitalWrite(buzer, LOW);
  delay(100);
  digitalWrite(relay, LOW);  
  }
  else if(distance >= 100)
  {
      digitalWrite(relay, HIGH); 
  }
  else{
    digitalWrite(led,LOW);
    digitalWrite(buzer, LOW);
    digitalWrite(relay, LOW); 
    noTone(buzer);
    }

  Serial.println(distance);
}
