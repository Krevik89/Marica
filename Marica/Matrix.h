#pragma once
#include <iostream>
using namespace std;

template<class T>
class Matrix
{
	T** arr;
	int row, col;
public:
    Matrix()
    {
        row = col = 0;
        arr = nullptr;
    }
    Matrix(int r, int c)
    {
        row = r;
        col = c;

        arr = (T**) new T * [row];
        for (int i = 0; i < row; i++)
            arr[i] = (T*)new T[col];
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
               arr[i][j] = 0;
    }
    ~Matrix()
    {
        if (col > 0)
        {
            for (int i = 0; i < row; i++)
                delete[] arr[i];
        }
        if (row > 0)
            delete[] arr;
    }

    T GetMij(int i, int j)
    {
        if ((row > 0) && (col > 0))
            return arr[i][j];
        else
            return 0;
    }
    void SetMij(int i, int j, T value)
    {
        if ((i < 0) || (i >= row))
            return;
        if ((j < 0) || (j >= col))
            return;
        arr[i][j] = value;
    }
    void Print(const char* ObjName)
    {
        cout << "Object: " << ObjName << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                cout << arr[i][j] << "\t";
            cout << endl;
        }
        cout << "---------------------" << endl << endl;
    }
    Matrix operator=(const Matrix& _M)
    {
        if (col > 0)
        {
            for (int i = 0; i < row; i++)
                delete[] arr[i];
        }

        if (row > 0)
        {
            delete[] arr;
        }

        row = _M.row;
        col = _M.col;

        arr = (T**) new T * [row]; // количество строк, количество указателей
        for (int i = 0; i < row; i++)
            arr[i] = (T*) new T[col];

        // заполнить значениями
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                arr[i][j] = _M.arr[i][j];
        return *this;
    }
    
    friend ostream& operator<<(ostream& os, const Matrix<T>& R) {
        for (int i = 0; i < R.row; i++) {
            for (int j = 0; j < R.col; j++)
                os << R.arr[i][j] << "\t";
            os << "\n";
        }
        return os;
    }
    friend istream& operator>>(istream& fin, Matrix<T>& R) {
        for (int i = 0; i < R.row; i++)
            for (int j = 0; j < R.col; j++)
                fin >> R.arr[i][j];
        return fin;
    }

    void Min() {
        T min = this->arr[0][0];
        for (int i = 0; i < this->row; i++){
            for (int j = 0; j < this->col; j++)
            {
                if (min > this->arr[i][j])min = this->arr[i][j];
            }
        }
        cout <<"Min: "<< min;
    }
    void Max() {
        T max = this->arr[0][0];
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++)
            {
                if (max < this->arr[i][j])max = this->arr[i][j];
            }
        }
        cout <<"Max: "<< max;
    }
    Matrix operator+ (const Matrix& R) {
        int r = max(row, R.row);
        int c = max(col, R.col);
        Matrix Res(r, c);
        if (row == R.row && col == R.col) {
            for (size_t i = 0; i < row; i++)
                for (size_t j = 0; j < col; j++)
                    Res.arr[i][j] = arr[i][j] + R.arr[i][j];
        }
        else {
            Matrix Mthis(r, c);
            Matrix MR(r, c);
            for (size_t i = 0; i < row; i++)
                for (size_t j = 0; j < col; j++)
                    Mthis.arr[i][j] = arr[i][j];

            for (size_t i = 0; i < R.row; i++)
                for (size_t j = 0; j < R.col; j++)
                    MR.arr[i][j] = R.arr[i][j];

            for (size_t i = 0; i < r; i++)
                for (size_t j = 0; j < c; j++)
                    Res.arr[i][j] = Mthis.arr[i][j] + MR.arr[i][j];
        }
        return Res;
    }
    Matrix operator-(const Matrix& R) {
        int r = max(row, R.row);
        int c = max(col, R.col);
        Matrix Res(r, c);
        if (row == R.row && col == R.col) {
            for (size_t i = 0; i < row; i++)
                for (size_t j = 0; j < col; j++)
                    Res.arr[i][j] = arr[i][j] - R.arr[i][j];
        }
        else {
            Matrix Mthis(r, c);
            Matrix MR(r, c);
            for (size_t i = 0; i < row; i++)
                for (size_t j = 0; j < col; j++)
                    Mthis.arr[i][j] = arr[i][j];

            for (size_t i = 0; i < R.row; i++)
                for (size_t j = 0; j < R.col; j++)
                    MR.arr[i][j] = R.arr[i][j];

            for (size_t i = 0; i < r; i++)
                for (size_t j = 0; j < c; j++)
                    Res.arr[i][j] = Mthis.arr[i][j] - MR.arr[i][j];
        }
        return Res;
    }
    Matrix operator*(const Matrix& R) {
        if (row == R.col)
        {
            Matrix Res(row, R.col);
            for (int i = 0; i < row; i++)
                for (int j = 0; j < R.col; j++)
                {
                    Res.arr[i][j] = 0;
                    for (int k = 0; k < col; k++)
                        Res.arr[i][j] += arr[i][k] * R.arr[k][j];
                }
            return Res;
        }
        else {
            cout << "Eroro";
        }
    }
    Matrix operator/(const Matrix& R) {
        if (row == R.col)
        {
            Matrix Res(row, R.col);
            for (int i = 0; i < row; i++)
                for (int j = 0; j < R.col; j++)
                {
                    Res.arr[i][j] = 0;
                    for (int k = 0; k < col; k++)
                        Res.arr[i][j] += R.arr[k][j]* arr[i][k];
                }
            return Res;
        }
        else {
            cout << "Eroro";
        }
    }
};

