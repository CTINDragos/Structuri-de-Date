#include<iostream>
#include<fstream>
//O(n)
void verifsortare(int* vector, int n)
{
	if (vector[0] >=vector[1])
	{
		bool a = 0;
		for (int i = 1;i<n-1;i++)
			if (vector[i] < vector[i + 1]) {
				a = 1;
				break;
			}
		if (a == 1) std::cout << "vector nesortat";
		else std::cout << "vector sortat descrescator";

	}
	if (vector[0] <=vector[1])
	{
		bool a = 0;
		for(int i=1;i<n-1;i++)
			if (vector[i] > vector[i + 1])
			{
				a = 1; break;
			}
		if (a == 1) std::cout << "vector nesortat";
		else std::cout << "vector sortat crescator";
	}
}
int main()
{
	int n;
	int* arr;
	std::ifstream f("a.txt");
	f >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++)
		f >> arr[i];
	f.close();
	verifsortare(arr, n);
}