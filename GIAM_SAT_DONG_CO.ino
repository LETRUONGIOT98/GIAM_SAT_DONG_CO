int encoder = 2;
 int counter;
float rpm;

int encoder1 = 3;
int counter1;
float rpm1;

 #include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

 
void setup() {
  lcd.init();
  //lcd.begin();
  lcd.backlight();
  pinMode(encoder, INPUT);
  pinMode(encoder1, INPUT);
  digitalWrite(encoder, HIGH);
  digitalWrite(encoder1, HIGH);
  attachInterrupt(0,countpulse,RISING);

}
 
void countpulse(){
        counter++;
}

void loop() {
  static uint32_t previousMillis;
  if (millis() - previousMillis >= 1000) { //Đếm số vòng trong 1 giây
            rpm = (counter/60.0)*60.0;     //1 giây đếm được bao nhiêu vòng chia số số xung của encoder và * 60 để đổi ra RPM      
            counter = 0;
            previousMillis = millis();
  }

  lcd.setCursor(0,0);
  lcd.print("S1:          rpm");
  lcd.setCursor(4,0);
  lcd.print(rpm,0);
  
  lcd.setCursor(0,1);
  lcd.print("S2:          rpm");
  lcd.setCursor(4,1);
  lcd.print(rpm1,0);
   
  delay(10);
}
