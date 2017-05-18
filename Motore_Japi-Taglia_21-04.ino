//MIN = 380
//MAX = 655

// Attributes

int pinTrigger = 2;

int pinA = 4;
int pinB = 7;

/*
 * Down:  A - HIGH / B - LOW
 * Up:  A - LOW / B - HIGH
 * 
 */

int pos;

void setup() {
  pinMode(pinTrigger, OUTPUT);
  pinMode(A0, INPUT);

  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);

  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(pinTrigger, LOW);

  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  
  pos = analogRead(A0);
  Serial.print(pos);

  digitalWrite(pinTrigger, HIGH);
  
  Serial.println(" ok");
}
