#include <vector>
#include <iostream>
int WIDTH = 0;
int HEIGHT = 0;









struct Cell
{
	bool up = false;
	bool right = false;
	bool down = false;
	bool left = false;
};

void setupMaze(std::vector<std::vector<Cell*>> &maze)
{
	maze.resize(HEIGHT);
	for(int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			maze[i].push_back(new Cell);	
		}
	}

}

void printMaze(const std::vector<std::vector<Cell*>> &maze)
{
	for (int i = 0; i < maze.size(); i++)
	{
		for (int j = 0; j < maze[i].size(); j++)
		{
			Cell *cell = maze[i][j];
			if (cell->up)
				std::cout << "u";
			if(cell->right)
				std::cout << "r";
			if(cell->down)
				std::cout << "d";
			if(cell->left)
				std::cout << "l";
			if(!cell->up && !cell->right && !cell->down && !cell->left)
				std::cout << "0";
			std::cout << " ";
		}
		std::cout << "\n";
	}
}

void generateMaze(std::vector<std::vector<Cell*>> &maze, int start)
{
	if (start >= WIDTH)
	{
		std::cout << "done" << std::endl; 
		return;
	}

	for (int i = 0; i < HEIGHT; i++)
	{
		if (true) // is possible
		{
			maze[i][start]->up = true;

			generateMaze(maze, start + 1);

			maze[i][start]->up = false;

			maze[i][start]->right = true;

			generateMaze(maze, start + 1);

			maze[i][start]->right = false;

			maze[i][start]->down = true;

			generateMaze(maze, start + 1);

			maze[i][start]->down = false;

			maze[i][start]->left = true;

			generateMaze(maze, start + 1);

			maze[i][start]->left = false;
		}
	}
}


int main(int argc, char* argv[])
{
	if (argc != 3)
		return EXIT_FAILURE;
	WIDTH = atoi(argv[1]);
	HEIGHT = atoi(argv[2]);
	std::vector<std::vector<Cell*>> maze;
	setupMaze(maze);
	printMaze(maze);
	generateMaze(maze, 0);
	printMaze(maze);
	return 0;
}
