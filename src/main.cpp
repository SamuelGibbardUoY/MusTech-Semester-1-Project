#include "mbed.h"
#include <string>
#include <vector>

#include "TextLCD.h"
#include "Button.h"
#include "game.h"
#include "messaging.h"

using std::string;
using std::vector;

TextLCD lcd(D5, D6, D7, D8, D9, D10, TextLCD::LCD16x2);

Semaphore semaphore_1(0);
Semaphore semaphore_2(0);
Semaphore semaphore_3(0);

Button left(D2, &semaphore_1);
Button right(D3, &semaphore_2);
Button select(D4, &semaphore_3);

Thread b1_thread;
Thread b2_thread;
Thread b3_thread;

Mutex mutex;

vector<Scene> scene_list;
int current_scene_number = 0;
Scene current_scene;

vector<string> options_text; // options to be displayed
int choice_index = 0; // index of current displayed option

void update_options_text() {
/*
Clear the options to be displayed and replace with the options for the current scene
*/
    options_text.clear();

    for (Choice i : current_scene.options) {
        options_text.push_back(i.text);
    }
}

void LCDPrint(int line, const char *text) {
    lcd.locate(0, line);
    lcd.printf("                ");
    lcd.locate(0, line);
    lcd.printf("%s", text);
}

void trigger_sounds() {
/*
Trigger samples, music and narration for the current scene
*/ 
    if (current_scene.music_id == -2) {
        stopMusic();
    }
    else if (current_scene.music_id != -1) { // if we want to change the music
        stopMusic();
        thread_sleep_for(1000); // wait for fadeout
        playMusic(current_scene.music_id);
    }

    playSample(current_scene.sample.id, current_scene.sample.volume, current_scene.sample.pan);
    thread_sleep_for(3000);
    playNarration(current_scene.narration_id);
}

void scroll_left() {
    while (true) {
        semaphore_1.acquire();

        mutex.lock();

        if (choice_index > 0) { // if we're not at the start of the list
            playSynth(1); // scroll sound (id = 1)
            choice_index--;

            LCDPrint(1, options_text[choice_index].c_str());
            playNarration(current_scene.options[choice_index].narration_id);
        }

        mutex.unlock();
    }
}

void scroll_right() {
    while (true) {
        semaphore_2.acquire();

        mutex.lock();

        if ((choice_index + 1) < options_text.size()) { // if we're not at the end of the list
            playSynth(1); // scroll sound (id = 1)
            choice_index++;

            LCDPrint(1, options_text[choice_index].c_str());
            playNarration(current_scene.options[choice_index].narration_id);
        }

        mutex.unlock();
    }
}

void select_option() {
    while (true) {
        semaphore_3.acquire();

        mutex.lock();

        playSynth(2); // select sound (id = 2)

        // move to the next scene
        current_scene_number = current_scene.options[choice_index].go_to;
        current_scene = scene_list[current_scene_number];
        update_options_text();
        choice_index = 0;

        LCDPrint(0, current_scene.text.c_str());
        LCDPrint(1, options_text[choice_index].c_str());
        trigger_sounds();

        mutex.unlock();
    }
}

int main() {
    mutex.lock();

    playMusic(0); // startup sound (id = 0)
    lcd.cls();
    LCDPrint(0, "PATHWAYS");
    thread_sleep_for(5000);

    scene_list = get_scenes();
    current_scene = scene_list[current_scene_number];

    update_options_text();

    lcd.cls();
    LCDPrint(0, current_scene.text.c_str());
    LCDPrint(1, options_text[choice_index].c_str());
    trigger_sounds();

    b1_thread.start(scroll_left);
    b2_thread.start(scroll_right);
    b3_thread.start(select_option);

    mutex.unlock();

    while (true);
}