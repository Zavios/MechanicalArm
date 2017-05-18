const int MIN = 390;
const int MAX = 645;

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
bool First;

void setup() {
  First = true;
  
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

  pos = analogRead(A0);
  Serial.print(pos);
  
  if(pos >= MAX){
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
  }
  else if(pos <= MIN){
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
  }
  else if(First == true){
    digitalWrite(pinB, LOW);
    digitalWrite(pinA, HIGH);
    First = false;
  }

  digitalWrite(pinTrigger, HIGH);
  
  Serial.println(" ok");
}
