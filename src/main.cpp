#include "mbed.h"
#include "TextLCD.h"
#include "Button.h"
#include "messaging.h"
#include "json_parsing.h"
#include <string>

using std::string;

TextLCD lcd(D4, D5, D6, D7, D8, D9, TextLCD::LCD16x2);

Semaphore semaphore_1(0);
Semaphore semaphore_2(0);
Semaphore semaphore_3(0);

Button left(D0, &semaphore_1);
Button right(D1, &semaphore_2);
Button select(D2, &semaphore_3);

Thread b1_thread;
Thread b2_thread;
Thread b3_thread;

Mutex choice_mutex;

// need to pad text with whitespaces to change whole line
//const char* options_text[] = {"Play Sample     ", "Play Narration  ", "Play Music      ", "Stop Music      ", NULL};
int choice_index = 0;
std::string choice = options_text[choice_index];

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
        lcd.printf("%s", choice.c_str());
        choice_mutex.unlock();
    }
}

void scroll_right() {
    while (true) {
        semaphore_2.acquire();

        choice_mutex.lock();
        if (options_text[choice_index + 1] != string("")) {
            playSynth(1); // id = 1
            choice_index++;
        }

        choice = options_text[choice_index];
        lcd.locate(0, 1);
        lcd.printf("%s", choice.c_str());
        choice_mutex.unlock();
    }
}

void select_option() {
    while (true) {
        semaphore_3.acquire();
        playSynth(2); // id = 2

        switch (choice_index) {
            case 0: playSample(0, 2, 1); break; // id = 0, volume = 2 (medium), pan = 1 (centre)
            case 1: playNarration(0); break; // id = 0
            case 2: playMusic(0); break; // id = 0
            case 3: stopMusic(); break;
        }
    }
}
// I sharted my pants

int main() {
    S_Scenes scenes = generate_fake_parse();
    scenes.update_options_text(0);

    playMusic(0); // id = 0
    lcd.cls();
    lcd.locate(0, 0);
    lcd.printf("PATHWAYS");
    thread_sleep_for(5000);

    b1_thread.start(scroll_left);
    b2_thread.start(scroll_right);
    b3_thread.start(select_option);

    lcd.locate(0, 0);
    lcd.printf("Scenario Name"); // top line
    lcd.locate(0, 1);
    lcd.printf("%s", choice.c_str()); // bottom line

    while (true);
}