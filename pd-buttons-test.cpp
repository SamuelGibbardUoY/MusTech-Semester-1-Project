#include "mbed.h"
#include "TextLCD.h"

TextLCD lcd(D1, D5, D6, D7, D8, D9, TextLCD::LCD16x2);

InterruptIn b1(D2, PullUp);
InterruptIn b2(D3, PullUp);
InterruptIn b3(D4, PullUp);

Thread b1_thread;
Thread b2_thread;
Thread b3_thread;

Semaphore b1_sem(0, 1);
Semaphore b2_sem(0, 1);
Semaphore b3_sem(0, 1);

void b1_callback() { b1_sem.release(); }
void b2_callback() { b2_sem.release(); }
void b3_callback() { b3_sem.release(); }

uint8_t concat(uint8_t arr[8]) {
    // concatenate an array of bits into an 8-bit number
    uint8_t result = 0;

    for (int i = 0; i < 8; i++) {
        result <<= 1;
        result |= (arr[i] & 1);
    }
    return result;
}

void sendMessage(uint8_t status, uint8_t data) {
    printf("%c", status);
    fflush(stdout);
    printf("%c", data);
    fflush(stdout);
}

void playSynth(uint8_t id, int volume, int pan) {
    uint8_t status[8] = {0};

    switch (volume) {
        case 0: break;
        case 1: status[4] = 1; break;
        case 2: status[3] = 1; break;
        case 3: status[3] = 1; status[4] = 1; break;
    }

    switch (pan) {
        case 0: break;
        case 1: status[6] = 1; break;
        case 2: status[5] = 1; break;
        case 3: status[5] = 1; status[6] = 1;
    }

    sendMessage(concat(status), id);
}

void playSample(uint8_t id, int volume, int pan) {
    uint8_t status[8] = {0, 0, 1, 0, 0, 0, 0, 0};

    switch (volume) {
        case 0: break;
        case 1: status[4] = 1; break;
        case 2: status[3] = 1; break;
        case 3: status[3] = 1; status[4] = 1; break;
    }

    switch (pan) {
        case 0: break;
        case 1: status[6] = 1; break;
        case 2: status[5] = 1; break;
        case 3: status[5] = 1; status[6] = 1;
    }

    sendMessage(concat(status), id);
}

void playNarration(uint8_t id, int volume, int pan) {
    sendMessage(0b01000000, id);
}

void playMusic(uint8_t id) {
    sendMessage(0b01100000, id);
}

void stopMusic() {
    sendMessage(0b10000000, 0b00000000);
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
    b1.fall(b1_callback);
    b2.fall(b2_callback);
    b3.fall(b3_callback);

    b1_thread.start(b1_func);
    b2_thread.start(b2_func);
    b3_thread.start(b3_func);

    lcd.cls();
    lcd.locate(0, 0);
    lcd.printf("PATHWAYS");
    lcd.locate(0, 1);
    lcd.printf("Hello, World!");

    while (true);
}