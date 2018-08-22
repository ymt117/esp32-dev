#define led 16

// －・－・・　－・－－　・－・－・
int words[] = {1, 0, 1, 0, 0, 2, 1, 0, 1, 1, 2, 0, 1, 0, 1, 0, 2};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(16, OUTPUT);
}

void morse(){
  for(int i=0; i<sizeof(words)/sizeof(int); i++){
    if(words[i] == 0){
      Serial.println("トン");
      digitalWrite(led, HIGH);
      delay(200);
      digitalWrite(led, LOW);
    }
    else if(words[i] == 1){
      Serial.println("ツー");
      digitalWrite(led, HIGH);
      delay(600);
      digitalWrite(led, LOW);
    }
    else{
      Serial.println();
      delay(600);
    }
    delay(100);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(sizeof(words)/sizeof(int));
  int inputchar = Serial.read();
  if(inputchar != -1){
    switch(inputchar){
      case '1':
        morse();
        break;
      
      case '0':
        break;
        
      default:
        break;
    }
  }
}
