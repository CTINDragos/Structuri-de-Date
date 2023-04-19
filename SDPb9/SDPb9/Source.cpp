#include <iostream>
#include<queue>
#include<vector>
#include<fstream>
typedef struct coordonatefinale
{
	int T, A;
};
typedef struct Coordonate
{
	int xmin, xmax, ymin, ymax, T;
}Coord;
void citireMatrice(std::vector<std::vector<char>>& Matrice, int& T)
{
	std::ifstream f("Text.txt");
	int m, n;
	char x;
	f >> T >> n >> m;
	Matrice.resize(n);
	for (int index = 0; index < n; ++index)
	{
		for (int j = 0; j < m; ++j)
		{
			f >> x;
			Matrice[index].push_back(x);
		}
	}
}
void BoolMatrix(std::vector<std::vector<bool>>& BoolMatrix)
{
	for (int index = 0; index < BoolMatrix.size(); ++index)
	{
		for (int j = 0; j < BoolMatrix[index].size(); ++j)
		{
			BoolMatrix[index][j] = false;
		}
	}
}
Coord Cautare(std::vector<std::vector<char>>Matrice, int i, int j, std::vector<std::vector<bool>>& BoolMatrix)
{
	Coord struct1;
	struct1.T = 0;
	struct1.xmax = -1;
	struct1.xmin = Matrice.size();
	struct1.ymin = Matrice[1].size();
	struct1.ymax = -1;
	std::queue<std::pair<int, int>>que;
	int dx[9] = { -1,1,0,0,-1,1,1,-1 };
	int dy[9] = { 0,0,-1,1,-1,-1,1,1 };
	que.push(std::make_pair(i, j));
	while(!que.empty())
	{
		for (int a = 0; a < 8; a++)
		{
			int aux1, aux2;
			aux1 = que.front().first + dx[a];
			aux2 = que.front().first + dy[a];
			if (aux1 >= 0 && aux2 >= 0 && aux1 < Matrice.size() && aux2 < Matrice[0].size()&&BoolMatrix[aux1][aux2]==false)
			{
				BoolMatrix[aux1][aux2] = true;
				if (Matrice[aux1][aux2] == 'P')
				{
					que.push(std::make_pair(aux1, aux2));
					break;
				}
			}

		}
			if (struct1.xmin > que.front().first)
				struct1.xmin = que.front().first;
			if (struct1.xmax < que.front().first)
				struct1.xmax = que.front().first;
			if (struct1.ymin > que.front().second)
				struct1.ymin = que.front().second;
			if (struct1.ymax < que.front().second)
				struct1.ymax = que.front().second;
			struct1.T++;
			 que.pop();
	}
	return struct1;

}
Coord vectorul_de_coordonate(std::vector<std::vector<char>>Matrice, std::vector < std::vector<bool>>MatriceVizitati, int T)
{
	int index, j, aria1 = 0, aria2 = Matrice.size() * Matrice[0].size();
	std::vector<Coord>VectorCoordonate;
	Coord cord{};

	for (index = 0; index < Matrice.size(); ++index)
	{
		for (j = 0; j < Matrice[index].size(); ++j)
		{
			if (Matrice[index][j] == 'P' && MatriceVizitati[index][j] == false)
			{

				VectorCoordonate.push_back(Cautare(Matrice, index, j, MatriceVizitati));//formez vectorul de coordonate 
			}
		}
	}
	for (index = 0; index < VectorCoordonate.size(); index++)
		if (VectorCoordonate[index].T >= T)
			T = VectorCoordonate[index].T;
	for (index = 0; index < VectorCoordonate.size(); index++)
		if (VectorCoordonate[index].T == T)
		{
			aria1 = (VectorCoordonate[index].xmax - VectorCoordonate[index].xmin) * (VectorCoordonate[index].ymax - VectorCoordonate[index].ymin);
			if (aria1 < aria2)
			{
				aria2 = aria1;
				cord.xmax = VectorCoordonate[index].xmax;
				cord.xmin = VectorCoordonate[index].xmin;
				cord.ymax = VectorCoordonate[index].ymax;
				cord.ymin = VectorCoordonate[index].ymin;

			}
		}
	return cord;
}

int main()
{
	int i, j, T;
	std::vector<Coord>VectorCoordonate;
	std::vector<std::vector<char>>Matrice;
	citireMatrice(Matrice, T);
	auto MatriceVizitati = std::vector<std::vector<bool>>(Matrice.size(), std::vector<bool>(Matrice[0].size()));
	BoolMatrix(MatriceVizitati);
	Coord eu;
	eu = vectorul_de_coordonate(Matrice, MatriceVizitati, T);
	std::cout << "imin=" << eu.xmin << std::endl << "imax=" << eu.xmax << std::endl << " jmin=" << eu.ymin << std::endl << "jmax= " << eu.ymax << std::endl;
}