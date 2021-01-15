## This is a draft
##

#include "qrcode.h"

void main(){
  QRCode qrcode;
  uint8_t qrcodeData[qrcode_getBufferSize(3)];
  qrcode_initText(&qrcode, qrcodeData, 3, ECC_MEDIUM, "HELLO WORLD");

  // Draw qr code
  display.clearDisplay();
  const uint8_t multiply = 2;
  const uint8_t margin = 2;
  for (uint8_t y = 0; y < qrcode.size; y++)
  {
    for (uint8_t x = 0; x < qrcode.size; x++)
    {
      if (qrcode_getModule(&qrcode, x, y))
      {
        // Calculate current screen postion
        uint8_t screenX;
        uint8_t screenY;
        screenX = (x == 0) ? margin : ((x * multiply) - 1) + margin;
        screenY = (y == 0) ? margin : ((y * multiply) - 1) + margin;

        // Draw two pixels box instead of pixel
        display.fillRect(screenX, screenY, multiply, multiply, SSD1306_WHITE);
      }
    }
  }
  display.display();
}
