#include <vector>
#include <iostream>

using vec2d = std::vector<std::vector<std::string>>;

//global
vec2d board;
bool over = false;

struct coordinates
{
	int x, y;
}a;
//Printing the board

void render(vec2d a)
{
	std::cout << "  0 1 2 \n";
	std::cout << "  -------\n";
	for (int i = 0; i < 3; i++)
	{
		std::cout << i<<"|";
		for (int j = 0; j < 3; j++)
			std::cout << a[i][j]<<" ";
		std::cout << "|";
		std::cout << std::endl;
	}
	std::cout << "  -------";
}

//Getting the user moves

coordinates get_move()
{
	std::cout << "\nInsert your x coordinates: ";
	std::cin >> a.x;
	std::cout << "Insert your y coordinates: ";
	std::cin >> a.y;
	if (::board[a.x][a.y] == "O" || ::board[a.x][a.y] == "X")
	{
		std::cout << "\n\nIllegal move! Please insert other coordinates \n\n";
		get_move();
	}
	else
		return {a.x,a.y};

}

//Giving board value

void printBoard()
{
	::board={{" ", " ", " "},								
			{" ", " ", " "},
			{" ", " ", " "}};
	render(::board);
}

//Placing the X or O in the tictactoe board

auto make_move(vec2d *g, coordinates  b, int *c)
{
	vec2d board1 = *g;

	if (*c == 1) 
	{
		board1[b.x][b.y] = "O";
		(*c)++;
		*g = board1;
		render(board1);
	}
	else
	{
		board1[b.x][b.y] = "X";
		(*c)--;
		*g = board1;
		render(board1);
	}
}
std::string get_winner(vec2d* a)
{
	int counter=0;
	vec2d bordCheck = *a;
	//Win conditions for X

	for (int x = 0; x < 3; x++)
	{
		if (bordCheck[x][0] == "X" && bordCheck[x][1] == "X" && bordCheck[x][2] == "X")
		{
			::over = true;
			return "X wins";
		}
		else if (bordCheck[0][x] == "X" && bordCheck[1][x] == "X" && bordCheck[2][x] == "X")
		{
			::over = true;
			return "X wins";
		}
	}
	if ((bordCheck[0][0] == "X" && bordCheck[1][1] == "X" && bordCheck[2][2] == "X") || (
		bordCheck[0][2] == "X" && bordCheck[1][1] == "X" && bordCheck[2][0] == "X"))
	{
		::over = true;
		return "X wins";
	}

	//Win conditions for O
	for (int x = 0; x < 3; x++)
	{
		if (bordCheck[x][0] == "O" && bordCheck[x][1] == "O" && bordCheck[x][2] == "O")
		{
			::over = true;
			return "O wins";
		}
		else if (bordCheck[0][x] == "O" && bordCheck[1][x] == "O" && bordCheck[2][x] == "O") 
		{
			::over = true;
			return "O wins";
		}
	}
	if ((bordCheck[0][0] == "O" && bordCheck[1][1] == "O" && bordCheck[2][2] == "O") || (
		bordCheck[0][2] == "O" && bordCheck[1][1] == "O" && bordCheck[2][0] == "O")) {
		::over = true;
		return "O wins";
	}
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if (bordCheck[x][y] == "O" || bordCheck[x][y] == "X")
				counter++;
			else
				return "Nothing";
		}
	}
	if (counter == 9) {
		std::cout << "\n\nThe match ends in a draw!\n";
		::over = true;
		return "Draw";
	}
}

int main()
{
	
	int playerTurn = 1;
	printBoard();
	while (!::over)
	{
		coordinates a = get_move();
		make_move(&::board, a, &playerTurn);
		get_winner(&::board);
	}
}