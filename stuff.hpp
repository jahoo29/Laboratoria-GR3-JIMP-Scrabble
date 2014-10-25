// Plik ktory stworzylem po to żeby przechowywać tam funkcje ktorych nie chcę w głównym pliku

class Board {
	
	private:
	// Wirtualna tablica 
	char* board[15][15];
	
	public:
	//  Bitmapa tablicy w oknie
	
	BITMAP* token;
	
	// wypełnia zmienną board zerami
	
	void initialize();
	
	// sprawdza czy płytka jest dobrze ustawiona i jesli tak to ją nadrukowuje na bitmapie token
	// UWAGA - is_good_for_print(Tile a) uzywamy dopiero po tym jak sprawdzilismy uklad kostek itd.
	
	bool is_good_for_print(Tile a);
	
	//Drukuje zawartość tablicy wirtualnej w terminalu
	
	void print_board();
	
	//nadrukowuje plytkę na bitmapie token
	
	void print_tile(Tile a);
	
	//NO IDEA
	
	bool break_check_x();
	bool break_check_y();
	
	//EONI
	
	//Generuje początkowy obraz planszy (ten ktory widac w oknie)
	
	BITMAP* board_bmp();
};

// W klasie databox trzymam zmienne obslugujące pętle w mainie - glownie po to
// zeby ich inicjalizacje byly w 1 miejscu i żeby nie pałętały się w pliku scrabble.cpp

class Databox {
	
	public:

	bool uneven;
	int last_x;
	int last_y;
	int locked_tiles;
	bool lonely_tile;
	bool overwrite;
	
	void initialize();
	
};
