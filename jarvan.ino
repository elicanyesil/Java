
//Step
const int stepPin = 9;
const int dirPin = 8;

//Dc
const int dc1 = 5;
const int dc2 = 4; 

//Leaf Switch
const int switch1 = 11;
const int switch2 = 10;

void setup() {
 Serial.begin(9600);
 pinMode(stepPin, OUTPUT);
 pinMode(dirPin, OUTPUT);
 pinMode(dc1, OUTPUT);
 pinMode(dc2, OUTPUT);

 pinMode(switch1, INPUT);
 pinMode(switch2, INPUT);
}

void loop() {
  forward(); //Dc lışıyor
  Serial.println("switch off");
  if( (digitalRead(switch1) == HIGH) && (digitalRead(switch2) == HIGH) ){
      Serial.println("switch on ");
      stop_dc();//Dc durucak
      delay(300);
      turnRight(300);
      delay(300);
      forward();
      delay(1000);
      stop_dc();
      turnLeft(300);
    }

}

void forward(){
    digitalWrite(dc1, HIGH);
    digitalWrite(dc2, HIGH);
    return;
  }

 void stop_dc(){
    digitalWrite(dc1,LOW);
    digitalWrite(dc2,LOW);
    return;
  }

  void turnRight(int N){
    
    digitalWrite(dirPin,HIGH); //Enables the motor to move in a opposite direction
    Serial.println("saga donuyorum");
    for(int x = 0; x < N; x++){
      Serial.println("dön");
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(24000);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(24000);
    }
    Serial.println("döndüm");
  }

    void turnLeft(int N){
    
    digitalWrite(dirPin,LOW); //Enables the motor to move in a opposite direction
    Serial.println("sola dönüyorum");
    for(int x = 0; x < N; x++){
      Serial.println("dön");
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(24000);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(24000);
    }
      Serial.println("döndüm");
    }
