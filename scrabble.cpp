#include <allegro.h>
#include <iostream>
#include <cmath>
#include "tile.cpp"
#include "stuff.cpp"

// powyżej importuję potrzebne biblioteki
// allegro - cały interfejs graficzny input myszki itd.
// iostream - wypisywanie w konsoli tekstowej informacji potrzebnych do debugowania i pisania programu
// w wersji ostatecznej iostream bedzie mozna prawdopodobnie wyrzucić
// cmath - potrzebowalem gdzies wartosci bezwzględnej
// tile i stuff - napisane przeze mnie klasy i funkcje

/*
DWA WAZNE NIUANSE:

1) w allegro przypisywanie bitmap moze się odbywac tylko w pętli glownej
a nie wewnątrz innej klasy - inaczej dostajesz segmentation fault i dupa.

2) Temu kodowi daleko do doskonałości - jesli modyfikujesz nie usuwaj dużych jego fragmentow ob moze to rozwalic calą
delkiatną jego konstrukcję




*/



// Wersja kodu na normalne systemy - tj. Linux, Solaris, BEos

// zmienna potrzebana do obsługi zamykania okna

volatile int Close = false;

// funkcja potrzebana do obsługi zamykania okna

      void close_button_handler()
      {
	 Close = true;
      }


//pętla główna programu

int main(){
	
// zmienne do obsługio myszki
bool clicked = true;
bool out = true;


// inicjalizacja pudełka boolow, tablicy płytek gracza i planszy do gry patrz stuff.hpp i tile.hpp
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

//Szerokość i wysokość okna gry w pixelach

const int scrx = 640;
const int scry = 480;

//uruchomienie biblioteki allegro

allegro_init();

//ustawienie funkcji obsługi zamknięcia okna

set_close_button_callback(close_button_handler);

//inicjalizacja myszy timera i klawiatury

install_keyboard();
install_timer();
install_mouse();

LOCK_FUNCTION(close_button_handler);
set_gfx_mode( GFX_AUTODETECT_WINDOWED, scrx, scry, 0, 0);

unscare_mouse();

// bitmapy innych ojektow w oknie gry

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

//  kolorowanie tych bitmap

clear_to_color( buffer, makecol( 255, 255, 255 ) ) ;
clear_to_color( worek, makecol( 0, 0, 0 ) );
clear_to_color( nsttura, makecol( 0, 0, 0 ) );
clear_to_color( tsnlg, makecol( 0, 0, 0 ) );

// Drukowanie napisow na tych bitmapach
textout_centre_ex(worek, font, "Worek do liter", (worek->w)/2, (worek->h)/2, makecol(255,0,0), -1);
textout_centre_ex(nsttura, font, "Nast. tura", (nsttura->w)/2, (nsttura->h)/2, makecol(255,0,0), -1);
textout_centre_ex(tsnlg, font, "Tu sloty na literki gracza", (tsnlg->w)/2, (tsnlg->h)/2, makecol(255,0,0), -1);

// kolejny bool obslugi myszy i początek pętli gry
bool hold=false;
while( !Close){
// mouse_b - prawda jesli klawisz myszy wcisnięty - nieprawda jesli nie
if(mouse_b){
if(!hold){
	//zaznaczanie kafla
	for(int i=0; i <7;i++){
	if(mouse_tile_collision(test_tiles[i])){
hold=true;
clicked=!clicked;
marked = i;
break;
}
}
// obsluga przycisku następna tura
if(mouse_x>=480&&mouse_x<=600&&mouse_y>=430&&mouse_y<=470){
	
			std::cout<<"Następna tura."<<std::endl;
			boolz.uneven = false;
			for(int i=0; i <7;i++){
				if (test_tiles[i].locked){
					boolz.locked_tiles++;
					std::cout<<test_tiles[i].letter<<' '<<test_tiles[i].pos_x<<' '<<test_tiles[i].pos_y<<std::endl;
//sprawdzanie rownosci kafelkow na planszy
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
			//sprawdzanie czy kafelki tworza jeden ciąg
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
			//sprawdzanie czy nie wkłada sie kafelka na inny kafelek
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
				//debagowy wypis komunikatu błędu
				//lonely tile - jakis kafel nie ma polaczenia z resztą
				//uneven - kafelki nie w 1 kolumnie / wierszu
				//overwriting existing tile = gracz polożyl kafel na juz zajęte pole
				std::cout<<"Dude your tile layout is incorrect"<<std::endl;
				std::cout<<"Lonely tile: "<<boolz.lonely_tile<<std::endl;
				std::cout<<"Uneven: "<<boolz.uneven<<std::endl;
				std::cout<<"Overwriting existing tile: "<<boolz.overwrite<<std::endl;
			}
			//resetowanie zmiennych kontroli
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
		// jesli mycha nie jest w miejscu w ktorym mozna wstawiac kafle to po prostu podaza za kursorem
		if(out){
			test_tiles[marked].pos_x = mouse_x-10;
			test_tiles[marked].pos_y = mouse_y-10;
			test_tiles[marked].unlock();
		}
		
		
		out = true;
	}

	
}
// wyswietlanie na wyjsciu zmiennych obslugi myszki na potrzeby debagowania
std::cout<<"CLICKED:"<<clicked<<std::endl;
std::cout<<"HOLD:"<<hold<<std::endl;


}

//jesli przycisk mychy nie przycisniety i jesli ktorys z kafli zaznaczony to podąża za mychą
if(!mouse_b){
if(hold)hold=false;
	if(!clicked&&marked<7){
 test_tiles[marked].pos_x = mouse_x-10;
 test_tiles[marked].pos_y = mouse_y-10;
 test_tiles[marked].unlock();
}


}
// drukowanie wszystkich bitmap na bufer
blit( test_board.token, buffer, 0, 0, 40, 40, test_board.token->w, test_board.token->h );
blit( worek, buffer, 0, 0, 480, 40, worek->w, worek->h );
blit( nsttura, buffer, 0, 0, 480, 430, nsttura->w, nsttura->h );
blit( tsnlg, buffer, 0, 0, 40, 450, tsnlg->w, tsnlg->h );
for(int i=0; i <7;i++)blit( test_tiles[i].tile, buffer, 0, 0, test_tiles[i].pos_x, test_tiles[i].pos_y, 20, 20 );
show_mouse(buffer);
//wyświetlanie bufera na ekranie
blit( buffer, screen, 0, 0, 0, 0, buffer->w, buffer->h );


//czekanie 20 sekund i czyszczenie bufera
rest(20);
clear_to_color( buffer, makecol( 255, 255, 255 ) ) ;

}


// niszczenie bitmap pisanie zawartosci plnszy do terminala i zamykanie allegra i programu
destroy_bitmap( buffer );
destroy_bitmap( worek );
destroy_bitmap( nsttura );
destroy_bitmap( tsnlg );

test_board.print_board();

allegro_exit();

return 0;

}
