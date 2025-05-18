#include "mbed.h"

BufferedSerial pc(USBTX, USBRX, 9600);

int main()
{
    pc.set_format(8, BufferedSerial::None, 1);

    while (true)
    {
        int byte_to_send = 53;
        pc.write(&byte_to_send, 1);

        ThisThread::sleep_for(1s);
    }
}