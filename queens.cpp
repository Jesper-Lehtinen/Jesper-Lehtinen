#include <vector>
#include <iostream>

int solutions = 0;
int possibilities = 0;

std::vector<std::vector<int>> getVector(int size)
{
    std::vector<std::vector<int>> queens;
    queens.resize(size);
    for (int i = 0; i < queens.size(); i++)
    {
        queens[i].resize(size);
        for (int j = 0; j < queens.at(i).size(); j++)
        {
            queens[i][j] = 0;
        }
    }
    return queens;
}

bool isLegal(const std::vector<std::vector<int>> &queens, int i, int j)
{
	// std::cout << "tuli1" << std::endl;
	for (int x = 0; x < queens[i].size(); x++)
	{
		if (queens[i][x] == 1)
			return false;
		if (queens[x][j] == 1)
			return false;
	}

	for (int l = 0; l < queens[i].size(); l++)
	{
		// std::cout << "l: " << l << "\t j: " << j << "\t i: " << i << std::endl;
		if (j-i+l >= 0 && j-i+l < queens[i].size() && queens[l][j - i + l] == 1)
			return false;
	}
	for (int r = 0; r < queens[i].size(); r++)
	{
		// std::cout << "r: " << r << "\t j: " << j << "\t i: " << i << std::endl;
		if (i+j-r >= 0 && i+j-r < queens.size() && queens[i + j - r][r] == 1)
			return false;
	}
	// std::cout << "tuli2" << std::endl;
	return true;
}


void solve(std::vector<std::vector<int>> &queens, int start, int end)
{
	int i = 0;
	if (start >= end)
	{
		solutions++;
		for (int i = 0; i < queens.size(); i++)
    		{
        		for (int j = 0; j < queens[i].size(); j++)
       			{
            			std::cout << queens[i][j] << " ";
        		}
        		std::cout << std::endl;
    		}
		std::cout << std::endl;
		return;
	}

	for (int i = 0; i < queens.size(); i++)
	{
		possibilities++;
		if (isLegal(queens, i, start))
		{
			// std::cout << "tuli" << std::endl;
			queens[i][start] = 1;

			solve(queens, start + 1, end);

			queens[i][start] = 0;
		}
	}
}


int main(int argc, char* argv[])
{
	int size = atoi(argv[1]);
	std::vector<std::vector<int>> queens = getVector(size);
	solve(queens, 0, queens.size());
	std::cout << "Solutions found: " << solutions << std::endl;
	std::cout << "Possible combinations found: " << possibilities << std::endl;
	return EXIT_SUCCESS;
}
