int t1 ;
int t2 ;
int value = 0 ;
int value_end ;
int answer ;
int presentcount = 0 ; //morse bit count
int pastcount;
int count;
int CircuitDelay = 3500;
int i = 0;
String Piece;
int s0 = 5;
int s1 = 6;
int s2 = 7;


//unsigned long siglen, t1,t2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
}

void loop() {
  digitalWrite(s2,HIGH);
  digitalWrite(s1,LOW);
  digitalWrite(s0,LOW);
  //High point reader
  while (digitalRead(2) == LOW) {}
  t1 = millis();

  //Low point reader
  while (digitalRead(2) == HIGH) {}
  t2 = millis();

  //unwanted spike error filter
  if (t2 - t1 > 250) {
    if (value == 0) { // getting initial value
      value = millis();
    }
    else { // storing initial value as past value and getting present value.
      value_end = millis();
      if (value_end - value - 300 < 400) {
        answer = value_end - value - 300;
        //Serial.println(RawDatatoString(answer));
        MorseBitCount(answer);
        if (pastcount > 0){
          MakeStringGreatAgain (pastcount, RawDatatoString(answer));
          
          }
      }
      else {
        answer = value_end - value - 3880 ;
        //Serial.println(RawDatatoString(answer));
        MorseBitCount(answer);
         if (pastcount > 0){
          MakeStringGreatAgain (pastcount, RawDatatoString(answer));
          
          }
        answer = 4000;
        //Serial.println(RawDatatoString(answer));
        MorseBitCount(answer);
         if (pastcount > 0){
          MakeStringGreatAgain (pastcount, RawDatatoString(answer));
          
          }
      }
      if (Piece != ""){Serial.print("Sonuç: ");Serial.print(Piece);Serial.println("");}
      value = value_end;
      value_end = 0;
     
    }
  
  }
}




void MorseBitCount (int answer) { // how many bits there is in a period

  if (answer < CircuitDelay) {
    presentcount++;
    return;
  }
  else {
    pastcount = presentcount   ;
    presentcount = 0 ;
    Serial.print("Bit: ");
    Serial.print(pastcount);
    Serial.println("");
    return;
  }
}



String RawDatatoString (int answer) {  //raw data to string
  if (answer < 110) {
    return "0";
  }
  else if ((answer > 110) && (answer < 400)) {
    return "1";
  }
  else {
    return "d";
  }
}

  String placeholder ="";
  void MakeStringGreatAgain (int count, String Str){
    
    if (i < count){
      if (Str == "d"){return;}
       
      else{ 
      placeholder = placeholder + Str;
      i++;
      return;
      }  
    }
    else if (i == count){
      Piece = placeholder;
      placeholder ="";
      i = 0;
      return;
      }   
      return; 
      }
      
  void GetSelect (int s0, int s1 , int s2){
      for(int x=0; x<=7; x++){
    digitalWrite(s0, bitRead(x,0));
    digitalWrite(s1, bitRead(x,1));
    digitalWrite(s2, bitRead(x,2));
    }
    }
    
