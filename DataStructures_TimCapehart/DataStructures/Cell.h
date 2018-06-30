#ifndef CELL_H
#define CELL_H

class Cell
{
private:
	int _row;
	int _col;
	char _display;
	int _adjacent;
	bool _bomb = false;
	bool _flag = false;
	bool _revealed = false;
	bool _tlCorner = false;
	bool _trCorner = false;
	bool _blCorner = false;
	bool _brCorner = false;
	bool _bRow = false;
	bool _tRow = false;
	bool _fCol = false;
	bool _lCol = false;
	bool _edge = false;
	/*int _position[2];*/
	
public:
	Cell();
	Cell(int row, int col, bool bomb);
	Cell(int row, int col, char display, int adjacent, bool bomb, bool flag);
	~Cell();

	void setRow(int row) { _row = row; };
	//int getRow() { return _row; };
	int getRow() const { return _row; };
	void setCol(int col) { _col = col; };
	//int getCol() { return _col; };
	int getCol() const { return _col; };
	//void setPosition(int row, int col) { _position[0] = row; _position[1] - col; };*/
	void setDisplay(char disp) { _display = disp; };
	char getDisplay() { return _display; };
	char getDisplay() const { return _display; };
	void setBomb(bool bomb) { _bomb = bomb; };
	bool getBomb() { return _bomb; };
	bool getBomb() const { return _bomb; };
	void setFlag(bool flag) { _flag = flag; };
	bool getFlag() { return _flag; };
	bool getFlag() const { return _flag; };
	void setTLCorner(bool corner) { _tlCorner = corner; };
	bool getTLCorner() const { return _tlCorner; };
	void setTRCorner(bool corner) { _trCorner = corner; };
	bool getTRCorner() const { return _trCorner; };
	void setBLCorner(bool corner) { _blCorner = corner; };
	bool getBLCorner() const { return _blCorner; };
	void setBRCorner(bool corner) { _brCorner = corner; };
	bool getBRCorner() const { return _brCorner; };
	void setBRow(bool corner) { _bRow = corner; };
	bool getBRow() const { return _bRow; };
	void setTRow(bool corner) { _tRow = corner; };
	bool getTRow() const { return _tRow; };
	void setFCol(bool corner) { _fCol = corner; };
	bool getFCol() const { return _fCol; };
	void setLCol(bool corner) { _lCol = corner; };
	bool getLCol() const { return _lCol; };
	void setRevealed(bool revealed) { _revealed = revealed; };
	bool getRevealed() { return _revealed; };
	bool getRevealed() const { return _revealed; };
	void incrementAdj() { _adjacent++; };
	char getAdjacent() const { return _adjacent; };
	void setEdge(bool edge) { _edge = edge; };
	bool getEdge() const { return _edge; };
	

};

Cell::Cell()
{
	/*_row = 0;
	_col = 0;*/
	_display = '\0';
	_adjacent = 0;
	_bomb = false;
	_flag = false;
	_revealed = false;
	/*_position[0] = _row;
	_position[1] = _col;*/
}

Cell::Cell(int row, int col, bool bomb)
{
	/*_row = row;
	_col = col;*/
	_display = '\0';
	_adjacent = 0;
	_bomb = false;
	_flag = false;
	_revealed = false;
	/*_position[0] = row;
	_position[1] = col;*/
}

Cell::Cell(int row, int col, char display, int adjacent, bool bomb, bool flag)
{
	/*_row = row;
	_col = col;*/
	_display = display;
	_adjacent = adjacent;
	_bomb = bomb;
	_flag = flag;
	_revealed = false;
	//_position[0] = row;
	//_position[1] = col;
}

Cell::~Cell()
{

}

#endif
