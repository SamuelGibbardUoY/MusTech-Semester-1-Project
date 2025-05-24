#include "mbed.h"
#include "TextLCD.h"
#include "Button.h"
#include "messaging.h"

TextLCD lcd(D1, D5, D6, D7, D8, D9, TextLCD::LCD16x2);

Semaphore b1_sem(0);
Semaphore b2_sem(0);
Semaphore b3_sem(0);

Button b1(D2, &b1_sem);
Button b2(D3, &b2_sem);
Button b3(D4, &b3_sem);

Thread b1_thread;
Thread b2_thread;
Thread b3_thread;

void printToLine(const char * text, int row) {
    if (row == 0) lcd.locate(0, 0); else lcd.locate(0, 1);
    lcd.printf("%s", text);
}

void b1_func() {
    while (true) {
        b1_sem.acquire();
        playSample(0, 2, 1); // id = 0, volume = 2 (medium), pan = 1 (centre)
    }
}

void b2_func() {
    while (true) {
        b2_sem.acquire();
        playMusic(0); // id = 0
    }
}

void b3_func() {
    while (true) {
        b3_sem.acquire();
        stopMusic();
    }
}

int main() {
    b1_thread.start(b1_func);
    b2_thread.start(b2_func);
    b3_thread.start(b3_func);

    lcd.cls();
    printToLine("PATHWAYS", 0);
    printToLine("Hello, World!", 1);

    while (true);
}