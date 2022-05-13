#pragma once
class Angajat
{
public:
	int elementId=3;
	CString nume;
	CString prenume;
	int varsta;
	CString adresa;
	COleDateTime dataAngajarii;
	CString departament;
	Angajat(const char* n = "", const char* p = "", int v = 0,const char* a="",COleDateTime d=COleDateTime::GetCurrentTime(), const char* dep = "") {
		elementId = Angajat::elementId;
		nume = n;
		prenume = p;
		varsta = v;
		adresa = a;
		dataAngajarii = d;
		departament = dep;
		Angajat::elementId++;
	}
	Angajat(Angajat &a) {
		elementId = a.elementId + 1;
		nume = a.nume;
		prenume = a.prenume;
		varsta = a.varsta;
		adresa = a.adresa;
		dataAngajarii = a.dataAngajarii;
		departament = a.departament;
		Angajat::elementId++;
	}
};

