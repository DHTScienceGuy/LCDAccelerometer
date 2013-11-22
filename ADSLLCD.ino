#include <LiquidCrystal.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int xPin = 3;		// X output of the accelerometer
const int yPin = 2;		// Y output of the accelerometer

void setup() {
  // initialize serial communications:
  Serial.begin(9600);
  // initialize the pins connected to the accelerometer
  // as inputs:
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  lcd.begin(16,2);
}

void loop() {
  // variables to read the pulse widths:
  int pulseX, pulseY;
  // variables to contain the resulting accelerations
  int accelerationX, accelerationY;
  
  // read pulse from x- and y-axes:
  pulseX = pulseIn(xPin,HIGH);  
  pulseY = pulseIn(yPin,HIGH);
  
  // convert the pulse width into acceleration
  // accelerationX and accelerationY are in milli-g's: 
  // earth's gravity is 1000 milli-g's, or 1g.
  accelerationX = ((pulseX / 10) - 500) * 8;
  accelerationY = ((pulseY / 10) - 500) * 8;

  // print the acceleration
  lcd.setCursor(0,1);
  lcd.print(accelerationX);
  // print a tab character:
  lcd.print("\t");
  lcd.setCursor(1,0);
  lcd.print(accelerationY);
  lcd.println();

  delay(100);
}
