/*Moshe Hershkovitz 313123150 07*/
#include "interface.h"
#include <string>
/********************************************************************
Function name:setMatrices
Input:
Output:arr of pointers to matrices with id.
The arr is of Types,that contains pointer tomatrix and id.
The function operation: we allocate memory to arr and then sets
						the matrices.ask for rows and cols and set it 
						inside the arr.
*************************************************************************/
void Interface::setMatrices()
{
	Types* arr[4];
	for (int i = 0; i < 4; i++)
	{
		string name;
		int rows, cols;
		//set the arr[i] with new Types class.
		arr[i] = new Types;
		cout << "please enter the id of matrix:" << endl;
		cin >> name;
		//name it
		arr[i]->setId(name);
		cout << "please insert matrix  rows and columns: " << endl;
		cin >> rows >> cols;
		//type of set func,we want to get compatitible values.
		while (rows < 1 || cols < 1)
		{
			cout << "invalid sizes. enter again: " << endl;
			cin >> rows >> cols;
		}
		//allocate memory to matrix from MyMatrix class to fill the pointer in Types.
		MyMatrix *temp = new MyMatrix(rows,cols);
		temp->setMatrix();
		arr[i]->setM(temp);
	}
	//call to the method
	PrintCalc(arr);
	DeleteArr(arr);
}
/********************************************************************
Function name:PrintMats
Input:pointer to pointer to arr
Output:
The function operation: we use ostream << operator to print the matrices
*************************************************************************/
void Interface::PrintMats(Types** arr)
{
	for (int i = 0; i < 4; i++)
	{
		//call with -> becauseits pointer.
		cout << arr[i]->getM();
	}
}
/********************************************************************
Function name:PrintCalc
Input:pointer to pointer to arr
Output:
The function operation: print arithmetic operations on matrices in the arr
						that we set in 	MyMatrix.cpp.
*************************************************************************/
void Interface::PrintCalc(Types** arr)
{
	int i, j;
	string choose;
	cout << arr[1]->getM();
	cout << "now we will do some arithmetic operation on the matrices:" << endl;
	cout << arr[0]->getId() << " + " << arr[1]->getId() << "=" << endl;//A+B PRINT
	cout << (arr[0]->getM() + arr[1]->getM()) << endl;//A+B CALC
	cout << arr[0]->getId() << " + " << arr[1]->getId() << "-" << arr[3]->getId() << " = " << endl;//A+B-D PRINT
	cout << (arr[0]->getM() + arr[1]->getM() - arr[3]->getM()) << endl;//A+B-D CALC
	cout << arr[0]->getId() << " * " << arr[1]->getId() << "=" << endl;//A*B PRINT
	cout << (arr[0]->getM() * arr[1]->getM()) << endl;//A*B CALC
	cout << arr[0]->getId() << " * " << arr[1]->getId() << " + " << arr[2]->getId() << " = " << endl;//a*b+c print
	cout << (arr[0]->getM() * arr[1]->getM() + arr[2]->getM()) << endl;//A*B+C CALC
	cout << " 2 " << " * " << arr[2]->getId() << " = " << endl;//2*C PRINT
	cout << (2 * arr[2]->getM()) << endl;//2*C CALC
	cout << arr[0]->getId()<< " = " << arr[0]->getId() << endl;//A=A PRINT
	cout << (arr[0]->getM() = arr[0]->getM());//A=A CALC
	cout << arr[2]->getId() <<" * "<<" 2 "<< " = " << endl;//C*2 PRINT
	cout << ( arr[2]->getM()*2) << endl;//C*2 CALC
	cout << arr[0]->getId() << " = " << arr[2]->getId() << " - " << arr[3]->getId() << endl;//A=C-D PRINT
	cout << (arr[2]->getM() - arr[3]->getM()= arr[1]->getM());//A=C-D CALC
	cout << arr[1]->getId() << " == " << arr[2]->getId() << endl;//B==C PRINT
	if (arr[1]->getM() == arr[2]->getM())//CHECK IF TRUE OR FALSE
		cout << "true" << endl;
	else
		cout << "false"<<endl;
	cout << arr[0]->getId() << " == " << arr[1]->getId() << endl;//A==B PRINT
	if (arr[0]->getM() == arr[1]->getM())//CHECK IF TRUE OR FALSE
		cout << "true" << endl;
	else
		cout << "false"<<endl;
	cout << "which matrix you want to search in it?:" << endl;
	cin >> choose;
	for (int l = 0; l < 4; l++)
	{
		if (arr[l]->getId() == choose)
		{
			cout << "which place you are looking for:please for [i][j] please give 2 numbers:" << endl;
			cin >> i >> j;
			arr[l]->getM().LookFor(i, j);
			return;
		}
	}
	cout << "the matrix you looked for is not exist." << endl;
	

}
/********************************************************************
Function name:DeleteArr
Input:pointer to pointer to arr
Output:
The function operation:free the memory.
*************************************************************************/
void Interface::DeleteArr(Types** arr)
{
	
	for (int i = 0; i < 4; i++)
	{
		//delete ;
		delete arr[i];
	}
}