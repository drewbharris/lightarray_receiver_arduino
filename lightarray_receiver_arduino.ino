#include <VirtualWire.h>

void setup()
{
    vw_setup(4800);
    vw_rx_start();
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen))
    {
      int i;
      for (i = 0; i < buflen; i++)
      {
        // analogWrite buf[i] here.. but write what?
      }
    }
}