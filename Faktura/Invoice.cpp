#include "Invoice.h"
#include<fstream>
#include <vector>

Invoice::Invoice()
{
	this->number = "default_number";
	this->invDate =  Date();
	this->sellDate = Date();
	this->payDate =  Date();
	this->anySeller = Company();
	this->anyBuyer = Company();
	this->anytable = Table();

	this->payForm = "przelew";
}

void Invoice::setSeller(Company seller) { this->anySeller = seller; }
void Invoice::setBuyer(Company buyer) { this->anyBuyer = buyer; }


string Invoice::getInfo() {
	
	string line;
	
	for (int i = 0; i < 127; i++)
		line += "-";
		string info;
		info =
			line +
			"\n\t\t\t\t\t\t FAKTURA VAT \tNUMER: \t" + this->number +
			"\n : Data wystawienia: " + this->invDate.getDateStamp() +
			"\n : Data sprzedazy: " + this->sellDate.getDateStamp() +
			"\n : Data zaplaty: " + this->payDate.getDateStamp() +
			"\n : Forma zaplaty: " + this->payForm +
			"\n\n : SPRZEDAWCA: " + this->anySeller.getInfoInv() +
			"\n : NABYWCA: " + this->anyBuyer.getInfoInv() +
			"\n" + this->anytable.getInfo() +
			"\n  Osoba upow. do wystawienia f-ry VAT: " + this->anySeller.getPerson() +
			"\t Osoba upow. do odbioru f-ry VAT: " + this->anyBuyer.getPerson() + "\n\n";
		return info;
	}


string Invoice::getShortInfo() {
	string line;
	for (int i = 0; i < 127; i++)
		line += "-";
	string info;
	info =
		line +
		"\n\t\t\t\t\t\t FAKTURA VAT \tNUMER: \t" + this->number +
		"\n : Data wystawenia: " + this->invDate.getDateStamp() +
		"\n : Data sprzedazy: " + this->sellDate.getDateStamp() +
		"\n : Data zaplaty: " + this->payDate.getDateStamp();
	return info;
}


void Invoice:: writeTofile(){
cout << " -> podaj nazwe pliku (bez spacji): ";
string pos;
cin >> pos;
pos += ".txt";
ofstream zapis(pos);
zapis << this->getInfo() << endl;
zapis << endl;
zapis.close(); //close the file
cout << endl << " FAKTURA nr: "<<this->number<<" z dnia: "<<this->invDate.getDateStamp() <<" zapisana w pliku: " + pos + " w folderze programu " << endl<<endl;

}

Invoice::~Invoice(){}
