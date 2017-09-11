
#include "Menu.h"
#include "library.h"
DataBase *wsk = &DataBase::getSingleton();

Menu::Menu()
{
	showMenu();
	wsk->~DataBase();
}

void Menu::showMenu() {
	cout << endl;
	//cout << " --------------------------------------" << endl;
	cout << " ^*^ Dzien dobry! dzis jest "<< wsk->dat.getDateStamp() <<endl;
	//cout << " --------------------------------------" << endl;
	bool k = true;
	while (k) {
		intro();
		string choice;
		cin >> choice;
		if (choice == "1")
		{
			addInvoice();
		}
		else if (choice == "2"){
			addCompany();
		}
		else if (choice == "3"){
			menuBase();
		}
		else if (choice == "4") {
			menuHistory();
		}
		else if (choice == "0")
		{
			cout << endl << " Do zobaczenia... " << endl;
			k = false;
		}
		else
			cout << " Wybierz poprawnie z podanych opcji... " << endl;
	}
}

/////////// -> menuInvoice ////////////////////////////
void Menu::addInvoice() {
	cout << "  -------------------" << endl;
	cout << " | + Nowa Faktura    | " << endl;
	cout << "  -------------------" << endl;

	// push next values into the vecComp
	wsk->vecInvo.push_back(Invoice());
	//wsk->vecInvo[wsk->vecInvo.size() - 1].getInfo();

	// print last values from the vecComp
	cout << "----------------------------------\n >> Poz.["
		<< wsk->vecInvo.size() << "] w Historii Faktur"
		<< endl << wsk->vecInvo[wsk->vecInvo.size() - 1].getInfo() << endl;
	
	// add info to invoice
	//seeting a cecInvo value of current position and show menu
	menuInvoice(wsk->vecInvo.size() - 1);
}

/////////// -> menuInvoice ////////////////////////////
void Menu::menuInvoice(int now) {
	string change_comp = " ";
	bool in = true;

	while (in) {
		char wich = NULL;
		cout << " MENU FAKTURA -> WYBIERZ OPCJE EDYCJI : " << endl;
		cout << "  [1]->>[ Dane Faktury ]" << endl;
		cout << "  [2]->>[ Dane Sprzedawcy ]" << endl;
		cout << "  [3]->>[ Dane Nabywcy ]" << endl;
		cout << "  [4]->>[ Ustaw pozycje] " << endl;
		cout << "  [5]->>[ Drukuj do pliku] " << endl;
		cout << "  [0]->>[ POWROT DO MENU ]" << endl;
		cout << "----------------------------------- " << endl;
		cout << "wybieram opcje nr: ";
		string choice;
		cin >> choice;
		if (choice == "1") {
			this->menuInvData(now, wsk);
			cout << wsk->vecInvo[now].getInfo();

		}
		else if (choice == "2") {
			Company *wcomp = &wsk->vecInvo[now].anySeller;
			char wich = 's';

			menuCompany(now, wcomp, wich);
			cout << wsk->vecInvo[now].getInfo();

		}
		else if (choice == "3") {
			Company *wcomp = &wsk->vecInvo[now].anyBuyer;
			char wich = 'b';

			menuCompany(now, wcomp, wich);
			cout << wsk->vecInvo[now].getInfo();

		}
		else if (choice == "4") {
			Table *table = &wsk->vecInvo[now].anytable;
			menuTable(table);
			cout << wsk->vecInvo[now].getInfo();
		}
		else if (choice == "5") {

			cout << wsk->vecInvo[now].getInfo();
			wsk->vecInvo[now].writeTofile();
			
		}
		else if (choice == "0")
			in = false;

		else
			cout << " Wybierz poprawnie z podanych opcji... " << endl;
	}
}

/////////// -> addCompany ////////////////////////////
void Menu::addCompany() {
	string str;
	cout << " -> podaj nazwe firmy: ";
	cin >> str;
	// push next values into the vecComp
	wsk->vecComp.push_back(Company(str));

	cout << "  -------------------" << endl;
	cout << " | + Nowa Firma      |" << endl;
	cout << "  -------------------" << endl;

	// print last values from the vecComp
	cout << "----------------------------------\n >> Poz.["
		<< wsk->vecComp.size() << "] w Bazie Firm"
		<< endl << wsk->vecComp[(wsk->vecComp.size()) - 1].getInfo() << endl;
	// add info to company
	//seeting a vecComp value of current position and show menu
	menuCompany(wsk->vecComp.size() - 1);
}

/////////// -> menuCompany ////////////////////////////
void Menu::menuCompany(int n) {
	bool i = true;
	while (i) {
		cout << endl;
		//cout << "->>[ + Nowa firma ]" << endl;
		cout << "WYBIERZ OPCJE : " << endl;
		cout << "  [1]->>[ Ustaw nazwe firmy] " << endl;
		cout << "  [2]->>[ Ustaw NIP ]" << endl;
		cout << "  [3]->>[ Ustaw adres firmy ]" << endl;
		cout << "  [4]->>[ Edytuj dane osoby upow. do faktury ]" << endl;
		cout << "  [0]->>[ POWROT DO MENU ]" << endl;
		cout << "----------------------------------- " << endl;
		cout << "wybieram opcje nr: ";
		string choice;
		cin >> choice;

		if (choice == "1")
		{
			cout << " -> podaj nazwe firmy: ";
			string str;
			cin >> str;
			wsk->vecComp[n].setCompanyName(str);
			cout << wsk->vecComp[n].getInfo();
		}
		else if (choice == "2")
		{
			cout << " -> popdaj NIP: ";
			string str;
			cin >> str;
			wsk->vecComp[n].setNip(str);
			cout << wsk->vecComp[n].getInfo();
		}
		else if (choice == "3")
		{
			string str, nr, kod, post;
			cout << " -> podaj ulice: ";
			cin >> str;
			cout << " -> podaj nr: ";
			cin >> nr;
			cout << " -> podaj kod: ";
			cin >> kod;
			cout << " -> podaj miasto: ";
			cin >> post;
			wsk->vecComp[n].setAddress(str, nr, kod, post);
			cout << wsk->vecComp[n].getInfo();
		}
		else if (choice == "4")
		{
			cout << " -> dane osoby upow. do faktury: " << endl;
			string str;
			cin >> str;
			wsk->vecComp[n].setPerson(str);
			cout << wsk->vecComp[n].getInfo();
		}

		else if (choice == "0")
			i = false;
		else
			cout << " Wybierz poprawnie z podanych opcji... " << endl;
	}
}

/////////// -> menuCompany ///////////////////////////
void Menu::menuCompany(int n, Company* comp, char w) {
	int now = n;
	char wich = w;
	Company* company = comp;
	bool i = true;
	while (i) {
		cout << endl;
		//cout << "->>[ + Nowa firma ]" << endl;
		cout << "WYBIERZ OPCJE : " << endl;
		cout << "  [1]->>[ POBIERZ z BAZY FIRM ]" << endl;
		cout << "  [2]->>[ Ustaw nazwe firmy] " << endl;
		cout << "  [3]->>[ Ustaw NIP ]" << endl;
		cout << "  [4]->>[ Ustaw adres firmy ]" << endl;
		cout << "  [5]->>[ Edytuj dane osoby upow. do faktury ]" << endl;
		cout << "  [6]->>[ ZAPISZ w BAZIE FIRM ]" << endl;
		cout << "  [0]->>[ POWROT DO MENU ]" << endl;
		cout << "----------------------------------- " << endl;
		cout << "wybieram opcje nr: ";
		string choice;
		cin >> choice;
		if (choice == "1")
		{
			bool k = true;
			while (k) {
				if (wsk->vecComp.size() == 0) { 
					cout << "\n\n\t BRAK POZYCJI w Bazie Firm \n";
					addCompany(); 
				}
				wsk->showBase();
				cout << "WYBIERZ OPCJE : " << endl;
				cout << "  [1]->>[ WYBIERZ NR z BAZY FIRM ]" << endl;
				cout << "  [2]->>[ + Nowa Firma ]" << endl;
				cout << "  [0]->>[ POWROT DO MENU ]" << endl;
				cout << "wybieram opcje nr: ";
				string str;
				cin >> str;
				if (str == "1") {
					string info = "\n\n\t BRAK POZYCJI w Bazie Firm \n";
					cout << "wybieram pozycje nr: ";
					int i;
					cin >> i;
					if (i <= 0 || i > wsk->vecComp.size())
						cout << info;
					else {
						cout << "wybrana Firma: ";
						cout << wsk->vecComp[i - 1].getInfo();
						//change company
						if (wich == 's') {
							wsk->vecInvo[now].setSeller(wsk->vecComp[i - 1]);
							system("pause");
							break;
						}
						else {
							wsk->vecInvo[now].setBuyer(wsk->vecComp[i - 1]);
							system("pause");
							break;
						}
					}
				}
				else if (str == "2")
					addCompany();

				else if (str == "0")
					k = false;
				else
					cout << " Wybierz poprawnie z podanych opcji... " << endl;
			}
			i = false;

		}

		if (choice == "2")
		{
			cout << " -> podaj nazwe firmy: ";
			string str;
			cin >> str;
			company->setCompanyName(str);
			cout << company->getInfo();
		}
		else if (choice == "3")
		{
			cout << " -> popdaj NIP: ";
			string str;
			cin >> str;
			company->setNip(str);
			cout << company->getInfo();
		}
		else if (choice == "4")
		{
			string str, nr, kod, post;
			cout << " -> podaj ulice: ";
			cin >> str;
			cout << " -> podaj nr: ";
			cin >> nr;
			cout << " -> podaj kod: ";
			cin >> kod;
			cout << " -> podaj miasto: ";
			cin >> post;
			company->setAddress(str, nr, kod, post);
			cout << company->getInfo();
		}
		else if (choice == "5")
		{
			cout << " -> dane osoby upow. do faktury: " << endl;
			string str;
			cin >> str;
			company->setPerson(str);
			cout << company->getInfo();
		}
		else if (choice == "6")
		{
			wsk->vecComp.push_back(*company);
			cout << company->getInfo();
			cout << " -> firma dodana do Bazy Firm, nr pozycji: [ " << wsk->vecComp.size() << " ]  ";
			system("pause");
		}

		else if (choice == "0")
		{
			i = false;
		}
		else
		{
			cout << " Wybierz poprawnie z podanych opcji... " << endl;
		}
	}
}

////////// ->  menubase //////////////////////////////////

void Menu::menuBase() {
	string info = "\n\n\t BRAK POZYCJI w Bazie Firm \n";
	bool t = true;
	while (t) {
		wsk->showBase();
		cout << endl;
		cout << " WYBIERZ OPCJE : " << endl;
		cout << "  [1]->>[ + Nowa Firma ] " << endl;
		cout << "  [2]->>[ Edytuj dane firmy] " << endl;
		cout << "  [3]->>[ Zapisz baze do pliku] " << endl;
		cout << "  [4]->>[ Usun ostatnia pozycje z bazy] " << endl;
		cout << "  [5]->>[ Usun wszystkie pozycje z bazy] " << endl;
		cout << "  [0]->>[ POWROT DO MENU ]" << endl;
		cout << "----------------------------------- " << endl;
		cout << " wybieram opcje nr: ";
		string h;
		cin >> h;
		if (h == "1") 
			addCompany();
		if (h == "2")
		{
			cout << " -> podaj nr pozycji firmy w bazie: ";
			int pos;
			cin >> pos;
			if (!wsk->vecComp.size() == 0) {
				cout << "----------------------------------\n >> Poz.["
					<< pos << "] w Bazie Firm"
					<< endl << wsk->vecComp[pos - 1].getInfo() << endl;
				menuCompany(pos - 1);
			}
			else
				cout << info;
		}
		else if (h == "3")
		{
			cout << " -> podaj nazwe pliku (bez spacji): ";
			string pos;
			cin >> pos;
			pos += ".txt";

			ofstream zapis(pos);
			zapis << "  -------------------" << endl;
			zapis << " | >  Baza Firm      |" << endl;
			zapis << "  -------------------" << endl;

			if (wsk->vecComp.size() == 0) {
				zapis << info;
			}
			else {
				// print all values from the vecComp
				for (int i = 0; i < wsk->vecComp.size(); ++i) {
					zapis << " >> Poz. [" << i + 1 << "] w Bazie Firm"
						<< wsk->vecComp[i].getInfo() << endl;
				}
				zapis << "\tRazem pozycji w Bazie Firm: " << wsk->vecComp.size() << endl
					<< endl << "\tDATA WYDRUKU: " << wsk->dat.getDateStamp() << endl;
				zapis << endl;
				zapis.close(); //close the file
				cout << "\tBaza Firm z dnia: " << wsk->dat.getDateStamp()
					<< "\tzapisana w pliku: " + pos + " w folderze programu " << endl;
				system("pause");
			}
		}
		else if (h == "4")
		{
			if (wsk->vecComp.size() == 0) {
				cout << info;
			}
			else {
				cout << " UWAGA: operacja spowoduje USUNIECIE pozycji nr "
					<< wsk->vecComp.size() << endl;
				cout << " nacisnij T (tak)/ N (nie) : ";
				string a;
				cin >> a;
				if (a == "t") { wsk->vecComp.pop_back(); }
			}
		}
		else if (h == "5")
		{
			if (wsk->vecComp.size() == 0) {
				cout << info;
			}
			else {
				cout << " UWAGA: operacja spowoduje USUNIECIE WSZYSTKICH POZYCJI"
					<< wsk->vecComp.size() << endl;
				cout << " nacisnij T (tak)/ N (nie) : ";
				string a;
				cin >> a;
				if (a == "t") { wsk->vecComp.clear(); }
			}
		}
		else if (h == "0")
			t = false;
		else
			cout << " Wybierz poprawnie z podanych opcji... " << endl;
	}
}

////////// -> menuHistory ////////////////////////////

void Menu::menuHistory() {
	string info = "\n\n\t BRAK POZYCJI w Historii Faktur \n";
	bool t = true;
	while (t) {
		wsk->showHistory();
		cout << endl;
		cout << " WYBIERZ OPCJE : " << endl;
		cout << "  [1]->>[ Edytuj Fakture ] " << endl;
		cout << "  [2]->>[ Zapisz Fakture ] " << endl;
		cout << "  [3]->>[ Zapisz Historie Faktur ] " << endl;
		cout << "  [4]->>[ Usun ostatnia pozycje z Historii Faktur ] " << endl;
		cout << "  [5]->>[ Usun wszystkie pozycje z Historii Faktur ] " << endl;
		cout << "  [0]->>[ POWROT DO MENU ]" << endl;
		cout << "----------------------------------- " << endl;
		cout << "  wybieram opcje nr: ";
		string h;
		cin >> h;
		if (h == "1")
		{
			if (wsk->vecInvo.size() == 0)
				cout << info ;
			else if (wsk->vecInvo.size() == 1) {
				cout<<endl << wsk->vecInvo[0].getInfo() << endl;
				menuInvoice(0);
			}
			else {
				cout << " -> podaj nr pozycji w Historii Faktur: ";
				int pos;
				cin >> pos;
				if (pos <= 0 || pos > wsk->vecInvo.size()) 
					cout << info;
				else {
					cout << "----------------------------------\n >> Poz.["
						<< pos << "] w Historii Faktur"
						<< endl << wsk->vecInvo[pos - 1].getInfo() << endl;
					menuInvoice(pos - 1);
				}
			}
		}
		else if (h == "2"){
			if (wsk->vecInvo.size() == 0)
				cout << info;
			else if (wsk->vecInvo.size() == 1) {
				cout << endl << wsk->vecInvo[0].getInfo() << endl;
				wsk->vecInvo[0].writeTofile();
				system("pause");
				}
			else {
				cout << " -> podaj nr pozycji w Historii Faktur: ";
				int pos;
				cin >> pos;
				if (pos <= 0 || pos > wsk->vecInvo.size())
					cout << info;
				else {
					cout << wsk->vecInvo[pos - 1].getInfo();
					wsk->vecInvo[pos - 1].writeTofile();
					system("pause");
				}
			}
		}
		else if (h == "3")
		{
			if (wsk->vecInvo.size() == 0) {
				cout << info;
			}

			else {
				cout << " -> podaj nazwe pliku (bez spacji): ";
				string pos;
				cin >> pos;
				pos += ".txt";

				ofstream zapis(pos);
				zapis << "  -------------------" << endl;
				zapis << " | + Historia Faktur |" << endl;
				zapis << "  -------------------" << endl;

				// print all values from the vecComp
				for (int i = 0; i < wsk->vecInvo.size(); ++i) {
					zapis << " >> Poz. [" << i + 1 << "] w Historii Faktur"
						<< endl << wsk->vecInvo[i].getInfo() << endl;
				}
				zapis << endl << "\tRazem pozycji w Historii Faktur: "
					<< wsk->vecInvo.size() << endl;;

				zapis << endl << "\tDATA WYDRUKU: " << wsk->dat.getDateStamp() << endl;

				zapis.close(); //close the file
				cout << "\t Historia Faktur z dnia: " << wsk->dat.getDateStamp()
					<< "  zapisana w pliku: " + pos + " w folderze programu " << endl;
				system("pause");
			}
		}
		else if (h == "4")
		{
			if (wsk->vecInvo.size() == 0) {
				cout << info;
			}
			else {
				cout << " UWAGA: operacja spowoduje USUNIECIE pozycji nr "
					<< wsk->vecInvo.size() << endl;
				cout << " nacisnij T (tak)/ N (nie) : ";
				string a;
				cin >> a;
				if (a == "t") { wsk->vecInvo.pop_back(); }
			}
		}
		else if (h == "5")
		{
			if (wsk->vecInvo.size() == 0) 
				cout << info;
			else {
				cout << " UWAGA: operacja spowoduje USUNIECIE WSZYSTKICH POZYCJI"
					<< wsk->vecInvo.size() << endl;
				cout << " nacisnij T (tak)/ N (nie) : ";
				string a;
				cin >> a;
				if (a == "t" || a == "T") { wsk->vecInvo.clear(); }
			}
		}
		else if (h == "0")
			t = false;
		else
			cout << endl << " Wybierz poprawnie z podanych opcji... " << endl;
	}
}


Menu::~Menu()
{
	cout << " . " << endl;
}





