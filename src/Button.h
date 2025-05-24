#pragma once
#include "mbed.h"

class Button
{
    InterruptIn _button;
    Semaphore * _semaphore;
    chrono::milliseconds _debounce_time;
    Kernel::Clock::time_point _last_press;

    void on_fall() {
        auto now = Kernel::Clock::now();
        if (now - _last_press >= _debounce_time) {
            _last_press = now;
            _semaphore->release();
        }
    }

    public:

    Button(PinName pin, Semaphore * semaphore, chrono::milliseconds debounce_time = 50ms)
        : _button(pin), _semaphore(semaphore), _debounce_time(debounce_time), _last_press(0)
    {
        _button.fall(callback(this, &Button::on_fall));
        _button.mode(PullUp);
    }
};