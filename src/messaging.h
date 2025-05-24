#pragma once
#include "mbed.h"

inline uint8_t concat(uint8_t arr[8]) {
    // concatenate an array of bits into an 8-bit number
    uint8_t result = 0;

    for (int i = 0; i < 8; i++) {
        result <<= 1;
        result |= (arr[i] & 1);
    }
    return result;
}

inline void sendMessage(uint8_t status, uint8_t data) {
    printf("%c", status);
    fflush(stdout);
    printf("%c", data);
    fflush(stdout);
}

inline void playSynth(uint8_t id, int volume, int pan) {
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

inline void playSample(uint8_t id, int volume, int pan) {
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

inline void playNarration(uint8_t id) {
    sendMessage(0b01000000, id);
}

inline void playMusic(uint8_t id) {
    sendMessage(0b01100000, id);
}

inline void stopMusic() {
    sendMessage(0b10000000, 0b00000000);
}