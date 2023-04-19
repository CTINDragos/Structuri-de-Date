#include<iostream>
#include<fstream>
int* transf(int** mat, int n, int m)
{
	int* vec = new int[n];
	for (int i = 0; i < n; i++)
	{
		vec[i] = 0;
		int pw = 0;
		for (int j = m - 1; j >= 0; j--)
		{
			std::cout << vec[i] << std::endl;
			vec[i] = vec[i] + (mat[i][j] * pow((n+2), pw));
			pw++;
		}
	}
	for (int i = 0; i < n; i++)
		std::cout << vec[i] << " ";
	return vec;
}
int main()
{
	std::ifstream f("fis.txt");
	int nrrows;
	int nrcols;
	int** matr;
	f >> nrrows;
	f >> nrcols;
	matr = new int* [nrcols];
	for (int i = 0; i < nrcols; i++)
		matr[i] = new int[nrrows];
	for (int i = 0; i < nrcols; i++)
		for (int j = 0; j < nrrows; j++)
			f >> matr[i][j];
	for (int i = 0; i < nrcols; i++)
	{
		for (int j = 0; j < nrrows; j++)
			std::cout << matr[i][j] << " ";
		std::cout << std::endl;
	}
	int* vec;
	vec = transf(matr, nrrows, nrcols);
}