#include <allegro.h>

// Prosty przyklad kodu w w allegro pokazujacy na 2 sekundy okno z czarnym kwadratem
// na bialym tle. Jak bedziecie konfigurowac allegro w swoim srodowisku mozecie uzyc
// zeby sprawidzic czy dziala. (Allegro wersja 4.4)

int main(){


const int scrx = 400;
const int scry = 400;


allegro_init();
install_timer();

set_gfx_mode( GFX_AUTODETECT_WINDOWED, scrx, scry, 0, 0);

BITMAP * obrazek1 = NULL;
BITMAP * buffer = NULL;


obrazek1 = create_bitmap( 200, 200 );
buffer = create_bitmap(400,400);

clear_to_color( obrazek1, makecol( 0, 0, 0 ) );
clear_to_color( buffer, makecol( 255, 255, 255 ) );
blit( obrazek1, buffer, 0, 0, 100, 100, obrazek1->w, obrazek1->h );
blit( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );

rest(2000);

destroy_bitmap( obrazek1 );
destroy_bitmap( buffer );
allegro_exit();
return 0;

}
