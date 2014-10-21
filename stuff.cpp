#include"stuff.hpp"

 void Board::initialize(){
	 for (int x=0;x<15;x++){
		 for (int y=0;y<15;y++){
		 board[x][y] = "0";
		 
	 }
	 }
	 
	 
	} 


 void Board::print_board(){
	 for (int x=0;x<15;x++){
		 for (int y=0;y<15;y++){
		 std::cout<<board[x][y];
		 
	 }
	 std::cout<<std::endl;
	 }
	 
	 
	} 



 BITMAP* Board::board_bmp(){
	 
	 
	BITMAP * board=NULL;
	
	BITMAP * red=NULL;
	BITMAP * pink=NULL;
	BITMAP * blue=NULL;
	BITMAP * grey=NULL;
	
	board = create_bitmap( 300, 300 );
	clear_to_color( board, makecol( 0, 255, 0 ) );
	
	red = create_bitmap( 20, 20 );
	pink = create_bitmap( 20, 20 );
	blue = create_bitmap( 20, 20 );
	grey = create_bitmap( 20, 20 );
	
	clear_to_color( red, makecol( 255, 0, 0 ) );
	clear_to_color( pink, makecol( 255, 127, 127 ) );
	clear_to_color( blue, makecol( 0, 0, 255 ) );
	clear_to_color( grey, makecol( 200, 200, 255 ) );
	
	//red print
	for(int x=1;x<16;x= x+7){
		for(int y=1;y<16;y=y+7){
			if(x!=8||y!=8){
				std::cout<<x<<y<<std::endl;
				blit( red, board, 0, 0, 20*(x-1), 20*(y-1), red->w, red->h );
			}
		}
	}
	// blue print
	for(int x=2;x<15;x= x+4){
		for(int y=2;y<15;y=y+4){
			
				std::cout<<x<<y<<std::endl;
				blit( blue, board, 0, 0, 20*(x-1), 20*(y-1), blue->w, blue->h );
			
		}
	}
	
	//pink print
	
	//central
	blit( pink, board, 0, 0, 140, 140, pink->w, pink->h );
	//rest
	for(int x = 1;x<5;x++){
	blit( pink, board, 0, 0, 20*(x), 20*(x), pink->w, pink->h );
	blit( pink, board, 0, 0, 20*(x+9), 20*(x+9), pink->w, pink->h );
	blit( pink, board, 0, 0, 20*(x), 20*(14-x), pink->w, pink->h );
	blit( pink, board, 0, 0, 20*(14-x), 20*(x), pink->w, pink->h );
}

//grey print

for(int x = 1;x<14;x+=11){
	blit( grey, board, 0, 0, 20*(x-1), 20*(x+2), grey->w, grey->h );
	blit( grey, board, 0, 0, 20*(x+2), 20*(x-1), grey->w, grey->h );
	blit( grey, board, 0, 0, 20*(x-1), 20*(12-x), grey->w, grey->h );
	blit( grey, board, 0, 0, 20*(x+2), 20*(15-x), grey->w, grey->h );
}
for(int x = 7;x<10;x+=2){
	blit( grey, board, 0, 0, 20*(x-1), 20*(x-1), grey->w, grey->h );
	blit( grey, board, 0, 0, 20*(15-x), 20*(x-1), grey->w, grey->h );
}


	blit( grey, board, 0, 0, 20*(3), 20*(7), grey->w, grey->h );
	blit( grey, board, 0, 0, 20*(7), 20*(3), grey->w, grey->h );
	blit( grey, board, 0, 0, 20*(7), 20*(11), grey->w, grey->h );
	blit( grey, board, 0, 0, 20*(11), 20*(7), grey->w, grey->h );
	
	blit( grey, board, 0, 0, 20*(12), 20*(8), grey->w, grey->h );
	blit( grey, board, 0, 0, 20*(8), 20*(12), grey->w, grey->h );
	blit( grey, board, 0, 0, 20*(6), 20*(12), grey->w, grey->h );
	blit( grey, board, 0, 0, 20*(12), 20*(6), grey->w, grey->h );

	blit( grey, board, 0, 0, 20*(2), 20*(8), grey->w, grey->h );
	blit( grey, board, 0, 0, 20*(8), 20*(2), grey->w, grey->h );
	blit( grey, board, 0, 0, 20*(2), 20*(6), grey->w, grey->h );
	blit( grey, board, 0, 0, 20*(6), 20*(2), grey->w, grey->h );


	return board;
	
}

void Board::print_tile(Tile a){
	if (a.locked){
	int iks = (a.pos_x-40)/20;
	int igrek = (a.pos_y-40)/20;
	if(board[iks][igrek]=="0"){
		board[iks] [igrek] = a.letter;
		blit(a.tile,this->token, 0, 0, a.pos_x-40, a.pos_y-40, 20, 20 );
	}
	
}
	
	
};

bool Board::is_good_for_print(Tile a){
	if (a.locked){
	int iks = (a.pos_x-40)/20;
	int igrek = (a.pos_y-40)/20;
	if(board[iks][igrek]=="0"){
		return true;

	}
	else return false;
}
else return true;	
	
};


void Databox::initialize(){
	
	 this->uneven=true;
	 this->last_x=-1;
	 this->last_y=-1;
	 this->locked_tiles = 0;
	 this->lonely_tile=false;
	 this->overwrite=false;
	
	
	
	
	};

