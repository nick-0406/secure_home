#include <IRremote.hpp>

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define Ir_pin 2
#define here 3
#define touch 10
#define green 5
#define red 6
#define buser 7
#define button 8
#define set_lcd 9
int pass[4]={0,0,0,0},mot[4]={1,5,7,3},count,i;

void setup() {
  // put your setup code here, to run once:
  pinMode(here,INPUT);
  pinMode(touch,INPUT);
  pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(buser,OUTPUT);
  pinMode(button,INPUT);
  pinMode(set_lcd,OUTPUT);
  IrReceiver.begin(Ir_pin);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool good=false;
  count=0;
  delay(4000);/*
    while(digitalRead(button)==0)
      digitalWrite(buser,HIGH);
    digitalWrite(buser,LOW);*/
    digitalWrite(set_lcd,HIGH);
  if(set_lcd){
    lcd.init();
    lcd.backlight();
    while(digitalRead(here)==1){
      lcd.setCursor(0,0);
      lcd.print("presentez-vous"); 
      lcd.setCursor(0,1);
      lcd.print("devant la camera");
    }
    if(digitalRead(here)==0){
      while(good==false && count<3){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("saisir le code");
        good=true;
        i=0;
        while(i<4){
            lcd.setCursor(i,1);
          if(IrReceiver.decode()){                                    
            int code = IrReceiver.decodedIRData.command;              
            switch (code){
              case 22 : code=0; break;
              case 12 : code=1; break;
              case 24 : code=2; break;
              case 94 : code=3; break;
              case 8 : code=4; break;
              case 28 : code=5; break;                             
              case 90 :code=6; break;
              case 66 :code=7; break;
              case 82 :code=8; break;
              case 74 :code=9; break;
            }
            lcd.print(code);
            mot[i]=code;
            i++;
            IrReceiver.resume();                                      
            delay(500);
          }
        }
        for (int i=0;i<4;++i){
          if(mot[i]!=pass[i])
            good=false;
        }
        if (!good){
          count++;
          lcd.clear();
          lcd.setCursor(3,0);
          lcd.print("Erreur !");
          lcd.setCursor(7,1);
          lcd.print(count);
          delay(2000);
        }  
      }
      if (good){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("BIENVENU !!");
        digitalWrite(buser,HIGH);
        digitalWrite(green,HIGH);
        delay(600);
        digitalWrite(buser,LOW);
        delay(3000);
        digitalWrite(green,LOW);
        lcd.clear();
      }
      else{
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Erreur d'authentificaion");
        lcd.setCursor(3,1);
        lcd.print("tificaion");
        digitalWrite(buser,HIGH);
        digitalWrite(red,HIGH);
        delay(1500);
        digitalWrite(buser,LOW);
        delay(3000);
        digitalWrite(red,LOW);
        lcd.clear();
      }
    }
    digitalWrite(set_lcd,LOW);
  }

}
