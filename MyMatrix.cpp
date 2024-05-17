/*Moshe Hershkovitz 313123150 07*/
#include "MyMatrix.h"
#include <iostream>


//constructors
MyMatrix::MyMatrix(int m, int n)
{
	_m = m;
	_n = n;
		_matrix = new double*[_m];
		for (int i = 0; i < _m; i++)
			_matrix[i] = new double[_n];

		for (int i = 0; i < _m; i++)
		{
			for (int j = 0; j < _n; j++)
			{
				_matrix[i][j] = 0;
			}
		}
}
MyMatrix::MyMatrix()
{
	_m = 2;
	_n = 2;
	_matrix = new double*[_m];
	for (int i = 0; i < _m; i++)
		_matrix[i] = new double[_n];

	for (int i = 0; i < _m; i++)
	{
		for (int j = 0; j < _n; j++)
		{
			_matrix[i][j] = 0;
		}
	}
}
MyMatrix::MyMatrix(const MyMatrix& other)//copy constructor
{
	_m = other._m;
	_n = other._n;
	_matrix = new double*[other._m];
	for (int i = 0; i < _m; i++)
		_matrix[i] = new double[other._n];
		for (int x = 0; x < other._m; x++)
		{
			for (int j = 0; j <other. _n; j++)
			{
				_matrix[x][j] = other[x][j];
			}
		}
}
//destructor
MyMatrix::~MyMatrix()
{
	for (int x = 0; x < _m; x++)
	{
		delete[] _matrix[x];
	}
	delete[] _matrix;
}
//print
void MyMatrix::Print() const
{
	cout << "--------------" << endl;;
	for (int i = 0; i < _m; i++)
	{
		for (int j = 0; j < _n; j++)
		{
			cout << _matrix[i][j]<<" ";
		}
		cout << endl;
	}
	cout << "--------------" << endl;
}
/********************************************************************
Function name:Zero()
Input:
Output:
The function operation:passes through the whole matrix  and give 0 value.
*************************************************************************/
void MyMatrix::Zero()
{
	for (int i = 0; i < _m; i++)
	{
		for (int j = 0; j < _n; j++)
			_matrix[i][j]=0;
	}
}
/********************************************************************
Function name:setMatrix()
Input:
Output:
The function operation:passes through the whole matrix  and give users
						value.
*************************************************************************/
void MyMatrix::setMatrix()
{
	for (int i = 0; i < _m; i++)
	{
		cout << "enter row number " << i + 1 << ": " << endl;
		for (int j = 0; j < _n; j++)
			cin >> _matrix[i][j];
	}
}
//define the operator +
MyMatrix MyMatrix::operator+(const MyMatrix& other) const 
{
	//first, we check if the matrices are in same size
	if (_m != other._m || _n != other._n) 
	{
		cout << "Matrix sizes do not match. Mission impossible. configure as default"<<endl;
		//use copt constructor
		MyMatrix temp(*this);
		//fill the matrix in 0
		temp.Zero();
		//return 0 matrix to the matrix (this)
		return (temp);
	}
	//set the result in matrix in same size
	MyMatrix temp(_m,_n);
	for (int i = 0; i < _m; i++)
	{
		for (int j = 0; j < _n; j++)
		{
			temp._matrix[i][j]=_matrix[i][j] + other._matrix[i][j];
		}
	}
	return temp;
}
//define the operator =
 MyMatrix MyMatrix ::operator=(const MyMatrix& other)
{
	 //first, we check if the matrices are in same size
	if (_m != other._m || _n != other._n)
	{
		cout << "Matrix sizes do not match. Mission impossible. configure as default" << endl;
		MyMatrix temp(*this);
		temp.Zero();
		return (temp);
	}
	MyMatrix temp(*this);
	//check the bool operator to know if we need do the operator or we want to saave time.
	if (temp == other)
	{
		cout << "You tried to compare the matrix with same matrix" << endl;
		return temp;
	}
	else
	{
		for (int i = 0; i < _m; i++)
		{
			for (int j = 0; j < _n; j++)
			{
				other[i][j]=temp[i][j];
			}
		}
		return temp;
	}
}
 //define the operator []
double* & MyMatrix::operator [](const double &index) const  // overloading operator []
{
	/*its give us back pointer by ref to arr of pointers,to specific place
	that contains arr itself*/
	return  _matrix[int(index)];
}
//define the operator -
MyMatrix MyMatrix::operator-(const MyMatrix& other) const
{
	//same like before
	if (_m != other._m || _n != other._n)
	{
		cout << "Matrix sizes do not match. Mission impossible." << endl;
		MyMatrix temp(*this);
		temp.Zero();
		return (temp);
	}
	MyMatrix temp(other._m, other._n);
	for (int i = 0; i < other._m; i++)
	{
		for (int j = 0; j < other._n; j++)
		{
			temp[i][j] = _matrix[i][j] - other[i][j];
		}
	}
	return temp;
}
//define the operator * between 2 matrices
MyMatrix MyMatrix::operator*(const MyMatrix& other)const
{
	int sum = 0;
	if (_n != other._m)
	{
		cout << "Matrix sizes do not match. Mission impossible. configure as default" << endl;
		MyMatrix temp(*this);
		temp.Zero();
		return (temp);
	}
	MyMatrix temp(_m, other._n);
	for (int i = 0; i < _m; i++)
	{
		for (int j = 0; j < other._n; j++)
		{
			for (int x = 0; x < _n; x++)
			{
				//calculate by rules of matrices
				sum = sum + (_matrix[i][x] * other[x][j]);
			}
			temp[i][j] = sum;
			sum = 0;
		}
	}
	return temp;
}
//define the operator * between number to matrix
MyMatrix operator*(int m, const MyMatrix & other)
{
	MyMatrix temp(other._m, other._n);
	for (int i = 0; i < other._m; i++)
	{
		for (int j = 0; j < other._n; j++)
		{
			temp[i][j] = m * other[i][j];
		}
	}
	return temp;
}
//define the operator * between matrix to number.
MyMatrix operator*(const MyMatrix& other, int m)
{
	//we set the problem opposite to the before operator
	return m * other;
}
//define the operator to cout the matrix directky,
ostream& operator<<(ostream& os, const MyMatrix& other)
{
	//print the matrix
	cout << "-------------" << endl;
	for (int i = 0; i < other._m; i++)
	{
		for (int j = 0; j < other._n; j++)
		{
			cout << other[i][j]<<" ";
		}
		cout << endl;
	}
	cout << "-------------" << endl;
	return os;
}
//operator overloading to check if 2 matrices are same.
bool  MyMatrix::operator==(const MyMatrix& other)
{
	if (_m != other._m || _n != other._n)
		return false;
	for (int i = 0; i < _m; i++)
	{
		for (int j = 0; j < _n; j++)
		{
			if (_matrix[i][j] != other[i][j])
				return false;
		}
	}
	return true;
}
/********************************************************************
Function name:LookFor()
Input:int i,int j
Output:print
The function operation:The method get 2 numbers are indicate on specific
						place in matrix, and it print out the value 
						inside, depend it exist.
*************************************************************************/
void MyMatrix::LookFor(int i,int j)
{
	MyMatrix temp(*this);
	for (int m = 0; m < _m; m++)
	{
		if (m == i)
		{
			for (int n = 0; n < _n; n++)
			{
				if (n == j)
				{
					cout << temp[i][j]<<endl;
					return;
				}
			}
			cout << "the place is not exist." << endl;
			return;
		}
	}
	cout << "the place is not exist." << endl;
	return;
}
