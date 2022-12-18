#pragma once
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

// 15 randuri de cate 10 locuri pentru Categoria 1
// 10 randuri de cate 10 locuri pentru Categoria 2
// 5 randuri de cate 10 locuri pentru Loja

/*
*
*
*
* Matricea Categoria 1 [15][max 10]
* Matricea Categoria 2 [10][max 10]
* Matricea Loja [5][max 10]
*
*
* int MC1[15][10]
* int MC2[10][10]
* int MC3[5][10]
*
*
*
*
*
*
*
*/

// Clasa Teatru

class Bilete_Teatru
{
private:
	char* spectator;
	long nr_telefon;
	long id_bilet;
	int nr_consoane;
	string tip_bilet;
	static int Nr_Total_Locuri;
	const string Oras = "Bucuresti";
	int locuri_ocupate;
	int Rand;
	int Loc;
	string denumire;
	string data;
	string durata_spectacol;
	int pret;
	friend Bilete_Teatru operator+(int valoare, Bilete_Teatru BT);
	friend Bilete_Teatru operator-(int valoare, Bilete_Teatru BT);
	friend ostream& operator<<(ostream& out, Bilete_Teatru BT);
	friend istream& operator>>(istream& in, Bilete_Teatru& BT);
public:
	Bilete_Teatru() : Oras("Bucuresti")
	{
		nr_consoane = 0;
		denumire = "O noapte furtunoasa";
		tip_bilet = "Categoria 1";
		data = "23.01.2003";
		durata_spectacol = "20:30 - 22:30";
		Nr_Total_Locuri = 300;
		Rand = 15;
		Loc = 10;
		pret = 60;
	}

	Bilete_Teatru(const char* spectator, long id_bilet, long nr_telefon, int nr_consoane, string tip_bilet, int Rand, int Loc, string denumire, string data, string durata_spectacol, string Oras) : Oras("Bucuresti")
	{
		this->nr_telefon = nr_telefon;
		this->id_bilet = id_bilet;
		this->nr_consoane = nr_consoane;
		this->tip_bilet = tip_bilet;
		this->Loc = Loc;
		this->Rand = Rand;
		this->denumire = denumire;
		this->data = data;
		this->durata_spectacol = durata_spectacol;
		if (spectator != nullptr)
		{
			this->spectator = new char[strlen(spectator) + 1];
			strcpy_s(this->spectator, strlen(spectator) + 1, spectator);
		}
	}

	Bilete_Teatru(const Bilete_Teatru& s) : Oras("Bucuresti")
	{
		this->nr_telefon = s.nr_telefon;
		this->id_bilet = s.id_bilet;
		this->nr_consoane = s.nr_consoane;
		this->tip_bilet = s.tip_bilet;
		this->denumire = s.denumire;
		this->Rand = s.Rand;
		this->Loc = s.Loc;
		this->data = s.data;
		if (spectator != nullptr)
		{
			this->spectator = new char[strlen(s.spectator) + 1];
			strcpy_s(this->spectator, strlen(s.spectator) + 1, s.spectator);
		}
		else
			this->spectator = nullptr;
	}

	Bilete_Teatru& operator=(const Bilete_Teatru i)
	{
		if (this != &i)
		{
			if (spectator != nullptr)
			{
				this->spectator = new char[strlen(i.spectator) + 1];
				strcpy_s(this->spectator, strlen(i.spectator) + 1, i.spectator);
			}
			else
				this->spectator = nullptr;
		}
		return *this;
	}

	long get_NR_telefon()
	{
		return nr_telefon;
	}

	int getLoc()
	{
		return Loc;
	}

	int getRand()
	{
		return Rand;
	}

	void setRand(int n)
	{
		Rand = n;
	}

	void setLoc(int n)
	{
		Loc = n;
	}

	string getData()
	{
		return data;
	}

	string getTip_Bilet()
	{
		return tip_bilet;
	}

	string getDenumire()
	{
		return denumire;
	}

	string getDurataSpectacol()
	{
		return durata_spectacol;
	}

	char* getNumeSpectator(string Nume)
	{
		const char* spectator = Nume.data();
		if (spectator != nullptr) {
			char* copy = new char[strlen(spectator) + 1];
			for (int i = 0; i < (strlen(spectator) + 1); i++) {
				copy[i] = spectator[i];
			}
			return copy;
		}
		else return nullptr;
	}
	bool consoane(char ch) {
		ch = toupper(ch);
		return !(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') && ch >= 65 && ch <= 90;
	}
	void set_NR_consoane(string Nume) {
		for (int i = 0; i < Nume.length(); i++) {
			if (consoane(Nume[i])) {
				++nr_consoane;
			}
		}
	}

		void set_NR_telefon(long numar)
		{
			nr_telefon = numar;
		}

		int get_NR_consoane()
		{
			return nr_consoane;
		}

		void set_ID_bilet()
		{
			id_bilet = get_NR_telefon();
			id_bilet = id_bilet * 10 + get_NR_consoane();
		}

		long get_ID_bilet()
		{
			return id_bilet;
		}

		static void setNr_Locuri(int Nr_Total_Locuri)
		{
			Bilete_Teatru::Nr_Total_Locuri = Nr_Total_Locuri;
		}

		static int getNr_Locuri()
		{
			return Nr_Total_Locuri;
		}

		~Bilete_Teatru()
		{
			if (spectator != nullptr)
				delete[] this->spectator;
		}
};
int Bilete_Teatru::Nr_Total_Locuri = 300;
Bilete_Teatru operator+(int valoare, Bilete_Teatru BT)
{
	BT.pret += valoare;
	return BT;
}
Bilete_Teatru operator-(int valoare, Bilete_Teatru BT)
{
	BT.Nr_Total_Locuri -= valoare;
	return BT;
}
ostream& operator<<(ostream& out, Bilete_Teatru BT)
{
	out << "Numele de pe bilet este: " << BT.spectator << endl;
	out << "Numarul biletului dumneavoastra este: ";
	out << BT.id_bilet;
	out << endl;
	out << "Denumirea spectacol: " << BT.denumire << endl;
	out << "Tipul biletului: " << BT.tip_bilet << endl;
	out << "Intervalul orar: " << BT.durata_spectacol << endl;
	return out;
}
istream& operator>>(istream& in, Bilete_Teatru& BT)
{
	cout << "Care este numele dumneavoastra? " << endl;
	in >> BT.spectator;
	return in;
}




// Clasa Film

class Bilete_Film
{
private:
	char* spectator;
	long nr_telefon;
	long id_bilet;
	int nr_consoane;
	string tip_bilet;
	static int Nr_Total_Locuri;
	const string Oras = "Bucuresti";
	int locuri_ocupate;
	int Rand;
	int Loc;
	string denumire;
	string data;
	string durata_film;
	int pret;
	friend Bilete_Film operator+(int valoare, Bilete_Film BF);
	friend Bilete_Film operator-(int valoare, Bilete_Film BF);
	friend ostream& operator<<(ostream& out, Bilete_Film BF);
	friend istream& operator>>(istream& in, Bilete_Film& BF);
public:
	Bilete_Film() : Oras("Bucuresti")
	{
		nr_consoane = 0;
		denumire = "Mission Impossible";
		tip_bilet = "Normal";
		data = "12.02.2003";
		durata_film = "15:30 - 17:30";
		Nr_Total_Locuri = 300;
		Rand = 15;
		Loc = 10;
		pret = 60;
	}

	Bilete_Film(const char* spectator, long id_bilet, long nr_telefon, int nr_consoane, string tip_bilet, int Rand, int Loc, string denumire, string data, string durata_film, string Oras) : Oras("Bucuresti")
	{
		this->nr_telefon = nr_telefon;
		this->id_bilet = id_bilet;
		this->nr_consoane = nr_consoane;
		this->tip_bilet = tip_bilet;
		this->Loc = Loc;
		this->Rand = Rand;
		this->denumire = denumire;
		this->data = data;
		this->durata_film = durata_film;
		if (spectator != nullptr)
		{
			this->spectator = new char[strlen(spectator) + 1];
			strcpy_s(this->spectator, strlen(spectator) + 1, spectator);
		}
	}

	Bilete_Film(const Bilete_Film& s) : Oras("Bucuresti")
	{
		this->nr_telefon = s.nr_telefon;
		this->id_bilet = s.id_bilet;
		this->nr_consoane = s.nr_consoane;
		this->tip_bilet = s.tip_bilet;
		this->denumire = s.denumire;
		this->Rand = s.Rand;
		this->Loc = s.Loc;
		this->data = s.data;
		if (spectator != nullptr)
		{
			this->spectator = new char[strlen(s.spectator) + 1];
			strcpy_s(this->spectator, strlen(s.spectator) + 1, s.spectator);
		}
		else
			this->spectator = nullptr;
	}

	Bilete_Film& operator=(const Bilete_Film i)
	{
		if (this != &i)
		{
			if (spectator != nullptr)
			{
				this->spectator = new char[strlen(i.spectator) + 1];
				strcpy_s(this->spectator, strlen(i.spectator) + 1, i.spectator);
			}
			else
				this->spectator = nullptr;
		}
		return *this;
	}

	long get_NR_telefon()
	{
		return nr_telefon;
	}

	int getLoc()
	{
		return Loc;
	}

	int getRand()
	{
		return Rand;
	}

	void setRand(int n)
	{
		Rand = n;
	}

	void setLoc(int n)
	{
		Loc = n;
	}

	string getData()
	{
		return data;
	}

	string getTip_Bilet()
	{
		return tip_bilet;
	}

	string getDenumire()
	{
		return denumire;
	}

	string getDurataSpectacol()
	{
		return durata_film;
	}

	char* getNumeSpectator(string Nume)
	{
		const char* spectator = Nume.data();
		if (spectator != nullptr) {
			char* copy = new char[strlen(spectator) + 1];
			for (int i = 0; i < (strlen(spectator) + 1); i++) {
				copy[i] = spectator[i];
			}
			return copy;
		}
		else return nullptr;
	}
	bool consoane(char ch) {
		ch = toupper(ch);
		return !(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') && ch >= 65 && ch <= 90;
	}
	void set_NR_consoane(string Nume) {
		for (int i = 0; i < Nume.length(); i++) {
			if (consoane(Nume[i])) {
				++nr_consoane;
			}
		}
	}

	void set_NR_telefon(long numar)
	{
		nr_telefon = numar;
	}

	int get_NR_consoane()
	{
		return nr_consoane;
	}

	void set_ID_bilet()
	{
		id_bilet = get_NR_telefon();
		id_bilet = id_bilet * 10 + get_NR_consoane();
	}

	long get_ID_bilet()
	{
		return id_bilet;
	}

	static void setNr_Locuri(int Nr_Total_Locuri)
	{
		Bilete_Film::Nr_Total_Locuri = Nr_Total_Locuri;
	}

	static int getNr_Locuri()
	{
		return Nr_Total_Locuri;
	}

	~Bilete_Film()
	{
		if (spectator != nullptr)
			delete[] this->spectator;
	}
};
int Bilete_Film::Nr_Total_Locuri = 300;
Bilete_Film operator+(int valoare, Bilete_Film BF)
{
	BF.pret += valoare;
	return BF;
}
Bilete_Film operator-(int valoare, Bilete_Film BF)
{
	BF.Nr_Total_Locuri -= valoare;
	return BF;
}
ostream& operator<<(ostream& out, Bilete_Film BF)
{
	out << "Numele de pe bilet este: " << BF.spectator << endl;
	out << "Numarul biletului dumneavoastra este: ";
	out << BF.id_bilet;
	out << endl;
	out << "Denumirea Filmului: " << BF.denumire << endl;
	out << "Tipul biletului: " << BF.tip_bilet << endl;
	out << "Intervalul orar: " << BF.durata_film << endl;
	return out;
}
istream& operator>>(istream& in, Bilete_Film& BF)
{
	cout << "Care este numele dumneavoastra? " << endl;
	in >> BF.spectator;
	return in;
}




//Clasa Fotbal

class Bilete_Fotbal
{
private:
	char* spectator;
	long nr_telefon;
	long id_bilet;
	int nr_consoane;
	string tip_bilet;
	static int Nr_Total_Locuri;
	const string Oras = "Bucuresti";
	int locuri_ocupate;
	int Rand;
	int Loc;
	string denumire;
	string data;
	string durata_meci;
	int pret;
	friend Bilete_Fotbal operator+(int valoare, Bilete_Fotbal BFO);
	friend Bilete_Fotbal operator-(int valoare, Bilete_Fotbal BFO);
	friend ostream& operator<<(ostream& out, Bilete_Fotbal BFO);
	friend istream& operator>>(istream& in, Bilete_Fotbal& BFO);
public:
	Bilete_Fotbal() : Oras("Bucuresti")
	{
		nr_consoane = 0;
		denumire = "Rapid vs Steaua";
		tip_bilet = "Tribuna 1";
		data = "1.12.2020";
		durata_meci = "15:00 - 16:30";
		Nr_Total_Locuri = 300;
		Rand = 15;
		Loc = 10;
		pret = 60;
	}

	Bilete_Fotbal(const char* spectator, long id_bilet, long nr_telefon, int nr_consoane, string tip_bilet, int Rand, int Loc, string denumire, string data, string durata_meci, string Oras) : Oras("Bucuresti")
	{
		this->nr_telefon = nr_telefon;
		this->id_bilet = id_bilet;
		this->nr_consoane = nr_consoane;
		this->tip_bilet = tip_bilet;
		this->Loc = Loc;
		this->Rand = Rand;
		this->denumire = denumire;
		this->data = data;
		this->durata_meci = durata_meci;
		if (spectator != nullptr)
		{
			this->spectator = new char[strlen(spectator) + 1];
			strcpy_s(this->spectator, strlen(spectator) + 1, spectator);
		}
	}

	Bilete_Fotbal(const Bilete_Fotbal& s) : Oras("Bucuresti")
	{
		this->nr_telefon = s.nr_telefon;
		this->id_bilet = s.id_bilet;
		this->nr_consoane = s.nr_consoane;
		this->tip_bilet = s.tip_bilet;
		this->denumire = s.denumire;
		this->Rand = s.Rand;
		this->Loc = s.Loc;
		this->data = s.data;
		if (spectator != nullptr)
		{
			this->spectator = new char[strlen(s.spectator) + 1];
			strcpy_s(this->spectator, strlen(s.spectator) + 1, s.spectator);
		}
		else
			this->spectator = nullptr;
	}

	Bilete_Fotbal& operator=(const Bilete_Fotbal i)
	{
		if (this != &i)
		{
			if (spectator != nullptr)
			{
				this->spectator = new char[strlen(i.spectator) + 1];
				strcpy_s(this->spectator, strlen(i.spectator) + 1, i.spectator);
			}
			else
				this->spectator = nullptr;
		}
		return *this;
	}

	long get_NR_telefon()
	{
		return nr_telefon;
	}

	int getLoc()
	{
		return Loc;
	}

	int getRand()
	{
		return Rand;
	}

	void setRand(int n)
	{
		Rand = n;
	}

	void setLoc(int n)
	{
		Loc = n;
	}

	string getData()
	{
		return data;
	}

	string getTip_Bilet()
	{
		return tip_bilet;
	}

	string getDenumire()
	{
		return denumire;
	}

	string getDurataSpectacol()
	{
		return durata_meci;
	}

	char* getNumeSpectator(string Nume)
	{
		const char* spectator = Nume.data();
		if (spectator != nullptr) {
			char* copy = new char[strlen(spectator) + 1];
			for (int i = 0; i < (strlen(spectator) + 1); i++) {
				copy[i] = spectator[i];
			}
			return copy;
		}
		else return nullptr;
	}
	bool consoane(char ch) {
		ch = toupper(ch);
		return !(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') && ch >= 65 && ch <= 90;
	}
	void set_NR_consoane(string Nume) {
		for (int i = 0; i < Nume.length(); i++) {
			if (consoane(Nume[i])) {
				++nr_consoane;
			}
		}
	}

	void set_NR_telefon(long numar)
	{
		nr_telefon = numar;
	}

	int get_NR_consoane()
	{
		return nr_consoane;
	}

	void set_ID_bilet()
	{
		id_bilet = get_NR_telefon();
		id_bilet = id_bilet * 10 + get_NR_consoane();
	}

	long get_ID_bilet()
	{
		return id_bilet;
	}

	static void setNr_Locuri(int Nr_Total_Locuri)
	{
		Bilete_Fotbal::Nr_Total_Locuri = Nr_Total_Locuri;
	}

	static int getNr_Locuri()
	{
		return Nr_Total_Locuri;
	}

	~Bilete_Fotbal()
	{
		if (spectator != nullptr)
			delete[] this->spectator;
	}
};
int Bilete_Fotbal::Nr_Total_Locuri = 300;
Bilete_Fotbal operator+(int valoare, Bilete_Fotbal BFO)
{
	BFO.pret += valoare;
	return BFO;
}
Bilete_Fotbal operator-(int valoare, Bilete_Fotbal BFO)
{
	BFO.Nr_Total_Locuri -= valoare;
	return BFO;
}
ostream& operator<<(ostream& out, Bilete_Fotbal BFO)
{
	out << "Numele de pe bilet este: " << BFO.spectator << endl;
	out << "Numarul biletului dumneavoastra este: ";
	out << BFO.id_bilet;
	out << endl;
	out << "Denumirea spectacol: " << BFO.denumire << endl;
	out << "Tipul biletului: " << BFO.tip_bilet << endl;
	out << "Intervalul orar: " << BFO.durata_meci << endl;
	return out;
}
istream& operator>>(istream& in, Bilete_Fotbal& BFO)
{
	cout << "Care este numele dumneavoastra? " << endl;
	in >> BFO.spectator;
	return in;
}