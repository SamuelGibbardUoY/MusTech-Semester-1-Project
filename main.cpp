#include <LiquidCrystal.h>

// Define LCD pins connected to the NUCLEO board
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Define button pins
const int powerButton = 6;  // Power button
const int scrollButton = 7; // Scroll button
const int resetButton = 8;  // Reset button

// State tracking
enum DisplayState { PATHWAYS, GAME_OVER };
DisplayState currentState = PATHWAYS;

void setup() {
    lcd.begin(16, 2); // LCD (16x2)
    
    // Configure buttons as inputs
    pinMode(powerButton, INPUT);
    pinMode(scrollButton, INPUT);
    pinMode(resetButton, INPUT);

    // Ensure "PATHWAYS" appears on startup
    lcd.clear();
    lcd.print("PATHWAYS");
}

void loop() {
    // Read button states
    int powerState = digitalRead(powerButton);
    int scrollState = digitalRead(scrollButton);
    int resetState = digitalRead(resetButton);

    // Power button ensures "PATHWAYS" is displayed
    if (powerState == HIGH) {
        lcd.clear();
        lcd.print("PATHWAYS");
        currentState = PATHWAYS;
    }

    // Scroll button switches to "GAME OVER"
    if (scrollState == HIGH && currentState == PATHWAYS) {
        lcd.clear();
        lcd.print("GAME OVER");
        currentState = GAME_OVER;
    }

    // Reset button restores "PATHWAYS"
    if (resetState == HIGH) {
        lcd.clear();
        lcd.print("PATHWAYS");
        currentState = PATHWAYS;
    }

    delay(200); // Small debounce delay to prevent accidental multiple presses
}

