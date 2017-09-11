#include "library.h"


/////////// -> menuInvData ////////////////////////////
void Menu::menuInvData(int n, DataBase *wsk) {
	int now = n;
	bool m = true;
	while (m) {
		cout << endl << " Dane Faktury -> WYBIERZ OPCJE : " << endl;
		cout << "  [1]->>[ Numer ]" << endl;
		cout << "  [2]->>[ Forma platnosci ]" << endl;
		cout << "  [3]->>[ Data wystawienia ]" << endl;
		cout << "  [4]->>[ Data sprzedazy ]" << endl;
		cout << "  [5]->>[ Data zaplaty] " << endl;
		cout << "  [0]->>[ POWROT DO MENU ]" << endl;
		cout << "----------------------------------- " << endl;
		cout << " wybieram opcje nr: ";
		string choice;
		cin >> choice;
		if (choice == "1") {
			cout << " -> podaj numer fakury: ";
			string str;
			cin >> str;
			wsk->vecInvo[now].number = str;
			wsk->vecInvo[now].getInfo();
		}
		else if (choice == "2") {
			cout << " -> podaj forme platnosci: ";
			string str;
			cin >> str;
			wsk->vecInvo[now].payForm = str;
			wsk->vecInvo[now].getInfo();
		}
		else if (choice == "3") {
			cout << " -> podaj date wystawienia (cyfy) : " << endl;
			wsk->vecInvo[now].invDate.menuData();
			wsk->vecInvo[now].getInfo();
		}
		else if (choice == "4") {
			cout << " -> podaj date sprzedazy (cyfry) : " << endl;
			wsk->vecInvo[now].sellDate.menuData();
			wsk->vecInvo[now].getInfo();
		}
		else if (choice == "5") {
			cout << " -> podaj date zaplaty (cyfry) : " << endl;
			wsk->vecInvo[now].payDate.menuData();
			wsk->vecInvo[now].getInfo();
		}
		else if (choice == "0")
			m = false;
		else
			cout << " Wybierz poprawnie z podanych opcji... " << endl;
	}
}

/////////// -> menuTable ////////////////////////////////
void Menu::menuTable(Table* tab) {
	bool t = true;
	while (t) {
		cout << endl;
		//cout << "->>[ + Nowa firma ]" << endl;
		cout << "WYBIERZ OPCJE : " << endl;
		cout << "  [1]->>[ Edytuj pozycje ] " << endl;
		cout << "  [2]->>[ Dodaj pozycje ]" << endl;
		cout << "  [3]->>[ Usun ostatnia pozycje ]" << endl;
		cout << "  [4]->>[ Usun wszystkie pozycje ]" << endl;
		cout << "  [0]->>[ POWROT DO MENU ]" << endl;
		cout << "----------------------------------- " << endl;
		cout << "wybieram opcje nr: ";
		string choice;
		cin >> choice;
		if (choice == "1")
		{
			if (tab->listPos.size() == 0) {
				cout << endl << " ---> BRAK POZYCJI w tabeli " << endl << endl;
			}
			else {
				cout << " -> podaj nr pozycji: ";
				int pos;
				cin >> pos;
				if ((pos <= 0) || (pos>tab->listPos.size()))
					cout << endl << " ---> BRAK POZYCJI w tabeli " << endl << endl;
				else {
					Position *nowpos = &tab->listPos[pos - 1];
					this->menuPosition(nowpos, tab);
				}
			}
		}
		else if (choice == "2")
		{
			tab->listPos.push_back(Position());
			cout << tab->getInfo();
			cout << " -> Dodano pozycje nr: " << tab->listPos.size() << endl;


		}
		else if (choice == "3")
		{
			if (tab->listPos.size() == 0) {
				cout << endl << " ---> BRAK POZYCJI w tabeli " << endl << endl;
			}
			else {
				int str;
				tab->listPos.pop_back();
				cout << tab->getInfo();
				cout << " -> Usunieto pozycje nr: " << tab->listPos.size() << endl;
			}
		}
		else if (choice == "4")
		{
			if (tab->listPos.size() == 0) {
				cout << endl << " ---> BRAK POZYCJI w tabeli " << endl << endl;

			}
			else {
				int str;
				tab->listPos.clear();
				cout << tab->getInfo();
				cout << " -> Usunieto " << tab->listPos.size() << " pozycji. " << endl;
			}
		}
		else if (choice == "0")
		{
			t = false;
		}
		else
		{
			cout << " Wybierz poprawnie z podanych opcji... " << endl;
		}


	}
}

/////////// -> menuPosittion ////////////////////////////
void Menu::menuPosition(Position* pos, Table* tab)
{
	bool m = true;
	while (m) {
		cout << endl;
		//cout << "->>[ + Nowa firma ]" << endl;
		cout << "WYBIERZ OPCJE : " << endl;
		cout << "  [1]->>[ Ustaw nazwe ] " << endl;
		cout << "  [2]->>[ Ustaw ilosc ]" << endl;
		cout << "  [3]->>[ Ustaw jm.]" << endl;
		cout << "  [4]->>[ Ustaw cene ]" << endl;
		cout << "  [5]->>[ Ustaw VAT ]" << endl;
		cout << "  [0]->>[ POWROT ]" << endl;
		cout << "----------------------------------- " << endl;
		cout << "wybieram opcje nr: ";
		string choice;
		cin >> choice;
		if (choice == "1") {
			cout << " -> podaj nazwe: ";
			string str;
			cin >> str;
			pos->setName(str);

		}
		else if (choice == "2") {
			cout << " -> popdaj ilosc: ";
			int str;
			cin >> str;
			pos->setQuantity(str);

		}
		else if (choice == "3") {
			string str;
			cout << " -> podaj jm: ";
			cin >> str;
			pos->setUnit(str);
		}
		else if (choice == "4") {
			cout << " -> podaj cene: " << endl;
			double str;
			cin >> str;
			pos->setPrice(str);
		}
		else if (choice == "5") {
			cout << " -> podaj wartosc VAT: " << endl;
			double str;
			cin >> str;
			pos->setPrice(str);

		}
		else if (choice == "0") {
			m = false;
		}
		else
			cout << " Wybierz poprawnie z podanych opcji... " << endl;

		pos->calculate();
		cout << tab->getInfo();
	}

}

/////////// -> show intro ////////////////////////////
void intro() {
	cout << endl;
	cout << " --------------------------------------" << endl;
	cout << "     *     F  A  K  T  U  R  A     *   " << endl;
	cout << " -- OPCJE  ----------------------------" << endl;
	cout << "          -------------------" << endl;
	cout << "  [1] ->>| + Nowa Faktura    | " << endl;
	cout << "          -------------------" << endl;
	cout << "          -------------------" << endl;
	cout << "  [2] ->>| + Nowa Firma      |" << endl;
	cout << "          -------------------" << endl;
	cout << "          -------------------" << endl;
	cout << "  [3] ->>| > Baza Firm       |" << endl;
	cout << "          -------------------" << endl;
	cout << "          -------------------" << endl;
	cout << "  [4] ->>| > Historia Faktur |" << endl;
	cout << "          -------------------" << endl;
	cout << "          -------------------" << endl;
	cout << "  [0] ->>| > Zamknij program |" << endl;
	cout << "          -------------------" << endl;
	cout << " --------------------------------------" << endl;
	cout << " wybieram opcje nr: ";
}




