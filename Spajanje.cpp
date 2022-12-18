//---------------------------------------------------------------------------

#include <fmx.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>
#include <stdlib.h>
#include <ctime>
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

};

TSpajanjeForma *SpajanjeForma;

 Zadaci z1;
 vector<Zadaci> svi_zadaci;
 int i=0;

//---------------------------------------------------------------------------

void dodaj_zadatak(){
	fstream lijeva_strana_file;
	fstream desna_strana_file;
	lijeva_strana_file.open("C:/Users/korisnik/Desktop/NoviFolder/slagalica/LijevaStrana.txt", ios::in);
	if(lijeva_strana_file.is_open()){
		desna_strana_file.open("C:/Users/korisnik/Desktop/NoviFolder/slagalica/DesnaStrana.txt", ios::in);
		if(desna_strana_file.is_open()){
			Zadaci z;
			string line1, line2;
			while (getline(lijeva_strana_file, line1) && getline(desna_strana_file, line2)){
				if(line1 == "KRAJ"){
					svi_zadaci.push_back(z);
					z.daj_parove().clear();
                    z = Zadaci();
				}
				else {
					Spajanje temp(line1, line2);
					z.dodaj_par(temp);
				}
			}

			desna_strana_file.close();
		}
		else{
			SpajanjeForma->TestText->Text = "Desna greska";
		}
		lijeva_strana_file.close();
		}
		else{
			SpajanjeForma->TestText->Text = "Lijeva greska";
		}
	   }

__fastcall TSpajanjeForma::TSpajanjeForma(TComponent* Owner)
	: TForm(Owner)
{
	int seed;
	vector<int>brojevi = {0, 1, 2, 3, 4, 5, 6, 7};
    srand(time(NULL));
	seed = rand()%20+1;
	std::srand (seed);
	random_shuffle(brojevi.begin(), brojevi.end());
	dodaj_zadatak();
    srand(time(NULL));
	rand();
	int broj;
	broj = rand()% svi_zadaci.size();
	Lijevo1->Text = svi_zadaci[broj].daj_parove()[0].getLijeva().c_str();
	Lijevo2->Text = svi_zadaci[broj].daj_parove()[1].getLijeva().c_str();
	Lijevo3->Text = svi_zadaci[broj].daj_parove()[2].getLijeva().c_str();
	Lijevo4->Text = svi_zadaci[broj].daj_parove()[3].getLijeva().c_str();
	Lijevo5->Text = svi_zadaci[broj].daj_parove()[4].getLijeva().c_str();
	Lijevo6->Text = svi_zadaci[broj].daj_parove()[5].getLijeva().c_str();
	Lijevo7->Text = svi_zadaci[broj].daj_parove()[6].getLijeva().c_str();
	Lijevo8->Text = svi_zadaci[broj].daj_parove()[7].getLijeva().c_str();
	Desno1->Text = svi_zadaci[broj].daj_parove()[brojevi[0]].getDesna().c_str();
	Desno2->Text = svi_zadaci[broj].daj_parove()[brojevi[1]].getDesna().c_str();
	Desno3->Text = svi_zadaci[broj].daj_parove()[brojevi[2]].getDesna().c_str();
	Desno4->Text = svi_zadaci[broj].daj_parove()[brojevi[3]].getDesna().c_str();
	Desno5->Text = svi_zadaci[broj].daj_parove()[brojevi[4]].getDesna().c_str();
	Desno6->Text = svi_zadaci[broj].daj_parove()[brojevi[5]].getDesna().c_str();
	Desno7->Text = svi_zadaci[broj].daj_parove()[brojevi[6]].getDesna().c_str();
	Desno8->Text = svi_zadaci[broj].daj_parove()[brojevi[7]].getDesna().c_str();
	TestText->Text = broj;
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



