#include <allegro.h>
#include <iostream>
#include <cmath>
#include "tile.cpp"
#include "stuff.cpp"

// Wersja kodu na normalne systemy - tj. Linux, Solaris, BEos

volatile int Close = false;

      void close_button_handler()
      {
	 Close = true;
      }

int main(){
	
	
bool clicked = true;
bool out = true;

Databox boolz;
boolz.initialize();
Board test_board;
Tile test_tiles [7];
int marked = 7;

test_board.initialize();

test_tiles[0].create("Ś",1,40,450);
test_tiles[1].create("Ż",1,60,450);
test_tiles[2].create("Ę",1,80,450);
test_tiles[3].create("Ą",1,100,450);
test_tiles[4].create("a",1,120,450);
test_tiles[5].create("t",1,140,450);
test_tiles[6].create("k",1,160,450);

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


BITMAP * worek = NULL;
BITMAP * buffer = NULL;
BITMAP * nsttura = NULL;
BITMAP * tsnlg = NULL;

for(int i=0; i <7;i++)test_tiles[i].tile = test_tiles[i].bmp();

buffer = create_bitmap(640,480);
worek = create_bitmap(120,120);
nsttura = create_bitmap(120,40);
tsnlg = create_bitmap(300,20);


test_board.token = test_board.board_bmp();

clear_to_color( buffer, makecol( 255, 255, 255 ) ) ;
clear_to_color( worek, makecol( 0, 0, 0 ) );
clear_to_color( nsttura, makecol( 0, 0, 0 ) );
clear_to_color( tsnlg, makecol( 0, 0, 0 ) );


textout_centre_ex(worek, font, "Worek do liter", (worek->w)/2, (worek->h)/2, makecol(255,0,0), -1);
textout_centre_ex(nsttura, font, "Nast. tura", (nsttura->w)/2, (nsttura->h)/2, makecol(255,0,0), -1);
textout_centre_ex(tsnlg, font, "Tu sloty na literki gracza", (tsnlg->w)/2, (tsnlg->h)/2, makecol(255,0,0), -1);


bool hold=false;
while( !Close){

if(mouse_b){
if(!hold){
	for(int i=0; i <7;i++){
	if(mouse_tile_collision(test_tiles[i])){
hold=true;
clicked=!clicked;
marked = i;
break;
}
}
if(mouse_x>=480&&mouse_x<=600&&mouse_y>=430&&mouse_y<=470){
			std::cout<<"Następna tura."<<std::endl;
			boolz.uneven = false;
			for(int i=0; i <7;i++){
				if (test_tiles[i].locked){
					boolz.locked_tiles++;
					std::cout<<test_tiles[i].letter<<' '<<test_tiles[i].pos_x<<' '<<test_tiles[i].pos_y<<std::endl;

				if (boolz.last_x<0&&boolz.last_y<0){
					boolz.last_x=test_tiles[i].pos_x;
					boolz.last_y=test_tiles[i].pos_y;

				}
				else{
				
				if(boolz.last_x!=test_tiles[i].pos_x&&boolz.last_y!=test_tiles[i].pos_y){
					boolz.uneven=true;
					
				}
			}
			}
			}
			for(int i=0; i <7;i++){
				if (test_tiles[i].locked){
					for(int j=0; j <7;j++){
						if(j!=i){
							if(test_tiles[j].locked){
								if(abs(test_tiles[j].pos_x-test_tiles[i].pos_x)>(boolz.locked_tiles-1)*20)boolz.lonely_tile=true;
								if(abs(test_tiles[j].pos_y-test_tiles[i].pos_y)>(boolz.locked_tiles-1)*20)boolz.lonely_tile=true;
							}
							
						}
					}
					
				}
			}
			
			for(int i=0; i <7;i++){
				if(!test_board.is_good_for_print(test_tiles[i])){
					boolz.overwrite = true;
					break;
				}
			}
			if(!boolz.uneven&&!boolz.lonely_tile&&!boolz.overwrite){


			for(int i=0; i <7;i++){
				
				test_board.print_tile(test_tiles[i]);
				
			}
			}
			else{
				std::cout<<"Dude your tile layout is incorrect"<<std::endl;
				std::cout<<"Lonely tile: "<<boolz.lonely_tile<<std::endl;
				std::cout<<"Uneven: "<<boolz.uneven<<std::endl;
				std::cout<<"Overwriting existing tile: "<<boolz.overwrite<<std::endl;
			}
			boolz.locked_tiles=0;
			boolz.lonely_tile=false;
			boolz.last_x=-1;
			boolz.last_y=-1;
			boolz.overwrite=false;
			while(mouse_b){}
		}
}
else{
	if(!clicked){
		if(out){
			test_tiles[marked].pos_x = mouse_x-10;
			test_tiles[marked].pos_y = mouse_y-10;
			
		}
		}
	if (clicked&&marked<7){
		
		
		
		// wstawianie w sloty tych dostępnych do tworzenia słów
		if(mouse_x>=40&&mouse_x<=340&&mouse_y>=450&&mouse_y<=470){
			test_tiles[marked].pos_x = mouse_x-(mouse_x%20);
			test_tiles[marked].pos_y = 450;
			out = false;
			
		}
		
		if(mouse_x>=40&&mouse_x<=340&&mouse_y>=40&&mouse_y<=340){
			test_tiles[marked].pos_x = mouse_x-(mouse_x%20);
			test_tiles[marked].pos_y = mouse_y-(mouse_y%20);
			out = false;
			test_tiles[marked].lock();
		}
		
		if(out){
			test_tiles[marked].pos_x = mouse_x-10;
			test_tiles[marked].pos_y = mouse_y-10;
			test_tiles[marked].unlock();
		}
		
		
		out = true;
	}

	
}
std::cout<<"CLICKED:"<<clicked<<std::endl;
std::cout<<"HOLD:"<<hold<<std::endl;


}


if(!mouse_b){
if(hold)hold=false;
	if(!clicked&&marked<7){
 test_tiles[marked].pos_x = mouse_x-10;
 test_tiles[marked].pos_y = mouse_y-10;
 test_tiles[marked].unlock();
}


}

blit( test_board.token, buffer, 0, 0, 40, 40, test_board.token->w, test_board.token->h );
blit( worek, buffer, 0, 0, 480, 40, worek->w, worek->h );
blit( nsttura, buffer, 0, 0, 480, 430, nsttura->w, nsttura->h );
blit( tsnlg, buffer, 0, 0, 40, 450, tsnlg->w, tsnlg->h );
for(int i=0; i <7;i++)blit( test_tiles[i].tile, buffer, 0, 0, test_tiles[i].pos_x, test_tiles[i].pos_y, 20, 20 );
show_mouse(buffer);
blit( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );

rest(20);
clear_to_color( buffer, makecol( 255, 255, 255 ) ) ;

}



destroy_bitmap( buffer );
destroy_bitmap( worek );
destroy_bitmap( nsttura );
destroy_bitmap( tsnlg );

test_board.print_board();

allegro_exit();

return 0;

}
