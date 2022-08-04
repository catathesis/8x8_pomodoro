#include <LedControl.h>
LedControl lc = LedControl(12, 11, 10, 1);
// Pin 12 is connected to the DATA IN-pin
// Pin 11 is connected to the CLK-pin
// Pin 10 is connected to the LOAD(/CS)-pin

void setLed(int addr, int row, int col, boolean state);

// define all on and all off for blinking
byte all[8] = {B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111};
byte off[8] = {B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000};

// eight images to show as timer progresses
byte one[8] = {B00000000, B00000000, B00000000, B00011000, B00011000, B00000000, B00000000, B00000000};
byte two[8] = {B00000000, B00000000, B00100100, B00011000, B00011000, B00100100, B00000000, B00000000};
byte three[8] = {B00000000, B00000000, B00111100, B00111100, B00111100, B00111100, B00000000, B00000000};
byte four[8] = {B00000000, B01000010, B00111100, B00111100, B00111100, B00111100, B01000010, B00000000};
byte five[8] = {B00000000, B01011010, B00111100, B01111110, B01111110, B00111100, B01011010, B00000000};
byte six[8] = {B00000000, B01111110, B01111110, B01111110, B01111110, B01111110, B01111110, B00000000};
byte seven[8] = {B10000001, B01111110, B01111110, B01111110, B01111110, B01111110, B01111110, B10000001};
byte eight[8] = {B10011001, B01111110, B01111110, B11111111, B11111111, B01111110, B01111110, B10011001};

int passFlag = 0; // setting flag so loop runs once

void setup() {
  //wake up the MAX72XX from power-saving mode
  lc.shutdown(0, false);
  lc.setIntensity(0, 15);  // 2nd number is brightness. (0 to 15)  using 15 with a film over the 8x8
}

void loop() {
  // put your main code here, to run repeatedly:
  if (passFlag == 0) { // prevents looping
    Animation();
  }
  // ensures all of the LEDs are off after loop to preserve battery
  lc.setRow(0, 0, off[0]);
  lc.setRow(0, 1, off[1]);
  lc.setRow(0, 2, off[2]);
  lc.setRow(0, 3, off[3]);
  lc.setRow(0, 4, off[4]);
  lc.setRow(0, 5, off[5]);
  lc.setRow(0, 6, off[6]);
  lc.setRow(0, 7, off[7]);
}

void Animation() {
  unsigned long delLong = 187500; // longer delay for lighting it up  187500 for 25 minutes split 8 ways
  unsigned long delShort = 37500; // shorter delay for removing LEDs  37500 for 5 minutes split 8 ways
  lc.setRow(0, 0, one[0]);
  lc.setRow(0, 1, one[1]);
  lc.setRow(0, 2, one[2]);
  lc.setRow(0, 3, one[3]);
  lc.setRow(0, 4, one[4]);
  lc.setRow(0, 5, one[5]);
  lc.setRow(0, 6, one[6]);
  lc.setRow(0, 7, one[7]);
  delay(delLong);
  lc.setRow(0, 0, two[0]);
  lc.setRow(0, 1, two[1]);
  lc.setRow(0, 2, two[2]);
  lc.setRow(0, 3, two[3]);
  lc.setRow(0, 4, two[4]);
  lc.setRow(0, 5, two[5]);
  lc.setRow(0, 6, two[6]);
  lc.setRow(0, 7, two[7]);
  delay(delLong);
  lc.setRow(0, 0, three[0]);
  lc.setRow(0, 1, three[1]);
  lc.setRow(0, 2, three[2]);
  lc.setRow(0, 3, three[3]);
  lc.setRow(0, 4, three[4]);
  lc.setRow(0, 5, three[5]);
  lc.setRow(0, 6, three[6]);
  lc.setRow(0, 7, three[7]);
  delay(delLong);
  lc.setRow(0, 0, four[0]);
  lc.setRow(0, 1, four[1]);
  lc.setRow(0, 2, four[2]);
  lc.setRow(0, 3, four[3]);
  lc.setRow(0, 4, four[4]);
  lc.setRow(0, 5, four[5]);
  lc.setRow(0, 6, four[6]);
  lc.setRow(0, 7, four[7]);
  delay(delLong);
  lc.setRow(0, 0, five[0]);
  lc.setRow(0, 1, five[1]);
  lc.setRow(0, 2, five[2]);
  lc.setRow(0, 3, five[3]);
  lc.setRow(0, 4, five[4]);
  lc.setRow(0, 5, five[5]);
  lc.setRow(0, 6, five[6]);
  lc.setRow(0, 7, five[7]);
  delay(delLong);
  lc.setRow(0, 0, six[0]);
  lc.setRow(0, 1, six[1]);
  lc.setRow(0, 2, six[2]);
  lc.setRow(0, 3, six[3]);
  lc.setRow(0, 4, six[4]);
  lc.setRow(0, 5, six[5]);
  lc.setRow(0, 6, six[6]);
  lc.setRow(0, 7, six[7]);
  delay(delLong);
  lc.setRow(0, 0, seven[0]);
  lc.setRow(0, 1, seven[1]);
  lc.setRow(0, 2, seven[2]);
  lc.setRow(0, 3, seven[3]);
  lc.setRow(0, 4, seven[4]);
  lc.setRow(0, 5, seven[5]);
  lc.setRow(0, 6, seven[6]);
  lc.setRow(0, 7, seven[7]);
  delay(delLong);
  lc.setRow(0, 0, eight[0]);
  lc.setRow(0, 1, eight[1]);
  lc.setRow(0, 2, eight[2]);
  lc.setRow(0, 3, eight[3]);
  lc.setRow(0, 4, eight[4]);
  lc.setRow(0, 5, eight[5]);
  lc.setRow(0, 6, eight[6]);
  lc.setRow(0, 7, eight[7]);
  delay(delLong);

  Blink(); // calls blink function when fully lit up

  lc.setRow(0, 0, eight[0]);
  lc.setRow(0, 1, eight[1]);
  lc.setRow(0, 2, eight[2]);
  lc.setRow(0, 3, eight[3]);
  lc.setRow(0, 4, eight[4]);
  lc.setRow(0, 5, eight[5]);
  lc.setRow(0, 6, eight[6]);
  lc.setRow(0, 7, eight[7]);
  delay(delShort);
  lc.setRow(0, 0, seven[0]);
  lc.setRow(0, 1, seven[1]);
  lc.setRow(0, 2, seven[2]);
  lc.setRow(0, 3, seven[3]);
  lc.setRow(0, 4, seven[4]);
  lc.setRow(0, 5, seven[5]);
  lc.setRow(0, 6, seven[6]);
  lc.setRow(0, 7, seven[7]);
  delay(delShort);
  lc.setRow(0, 0, six[0]);
  lc.setRow(0, 1, six[1]);
  lc.setRow(0, 2, six[2]);
  lc.setRow(0, 3, six[3]);
  lc.setRow(0, 4, six[4]);
  lc.setRow(0, 5, six[5]);
  lc.setRow(0, 6, six[6]);
  lc.setRow(0, 7, six[7]);
  delay(delShort);
  lc.setRow(0, 0, five[0]);
  lc.setRow(0, 1, five[1]);
  lc.setRow(0, 2, five[2]);
  lc.setRow(0, 3, five[3]);
  lc.setRow(0, 4, five[4]);
  lc.setRow(0, 5, five[5]);
  lc.setRow(0, 6, five[6]);
  lc.setRow(0, 7, five[7]);
  delay(delShort);
  lc.setRow(0, 0, four[0]);
  lc.setRow(0, 1, four[1]);
  lc.setRow(0, 2, four[2]);
  lc.setRow(0, 3, four[3]);
  lc.setRow(0, 4, four[4]);
  lc.setRow(0, 5, four[5]);
  lc.setRow(0, 6, four[6]);
  lc.setRow(0, 7, four[7]);
  delay(delShort);
  lc.setRow(0, 0, three[0]);
  lc.setRow(0, 1, three[1]);
  lc.setRow(0, 2, three[2]);
  lc.setRow(0, 3, three[3]);
  lc.setRow(0, 4, three[4]);
  lc.setRow(0, 5, three[5]);
  lc.setRow(0, 6, three[6]);
  lc.setRow(0, 7, three[7]);
  delay(delShort);
  lc.setRow(0, 0, two[0]);
  lc.setRow(0, 1, two[1]);
  lc.setRow(0, 2, two[2]);
  lc.setRow(0, 3, two[3]);
  lc.setRow(0, 4, two[4]);
  lc.setRow(0, 5, two[5]);
  lc.setRow(0, 6, two[6]);
  lc.setRow(0, 7, two[7]);
  delay(delShort);
  lc.setRow(0, 0, one[0]);
  lc.setRow(0, 1, one[1]);
  lc.setRow(0, 2, one[2]);
  lc.setRow(0, 3, one[3]);
  lc.setRow(0, 4, one[4]);
  lc.setRow(0, 5, one[5]);
  lc.setRow(0, 6, one[6]);
  lc.setRow(0, 7, one[7]);
  delay(delShort);

  Blink();  // calls blink function when cycle is complete
  passFlag++;  // increments passFlag to prevent looping;  interrupt button will restart
}

void Blink() {
  int count = 0;
  while (count < 30) {
    lc.setRow(0, 0, off[0]);
    lc.setRow(0, 1, off[1]);
    lc.setRow(0, 2, off[2]);
    lc.setRow(0, 3, off[3]);
    lc.setRow(0, 4, off[4]);
    lc.setRow(0, 5, off[5]);
    lc.setRow(0, 6, off[6]);
    lc.setRow(0, 7, off[7]);
    delay(100);
    lc.setRow(0, 0, all[0]);
    lc.setRow(0, 1, all[1]);
    lc.setRow(0, 2, all[2]);
    lc.setRow(0, 3, all[3]);
    lc.setRow(0, 4, all[4]);
    lc.setRow(0, 5, all[5]);
    lc.setRow(0, 6, all[6]);
    lc.setRow(0, 7, all[7]);
    delay(100);
    count = count + 1;
  }
}
