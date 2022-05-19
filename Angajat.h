#pragma once
#include <fstream>
class Angajat
{
public:
	float salariu;
	int elementId=0;
	CString nume;
	CString prenume;
	int varsta;
	CString adresa;
	COleDateTime dataAngajarii;
	CString departament;
	Angajat(float s = 12.3, const char* n = "Popescu", const char* p = "Ion", int v = 0, const char* a = "Nicaieri Nicaieri Nicaieri Nicaieri ", COleDateTime d = COleDateTime::GetCurrentTime(), const char* dep = "No") {
		salariu = s;
		nume = n;
		prenume = p;
		varsta = v;
		adresa = a;
		dataAngajarii = d;
		departament = dep;
	}
	Angajat(Angajat &a) {
		elementId = a.elementId;
		salariu = a.salariu;
		nume = a.nume;
		prenume = a.prenume;
		varsta = a.varsta;
		adresa = a.adresa;
		dataAngajarii = a.dataAngajarii;
		departament = a.departament;
	}
	void write() {
		std::ofstream file;
		file.open("date.txt", std::ios::app);
		file.write((char*)&(*this), sizeof(Angajat));
		file.close();
	}
	void read() {
		std::ifstream file;
		file.open("date.txt", std::ios::in);
		file.seekg(0);
		file.read((char*)&(*this), sizeof(Angajat));
		file.close();
	}
	void save(std::ostream& data) {
		char* c = (char*)(LPCTSTR)nume;
		data.write((char*)c, 256);
	}
};

