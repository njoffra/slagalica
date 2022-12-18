//---------------------------------------------------------------------------

#include <fmx.h>

#pragma hdrstop

#include <vector>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include <windows.h>
#include <string>
#include <fstream>
#include <filesystem>

#include "Zaokruzivanje.h"
#include "Navigacija.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
using namespace std;
TZaokruzivanjeForma *ZaokruzivanjeForma;
int izabran_odgovor;
int tacan_odg_rb;
int skor;
int broj_pokusaja=0;
int seed;

// mozda se moze deklatist u headeru al me strah ovih errora
// test test test

vector <String> pitanja;
vector <String> odg1;
vector <String> odg2;
vector <String> tacan_odg;
//---------------------------------------------------------------------------

void ocisti(){
	ZaokruzivanjeForma->Odgovor1->IsChecked = false;
	ZaokruzivanjeForma->Odgovor2->IsChecked = false;
	ZaokruzivanjeForma->Odgovor3->IsChecked = false;
	ZaokruzivanjeForma->Odgovor4->IsChecked = false;
}


void izmjesaj_pitanja(){

// Kad ovaj repetativni kod ubacim u funkciju budu neki errori bez ikakve poruke

	fstream pitanjaFile;
	pitanjaFile.open("C:/Users/korisnik/Desktop/NoviFolder/slagalica/pitanja.txt", ios::in);
	if(pitanjaFile.is_open()){
		string line;
		while (getline(pitanjaFile, line)){

		String novi_string(line.c_str());// std::string i String nje isto
		pitanja.push_back(novi_string);

		}

		ZaokruzivanjeForma->Label1->Text = pitanja.size(); // za provjeru
		pitanjaFile.close();
	}
	else{
		ZaokruzivanjeForma->Label1->Text = "nije otvorfeno" ;
	}


	fstream odg1File;
	odg1File.open("C:/Users/korisnik/Desktop/NoviFolder/slagalica/odg1.txt", ios::in);
	if(odg1File.is_open()){
		string line;
		while (getline(odg1File, line)){

		String novi_string(line.c_str());
		odg1.push_back(novi_string);

		}

		odg1File.close();

	}else{
		ZaokruzivanjeForma->Label1->Text = "nije otvorfeno" ;
	}

	fstream odg2File;
	odg2File.open("C:/Users/korisnik/Desktop/NoviFolder/slagalica/odg2.txt", ios::in);
	if(odg2File.is_open()){
		string line;
		while (getline(odg2File, line)){

		String novi_string(line.c_str());
		odg2.push_back(novi_string);

		}

		odg2File.close();

	}else{
		ZaokruzivanjeForma->Label1->Text = "nije otvorfeno" ;
	}

	fstream tacan_odgFile;
	tacan_odgFile.open("C:/Users/korisnik/Desktop/NoviFolder/slagalica/tacanOdg.txt", ios::in);
	if(tacan_odgFile.is_open()){
		string line;
		while (getline(tacan_odgFile, line)){

		String novi_string(line.c_str());
		tacan_odg.push_back(novi_string);

		}

		tacan_odgFile.close();
	}else{
		ZaokruzivanjeForma->Label1->Text = "nije otvorfeno" ;
	}

	srand(time(NULL));
	seed = rand()%20+1; //neki random seed da svaki put budu drugaciji redoslijedi

	std::srand (seed);
	random_shuffle(pitanja.begin(), pitanja.end());

	std::srand (seed);
	random_shuffle(odg1.begin(), odg1.end());

	std::srand (seed);
	random_shuffle(odg2.begin(), odg2.end());

	std::srand (seed);
	random_shuffle(tacan_odg.begin(), tacan_odg.end());
}

__fastcall TZaokruzivanjeForma::TZaokruzivanjeForma(TComponent* Owner)
	: TForm(Owner)
{
	// ovaj kod se runna kad god se udje na formu i samo tada

	izmjesaj_pitanja();
	srand(time(NULL));
	rand();
	tacan_odg_rb = rand()% 3 + 1;
	TekstPitanja->Text = pitanja[broj_pokusaja];

	if(tacan_odg_rb == 1){
		Odgovor1->Text = tacan_odg[broj_pokusaja];
		Odgovor2->Text = odg1[broj_pokusaja];
		Odgovor3->Text = odg2[broj_pokusaja];
	}
	else if(tacan_odg_rb == 2){
		Odgovor1->Text = odg1[broj_pokusaja];
		Odgovor2->Text = tacan_odg[broj_pokusaja];
		Odgovor3->Text = odg2[broj_pokusaja];
	}
	else{
        Odgovor1->Text = odg1[broj_pokusaja];
		Odgovor2->Text = odg2[broj_pokusaja];
		Odgovor3->Text = tacan_odg[broj_pokusaja];
    }
	Odgovor4->Text = "Ne znam";
	TrenutniBodovi->Text = skor;
}
//---------------------------------------------------------------------------
void __fastcall TZaokruzivanjeForma::Odgovor1Change(TObject *Sender)
{
	izabran_odgovor = 1;
}
//---------------------------------------------------------------------------
void __fastcall TZaokruzivanjeForma::Odgovor2Change(TObject *Sender)
{
    izabran_odgovor = 2;
}
//---------------------------------------------------------------------------
void __fastcall TZaokruzivanjeForma::Odgovor3Change(TObject *Sender)
{
    izabran_odgovor = 3;
}
//---------------------------------------------------------------------------
void __fastcall TZaokruzivanjeForma::Odgovor4Change(TObject *Sender)
{
    izabran_odgovor = 4;
}
//---------------------------------------------------------------------------
void __fastcall TZaokruzivanjeForma::PotvrdiButtonClick(TObject *Sender)
{
    // ovaj kod se runna kad god se klikne dugme

	int a;
	srand(time(NULL));
	rand();
// nasumicno raspodjeljivanje pitanja i odgovora, moze i jednostavnije al mrsko mi
	if(tacan_odg_rb == 1){

					if(izabran_odgovor == 1) skor = skor + 3;
					else if(izabran_odgovor == 4) skor = skor;
					else  skor = skor - 1;
					ocisti();
					}

			else if(tacan_odg_rb == 2){
					if(izabran_odgovor == 2) skor = skor + 3;
					else if(izabran_odgovor == 4) skor = skor;
					else skor = skor - 1;
					ocisti();
					}

			else if(tacan_odg_rb == 3){
					if(izabran_odgovor == 3) skor = skor + 3;
					else if(izabran_odgovor == 4) skor = skor;
					else  skor = skor - 1;
                    ocisti();

				}
                broj_pokusaja++;

	if(broj_pokusaja < pitanja.size()){
    tacan_odg_rb = rand()% 3 + 1;
			TekstPitanja->Text = pitanja[broj_pokusaja];
			if(tacan_odg_rb==1){
				Odgovor1->Text = tacan_odg[broj_pokusaja];
				a = rand()%2+1;
				if(a==1){
					Odgovor2->Text = odg1[broj_pokusaja];
					Odgovor3->Text = odg2[broj_pokusaja];
				}
				else{
					Odgovor2->Text = odg2[broj_pokusaja];
					Odgovor3->Text = odg1[broj_pokusaja];
				}
			}
			else if(tacan_odg_rb==2){
				Odgovor2->Text = tacan_odg[broj_pokusaja];
				a = rand()%2+1;
				if(a==1){
					Odgovor1->Text = odg1[broj_pokusaja];
					Odgovor3->Text = odg2[broj_pokusaja];
				}
				else{
					Odgovor1->Text = odg2[broj_pokusaja];
					Odgovor3->Text = odg1[broj_pokusaja];
				}
			}
			else if(tacan_odg_rb==3){
				Odgovor3->Text = tacan_odg[broj_pokusaja];
				a = rand()%2+1;
				if(a==1){
					Odgovor1->Text = odg1[broj_pokusaja];
					Odgovor2->Text = odg2[broj_pokusaja];
				}
				else{
					Odgovor1->Text = odg2[broj_pokusaja];
					Odgovor2->Text = odg1[broj_pokusaja];
				}
			}
			Odgovor4->Text = "Ne znam";

	}
	else{
        // kad nestane pitanja ili se odgovori na dovoljno pitanja
		NavigacijaForma->ZaokruziButton->Enabled = false;
		NavigacijaForma->ukupni_bodovi += skor; // ukupni_bodovi je deklarisana Navigacija.h
		NavigacijaForma->UkupniBodovi->Text = NavigacijaForma->ukupni_bodovi;
		this->Close();
		NavigacijaForma->Show();
	}
    // svaki put ispise trenutni skor
	TrenutniBodovi->Text = skor;
}
//---------------------------------------------------------------------------
