#include <allegro.h>
#include <iostream>
#include "tile.cpp"

// Wersja z 18.10.2014




volatile int Close = false;



      void close_button_handler()
      {
	 Close = true;
      }
      
bool mouse_tile_collision(Tile a){
	if(mouse_x>=a.pos_x&&mouse_x<=a.pos_x+20){
		if(mouse_y>=a.pos_y&&mouse_y<=a.pos_y+20)return true;
	}
 return false;
	}

int main(){
bool clicked = true;
Tile fckng_test_tile;
fckng_test_tile.create("A",1,190,190);

const int scrx = 640;
const int scry = 480;


allegro_init();

set_close_button_callback(close_button_handler);

install_keyboard();
install_timer();
install_mouse();
LOCK_FUNCTION(close_button_handler);
set_gfx_mode( GFX_AUTODETECT_WINDOWED, scrx, scry, 0, 0);

unscare_mouse();

BITMAP * obrazek1 = NULL;
BITMAP * worek = NULL;
BITMAP * buffer = NULL;
BITMAP * tile = NULL;
BITMAP * nsttura = NULL;
BITMAP * tsnlg = NULL;


obrazek1 = create_bitmap( 400, 400 );
buffer = create_bitmap(640,480);
worek = create_bitmap(120,120);
nsttura = create_bitmap(120,40);
tsnlg = create_bitmap(400,20);

tile = fckng_test_tile.bmp();

clear_to_color( obrazek1, makecol( 0, 0, 0 ) );
clear_to_color( buffer, makecol( 255, 255, 255 ) ) ;
clear_to_color( worek, makecol( 0, 0, 0 ) );
clear_to_color( nsttura, makecol( 0, 0, 0 ) );
clear_to_color( tsnlg, makecol( 0, 0, 0 ) );

textout_centre_ex(obrazek1, font, "Plansza", (obrazek1->w)/2, (obrazek1->h)/2, makecol(255,0,0), -1);
textout_centre_ex(worek, font, "Worek do liter", (worek->w)/2, (worek->h)/2, makecol(255,0,0), -1);
textout_centre_ex(nsttura, font, "Nast. tura", (nsttura->w)/2, (nsttura->h)/2, makecol(255,0,0), -1);
textout_centre_ex(tsnlg, font, "Tu sloty na literki gracza", (tsnlg->w)/2, (tsnlg->h)/2, makecol(255,0,0), -1);

int tile_x=fckng_test_tile.pos_x;
int tile_y=fckng_test_tile.pos_y;
bool hold=false;
while( !Close){

if(mouse_b){
if(!hold){
	if(mouse_tile_collision(fckng_test_tile)){
hold=true;
clicked=!clicked;
}
}
}
if(!mouse_b){
if(hold)hold=false;
	if(!clicked){
 fckng_test_tile.pos_x = mouse_x-10;
 fckng_test_tile.pos_y = mouse_y-10;
 tile_x = mouse_x-10;
 tile_y = mouse_y-10;
}

}

blit( obrazek1, buffer, 0, 0, 40, 40, obrazek1->w, obrazek1->h );
blit( worek, buffer, 0, 0, 480, 40, worek->w, worek->h );
blit( nsttura, buffer, 0, 0, 480, 430, nsttura->w, nsttura->h );
blit( tsnlg, buffer, 0, 0, 40, 450, tsnlg->w, tsnlg->h );
blit( tile, buffer, 0, 0, tile_x, tile_y, tile->w, tile->h );
show_mouse(buffer);
blit( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );

rest(20);
clear_to_color( buffer, makecol( 255, 255, 255 ) ) ;

}

destroy_bitmap( tile );
destroy_bitmap( obrazek1 );
destroy_bitmap( buffer );
destroy_bitmap( worek );
destroy_bitmap( nsttura );
destroy_bitmap( tsnlg );

allegro_exit();

return 0;

}
