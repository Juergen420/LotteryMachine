//Lottery Machine Coding Challange possible solution by juergen [GER]
//
//Challange: Code a Lottery Machine wich draws 7 Random Numbers between 1 and 50 but
//           doesn't draw two Numbers twice per Round 
//
//Connect a button between GND and digitalPin 6

int n1 = 0;                             // n1 - n7 = Previous 
int n2 = 0; 
int n3 = 0;
int n4 = 0;
int n5 = 0;
int n6 = 0;
int n7 = 0;
int Button = 6;                         //declairing Pushbutton on  Ardunio
int randn;                              //declairing variable for random Number
int pr;                                 //declairing variable for Serialprint
int count = 0;                          //countwer for saving variables

void setup() {
     Serial.begin(9600);
     pinMode(Button, INPUT_PULLUP);
     Serial.println("Lottery Machine by juergen");
     Serial.println("Press Button (Pin 6) to Start");
     Serial.println("-----------------------------");
     randomSeed(analogRead(0));         //picking Random Seed via Analog Pin 0
}

void loop() {
  
if (!digitalRead(Button)){                          //check if Button is Pressed
   label:
    randn = random(1, 50);                          //generate random Nuber between 0 and 50
      if(randn != n1){                              //verify that the generated Number is not already drawn
      if(randn != n2){                              
      if(randn != n3){
      if(randn != n4){                              
      if(randn != n5){
      if(randn != n6){
      if(randn != n7){
          pr = randn;                               //if it isnt already drawn, Print to Serial Monitor  
          Serial.println("-----------------");
          Serial.print("Your ");
          Serial.print(++count);
          Serial.print(". Number is: ");
          Serial.println(pr);
      }}}}}}}
      else{
        goto label;                                 //if its already drawn reapeat checking cycle with a new generatet Nuber
      }     


switch (count) {                                    //saving process of the previous drawn Numbers
    case 1:
      n1 = pr;
      break;
    case 2:
      n2 = pr;
      break;
    case 3:
      n3 = pr;
      break;
    case 4:
      n4 = pr;
      break;
    case 5:
      n5 = pr;
      break;
    case 6:
      n6 = pr;
      break;
    case 7:                                         //if 7 Numbers are drawn reset all values and start a new Round
      n7 = 0;
      n6 = 0;
      n5 = 0;
      n4 = 0;
      n3 = 0;
      n2 = 0;
      n1 = 0;
     count = 0;
      
      Serial.println(); 
      Serial.println("-------- New round! --------");
      Serial.println();
     
      break;

      }
        delay(200);              
    while (!digitalRead(Button));
}  }
