class Board {
	
	private:
	char* board[15][15];
	
	public:
	
	BITMAP* token;
	
	void initialize();
	bool is_good_for_print(Tile a);
	void print_board();
	void print_tile(Tile a);
	bool break_check_x();
	bool break_check_y();
	
	BITMAP* board_bmp();
};

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
