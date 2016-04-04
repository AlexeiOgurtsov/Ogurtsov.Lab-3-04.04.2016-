#include <iostream>
using namespace std;

double** CreateMatrix(int);
void IsDataValidSize(int&);
void DisplayMatrix(double**, int);
void FillingMatrixOfMaxElements(double**, double**, int);
void FillingFirstMatrix(double **, int);
double MaxElementInMatrix(double**, int);
void FreeMemory(double**, int);

int main(){
	int n = 0;
	IsDataValidSize(n);
	system("cls");
	double** a = CreateMatrix(n);
	cout << "First Matrix:" << endl << endl;
	FillingFirstMatrix(a, n);
	DisplayMatrix(a, n);
	cout << "-----------------------------------------------------------" << endl;
	double** b = CreateMatrix(n);
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

double** CreateMatrix(int n)
{
	double **a = new double*[n];
	for (int i = 0; i < n; i++)
		a[i] = new double[n];
	return a;
}

void DisplayMatrix(double** a, int n)
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

void FillingFirstMatrix(double **a, int n)
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

void FillingMatrixOfMaxElements(double** a, double **b, int n)
{
	//it is still undone
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0)
			{
				b[i][j] = a[i][j];
			}
			else
			{
				b[i][j] = i;
			}
		}
	}
}

double MaxElementInMatrix(double** c, int n)
{
	double max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (c[i][j] > max)
				max = c[i][j];
		}
	}
	return max;
}

void FreeMemory(double** a, int n)
{
	for (int i = 0; i < n; i++)
		delete[]a[i];
	delete[]a;
}