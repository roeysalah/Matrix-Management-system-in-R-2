/*Moshe Hershkovitz 313123150 07*/
#pragma once
#ifndef _MYMATRIX
#define _MYMATRIX
#include <iostream>
#include<math.h>
#pragma warning(disable: 4996)
using namespace std;
/*
 * This class has privates variables.numer of rows, number of cols and
 * pointer to pointer to arrays.in this class we set lot of operators
 * that we can use them on matrices.
 */
class MyMatrix
{
private:
	int _n , _m;//m is rows , n is cols
	double ** _matrix;//pointer to array of pointers to arrays.
public:
	void setN(int n)  { this->_n = n; }
	void setM(int m)  { this->_m = m; }
	int getN() const { return this->_n; }
	int getM() const { return this->_m; }
	//constructs
	MyMatrix(const MyMatrix& other);
	MyMatrix(int n, int m);
	MyMatrix();
	//destruct
	~MyMatrix();
	//funcs
	void Print() const;
	void setMatrix();
	void Zero();
	void LookFor(int i,int j);
	//operators overloading
	MyMatrix operator+(const MyMatrix& other) const;
	MyMatrix operator-(const MyMatrix& other) const;
	MyMatrix operator*(const MyMatrix& other) const;
	MyMatrix operator=(const MyMatrix& other);
	//bool operator!=(const MyMatrix& other);
	double *& operator[](const double & index) const;
	bool operator==(const MyMatrix& other);
	/*friend operators
	Its friend method because we want to use this in global program
	and we use in some variables like int.*/
	friend ostream& operator<<(ostream& os, const MyMatrix& other);
	friend MyMatrix operator*(int m, const MyMatrix& other);
	friend MyMatrix operator*(const MyMatrix& other, int m);
};
#endif



