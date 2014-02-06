#include <VirtualWire.h>

const int receive_pin = 11;
const int light_pin = 3;
char message[4]; 

void setup()
{
    delay(1000);
    
    vw_set_rx_pin(receive_pin);
    vw_setup(4800);
    vw_rx_start();

    pinMode(light_pin, OUTPUT);
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) 
    {
        int i;
        
        for (i = 0; i < buflen; i++) {            
          message[i] = char(buf[i]);
        }
        
        // Null terminate the char array
        // This needs to be done otherwise problems will occur
        // when the incoming messages has less digits than the
        // one before. 
        message[buflen] = '\0';
        
        int data = atoi(message);
        analogWrite(3, data); // PWM

    }
}
