//---------------------------------------------------------------------------

#include <fmx.h>
#include <vector>
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
	String lijeva_rijec, desna_rijec;

public:
	void setLijeva(String rijec){
		this->lijeva_rijec = rijec;
	}

	void setDesna(String rijec){
		this->desna_rijec = rijec;
	}
	String getLijeva(){
		return this->lijeva_rijec;
	}
	String getDesna(){
		return this->desna_rijec;
	}
};

class Parovi{
private:
	vector<Spajanje>parovi;
public:
	void dodaj_par(Spajanje par){
		this->parovi.push_back(par);
	}
	vector<Spajanje> daj_parove(){
		return this->parovi;
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

