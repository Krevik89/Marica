#include <iostream>
#include"Matrix.h"

using namespace std;


int main()
{
	setlocale(LC_ALL, "");
	srand(time(0));
	Matrix<int> M(2, 2);
	Matrix<int> M1(2, 3);
	Matrix<int> M2(2, 2);
	
	//авто заполнение
	/*for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			M.SetMij(i, j, i + j);

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			M1.SetMij(i, j, i + j);

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			M2.SetMij(i, j, i + j);*/
	//ручное заполнение
	/*int n;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "Введите число\n"; cin >> n;
			M.SetMij(i, j, n);
		}	
	}*/
	//cout << M<<endl;
	//cout << M1<<endl;
	//cout << M2<<endl;

	//cout << "M + M1:\n" << M+M1 << endl << endl;
	//cout << "M - M1:\n" << M-M1 << endl << endl;
	//cout << "M * M2:\n" << M*M2 << endl << endl;
	//cout << M;
	// 
	//Min MAx
	/*M.Max();
	cout << endl;
	M.Min();
	cout << endl;*/
	
	int n;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << "Введите число\n"; cin >> n;
			M.SetMij(i, j, n);
		}
	}
	cout << M<<endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << "Введите число\n"; cin >> n;
			M2.SetMij(i, j, n);
		}
	}
	cout << M2<<endl;
	cout << "M / M2:\n" << M / M2 << endl << endl;

}


