#include <Bounce.h>
#include <usb_dev.h>
#include <usb_keyboard.h>
#include <core_pins.h>

int main() {
  Bounce rotaryA = Bounce(23, 5);
  Bounce rotaryB = Bounce(22, 5);
  Bounce pushButton = Bounce(21, 5);
  Bounce button1 = Bounce(20, 5);
  Bounce button2 = Bounce(11, 5);
  Bounce button3 = Bounce(3, 5);
  Bounce button4 = Bounce(0, 5);

  pinMode(23, INPUT_PULLUP); // A
  pinMode(22, INPUT_PULLUP); // B
  pinMode(21, INPUT_PULLUP); // Z
  pinMode(20, INPUT_PULLUP); // 1
  pinMode(11, INPUT_PULLUP); // 2
  pinMode(3, INPUT_PULLUP); // 3
  pinMode(0, INPUT_PULLUP); // 4

  for(;;) {
    rotaryA.update();
    rotaryB.update();
    pushButton.update();
    button1.update();
    button2.update();
    button3.update();
    button4.update();
    
    if (rotaryA.fallingEdge()) {
      if (rotaryB.read()) {
        Keyboard.press(KEY_MEDIA_VOLUME_INC);
        Keyboard.release(KEY_MEDIA_VOLUME_INC);
      } else {
        Keyboard.press(KEY_MEDIA_VOLUME_DEC);
        Keyboard.release(KEY_MEDIA_VOLUME_DEC);      
      }
    }

    if (pushButton.fallingEdge()) {
      Keyboard.press(KEY_LEFT_GUI);
      delay(100);
      Keyboard.write('h');
      Keyboard.release(KEY_LEFT_GUI);
    }
    
    if (button1.fallingEdge()) {
      Keyboard.press(KEY_MEDIA_PLAY_PAUSE);
      Keyboard.release(KEY_MEDIA_PLAY_PAUSE);
    }

    if (button2.fallingEdge()) {
      Keyboard.press(KEY_LEFT_GUI);
      delay(100);
      Keyboard.write('h');
      Keyboard.release(KEY_LEFT_GUI);    
      delay(100);
      Keyboard.press(KEY_LEFT_GUI);
      delay(100);
      Keyboard.write(' ');
      Keyboard.release(KEY_LEFT_GUI);
      delay(100);
      Keyboard.write('s');
      delay(100);
      Keyboard.write('p');
      delay(100);
      Keyboard.write('o');
      delay(100);
      Keyboard.write('t');
      delay(100);
      Keyboard.write('i');
      delay(100);
      Keyboard.write('f');    
      delay(100);
      Keyboard.println('y');
    }
    
    if (button3.fallingEdge()) {
      Keyboard.press(KEY_MEDIA_PREV_TRACK);
      Keyboard.release(KEY_MEDIA_PREV_TRACK);
    }

    if (button4.fallingEdge()) {
      Keyboard.press(KEY_MEDIA_NEXT_TRACK);
      Keyboard.release(KEY_MEDIA_NEXT_TRACK);
    }
  }
}
