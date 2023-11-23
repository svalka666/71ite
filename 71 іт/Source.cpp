#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** d, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** d, const int rowCount, const int colCount);
void Sort(int** d, const int rowCount, const int colCount);
void Change(int** d, const int row1, const int row2, const int colCount);
void Calc(int** d, const int rowCount, const int colCount, int& S, int& k);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -31;
	int High = 54;
	int rowCount = 9;
	int colCount = 5;
	int** d = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		d[i] = new int[colCount];
	Create(d, rowCount, colCount, Low, High);
	Print(d, rowCount, colCount);
	Sort(d, rowCount, colCount);
	Print(d, rowCount, colCount);
	int S = 0;
	int k = 0;
	Calc(d, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(d, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] d[i];
	delete[] d;
	return 0;
}
void Create(int** d, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			d[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** d, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << d[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** d, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < rowCount - 1; i0++)
		for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
			if ((d[i1][0] > d[i1 + 1][0])
				||
				(d[i1][0] == d[i1 + 1][0] &&
					d[i1][1] < d[i1 + 1][1])
				||
				(d[i1][0] == d[i1 + 1][0] &&
					d[i1][1] == d[i1 + 1][1] &&
					d[i1][3] > d[i1 + 1][3]))
				Change(d, i1, i1 + 1, colCount);
}
void Change(int** d, const int row1, const int row2, const int colCount)
{
	int tmp;
	for (int j = 0; j < colCount; j++)
	{
		tmp = d[row1][j];
		d[row1][j] = d[row2][j];
		d[row2][j] = tmp;
	}
}
void Calc(int** d, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (d[i][j] > 0 && !(d[i][j] % 5 == 0))
			{
				S += d[i][j];
				k++;
				d[i][j] = 0;
			}
}