// klasa Tile - obsługuje płytki ktorych gracz nie umiescil na planszy i te ktore
// juz umiescil ale komp nie zatwierdzil jescze poprawnosci slowa i/lub jego ulozenia

class Tile {
	
	private:
	
	
	
	public:
	
		char* letter;
		 int value;
		 int pos_x;
		 int pos_y;
	
	void create(char* lett,int valu,int x,int y);
	BITMAP* bmp();

};
