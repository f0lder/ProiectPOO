#pragma once
#include "Angajat.h"
class DB
{
public:
	Angajat *data;
	int numberOfElements;
	DB() {
		 data = new Angajat[numberOfElements + 1];
	}
};

