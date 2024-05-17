/*Moshe Hershkovitz 313123150 07*/
#include "Interface.h"
#define _CRTDBG_MAP_ALLOC


int main()
{
	//checking for memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Interface::setMatrices();//send to interface

	
	return 0;
}