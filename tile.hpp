// klasa Tile - obsługuje płytki ktorych gracz nie umiescil na planszy i te ktore
// juz umiescil ale komp nie zatwierdzil jescze poprawnosci slowa i/lub jego ulozenia



class Tile {
	
	private:
	
	
	
	public:
	// Przechowuje literkę ktora jest nadrukowana na płytce - jest wskaznikiem bo łatwiej jest uzywac wskaznika 
	// w nektorych funkcjach alegro
		char* letter;
	// Wartość punktowa płytki
		 int value;
	// pozycje x i y w oknie gry
		 int pos_x;
		 int pos_y;
	// Bitmapa zawierająca obraz płytki
		 BITMAP * tile;
	// jesli plytka jest umieszczona na planszy true jesli nie to false
		 bool locked;
	// inicjuje płytkę dla danej litery wartości i w danych spółrzędnych
	void create(char* lett,int valu,int x,int y);
	//zmiany stanu płytki - bool locked i unclocked
	void lock();
	void unlock();
	// zwraca bitmapę z obrazem płytki
	BITMAP* bmp();

};
