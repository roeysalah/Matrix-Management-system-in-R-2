/*Moshe Hershkovitz 313123150 07*/
#include "MyMatrix.h";
#include <iostream>
#include<math.h>
#include "Types.h"
#pragma once

/*
 * This class represents a main to user.
 */
class Interface
{
public:
	/*The mathods are static because we want the opportinity to use them
	during the time run and we want the values will stay all the time.*/
	static void setMatrices();//set the matrices with values
	static void PrintMats(Types** arr);//func to print the matrices
	static void PrintCalc(Types** arr);//method to print some arithmetic expressions
	static void DeleteArr(Types** arr);//method to free memory
};