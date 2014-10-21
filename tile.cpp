#include "tile.hpp"


	
	void Tile::create( char* lett,int valu,int x,int y){
		this->letter=lett;
		this->value=valu;
		this->pos_x = x;
		this->pos_y = y;
		this->tile = NULL;
		this->locked=false;
		
		};
	
	BITMAP* Tile::bmp(){
		BITMAP * rect;
		const char* let = this->letter;
		rect = create_bitmap( 20, 20 );
		clear_to_color( rect, makecol( 127, 127, 127 ) );
		textout_centre_ex(rect, font, let, 10, 10, makecol(255,255,255), -1);
		return rect;
	};
	
	void Tile::lock(){
		this->locked=true;
	}
		
	void Tile::unlock(){
		this->locked=false;
	}
	
bool mouse_tile_collision(Tile a){
	if(mouse_x>=a.pos_x&&mouse_x<=a.pos_x+20){
		if(mouse_y>=a.pos_y&&mouse_y<=a.pos_y+20)return true;
	}
 return false;
	}
	
	
