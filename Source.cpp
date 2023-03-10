#include<stdio.h>
#include<stdlib.h>
#include "Clase.h"


// Numarul total de locuri este de 300 de locuri
// Categoria 1 are 150 de locuri cu 15 randuri si cu 10 locuri per rand
// Categoria 2 are 100 de locuri cu 10 randuri si cu 10 locuri per rand
// Categoria Loja are 50 de locuri cu 5 randuri si cu 10 locuri per rand


string Teatru1 = "Teatrul National Bucuresti";

string Teatru2 = "Teatrul de Comedie";

string Teatru3 = "Teatrul Odeon";


string cinematograf1 = "Cinema Europa";

string cinematograf2 = "Happy Cinema";

string cinematograf3 = "Cinema City";

string cinematograf4 = "Hollywood Mulptiplex";


string stadion1 = "National Arena";

string stadion2 = "Steaua Stadium";

string stadion3 = "Stadionul Dinamo";

string stadion4 = "Complex Sportiv National Lia Manoliu";


// Functii pe care le-am folosit

//Nume_Cinematograf:
//
//cout << "\nLa ce cinematograf doriti sa mergeti? (Cinema Europa, Happy Cinema, Cinema City, Hollywood Multiplex)\n";
//getline(cin, nume_cinematograf);
//verificare = verificare_Litere(nume_cinematograf);
//if (verificare == false)
//{
//	system("CLS");
//	cout << "\nVa rugam introduceti doar litere.\n";
//	goto Nume_Cinematograf;
//}
//if (nume_cinematograf == cinematograf1 || nume_cinematograf == cinematograf2 || nume_cinematograf == cinematograf3 || nume_cinematograf == cinematograf4)
//{
//}
//else
//{
//	cout << "\nCinematograful introdus nu face parte din lista de cinematografe disponibile\n";
//	goto Nume_Cinematograf;
//}
//
//
//Nume_Stadion:
//
//cout << "\nLa ce stadion doriti sa mergeti? (National Arena, Steaua Stadium, Stadionul Dinamo, Complex Sportiv National Lia Manoliu)\n";
//getline(cin, nume_stadion);
//verificare = verificare_Litere(nume_stadion);
//if (verificare == false)
//{
//	system("CLS");
//	cout << "\nVa rugam introduceti doar litere.\n";
//	goto Nume_Stadion;
//}
//if (nume_stadion == stadion1 || nume_stadion == stadion2 || nume_stadion == stadion3 || nume_stadion == stadion4)
//{
//}
//else
//{
//	cout << "\nStadionul introdus nu face parte din lista de stadioane disponibile\n";
//	goto Nume_Stadion;
//}





void Functie_De_Scriere()
{
	FILE* F;
	int Nr_Locuri[9] = { 150, 100, 50, 140, 90, 40, 150, 100, 50 };
	fopen_s(&F, "Fisier.dat", "wb");
	if (F != NULL)
	{
		printf("\nS-a deschis fisierul!\n");
		fwrite(&Nr_Locuri, sizeof(int) * 9, 1, F);
		fclose(F);
	}
	else
	{
		printf("\nNu s-a deschis fisierul!");
	}
}

void Citire_Fisier()
{
	int Numere_Locuri[9];
	FILE* F;
	fopen_s(&F, "Fisier.dat", "rb");
	if (F != NULL)
	{
		fread(Numere_Locuri, sizeof(int) * 9, 1, F);
		printf("\n Numerele de locuri ramase din Cateogoria 1, 2 si Loja in ordine sunt: ");
		for (int i = 0; i < 9; i++)
		{
			printf("%d, ", Numere_Locuri[i]);
		}
		printf("\n");
		fclose(F);
	}
	else
	{
		printf("\nFisierul nu s-a putut deschide!\n");
	}
}

bool Verificare_Lungime_Nr_Telefon(long Numar_de_Telefon)
{
	int i = 0;
	do
	{
		Numar_de_Telefon = Numar_de_Telefon / 10;
		i++;
	} while (Numar_de_Telefon > 0);
	if (i == 8)
		return true;
	else
		return false;
}


bool Verificare_Litere(string Ceva)
{
	char ch[10] = { '1','2','3','4','5','6','7','8','9' };
	for (int i = 0; i < 10; i++)
	{
		if (Ceva.find(ch[i]) != string::npos)
		{
			return false;
		}
	}
}



int main()
{
	int Categoria_Aleasa, Cel_mai_apropiat, r = 0;
	int Nr_Locuri[9], Nr_Locuri_Film[9], Nr_Locuri_Fotbal[9];
	string Nume, Nume_Teatru, nume_stadion, nume_cinematograf;
	long long Nr_Telefon = 0;
	bool Verificare = false;

Nume:


	printf("\nCare va fi numele de pe bilet?\n");
	getline(cin, Nume);

	Verificare = Verificare_Litere(Nume);
	if (Verificare == false)
	{
		system("CLS");
		printf("\nAti introdus un numar in nume, va rugam sa introduceti din nou!\n");
		goto Nume;
	}

Telefon:

	printf("\nCare este numarul dumneavoastra de telefon? ( Fara cifrele 07 )\n");
	cin >> Nr_Telefon;
	if (!cin)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}


	Verificare = Verificare_Lungime_Nr_Telefon(Nr_Telefon);
	if (Verificare == false)
	{
		system("CLS");
		printf("\nNumarul de telefon pe care l-ati introdus nu e corect!\nVa rugam introduceti din nou!\n");
		goto Telefon;
	}




Eveniment:
	printf("\nLa ce eveniment doriti sa mergeti?\n");
	printf("\n1. Meci de Fotbal, 2. Film, 3. Piesa de teatru\n");
	fflush(stdin);
	cin >> Categoria_Aleasa;
	if (!cin)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	if (Categoria_Aleasa == 1)
	{
		Nume_Stadion:

		cout << "\nLa ce stadion doriti sa mergeti? (National Arena, Steaua Stadium, Stadionul Dinamo, Complex Sportiv National Lia Manoliu)\n";
		getline(cin, nume_stadion);
		Verificare = Verificare_Litere(nume_stadion);
		if (Verificare == false)
		{
			system("CLS");
			cout << "\nVa rugam sa introduceti doar litere.\n";
			goto Nume_Stadion;
		}
		if (nume_stadion == stadion1 || nume_stadion == stadion2 || nume_stadion == stadion3 || nume_stadion == stadion4)
		{
		}
		else
		{
			cout << "\nStadionul introdus nu face parte din lista de stadioane disponibile\n";
			goto Nume_Stadion;
		}
	Operatie2:
		printf("\nDoriti sa mergeti la un nou meci de fotbal? (1 pentru da, 0 pentru nu)\n");
		cin >> Categoria_Aleasa;
		if (!cin)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		if (Categoria_Aleasa == 1)
		{
			FILE* F3;
			int Nr_Locuri_Fotbal[9] = { 150, 100, 50, 140, 90, 40, 150, 100, 50 };
			fopen_s(&F3, "Fisier3.dat", "wb");
			if (F3 != NULL)
			{
				printf("\nS-a deschis fisierul!\n");
				fwrite(&Nr_Locuri_Fotbal, sizeof(int) * 9, 1, F3);
				fclose(F3);
			}
			else
			{
				printf("\nNu s-a deschis fisierul!");
			}
		}
		else if (Categoria_Aleasa != 1 && Categoria_Aleasa != 0)
		{
			system("CLS");
			printf("\nNumarul dat nu face parte din operatiile date\n");
			goto Operatie2;
		}
		FILE* F3;
		fopen_s(&F3, "Fisier3.dat", "rb");
		if (F3 != NULL)
		{
			fread(Nr_Locuri_Fotbal, sizeof(int) * 9, 1, F3);
			printf("\n Numerele de locuri ramase din cele Tribuna 1, Tribuna 2 si cele de Peluza in ordine sunt: ");
			for (int i = 6; i < 9; i++)
			{
				printf("%d, ", Nr_Locuri_Fotbal[i]);
			}
			printf("\n");
			fclose(F3);
		}
		else
		{
			printf("\nFisierul nu s-a putut deschide!\n");
		}
		main3:
		printf("\nBuna Ziua, ce operatie doriti sa indepliniti?\n");
		printf("\nTastati numarul din fata operatiei pentru a incepe acea operatie: \n\n1.Creeare Tribuna 1 1\n\n2.Creeare Tribuna 2\n\n3.Creeare Ticket Peluza\n\n4.Aflare informatii despre stadion de fotbal ( Numarul maxim de locuri, Numarul de randuri, Numarul de locuri ocupate ) \n\n5.Incheiere Program\n\nCostul unui bilet de Tribuna 1 este de 30 de lei\nCostul unui bilet de Tribuna 2 este de 60 de lei\nCostul unui bilet pentru Peluza este de 120 de lei\n\n");
		cin >> Categoria_Aleasa;
		if (!cin)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		Bilete_Fotbal BFO;
		if (Categoria_Aleasa == 1)
		{
			Cel_mai_apropiat = Nr_Locuri_Fotbal[0] / 10;
			if (Nr_Locuri_Fotbal[0] / 10 >= 1 && Nr_Locuri_Fotbal[6] > 1)
			{
				if (Nr_Locuri_Fotbal[0] / 10 == 15 || Nr_Locuri_Fotbal[0] / 10 == 1)
				{

					BFO.setRand(Cel_mai_apropiat);
					BFO.setLoc(Nr_Locuri_Fotbal[0] - Nr_Locuri_Fotbal[3]);
					Nr_Locuri_Fotbal[3]++;
					Nr_Locuri_Fotbal[6]--;

				}
				else if (Nr_Locuri_Fotbal[3] == 149 || Nr_Locuri_Fotbal[3] == 9)
				{
					Nr_Locuri_Fotbal[3]++;
					BFO.setRand(Cel_mai_apropiat);
					BFO.setLoc((Nr_Locuri_Fotbal[0] + 19) - Nr_Locuri_Fotbal[3]);
					Nr_Locuri_Fotbal[3] = 1;
					Nr_Locuri_Fotbal[6]--;
				}
				else if (Nr_Locuri_Film[0] % 10 == 0)
				{
					BFO.setRand(Cel_mai_apropiat - 1);
					BFO.setLoc(Nr_Locuri_Fotbal[0] - (Cel_mai_apropiat * 10));
					Nr_Locuri_Fotbal[0]--;
					Nr_Locuri_Fotbal[6]--;
				}
				else
				{
					BFO.setRand(Cel_mai_apropiat);
					BFO.setLoc(Nr_Locuri_Fotbal[0] - (Cel_mai_apropiat * 10));
					Nr_Locuri_Fotbal[0]--;
					Nr_Locuri_Fotbal[6]--;
				}
				BFO.set_NR_telefon(Nr_Telefon);
				BFO.set_NR_consoane(Nume);
				BFO.set_ID_bilet();
				cout << "Ati ales stadionul: " << nume_stadion << endl;
				cout << endl << "Filmul: " << BFO.getDenumire() << " are loc la data de : " << BFO.getData() << " intre orele: " << BFO.getDurataSpectacol() << "." << endl;
				cout << "Biletul dumneavoastra este pe numele: " << BFO.getNumeSpectator(Nume) << " si are numarul: " << BFO.get_ID_bilet() << "." << endl;
				cout << "Sunteti la Tribuna 1 la randul : " << BFO.getRand() << " si locul : " << BFO.getLoc() << endl;
				cout << endl << "Vizionare placuta!" << endl;
			}
			else
			{
			reincercare3_1:
				printf("\nNe pare rau, nu mai exista locuri pentru aceasta categorie.\n");
				printf("\nAti dorit alt bilet la o alta categorie? ( 1 pentru da si 0 pentru nu )\n");
				scanf_s("%d", &Categoria_Aleasa);
				if (Categoria_Aleasa == 1)
				{
					system("CLS");
					printf("\nVa multumim pentru rabdare.\n");
					goto main3;
				}
				else if (Categoria_Aleasa == 0)
				{
					printf("\nNe pare rau ca nu am putut sa va ajutam!\n");
					printf("\nVa multumim pentru utilizare!\n");
				}
				else
				{
					printf("\nNu ati introdus o valoare posibila!\n");
					goto reincercare3_1;
				}
			}
		}
		else if (Categoria_Aleasa == 2)
		{
			Cel_mai_apropiat = Nr_Locuri_Fotbal[1] / 10;
			if (Nr_Locuri_Fotbal[1] / 10 >= 1 && Nr_Locuri_Fotbal[7] > 1)
			{
				if (Nr_Locuri_Fotbal[1] / 10 == 10 || Nr_Locuri_Fotbal[1] / 10 == 1)
				{

					BFO.setRand(Cel_mai_apropiat);
					BFO.setLoc(Nr_Locuri_Fotbal[1] - Nr_Locuri_Fotbal[4]);
					Nr_Locuri_Fotbal[4]++;
					Nr_Locuri_Fotbal[7]--;

				}
				else if (Nr_Locuri_Fotbal[4] == 99 || Nr_Locuri_Fotbal[4] == 9)
				{
					Nr_Locuri_Fotbal[4]++;
					BFO.setRand(Cel_mai_apropiat);
					BFO.setLoc((Nr_Locuri_Fotbal[1] + 19) - Nr_Locuri_Fotbal[4]);
					Nr_Locuri_Fotbal[4] = 1;
					Nr_Locuri_Fotbal[7]--;
				}
				else if (Nr_Locuri_Fotbal[1] % 10 == 0)
				{
					BFO.setRand(Cel_mai_apropiat - 1);
					BFO.setLoc(Nr_Locuri_Fotbal[1] - (Cel_mai_apropiat * 10));
					Nr_Locuri_Fotbal[1]--;
					Nr_Locuri_Fotbal[6]--;
				}
				else
				{
					BFO.setRand(Cel_mai_apropiat);
					BFO.setLoc(Nr_Locuri_Fotbal[1] - (Cel_mai_apropiat * 10));
					Nr_Locuri_Fotbal[1]--;
					Nr_Locuri_Fotbal[7]--;
				}
				BFO.set_NR_telefon(Nr_Telefon);
				BFO.set_NR_consoane(Nume);
				BFO.set_ID_bilet();
				cout << "Ati ales stadionul: " << nume_stadion << endl;
				cout << endl << "Meciul: " << BFO.getDenumire() << " are loc la data de : " << BFO.getData() << " intre orele: " << BFO.getDurataSpectacol() << "." << endl;
				cout << "Biletul dumneavoastra este pe numele: " << BFO.getNumeSpectator(Nume) << " si are numarul: " << BFO.get_ID_bilet() << "." << endl;
				cout << "Sunteti la Tribuna 2 la randul: " << BFO.getRand() << " si locul: " << BFO.getLoc() << endl;
				cout << endl << "Vizionare placuta!" << endl;
			}
			else
			{
			reincercare3_2:
				printf("\nNe pare rau, nu mai exista locuri pentru aceasta categorie.\n");
				printf("\nAti dorit alt bilet la o alta categorie? ( 1 pentru da si 0 pentru nu )\n");
				scanf_s("%d", &Categoria_Aleasa);
				if (Categoria_Aleasa == 1)
				{
					system("CLS");
					printf("\nVa multumim pentru rabdare.\n");
					goto main3;
				}
				else if (Categoria_Aleasa == 0)
				{
					printf("\nNe pare rau ca nu am putut sa va ajutam!\n");
					printf("\nVa multumim pentru utilizare!\n");
				}
				else
				{
					printf("\nNu ati introdus o valoare posibila!\n");
					goto reincercare3_2;
				}
			}
		}
		else if (Categoria_Aleasa == 3)
		{
			Cel_mai_apropiat = Nr_Locuri_Fotbal[2] / 10;
			if (Nr_Locuri_Fotbal[2] / 10 >= 1 && Nr_Locuri_Fotbal[8] > 1)
			{
				if (Nr_Locuri_Fotbal[2] / 10 == 5 || Nr_Locuri_Fotbal[5] / 10 == 1)
				{

					BFO.setRand(Cel_mai_apropiat);
					BFO.setLoc(Nr_Locuri_Fotbal[2] - Nr_Locuri_Fotbal[5]);
					Nr_Locuri_Fotbal[5]++;
					Nr_Locuri_Fotbal[8]--;

				}
				else if (Nr_Locuri_Fotbal[5] == 49 || Nr_Locuri_Fotbal[5] == 9)
				{
					Nr_Locuri_Fotbal[5]++;
					BFO.setRand(Cel_mai_apropiat);
					BFO.setLoc((Nr_Locuri_Fotbal[2] + 19) - Nr_Locuri_Fotbal[5]);
					Nr_Locuri_Fotbal[5] = 1;
					Nr_Locuri_Fotbal[8]--;
				}
				else if (Nr_Locuri_Fotbal[2] % 10 == 0)
				{
					BFO.setRand(Cel_mai_apropiat - 1);
					BFO.setLoc(Nr_Locuri_Fotbal[2] - (Cel_mai_apropiat * 10));
					Nr_Locuri_Fotbal[2]--;
					Nr_Locuri_Fotbal[8]--;
				}
				else
				{
					BFO.setRand(Cel_mai_apropiat);
					BFO.setLoc(Nr_Locuri_Fotbal[2] - (Cel_mai_apropiat * 10));
					Nr_Locuri_Fotbal[2]--;
					Nr_Locuri_Fotbal[8]--;
				}
				BFO.set_NR_telefon(Nr_Telefon);
				BFO.set_NR_consoane(Nume);
				BFO.set_ID_bilet();
				cout << "Ati ales stadionul: " << nume_stadion << endl;
				cout << endl << "Meciul: " << BFO.getDenumire() << " are loc la data de : " << BFO.getData() << " intre orele: " << BFO.getDurataSpectacol() << "." << endl;
				cout << "Biletul dumneavoastra este pe numele: " << BFO.getNumeSpectator(Nume) << " are numarul: " << BFO.get_ID_bilet() << "." << endl;
				cout << "Sunteti pe Peluza la randul: " << BFO.getRand() << " si locul: " << BFO.getLoc() << endl;
				cout << endl << "Vizionare placuta!" << endl;
			}
			else
			{
			reincercare3_3:
				printf("\nNe pare rau, nu mai exista locuri pentru aceasta categorie.\n");
				printf("\nAti dorit alt bilet la o alta categorie? ( 1 pentru da si 0 pentru nu )\n");
				scanf_s("%d", &Categoria_Aleasa);
				if (Categoria_Aleasa == 1)
				{
					system("CLS");
					printf("\nVa multumim pentru rabdare.\n");
					goto main3;
				}
				else if (Categoria_Aleasa == 0)
				{
					printf("\nNe pare rau ca nu am putut sa va ajutam!\n");
					printf("\nVa multumim pentru utilizare!\n");
				}
				else
				{
					printf("\nNu ati introdus o valoare posibila!\n");
					goto reincercare3_3;
				}
			}
		}
		else if (Categoria_Aleasa == 4)
		{
		A3:
			printf("\nCe doriti sa aflati despre stadionul de fotbal?\n1.Numarul total de locuri\n\n2.Numarul de locuri ocupate\n\n3.Numarul de scaune pe rand\n\n4.Data, ora si denumirea urmatorului meci\n\n");
			cin >> r;
			if (!cin)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			if (r == 1)
			{
				printf("\nNumarul total de locuri este de 300 de locuri\n");
			}
			else if (r == 2)
			{
				printf("\nNumarul total de locuri ocupate este: %d\n", (300 - (Nr_Locuri_Fotbal[6] + Nr_Locuri_Fotbal[7] + Nr_Locuri_Fotbal[8])));
				printf("\nNumarul total de locuri ramase este: %d\n", (Nr_Locuri_Fotbal[6] + Nr_Locuri_Fotbal[7] + Nr_Locuri_Fotbal[8]));
			}
			else if (r == 3)
			{
				printf("\Tribuna 1 are 15 randuri cu 10 scaune per rand\n");
				printf("\Tribuna 2 are 10 randuri cu 10 scaune per rand\n");
				printf("\Peluza are 5 randuri cu 10 scaune per rand\n");
			}
			else if (r == 4)
			{
				cout << endl << "Meciul: " << BFO.getDenumire() << " are loc la data de : " << BFO.getData() << " intre orele: " << BFO.getDurataSpectacol() << "." << endl;
			}
			else
			{
				printf("\nValoarea introdus nu face parte din comenzile meniului.");
				goto A3;
			}
		}
		else if (Categoria_Aleasa == 5)
		{
			printf("\nVa multumim pentru utilizare!\n");
			return 0;
		}
		else
		{
			printf("\nValoarea introdusa nu face parte din lista de optiuni. Doriti sa incercati din nou ( 1 pentru da si 0 pentru nu ) ");
			cin >> r;
			if (!cin)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			if (r == 1)
			{
				system("CLS");
				goto main3;
			}
			else
			{
				printf("\nVa multumim pentru utilizare!\n");
				return 0;
			}
		}
		fopen_s(&F3, "Fisier3.dat", "wb");
		if (F3 != NULL)
		{
			//printf("\nS-a deschis fisierul!\n");
			fwrite(&Nr_Locuri_Fotbal, sizeof(int) * 9, 1, F3);
			fclose(F3);
		}
		else
		{
			printf("\nNu s-a deschis fisierul!");
		}
	}
	else if (Categoria_Aleasa == 2)
	{
	Nume_Cinematograf:

		cout << "\nLa ce cinematograf doriti sa mergeti? (Cinema Europa, Happy Cinema, Cinema City, Hollywood Multiplex)\n";
		getline(cin, nume_cinematograf);
		Verificare = Verificare_Litere(nume_cinematograf);
		if (Verificare == false)
		{
			system("CLS");
			cout << "\nVa rugam introduceti doar litere.\n";
			goto Nume_Cinematograf;
		}
		if (nume_cinematograf == cinematograf1 || nume_cinematograf == cinematograf2 || nume_cinematograf == cinematograf3 || nume_cinematograf == cinematograf4)
		{
		}
		else
		{
			cout << "\nCinematograful introdus nu face parte din lista de cinematografe disponibile\n";
			goto Nume_Cinematograf;
		}
		Operatie3:
		printf("\nDoriti sa mergeti la un nou film? (1 pentru da, 0 pentru nu)\n");
		cin >> Categoria_Aleasa;
		if (!cin)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		if (Categoria_Aleasa == 1)
		{
			FILE* F2;
			int Nr_Locuri_Film[9] = { 150, 100, 50, 140, 90, 40, 150, 100, 50 };
			fopen_s(&F2, "Fisier2.dat", "wb");
			if (F2 != NULL)
			{
				printf("\nS-a deschis fisierul!\n");
				fwrite(&Nr_Locuri_Film, sizeof(int) * 9, 1, F2);
				fclose(F2);
			}
			else
			{
				printf("\nNu s-a deschis fisierul!");
			}
		}
		else if (Categoria_Aleasa != 1 && Categoria_Aleasa != 0)
		{
			system("CLS");
			printf("\nNumarul dat nu face parte din operatiile date\n");
			goto Operatie2;
		}
		FILE* F2;
		fopen_s(&F2, "Fisier2.dat", "rb");
		if (F2 != NULL)
		{
			fread(Nr_Locuri_Film, sizeof(int) * 9, 1, F2);
			printf("\n Numerele de locuri ramase din cele Normale, cele VIP si cele Ultra VIP in ordine sunt: ");
			for (int i = 6; i < 9; i++)
			{
				printf("%d, ", Nr_Locuri_Film[i]);
			}
			printf("\n");
			fclose(F2);
		}
		else
		{
			printf("\nFisierul nu s-a putut deschide!\n");
		}
	main2:
		printf("\nBuna Ziua, ce operatie doriti sa indepliniti?\n");
		printf("\nTastati numarul din fata operatiei pentru a incepe acea operatie: \n\n1.Creeare Ticket Normal 1\n\n2.Creeare Ticket VIP\n\n3.Creeare Ticket Ultra-VIP\n\n4.Aflare informatii despre sala de cinematograf ( Numarul maxim de locuri, Numarul de randuri, Numarul de locuri ocupate ) \n\n5.Incheiere Program\n\nCostul unui bilet Normal este de 30 de lei\nCostul unui bilet VIP este de 60 de lei\nCostul unui bilet Ultra VIP este de 120 de lei\n\n");
		cin >> Categoria_Aleasa;
		if (!cin)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		Bilete_Film BF;
		if (Categoria_Aleasa == 1)
		{
			Cel_mai_apropiat = Nr_Locuri_Film[0] / 10;
			if (Nr_Locuri_Film[0] / 10 >= 1 && Nr_Locuri_Film[6] > 1)
			{
				if (Nr_Locuri_Film[0] / 10 == 15 || Nr_Locuri_Film[0] / 10 == 1)
				{

					BF.setRand(Cel_mai_apropiat);
					BF.setLoc(Nr_Locuri_Film[0] - Nr_Locuri_Film[3]);
					Nr_Locuri_Film[3]++;
					Nr_Locuri_Film[6]--;

				}
				else if (Nr_Locuri_Film[3] == 149 || Nr_Locuri_Film[3] == 9)
				{
					Nr_Locuri_Film[3]++;
					BF.setRand(Cel_mai_apropiat);
					BF.setLoc((Nr_Locuri_Film[0] + 19) - Nr_Locuri_Film[3]);
					Nr_Locuri_Film[3] = 1;
					Nr_Locuri_Film[6]--;
				}
				else if (Nr_Locuri_Film[0] % 10 == 0)
				{
					BF.setRand(Cel_mai_apropiat - 1);
					BF.setLoc(Nr_Locuri_Film[0] - (Cel_mai_apropiat * 10));
					Nr_Locuri_Film[0]--;
					Nr_Locuri_Film[6]--;
				}
				else
				{
					BF.setRand(Cel_mai_apropiat);
					BF.setLoc(Nr_Locuri_Film[0] - (Cel_mai_apropiat * 10));
					Nr_Locuri_Film[0]--;
					Nr_Locuri_Film[6]--;
				}
				BF.set_NR_telefon(Nr_Telefon);
				BF.set_NR_consoane(Nume);
				BF.set_ID_bilet();
				cout << "Ati ales cinematograful: " << nume_cinematograf << endl;
				cout << endl << "Filmul: " << BF.getDenumire() << " are loc la data de : " << BF.getData() << " intre orele: " << BF.getDurataSpectacol() << "." << endl;
				cout << "Biletul dumneavoastra este pe numele: " << BF.getNumeSpectator(Nume) << " si are numarul: " << BF.get_ID_bilet() << "." << endl;
				cout << "Aveti un bilet de tip Normal la randul : " << BF.getRand() << " si locul : " << BF.getLoc() << endl;
				cout << endl << "Vizionare placuta!" << endl;
			}
			else
			{
			reincercare2_1:
				printf("\nNe pare rau, nu mai exista locuri pentru aceasta categorie.\n");
				printf("\nAti dorit alt bilet la o alta categorie? ( 1 pentru da si 0 pentru nu )\n");
				scanf_s("%d", &Categoria_Aleasa);
				if (Categoria_Aleasa == 1)
				{
					system("CLS");
					printf("\nVa multumim pentru rabdare.\n");
					goto main2;
				}
				else if (Categoria_Aleasa == 0)
				{
					printf("\nNe pare rau ca nu am putut sa va ajutam!\n");
					printf("\nVa multumim pentru utilizare!\n");
				}
				else
				{
					printf("\nNu ati introdus o valoare posibila!\n");
					goto reincercare2_1;
				}
			}
		}
		else if (Categoria_Aleasa == 2)
		{
			Cel_mai_apropiat = Nr_Locuri_Film[1] / 10;
			if (Nr_Locuri_Film[1] / 10 >= 1 && Nr_Locuri_Film[7] > 1)
			{
				if (Nr_Locuri_Film[1] / 10 == 10 || Nr_Locuri_Film[1] / 10 == 1)
				{

					BF.setRand(Cel_mai_apropiat);
					BF.setLoc(Nr_Locuri_Film[1] - Nr_Locuri_Film[4]);
					Nr_Locuri_Film[4]++;
					Nr_Locuri_Film[7]--;

				}
				else if (Nr_Locuri_Film[4] == 99 || Nr_Locuri_Film[4] == 9)
				{
					Nr_Locuri_Film[4]++;
					BF.setRand(Cel_mai_apropiat);
					BF.setLoc((Nr_Locuri_Film[1] + 19) - Nr_Locuri_Film[4]);
					Nr_Locuri_Film[4] = 1;
					Nr_Locuri_Film[7]--;
				}
				else if (Nr_Locuri_Film[1] % 10 == 0)
				{
					BF.setRand(Cel_mai_apropiat - 1);
					BF.setLoc(Nr_Locuri_Film[1] - (Cel_mai_apropiat * 10));
					Nr_Locuri_Film[1]--;
					Nr_Locuri_Film[6]--;
				}
				else
				{
					BF.setRand(Cel_mai_apropiat);
					BF.setLoc(Nr_Locuri_Film[1] - (Cel_mai_apropiat * 10));
					Nr_Locuri_Film[1]--;
					Nr_Locuri_Film[7]--;
				}
				BF.set_NR_telefon(Nr_Telefon);
				BF.set_NR_consoane(Nume);
				BF.set_ID_bilet();
				cout << "Ati ales cinematograful: " << nume_cinematograf << endl;
				cout << endl << "Filmul: " << BF.getDenumire() << " are loc la data de : " << BF.getData() << " intre orele: " << BF.getDurataSpectacol() << "." << endl;
				cout << "Biletul dumneavoastra este pe numele: " << BF.getNumeSpectator(Nume) << " si are numarul: " << BF.get_ID_bilet() << "." << endl;
				cout << "Sunteti la VIP la randul: " << BF.getRand() << " si locul: " << BF.getLoc() << endl;
				cout << endl << "Vizionare placuta!" << endl;
			}
			else
			{
			reincercare2_2:
				printf("\nNe pare rau, nu mai exista locuri pentru aceasta categorie.\n");
				printf("\nAti dorit alt bilet la o alta categorie? ( 1 pentru da si 0 pentru nu )\n");
				scanf_s("%d", &Categoria_Aleasa);
				if (Categoria_Aleasa == 1)
				{
					system("CLS");
					printf("\nVa multumim pentru rabdare.\n");
					goto main2;
				}
				else if (Categoria_Aleasa == 0)
				{
					printf("\nNe pare rau ca nu am putut sa va ajutam!\n");
					printf("\nVa multumim pentru utilizare!\n");
				}
				else
				{
					printf("\nNu ati introdus o valoare posibila!\n");
					goto reincercare2_2;
				}
			}
		}
		else if (Categoria_Aleasa == 3)
		{
			Cel_mai_apropiat = Nr_Locuri_Film[2] / 10;
			if (Nr_Locuri_Film[2] / 10 >= 1 && Nr_Locuri_Film[8] > 1)
			{
				if (Nr_Locuri_Film[2] / 10 == 5 || Nr_Locuri_Film[5] / 10 == 1)
				{

					BF.setRand(Cel_mai_apropiat);
					BF.setLoc(Nr_Locuri_Film[2] - Nr_Locuri_Film[5]);
					Nr_Locuri_Film[5]++;
					Nr_Locuri_Film[8]--;

				}
				else if (Nr_Locuri_Film[5] == 49 || Nr_Locuri_Film[5] == 9)
				{
					Nr_Locuri[5]++;
					BF.setRand(Cel_mai_apropiat);
					BF.setLoc((Nr_Locuri_Film[2] + 19) - Nr_Locuri_Film[5]);
					Nr_Locuri_Film[5] = 1;
					Nr_Locuri_Film[8]--;
				}
				else if (Nr_Locuri_Film[2] % 10 == 0)
				{
					BF.setRand(Cel_mai_apropiat - 1);
					BF.setLoc(Nr_Locuri_Film[2] - (Cel_mai_apropiat * 10));
					Nr_Locuri_Film[2]--;
					Nr_Locuri_Film[8]--;
				}
				else
				{
					BF.setRand(Cel_mai_apropiat);
					BF.setLoc(Nr_Locuri_Film[2] - (Cel_mai_apropiat * 10));
					Nr_Locuri_Film[2]--;
					Nr_Locuri_Film[8]--;
				}
				BF.set_NR_telefon(Nr_Telefon);
				BF.set_NR_consoane(Nume);
				BF.set_ID_bilet();
				cout << "Ati ales cinematograful: " << nume_cinematograf << endl;
				cout << endl << "Filmul: " << BF.getDenumire() << " are loc la data de : " << BF.getData() << " intre orele: " << BF.getDurataSpectacol() << "." << endl;
				cout << "Biletul dumneavoastra este pe numele: " << BF.getNumeSpectator(Nume) << " are numarul: " << BF.get_ID_bilet() << "." << endl;
				cout << "Sunteti la Ultra VIP la randul: " << BF.getRand() << " si locul: " << BF.getLoc() << endl;
				cout << endl << "Vizionare placuta!" << endl;
			}
			else
			{
			reincercare2_3:
				printf("\nNe pare rau, nu mai exista locuri pentru aceasta categorie.\n");
				printf("\nAti dorit alt bilet la o alta categorie? ( 1 pentru da si 0 pentru nu )\n");
				scanf_s("%d", &Categoria_Aleasa);
				if (Categoria_Aleasa == 1)
				{
					system("CLS");
					printf("\nVa multumim pentru rabdare.\n");
					goto main2;
				}
				else if (Categoria_Aleasa == 0)
				{
					printf("\nNe pare rau ca nu am putut sa va ajutam!\n");
					printf("\nVa multumim pentru utilizare!\n");
				}
				else
				{
					printf("\nNu ati introdus o valoare posibila!\n");
					goto reincercare2_3;
				}
			}
		}
		else if (Categoria_Aleasa == 4)
		{
		A2:
			printf("\nCe doriti sa aflati despre sala de cinematograf?\n1.Numarul total de locuri\n\n2.Numarul de locuri ocupate\n\n3.Numarul de scaune pe rand\n\n4.Data, ora si denumirea urmatorului spectacol\n\n");
			cin >> r;
			if (!cin)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			if (r == 1)
			{
				printf("\nNumarul total de locuri este de 300 de locuri\n");
			}
			else if (r == 2)
			{
				printf("\nNumarul total de locuri ocupate este: %d\n", (300 - (Nr_Locuri_Film[6] + Nr_Locuri_Film[7] + Nr_Locuri_Film[8])));
				printf("\nNumarul total de locuri ramase este: %d\n", (Nr_Locuri_Film[6] + Nr_Locuri_Film[7] + Nr_Locuri_Film[8]));
			}
			else if (r == 3)
			{
				printf("\nCategoria 1 are 15 randuri cu 10 scaune per rand\n");
				printf("\nCategoria 2 are 10 randuri cu 10 scaune per rand\n");
				printf("\nCategoria Loja are 5 randuri cu 10 scaune per rand\n");
			}
			else if (r == 4)
			{
				cout << endl << "Filmul: " << BF.getDenumire() << " are loc la data de : " << BF.getData() << " intre orele: " << BF.getDurataSpectacol() << "." << endl;
			}
			else
			{
				printf("\nValoarea introdus nu face parte din comenzile meniului.");
				goto A2;
			}
		}
		else if (Categoria_Aleasa == 5)
		{
			printf("\nVa multumim pentru utilizare!\n");
			return 0;
		}
		else
		{
			printf("\nValoarea introdusa nu face parte din lista de optiuni. Doriti sa incercati din nou ( 1 pentru da si 0 pentru nu ) ");
			cin >> r;
			if (!cin)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			if (r == 1)
			{
				system("CLS");
				goto main2;
			}
			else
			{
				printf("\nVa multumim pentru utilizare!\n");
				return 0;
			}
		}
		fopen_s(&F2, "Fisier2.dat", "wb");
		if (F2 != NULL)
		{
			//printf("\nS-a deschis fisierul!\n");
			fwrite(&Nr_Locuri_Film, sizeof(int) * 9, 1, F2);
			fclose(F2);
		}
		else
		{
			printf("\nNu s-a deschis fisierul!");
		}
	}
	else if (Categoria_Aleasa == 3)
	{
	Nume_Teatru:


		printf("\nLa care teatru doriti sa mergeti? (Teatrul National Bucuresti, Teatrul de Comedie, Teatrul Odeon)\n");
		getline(cin, Nume_Teatru);


		Verificare = Verificare_Litere(Nume_Teatru);
		if (Verificare == false)
		{
			system("CLS");
			printf("\nAti introdus un numar in nume, va rugam sa introduceti din nou!\n");
			goto Nume_Teatru;
		}


		if (Nume_Teatru == Teatru1 || Nume_Teatru == Teatru2 || Nume_Teatru == Teatru3)
		{
		}
		else
		{
			printf("\nTeatrul introdus nu face parte din teatrele la care va putem oferi bilete\n");
			goto Nume_Teatru;
		}
	Operatie:
		printf("\nDoriti sa mergeti la o noua piesa de teatru? (1 pentru da, 0 pentru nu)\n");
		cin >> Categoria_Aleasa;
		if (!cin)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		if (Categoria_Aleasa == 1)
		{
			FILE* F;
			int Nr_Locuri[9] = { 150, 100, 50, 140, 90, 40, 150, 100, 50 };
			fopen_s(&F, "Fisier.dat", "wb");
			if (F != NULL)
			{
				printf("\nS-a deschis fisierul!\n");
				fwrite(&Nr_Locuri, sizeof(int) * 9, 1, F);
				fclose(F);
			}
			else
			{
				printf("\nNu s-a deschis fisierul!");
			}
		}
		else if (Categoria_Aleasa != 1 && Categoria_Aleasa != 0)
		{
			system("CLS");
			printf("\nNumarul dat nu face parte din operatiile date\n");
			goto Operatie;
		}
		FILE* F;
		fopen_s(&F, "Fisier.dat", "rb");
		if (F != NULL)
		{
			fread(Nr_Locuri, sizeof(int) * 9, 1, F);
			printf("\n Numerele de locuri ramase din Cateogoria 1, 2 si Loja in ordine sunt: ");
			for (int i = 6; i < 9; i++)
			{
				printf("%d, ", Nr_Locuri[i]);
			}
			printf("\n");
			fclose(F);
		}
		else
		{
			printf("\nFisierul nu s-a putut deschide!\n");
		}
	main:
		printf("\nBuna Ziua, ce operatie doriti sa indepliniti?\n");
		printf("\nTastati numarul din fata operatiei pentru a incepe acea operatie: \n\n1.Creeare Ticket Categorie 1\n\n2.Creeare Ticket Categorie 2\n\n3.Creeare Ticket Loja\n\n4.Aflare informatii despre sala de teatru ( Numarul maxim de locuri, Numarul de randuri, Numarul de locuri ocupate ) \n\n5.Incheiere Program\n\nCostul unui bilet din Categoria 1 este de 30 de lei\nCostul unui bilet din Categoria 2 este de 60 de lei\nCostul unui bilet din Categoria 3 este de 120 de lei\n\n");
		cin >> Categoria_Aleasa;
		if (!cin)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		Bilete_Teatru BT;
		if (Categoria_Aleasa == 1)
		{
			Cel_mai_apropiat = Nr_Locuri[0] / 10;
			if (Nr_Locuri[0] / 10 >= 1 && Nr_Locuri[6] > 1)
			{
				if (Nr_Locuri[0] / 10 == 15 || Nr_Locuri[0] / 10 == 1)
				{

					BT.setRand(Cel_mai_apropiat);
					BT.setLoc(Nr_Locuri[0] - Nr_Locuri[3]);
					Nr_Locuri[3]++;
					Nr_Locuri[6]--;

				}
				else if (Nr_Locuri[3] == 149 || Nr_Locuri[3] == 9)
				{
					Nr_Locuri[3]++;
					BT.setRand(Cel_mai_apropiat);
					BT.setLoc((Nr_Locuri[0] + 19) - Nr_Locuri[3]);
					Nr_Locuri[3] = 1;
					Nr_Locuri[6]--;
				}
				else if (Nr_Locuri[0] % 10 == 0)
				{
					BT.setRand(Cel_mai_apropiat - 1);
					BT.setLoc(Nr_Locuri[0] - (Cel_mai_apropiat * 10));
					Nr_Locuri[0]--;
					Nr_Locuri[6]--;
				}
				else
				{
					BT.setRand(Cel_mai_apropiat);
					BT.setLoc(Nr_Locuri[0] - (Cel_mai_apropiat * 10));
					Nr_Locuri[0]--;
					Nr_Locuri[6]--;
				}
				BT.set_NR_telefon(Nr_Telefon);
				BT.set_NR_consoane(Nume);
				BT.set_ID_bilet();
				cout << "Ati ales teatrul: " << Nume_Teatru << endl;
				cout << endl << "Spectacolul: " << BT.getDenumire() << " are loc la data de : " << BT.getData() << " intre orele: " << BT.getDurataSpectacol() << "." << endl;
				cout << "Biletul dumneavoastra este pe numele: " << BT.getNumeSpectator(Nume) << " are numarul: " << BT.get_ID_bilet() << "." << endl;
				cout << "Sunteti la Categoria 1 la randul : " << BT.getRand() << " si locul : " << BT.getLoc() << endl;
				cout << endl << "Vizionare placuta!" << endl;
			}
			else
			{
			reincercare1:
				printf("\nNe pare rau, nu mai exista locuri pentru aceasta categorie.\n");
				printf("\nAti dorit alt bilet la o alta categorie? ( 1 pentru da si 0 pentru nu )\n");
				scanf_s("%d", &Categoria_Aleasa);
				if (Categoria_Aleasa == 1)
				{
					system("CLS");
					printf("\nVa multumim pentru rabdare.\n");
					goto main;
				}
				else if (Categoria_Aleasa == 0)
				{
					printf("\nNe pare rau ca nu am putut sa va ajutam!\n");
					printf("\nVa multumim pentru utilizare!\n");
				}
				else
				{
					printf("\nNu ati introdus o valoare posibila!\n");
					goto reincercare1;
				}
			}
		}
		else if (Categoria_Aleasa == 2)
		{
			Cel_mai_apropiat = Nr_Locuri[1] / 10;
			if (Nr_Locuri[1] / 10 >= 1 && Nr_Locuri[7] > 1)
			{
				if (Nr_Locuri[1] / 10 == 10 || Nr_Locuri[1] / 10 == 1)
				{

					BT.setRand(Cel_mai_apropiat);
					BT.setLoc(Nr_Locuri[1] - Nr_Locuri[4]);
					Nr_Locuri[4]++;
					Nr_Locuri[7]--;

				}
				else if (Nr_Locuri[4] == 99 || Nr_Locuri[4] == 9)
				{
					Nr_Locuri[4]++;
					BT.setRand(Cel_mai_apropiat);
					BT.setLoc((Nr_Locuri[1] + 19) - Nr_Locuri[4]);
					Nr_Locuri[4] = 1;
					Nr_Locuri[7]--;
				}
				else if (Nr_Locuri[1] % 10 == 0)
				{
					BT.setRand(Cel_mai_apropiat - 1);
					BT.setLoc(Nr_Locuri[1] - (Cel_mai_apropiat * 10));
					Nr_Locuri[1]--;
					Nr_Locuri[6]--;
				}
				else
				{
					BT.setRand(Cel_mai_apropiat);
					BT.setLoc(Nr_Locuri[1] - (Cel_mai_apropiat * 10));
					Nr_Locuri[1]--;
					Nr_Locuri[7]--;
				}
				BT.set_NR_telefon(Nr_Telefon);
				BT.set_NR_consoane(Nume);
				BT.set_ID_bilet();
				cout << "Ati ales teatrul: " << Nume_Teatru << endl;
				cout << endl << "Spectacolul: " << BT.getDenumire() << " are loc la data de : " << BT.getData() << " intre orele: " << BT.getDurataSpectacol() << "." << endl;
				cout << "Biletul dumneavoastra este pe numele: " << BT.getNumeSpectator(Nume) << " are numarul: " << BT.get_ID_bilet() << "." << endl;
				cout << "Sunteti la Categoria 2 la randul: " << BT.getRand() << " si locul: " << BT.getLoc() << endl;
				cout << endl << "Vizionare placuta!" << endl;
			}
			else
			{
			reincercare2:
				printf("\nNe pare rau, nu mai exista locuri pentru aceasta categorie.\n");
				printf("\nAti dorit alt bilet la o alta categorie? ( 1 pentru da si 0 pentru nu )\n");
				scanf_s("%d", &Categoria_Aleasa);
				if (Categoria_Aleasa == 1)
				{
					system("CLS");
					printf("\nVa multumim pentru rabdare.\n");
					goto main;
				}
				else if (Categoria_Aleasa == 0)
				{
					printf("\nNe pare rau ca nu am putut sa va ajutam!\n");
					printf("\nVa multumim pentru utilizare!\n");
				}
				else
				{
					printf("\nNu ati introdus o valoare posibila!\n");
					goto reincercare2;
				}
			}
		}
		else if (Categoria_Aleasa == 3)
		{
			Cel_mai_apropiat = Nr_Locuri[2] / 10;
			if (Nr_Locuri[2] / 10 >= 1 && Nr_Locuri[8] > 1)
			{
				if (Nr_Locuri[2] / 10 == 5 || Nr_Locuri[5] / 10 == 1)
				{

					BT.setRand(Cel_mai_apropiat);
					BT.setLoc(Nr_Locuri[2] - Nr_Locuri[5]);
					Nr_Locuri[5]++;
					Nr_Locuri[8]--;

				}
				else if (Nr_Locuri[5] == 49 || Nr_Locuri[5] == 9)
				{
					Nr_Locuri[5]++;
					BT.setRand(Cel_mai_apropiat);
					BT.setLoc((Nr_Locuri[2] + 19) - Nr_Locuri[5]);
					Nr_Locuri[5] = 1;
					Nr_Locuri[8]--;
				}
				else if (Nr_Locuri[2] % 10 == 0)
				{
					BT.setRand(Cel_mai_apropiat - 1);
					BT.setLoc(Nr_Locuri[2] - (Cel_mai_apropiat * 10));
					Nr_Locuri[2]--;
					Nr_Locuri[8]--;
				}
				else
				{
					BT.setRand(Cel_mai_apropiat);
					BT.setLoc(Nr_Locuri[2] - (Cel_mai_apropiat * 10));
					Nr_Locuri[2]--;
					Nr_Locuri[8]--;
				}
				BT.set_NR_telefon(Nr_Telefon);
				BT.set_NR_consoane(Nume);
				BT.set_ID_bilet();
				cout << "Ati ales teatrul: " << Nume_Teatru << endl;
				cout << endl << "Spectacolul: " << BT.getDenumire() << " are loc la data de : " << BT.getData() << " intre orele: " << BT.getDurataSpectacol() << "." << endl;
				cout << "Biletul dumneavoastra este pe numele: " << BT.getNumeSpectator(Nume) << " are numarul: " << BT.get_ID_bilet() << "." << endl;
				cout << "Sunteti la Loja la randul: " << BT.getRand() << " si locul: " << BT.getLoc() << endl;
				cout << endl << "Vizionare placuta!" << endl;
			}
			else
			{
			reincercare3:
				printf("\nNe pare rau, nu mai exista locuri pentru aceasta categorie.\n");
				printf("\nAti dorit alt bilet la o alta categorie? ( 1 pentru da si 0 pentru nu )\n");
				scanf_s("%d", &Categoria_Aleasa);
				if (Categoria_Aleasa == 1)
				{
					system("CLS");
					printf("\nVa multumim pentru rabdare.\n");
					goto main;
				}
				else if (Categoria_Aleasa == 0)
				{
					printf("\nNe pare rau ca nu am putut sa va ajutam!\n");
					printf("\nVa multumim pentru utilizare!\n");
				}
				else
				{
					printf("\nNu ati introdus o valoare posibila!\n");
					goto reincercare3;
				}
			}
		}
		else if (Categoria_Aleasa == 4)
		{
		A:
			printf("\nCe doriti sa aflati despre sala de teatru?\n1.Numarul total de locuri\n\n2.Numarul de locuri ocupate\n\n3.Numarul de scaune pe rand\n\n4.Data, ora si denumirea urmatorului spectacol\n\n");
			cin >> r;
			if (!cin)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			if (r == 1)
			{
				printf("\nNumarul total de locuri este de 300 de locuri\n");
			}
			else if (r == 2)
			{
				printf("\nNumarul total de locuri ocupate este: %d\n", (300 - (Nr_Locuri[6] + Nr_Locuri[7] + Nr_Locuri[8])));
				printf("\nNumarul total de locuri ramase este: %d\n", (Nr_Locuri[6] + Nr_Locuri[7] + Nr_Locuri[8]));
			}
			else if (r == 3)
			{
				printf("\nCategoria 1 are 15 randuri cu 10 scaune per rand\n");
				printf("\nCategoria 2 are 10 randuri cu 10 scaune per rand\n");
				printf("\nCategoria Loja are 5 randuri cu 10 scaune per rand\n");
			}
			else if (r == 4)
			{
				cout << endl << "Spectacolul: " << BT.getDenumire() << " are loc la data de : " << BT.getData() << " intre orele: " << BT.getDurataSpectacol() << "." << endl;
			}
			else
			{
				printf("\nValoarea introdus nu face parte din comenzile meniului.");
				goto A;
			}
		}
		else if (Categoria_Aleasa == 5)
		{
			printf("\nVa multumim pentru utilizare!\n");
			return 0;
		}
		else
		{
			printf("\nValoarea introdusa nu face parte din lista de optiuni. Doriti sa incercati din nou ( 1 pentru da si 0 pentru nu ) ");
			cin >> r;
			if (!cin)
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			if (r == 1)
			{
				system("CLS");
				goto main;
			}
			else
			{
				printf("\nVa multumim pentru utilizare!\n");
				return 0;
			}
		}
		fopen_s(&F, "Fisier.dat", "wb");
		if (F != NULL)
		{
			//printf("\nS-a deschis fisierul!\n");
			fwrite(&Nr_Locuri, sizeof(int) * 9, 1, F);
			fclose(F);
		}
		else
		{
			printf("\nNu s-a deschis fisierul!");
		}
	}
	else
	{
		printf("\nValoarea introdusa nu face parte din operatiile aratate\n");
		goto Eveniment;
	}
	return 0;
}
