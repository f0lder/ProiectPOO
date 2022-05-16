#pragma once
#include "Angajat.h"
class DB
{
public:
	
	Angajat *data;
	int numberOfElements;
	DB(int n=0) {
		numberOfElements = n;
		data = new Angajat[numberOfElements + 1];
	}
};

