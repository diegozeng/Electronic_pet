#include <U8glib.h>

//Define V0 pin for LCD light control
#define V0 11
//define LCD data pin
U8GLIB_ST7920_128X64_4X u8g(8, 9, 10, 12, 4, 5, 6, 7, 1, 2, 3);

void draw(){
  u8g.drawDisc(9,9,9);
  u8g.drawCircle(9+9,9+9,9);
}

void setup(){
  //LCD light
  analogWrite(V0,255/3*2);
  // assign default color value
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) 
    u8g.setColorIndex(255);     // white
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT )
    u8g.setColorIndex(3);         // max intensity
  else if ( u8g.getMode() == U8G_MODE_BW )
    u8g.setColorIndex(1);         // pixel on
}

void loop(){
  //Draw on the LCD
  u8g.firstPage();//clear screen
  //draw new figure
  do{draw();}while(u8g.nextPage());
}
