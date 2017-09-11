#include "DataBase.h"


DataBase::DataBase(){
	//reserving memory for vectors
	this->vecComp.reserve(10);
	this->vecInvo.reserve(10);
	this->dat = Date();
}


void DataBase::showBase() {
	cout << "  -------------------" << endl;
	cout << " | >  Baza Firm      |" << endl;
	cout << "  -------------------" << endl;
	// print all values from the vecComp
	if (this->vecComp.size() == 0) {
		cout << "\tBRAK POZYCJI w Bazie Firm" << endl;
	}
	else {

		for (int i = 0; i < vecComp.size(); ++i) {
			cout << " >> Poz. [" << i + 1 << "] w Bazie Firm"
				<< this->vecComp[i].getInfo() << endl;
		}
		cout << "\tRazem pozycji  w bazie : " << this->vecComp.size() << endl;
	}
}


void DataBase::showHistory() {
	cout << "  -------------------" << endl;
	cout << " | + Historia Faktur |" << endl;
	cout << "  -------------------" << endl;
	// print all values from the vecComp
	if (vecInvo.size() == 0) {
		cout << "  BRAK POZYCJI w Historii Faktur" << endl;
	}
	else {

		for (int i = 0; i < vecInvo.size(); ++i) {
			cout << endl << " >> Poz. [" << (i + 1) << "] w Historii Faktur"
				<< endl << vecInvo[i].getShortInfo() << endl;
		}
		cout << endl << "Razem pozycji  w Historii Faktur: " << vecInvo.size() << endl;
	}
}


DataBase::~DataBase()
{
	cout << endl << " Usunieto baze danych. Razem pozycji: "
		<< vecComp.size() + vecInvo.size();
}
