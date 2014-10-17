#include <allegro.h>

// Prosty przyklad kodu w w allegro zaczalem eksperymentowac z myszka obsluga okna i
// innymi.Okolo 40% silnika na ktorym bedzie mozna postawic scrabble(przesuwanie plytki) Jak bedziecie konfigurowac allegro w swoim srodowisku mozecie uzyc
// zeby sprawidzic czy dziala. (Allegro wersja 4.4)




volatile int Close = false;



      void close_button_handler()
      {
	 Close = true;
      }


int main(){
  
bool clicked = false;


const int scrx = 400;
const int scry = 400;


allegro_init();

set_close_button_callback(close_button_handler);

install_keyboard();
install_timer();
install_mouse();

LOCK_FUNCTION(close_button_handler);

set_gfx_mode( GFX_AUTODETECT_WINDOWED, scrx, scry, 0, 0);



BITMAP * obrazek1 = NULL;
BITMAP * buffer = NULL;
BITMAP * tile = NULL;

tile = create_bitmap( 20, 20 );
obrazek1 = create_bitmap( 200, 200 );
buffer = create_bitmap(400,400);


clear_to_color( obrazek1, makecol( 0, 0, 0 ) );
clear_to_color( buffer, makecol( 255, 255, 255 ) ) ;
clear_to_color( tile, makecol( 127, 127, 127 ) );
textout_centre_ex(tile, font, "A", 10, 10, makecol(255,255,255), -1);

show_mouse(buffer);

int tile_x=0;
int tile_y=0;
bool hold=false;
while( !Close){

if(mouse_b){
if(!hold){
hold=true;
clicked=!clicked;
}
}

if(!mouse_b){
if(hold)hold=false;
	if(!clicked){
 tile_x = mouse_x-10;
 tile_y = mouse_y-10;
 
}

}

blit( obrazek1, buffer, 0, 0, 100, 100, obrazek1->w, obrazek1->h );
textout_centre_ex(buffer, font, "Hello, world!", scrx/2, scry/2, makecol(255,0,0), -1);
blit( tile, buffer, 0, 0, tile_x, tile_y, tile->w, tile->h );
blit( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );

rest(20);
clear_to_color( buffer, makecol( 255, 255, 255 ) ) ;

}

destroy_bitmap( tile );
destroy_bitmap( obrazek1 );
destroy_bitmap( buffer );
allegro_exit();

return 0;

}
