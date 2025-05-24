#include "mbed.h"
#include "TextLCD.h"
#include "Button.h"
#include "messaging.h"

TextLCD lcd(D1, D5, D6, D7, D8, D9, TextLCD::LCD16x2);

Semaphore semaphore_1(0);
Semaphore semaphore_2(0);
Semaphore semaphore_3(0);

Button left(D2, &semaphore_1);
Button right(D3, &semaphore_2);
Button select(D4, &semaphore_3);

Thread b1_thread;
Thread b2_thread;
Thread b3_thread;

Mutex choice_mutex;

// need to pad text with whitespaces to change whole line
const char* options_text[] = {"Play Sample     ", "Play Narration  ", "Play Music      ", "Stop Music      ", NULL};
int choice_index = 0;
const char* choice = options_text[choice_index];

void scroll_left() {
    while (true) {
        semaphore_1.acquire();

        choice_mutex.lock();
        if (choice_index > 0) {
            playSynth(1); // id = 1
            choice_index--;
        }

        choice = options_text[choice_index];
        lcd.locate(0, 1);
        lcd.printf("%s", choice);
        choice_mutex.unlock();
    }
}

void scroll_right() {
    while (true) {
        semaphore_2.acquire();

        choice_mutex.lock();
        if (options_text[choice_index + 1] != NULL) {
            playSynth(1); // id = 1
            choice_index++;
        }

        choice = options_text[choice_index];
        lcd.locate(0, 1);
        lcd.printf("%s", choice);
        choice_mutex.unlock();
    }
}

void select_option() {
    while (true) {
        semaphore_3.acquire();
        playSynth(2); // id = 2

        switch (choice_index) {
            case 0: playSample(0, 2, 1); break; // id = 0, volume = 2 (medium), pan = 1 (centre)
            case 1: playNarration(1); break; // id = 1
            case 2: playMusic(0); break; // id = 0
            case 3: stopMusic(); break;
        }
    }
}

int main() {
    lcd.cls();
    lcd.locate(0, 0);
    lcd.printf("PATHWAYS"); // startup screen
    thread_sleep_for(2000);

    b1_thread.start(scroll_left);
    b2_thread.start(scroll_right);
    b3_thread.start(select_option);

    lcd.locate(0, 0);
    lcd.printf("Scenario Name"); // top line
    lcd.locate(0, 1);
    lcd.printf("%s", choice); // bottom line

    while (true);
}