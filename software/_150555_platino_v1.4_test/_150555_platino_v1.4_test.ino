/*
  Simple Platino test program to see if everything works as expected.

  Displays the value of rotary encoder 1. The RGB LED's color depends
  on this value. The pushbuttons influence the value too. The Buzzer
  sounds when board setup is done.
  
  Copyright (c) 2015 Elektor, www.elektor.com

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

// Platino solder jumpers for readability.
const uint8_t jp1 = 'B'; // Buzzer
const uint8_t jp3 = 'C'; // Backlight
const uint8_t jp4 = 'B'; // S1
const uint8_t jp5 = 'B'; // S2
const uint8_t jp6 = 'B'; // S3
const uint8_t jp7 = 'B'; // S4
const uint8_t jp14 = 'B'; // LED
const uint8_t jp15 = 'D'; // LCD RS
const uint8_t jp16 = 'D'; // LCD E


void show_value(int16_t val)
{
  // Print a numerical value, right justified.
  Platino.display.setCursor(0,0);
  Platino.display.print("      ");
  Platino.display.setCursor(0,0);
  if (val>=0) Platino.display.print(' ');
  if (abs(val)<10000) Platino.display.print(' ');
  if (abs(val)<1000) Platino.display.print(' ');
  if (abs(val)<100) Platino.display.print(' ');
  if (abs(val)<10) Platino.display.print(' ');
  Platino.display.print(val);
}

void setup(void)
{
  // Configure Platino.
  Platino.begin(jp1,jp3,jp4,jp5,jp6,jp7,jp14,jp15,jp16);
  // Activate the peripherals of your board.
  Platino.hasDisplay(4,20,true,true); // 4X20 LCD, show Platino splash screen.
  Platino.hasBacklight(); // Not all LCDs have a backlight.
  Platino.hasKnob(1); // Rotary encoder (with pushbutton).
  Platino.hasPushbutton(3); // Pushbutton of rotary encoder.
  Platino.hasPushbutton(4); // Pushbutton.
  Platino.hasLedRgb(); // RGB LED.
  Platino.hasBuzzer(); // Buzzer.
  Platino.backlight(true); // Backlight on.
  Platino.ledRgb(0,0,0); // RGB LED off.
  delay(2000); // Give the user time to read the splash screen.
  Platino.display.clear(); // Clear display.
  show_value(Platino.knobRead(1)); // Print the value of rotary encoder 1.
  // Make a sound to indicate that the board is ready.
  Platino.beep(1000,100);
  delay(50);
  Platino.beep(750,100);
  delay(50);
  Platino.beep(500,100);
}

void loop(void)
{
  if (Platino.knobChanged(1)==true)
  {
    // Update the display everytime the position of enocder 1 changes.
    int16_t val = Platino.knobRead(1);
    show_value(val);
    Serial.println(val);
    // Update RGB LED.
    if (val<0) Platino.ledRgb(1,1,1); // Negative values: white.
    else if (val<10) Platino.ledRgb(0,0,0); // Less than 10: off.
    else if (val<100) Platino.ledRgb(1,0,0); // Less than 100: red.
    else if (val<1000) Platino.ledRgb(0,0,1); // Less than 1000: blue.
    else Platino.ledRgb(0,1,0); // Else: green.
  }
  if (Platino.pushbuttonRead(3)==PUSHBUTTON_DOWN)
  {
    // Pressing the encoder's pushbutton resets the encoder value.
    Platino.knobWrite(1,0);
  }
  if (Platino.pushbuttonRead(4)==PUSHBUTTON_DOWN)
  {
    // Pressing the pushbutton multiplies value by 10.
    Platino.knobWrite(1,10*Platino.knobRead(1));
  }
}

