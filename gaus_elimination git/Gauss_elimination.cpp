// Gauss_elimination.cpp
//

#include <iostream>

void gauss_elimination(double ** tab, int size)
{
	double h = 0;

	for (int i = 0; i < size ; i++)
	{
		for (int j = 0; j <= size ; j++)
		{
			if (j > i)
			{
				h = -tab[i][j] / tab[i][i];

				for (int k = 0; k <= size ; k++)
				{
					tab[k][j] = tab[k][i] * h + tab[k][j];
				}
			}
		}
	}

	for (int i = size-1; i >= 0; i--)
	{
		for (int j = size-1; j >= 0; j--)
		{
			if (j < i)
			{
				h = -tab[i][j] / tab[i][i];

				for (int k = size; k >= 0; k--)
				{
					tab[k][j] = tab[k][i] * h + tab[k][j];
				}
			}
		}
	}
}

void unknown(double ** tab, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "x" << i << ": " << tab[size][i] / tab[i][i] << std::endl;
	}
}


int main()
{
	int size = 0;
    std::cout << "Ile niewiadowmych ?\n"; 
	std::cin >> size;

	double ** tab = new double * [size + 1];

	for (int i = 0; i < size + 1; i++)
	{
		tab[i] = new double[size];
	}

	for (int j = 0; j < size ; j++)
	{
		for (int i = 0; i < size + 1 ; i++)
		{
			system("cls");

			if (i == size)
			{
				std::cout << " Podaj wartosci wyrazu wolnego " << j + 1 << " rownania \n";
			}
			else
			{
				std::cout << " Podaj " << i + 1  <<" wartosc "<< j + 1 << " rownania \n";
			}

			std::cin >> tab[i][j];

			system("cls");
		}

	}
	
	gauss_elimination(tab, size);
	unknown(tab, size);

	system("pause");

	delete [] tab;
	return 0;
}