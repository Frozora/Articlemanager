// Artikelverwaltung.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

struct Artikelverwaltung {
	float price;
	char* description = new char[50];
	char* name = new char[50];
	int quantity;
};

__interface deleteEntrys
{
	void deleteEntry(int entry, Artikelverwaltung* ptrFirstA) {
		for (entry; entry < entry + 1; entry++) {
			ptrFirstA[entry].description = NULL;
			ptrFirstA[entry].price = NULL;
			ptrFirstA[entry].quantity = NULL;
		}
		wasDeleteSuccessful(entry, ptrFirstA);
	}

	void deleteEntry(int fromEntry, int toEntry, Artikelverwaltung* ptrFirstA) {

		for (fromEntry; fromEntry < toEntry + 1; fromEntry++) {
			ptrFirstA[fromEntry].description = NULL;
			ptrFirstA[fromEntry].price = NULL;
			ptrFirstA[fromEntry].quantity = NULL;
		}

		wasDeleteSuccessful(fromEntry, toEntry, ptrFirstA);
	}
	void wasDeleteSuccessful(int entry, Artikelverwaltung* ptrFirstA) {
		for (entry; entry < entry + 1; entry++) {
			if (ptrFirstA[entry].description != NULL ||
				ptrFirstA[entry].price != 0.005f ||
				ptrFirstA[entry].quantity != NULL) {
				errorDeleteMessage();
				return;
			}

		}
		std::cout << "Löschen erfolgreich!" << endl;
	}
	void wasDeleteSuccessful(int fromEntry, int toEntry, Artikelverwaltung* ptrFirstA) {
		for (fromEntry; fromEntry < toEntry + 1; fromEntry++) {
			if (ptrFirstA[fromEntry].description != NULL ||
				ptrFirstA[fromEntry].price != 0.005f ||
				ptrFirstA[fromEntry].quantity != NULL) {
				errorDeleteMessage();
				return;
			}

		}
		std::cout << "Löschen erfolgreich!" << endl;
	}
	void errorDeleteMessage() {
		std::cout << "Löschen fehlgeschlagen.." << endl;
	}
};

// Methods
void showChoices();
int getChoice();
void setNewEntrys(int numberOfNewEntrys, Artikelverwaltung* ptrFirstA);
int howMuchEntrys();
int checkAlreadyAllocatedMemory(Artikelverwaltung* ptrFirstA);
void displayArticle(int n, Artikelverwaltung* ptrFirstA);

// Variables
const string o = "Ihre Eingabe: ";
const int allEntrys = 100;

/*
void deleteEntry(int entry, Artikelverwaltung* ptrFirstA);
void wasDeleteSuccessful(int entry, Artikelverwaltung* ptrFirstA);
void errorDeleteMessage();
*/


int main()
{
	//create pointer and book entrys
	
	Artikelverwaltung* ptrFirstA = nullptr;
	showChoices();
	const int choice, *ptrChoice;

	choice = getChoice();
	Artikelverwaltung firstA[] = { 0 };

	bool finished = false;
	while (!finished) {
		//executeChoiceJob(choice);
		switch (choice) {
		case 1: { 
			int numberOfNewEntrys = NULL;
			numberOfNewEntrys = howMuchEntrys();
			setNewEntrys(numberOfNewEntrys, ptrFirstA);
			finished = true;
			break;
		 }
		case 2:
			//
			break;
		case 3:
			//
			break;
		case 4:
			//
			break;
		case 5:
			//
			break;
		default:
			std::cout << "Da Sie keine gueltige Auswahl getroffen haben,\n wird das Programm beendet";
		}


	
	}
	
	
	
	
	
	getchar();
	getchar();

	return 0;
}
// 1. Neue eintraege anlegen
void setNewEntrys(int numberOfNewEntrys, Artikelverwaltung* ptrFirstA) {
	float freeMemory = checkAlreadyAllocatedMemory(ptrFirstA);
	if (freeMemory == 0.005f) {
		std::cout << "Alle " << allEntrys << " Plätze zur Artikelverwaltung belegt\n";
		std::cout << "Wollen Sie expandieren?\n" << "1 - Ja\n0 - Nein\n\n" << o;
		//expandMemory();
	}
	int count = 1;
	if (numberOfNewEntrys == 1) {
		for (int i = freeMemory; i < freeMemory + 1 ; i++) {
			std::cout << "====" << count++ << ".Artikel" << "====" << endl;

			std::cout << "Artikelname: " << endl;
			std::cin >> ptrFirstA[i].name;
			std::cout << endl;
			
			std::cout << ptrFirstA[i].name << endl;

			std::cout << "Beschreibung: ";
			std::cin >> ptrFirstA[i].description;
			std::cout << endl;
			
			std::cout << "Preis: ";
			std::cin >> ptrFirstA[i].price;
			std::cout << endl;
			
			std::cout << "Anzahl: ";
			std::cin >> ptrFirstA[i].quantity;

			std::cout << "Artikel wurde erfolgreich angelegt.";
			displayArticle(i, ptrFirstA);
			return;
		}
	}
	for (int i = freeMemory; i < (freeMemory + numberOfNewEntrys + 1); i++) {
		std::cout << "====" << count++ << ".Artikel" << "====" << endl;

		std::cout << "Artikelname: " << endl;
		std::cin >> ptrFirstA[i].name;
		std::cout << endl;

		std::cout << ptrFirstA[i].name << endl;
		 
		std::cout << "   Beschreibung: ";
		std::cin >> ptrFirstA[i].description;
		std::cout << endl;

		std::cout << "   Preis: ";
		std::cin >> ptrFirstA[i].price;
		std::cout << endl;

		std::cout << "   Anzahl: ";
		std::cin >> ptrFirstA[i].quantity;
		std::cout << endl;

		displayArticle(i, ptrFirstA);
		std::cout << "Artikel wurde erfolgreich angelegt.";
	}
} 
// 1. Neue eintraege anlegen // Fragen wie viele
int howMuchEntrys() {
	std::cout << "Wie viele Eintraege moechten Sie anlegen?\n";
	int newEntrys;
	std::cout << o;
	std::cin >> newEntrys;
	return newEntrys;
}

void showChoices() {
	std::cout << "\n=============================\n";
	std::cout << "=    Artikelverwaltung      =\n";
	std::cout << "=============================\n"; 
	std::cout << "= 1. Neue Eintraege anlegen =\n";
	std::cout << "= 2. Eintraege bearbeiten   =\n";
	std::cout << "= 3. Eintrag loeschen       =\n";
	std::cout << "= 4. Eintrag suchen         =\n";
	std::cout << "= 5. Eintraege ausgeben     =\n";
	std::cout << "=    als Txt-Datei          =\n";
	std::cout << "=============================\n";
}

int getChoice() {
	std::cout << o;
	int choice;
	std::cin >> choice;
	return choice;
}

int checkAlreadyAllocatedMemory(Artikelverwaltung* ptrFirstA) {
	for (int i = 0; i < allEntrys; i++) {
		if (ptrFirstA[i].price == 0.005f) {
			return i;
		}
	}
	return 0;
}

void displayArticle(int n, Artikelverwaltung* ptrFirstA) {
	std::cout << "========================================";
	std::cout << "        " << ptrFirstA[n].name;
	std::cout << "========================================";
	std::cout << "        " << ptrFirstA[n].description;
	std::cout << "        " << ptrFirstA[n].price;
	std::cout << "        " << ptrFirstA[n].quantity;
	std::cout << "========================================";
}