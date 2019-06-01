
#include <queue>
#include <iostream>
#include <string>
using namespace std;

class Coord {
public:
	Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
	int r() const { return m_r; }
	int c() const { return m_c; }

private:
	int m_r;
	int m_c;
};

bool equals(Coord a, Coord b);
void printMaze(string maze[], int nRows);
void updateMaze(string maze[], int r, int c);

// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise
bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec) {
	Coord end(er, ec);
	queue<Coord> coords;
	coords.push(Coord(sr, sc));
	updateMaze(maze, sr, sc);
	while (!coords.empty()) {
		Coord current = coords.front();
		coords.pop();
		if (equals(current, end))
			return true;
		int cr = current.r(); //current row
		int cc = current.c(); //current col
		if (cr + 1 < nRows && maze[cr + 1][cc] != 'D' && maze[cr + 1][cc] != 'X') { //south
			updateMaze(maze, cr + 1, cc);
			coords.push(Coord(cr + 1, cc));
		}
		if (cc - 1 >= 0 && maze[cr][cc - 1] != 'D' && maze[cr][cc - 1] != 'X') { //west
			updateMaze(maze, cr, cc - 1);
			coords.push(Coord(cr, cc - 1));
		}
		if (cr - 1 >= 0 && maze[cr - 1][cc] != 'D' && maze[cr - 1][cc] != 'X') { //north
			updateMaze(maze, cr - 1, cc);
			coords.push(Coord(cr - 1, cc));
		}
		if (cc + 1 < nCols && maze[cr][cc + 1] != 'D' && maze[cr][cc + 1] != 'X') { //east
			updateMaze(maze, cr, cc + 1);
			coords.push(Coord(cr, cc + 1));
		}
		
	}
	return false;
}

bool equals(Coord a, Coord b) {
	if (a.r() == b.r() && a.c() == b.c())
		return true;
	return false;
}
void printMaze(string maze[], int nRows) {
	for (int i = 0; i != nRows; i++) {
		cout << maze[i] << endl;
	}
}

void updateMaze(string maze[], int r, int c) {
	maze[r][c] = 'D'; //D for discovered
}


int main()
{	
	string maze[10] = {
			   "XXXXXXXXXX",
			   "X....X...X",
			   "X.XX.XX..X",
			   "XXX....X.X",
			   "X.XXX.XXXX",
			   "X.X...X..X",
			   "X...X.X..X",
			   "XXXXX.X.XX",
			   "X........X",
			   "XXXXXXXXXX"
	};
	if (pathExists(maze, 10, 10, 3, 5, 8, 8))
		cout << "Solvable!" << endl;
	else
		cout << "Out of luck!" << endl;
}


