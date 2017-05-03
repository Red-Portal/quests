//Aqua Light(수란) dc07650@naver.com - Anything about the code, email me

int memory[256];
int compa;
String inString = "";    
int nametag, mug, cup;
String bckString = "";
int lose[256];

void setup() {
  
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(11,OUTPUT);
  while (!Serial) {
    ; 
  }

  //Serial.println("\n\nString toInt():");
  Serial.println();
          digitalWrite(13,LOW);

}

void loop() {
  while (Serial.available() > 0) {
    int inChar = Serial.read();
   
  
      {
      inString += (char)inChar;
    }
    if (inChar == '\n') {
      /*Serial.print("Value:");
      Serial.println(inString.toInt());
      Serial.print("String:");
      Serial.println(inString);
      Serial.println(int(inString.charAt(0)));
*/
       bckString = inString;

          while(true){
            if(bckString.indexOf(':', cup)==-1){
             break;    
            }
            
          lose[int(inString.charAt(bckString.indexOf(':', cup)+2))] = bckString.indexOf(':', cup)+2;
         // Serial.print(lose[int(inString.charAt(bckString.indexOf(':', cup)+2))]);
         // Serial.print("=");
         // Serial.println(inString.charAt(bckString.indexOf(':', cup)+2));
          cup = lose[int(inString.charAt(bckString.indexOf(':', cup)+2))];
          
          }
          
          inString = bckString;
         // while(true){}
///////////////////////////////////////////////////////////////////////////////////////////··············
      while(inString != NULL){
      
      
      
      if(isDigit(inString.charAt(0))){
        compa = inString.toInt();
       }else if(isAscii(inString.charAt(0))){
        compa = int(inString.charAt(0));
       }

       
    //  Serial.println(compa);
    // Serial.println("//////////");
      switch(compa){
        /*case ':':
          parString();
          lose[int(inString.charAt(0))] = bckString.indexOf(inString.charAt(0));
          Serial.println(lose[int(inString.charAt(0))]);
          break;*/
        case '=':
          parString();
          nametag = int(inString.charAt(0)); 
          //int var = nametag;
          parString();
          memory[nametag]= inString.toInt();
          /*Serial.print("Name is: ");
          Serial.write(nametag);
          Serial.print(" = ");
          Serial.println(memory[nametag])*/;
        break;
        case '+':
          parString();
          cup = int(inString.charAt(0));
          parString();
          mug = 0;
         if(isDigit(inString.charAt(0))){
           mug = inString.toInt();
           memory[cup] = memory[cup] + mug; 
          }else if(isAscii(inString.charAt(0))){
           mug = int(inString.charAt(0));
           memory[cup] = memory[cup] + memory[mug];
          }
         // Serial.println(memory[cup]);
          break;
        case '-':
        parString();
          cup = int(inString.charAt(0));
          parString();
          mug = 0;
         if(isDigit(inString.charAt(0))){
           mug = inString.toInt();
           memory[cup] = memory[cup] - mug; 
          }else if(isAscii(inString.charAt(0))){
           mug = int(inString.charAt(0));
           memory[cup] = memory[cup] - memory[mug];
          }
         // Serial.println(memory[cup]);
          break;
        case '/':
        parString();
          cup = int(inString.charAt(0));
          parString();
          mug = 0;
         if(isDigit(inString.charAt(0))){
           mug = inString.toInt();
           memory[cup] = memory[cup] / mug; 
          }else if(isAscii(inString.charAt(0))){
           mug = int(inString.charAt(0));
           memory[cup] = memory[cup] / memory[mug];
          }
         // Serial.println(memory[cup]);
          break;
        case '*':
        parString();
          cup = int(inString.charAt(0));
          parString();
          mug = 0;
         if(isDigit(inString.charAt(0))){
           mug = inString.toInt();
           memory[cup] = memory[cup] * mug; 
          }else if(isAscii(inString.charAt(0))){
           mug = int(inString.charAt(0));
           memory[cup] = memory[cup] * memory[mug];
          }
         // Serial.println(memory[cup]);
          break;
        case 'c':
        parString();
        if(memory[int(inString.charAt(0))]!=0){
              parString();
              inString = bckString.substring(lose[int(inString.charAt(0))]+1);
              //Serial.println(inString);
        }else if(memory[int(inString.charAt(0))==0]==0){
              parString(); parString();
              inString = bckString.substring(lose[int(inString.charAt(0))]+1);
             //Serial.println(inString);
        }
           
        break;
        case 'p':
        parString();
        Serial.println(memory[int(inString.charAt(0))]);
          
        break;

        case ';':
        inString = "";
        break;
      }
      
      parString();
      
      }
      // clear the string for new input:
      inString = "";
    }
    
  }
}

void parString(){
  int temp = inString.indexOf(' ');
      String del = inString.substring(0, temp);
       //Serial.print("del:");
       //Serial.println(del);
       inString.remove(0, del.length()+1);
       //Serial.print("aft:");
       //Serial.println(inString);
}


