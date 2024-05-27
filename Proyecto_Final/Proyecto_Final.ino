/*
   Fundacion Kinal
   Centro educativo tecnico laboral kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Proyecto final
   Dev: Jefferson Yahir Gonzalez Gonzalez
   Fecha: 23 de Mayo
*/
//librerias
#include <Servo.h>
#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

//directivas de preprocesador
#define filas_teclado 4
#define columnas_teclado 4
#define f1_teclado 9
#define f2_teclado 8
#define f3_teclado 7
#define f4_teclado 6
#define c1_teclado 5
#define c2_teclado 4
#define c3_teclado 3
#define c4_teclado 2
#define pin_servo 10
#define led_1 A3
#define led_2 A2
#define led_3 A1
#define led_4 A0
#define A 18
#define B 19
#define C 11
#define D 12

//directivas de preprocesador para la LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

//simplificando instrucciones con directivas de preprocesador
#define ON(pin) digitalWrite(pin, HIGH)
#define OFF(pin) digitalWrite(pin, LOW)

//teclado matricial
char keys[filas_teclado][columnas_teclado] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pines_filas[filas_teclado] = {f1_teclado, f2_teclado, f3_teclado, f4_teclado};
byte pines_columnas[columnas_teclado] = {c1_teclado, c2_teclado, c3_teclado, c4_teclado};


//teclado matricial
Keypad teclado = Keypad(makeKeymap(keys), pines_filas, pines_columnas, filas_teclado, columnas_teclado);

//servomotor
Servo servo;

//autofantastico
void autofantastico() {
  ON(led_1); delay(500); OFF(led_1);
   ON(led_2); delay(500); OFF(led_2);
  ON(led_3); delay(500); OFF(led_3);
  ON(led_4); delay(500); OFF(led_4);
    ON(led_3); delay(500); OFF(led_3);
     ON(led_2); delay(500); OFF(led_2);
  ON(led_1); ON(led_2); ON(led_3); ON(led_4); delay(500);
      OFF(led_1); OFF(led_2); OFF(led_3); OFF(led_4); delay(500);
}
//display
void contador() {
  
  OFF(A);
  OFF(B);
  ON(C);
  ON(D);
  delay(1000);
  
  OFF(A);
  OFF(B);
  ON(C);
  OFF(D);
  delay(1000);


}
void setup() {
  
  Serial.begin(9600);
  servo.attach(pin_servo);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Jefferson");
  lcd.setCursor(0, 1);
  lcd.print("Proyecto Final");
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
}
void loop() {
  char tecla = teclado.getKey(); 
  if (tecla == '1') { //contador 0-99
    for (int x = 0; x <= 99; x++) {
      Serial.println(x); 
      delay(100); 
    }
  }
  if (tecla == '2') { //contador 99-0
    for (int y = 99; y >= 0; y--) {
      Serial.println(y); 
      delay(100); 
    }
  }
  if (tecla == '3') { //suto fantastico
    for (int i = 0; i < 5; i++) { 
      autofantastico();
    }
  }
  if (tecla == '4') { // display innovaciòn
   contador();
  }
  if (tecla == '5') { // movimiento del servomotor
    for (int pos = 0; pos <= 180; pos++) { 
      servo.write(pos);
      delay(15); 
    }
  }
}
