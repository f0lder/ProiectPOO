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
	void sortById(int maxnr) {
		int i, j;
		Angajat aux;
		for ( i = 1; i < maxnr; i++) {
			for (j = 1; j < maxnr - i; j++) {
				if (data[j].elementId > data[j + 1].elementId) {
					aux = data[j];
					data[j] = data[j + 1];
					data[j + 1] = aux;
				}
			}
		}
	}
};