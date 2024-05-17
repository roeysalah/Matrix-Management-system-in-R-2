/*Moshe Hershkovitz 313123150 07*/
#pragma once
#include "MyMatrix.h"
#include <string>

/*
 * This class has privates variables.name of matrix and pointer to matrix.
 *	The user set name and matrix, and we will set him a Types.
 */
class Types
{
	MyMatrix *_m;
	string _id;
public:
	void setM(MyMatrix *c)
	{
		this->_m = c;
		_m->Print();
	}
	void setId(string& od)
	{
		_id = od;
	}
	MyMatrix getM() const { return *_m; }
	string getId() const { return _id; }
	~Types() { delete _m; }
};

