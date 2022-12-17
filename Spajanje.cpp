//---------------------------------------------------------------------------

#include <fmx.h>
#include <vector>
#include <fstream>
#pragma hdrstop

#include "Spajanje.h"
#include "Navigacija.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

using namespace std;
int bodovi=0;

class Spajanje{

private:
	string lijeva_rijec, desna_rijec;

public:
	void setLijeva(string rijec){
		this->lijeva_rijec = rijec;
	}

	void setDesna(string rijec){
		this->desna_rijec = rijec;
	}

	string getLijeva(){
		return this->lijeva_rijec;
	}

	string getDesna(){
		return this->desna_rijec;
	}
	Spajanje(string lijeva, string desna){
		this->lijeva_rijec = lijeva;
		this->desna_rijec = desna;
	}
};

class Zadaci{
private:
	vector<Spajanje>parovi;
	string pitanje;
public:
	void dodaj_par(Spajanje par){
		this->parovi.push_back(par);
	}

	vector<Spajanje> daj_parove(){
		return this->parovi;
	}

	void setPitanje(string p){
		this->pitanje = p;
	}

	string getPitanje(){
		return this->pitanje;
	}

    void dodaj_zadatak(){
	fstream lijeva_strana_file;
	fstream desna_strana_file;
	lijeva_strana_file.open("C:/Users/korisnik/Desktop/NoviFolder/slagalica/LijevaStrana.txt", ios::in);
	if(lijeva_strana_file.is_open()){
		desna_strana_file.open("C:/Users/korisnik/Desktop/NoviFolder/slagalica/DesnaStrana.txt", ios::in);
		if(desna_strana_file.is_open()){
			string line1, line2;
			while (getline(lijeva_strana_file, line1) && getline(desna_strana_file, line2)){
				if(line1 != "KRAJ"){
					Spajanje temp(line1, line2);
					this->parovi.push_back(temp);
					}
			}
			desna_strana_file.close();
		}else{
			SpajanjeForma->TestText->Text = "Desna greska";
		}
		lijeva_strana_file.close();
		}else{
			SpajanjeForma->TestText->Text = "Lijeva greska";
		}
	}

};

TSpajanjeForma *SpajanjeForma;



//---------------------------------------------------------------------------
__fastcall TSpajanjeForma::TSpajanjeForma(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TSpajanjeForma::IzlazButtonClick(TObject *Sender)
{
		NavigacijaForma->SpajanjeButton->Enabled = false;
		NavigacijaForma->ukupni_bodovi += bodovi;
		NavigacijaForma->UkupniBodovi->Text = NavigacijaForma->ukupni_bodovi;
		this->Close();
		NavigacijaForma->Show();
}
//---------------------------------------------------------------------------

void __fastcall TSpajanjeForma::TestDugmeClick(TObject *Sender)
{
	Zadaci z1;
	z1.dodaj_zadatak();
	String test = z1.daj_parove()[0].getLijeva().c_str();
	TestText->Text = test;

}
//---------------------------------------------------------------------------

