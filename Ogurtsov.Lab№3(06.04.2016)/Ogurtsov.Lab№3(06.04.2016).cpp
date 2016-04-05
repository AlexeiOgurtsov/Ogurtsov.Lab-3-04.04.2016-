#include <iostream>
using namespace std;

int** CreateMatrix(int);
void IsDataValidSize(int&);
void DisplayMatrix(int**, int);
void FillingMatrixOfMaxElements(int**, int**, int);
void FillingFirstMatrix(int **, int);
int MaxElementInMatrix(int**, int, int, int, int);
void FreeMemory(int**, int);

int main(){
	int n = 0;
	IsDataValidSize(n);
	system("cls");
	int** a = CreateMatrix(n);
	cout << "First Matrix:" << endl << endl;
	FillingFirstMatrix(a, n);
	cout << "Matrix:" << endl << endl;
	DisplayMatrix(a, n);
	cout << "-----------------------------------------------------------" << endl;
	int** b = CreateMatrix(n);
	cout << "Matrix of Max Elements:" << endl << endl;
	FillingMatrixOfMaxElements(a, b, n);
	DisplayMatrix(b, n);
	cout << "-----------------------------------------------------------" << endl;
	system("pause");
	FreeMemory(a, n);
	FreeMemory(b, n);
	return 0;
}

void IsDataValidSize(int &n)
{
	while (true)
	{
		system("cls");
		cout << "Enter Size of square matrix(Size > 0):";
		cin >> n;
		if (n > 0) break;
	}
}

int** CreateMatrix(int n)
{
	int **a = new int*[n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	return a;
}

void DisplayMatrix(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j];
			if (j < n - 1)
				cout.width(12);
		}
		cout << endl;
	}
}

void FillingFirstMatrix(int **a, int n)
{
	while (true)
	{
		system("cls");
		int k;
		cout << "Do you want Random Array?" << endl;
		cout << "1.Yes" << endl;
		cout << "2.No" << endl;
		cin >> k;
		system("cls");
		if (k == 1)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					a[i][j] = rand() % 100 - 50;
				}
			}
			break;
		}
		if (k == 2)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cout << "Enter [" << i << "]" << "[" << j << "] element :";
						cin >> a[i][j];
				}
			}
			system("cls");
			break;
		}
	}
}

void FillingMatrixOfMaxElements(int** a, int **b, int n)
{
	int currentmax = a[0][0];
	for (int j = 0; j < n; j++)
		b[0][j] = a[0][j];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			
				currentmax = a[i][j];
				b[i][j] = MaxElementInMatrix(a, n, i, j, currentmax);
				
		}
	}
}

int MaxElementInMatrix(int** a, int n, int i, int j, int currentmax)
{
	i--;
	int max = currentmax;
	int l = i;
	int left = j - 1;
	if (j - 1 < 0)
		left = 0;
	int right = j + 1;
	if (j + 1 == n)
		right = n - 1;
	while (l >= 0)
	{
		for (int p = left; p < right + 1; p++)
		{
			if (a[l][p] > max)
				max = a[l][p];
		}
		l--;
		if (l == -1) break;
		if (left != 0)
		left--;
		if (right != n)
		right++;
	}
	return max;
}

void FreeMemory(int** a, int n)
{
	for (int i = 0; i < n; i++)
		delete[]a[i];
	delete[]a;
}