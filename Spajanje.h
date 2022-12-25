//---------------------------------------------------------------------------

#ifndef SpajanjeH
#define SpajanjeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
//---------------------------------------------------------------------------
class TSpajanjeForma : public TForm
{
__published:	// IDE-managed Components
	TButton *IzlazButton;
	TText *TestText;
	TButton *Lijevo1;
	TButton *Lijevo2;
	TButton *Lijevo3;
	TButton *Lijevo4;
	TButton *Lijevo5;
	TButton *Lijevo6;
	TButton *Lijevo7;
	TButton *Lijevo8;
	TButton *Desno1;
	TButton *Desno2;
	TButton *Desno3;
	TButton *Desno4;
	TButton *Desno5;
	TButton *Desno6;
	TButton *Desno7;
	TButton *Desno8;
	void __fastcall IzlazButtonClick(TObject *Sender);
	void __fastcall Lijevo1Click(TObject *Sender);
	void __fastcall Lijevo2Click(TObject *Sender);
	void __fastcall Lijevo3Click(TObject *Sender);
	void __fastcall Lijevo4Click(TObject *Sender);
	void __fastcall Lijevo5Click(TObject *Sender);
	void __fastcall Lijevo6Click(TObject *Sender);
	void __fastcall Lijevo7Click(TObject *Sender);
	void __fastcall Lijevo8Click(TObject *Sender);
	void __fastcall Desno1Click(TObject *Sender);
	void __fastcall Desno2Click(TObject *Sender);
	void __fastcall Desno3Click(TObject *Sender);
	void __fastcall Desno4Click(TObject *Sender);
	void __fastcall Desno5Click(TObject *Sender);
	void __fastcall Desno6Click(TObject *Sender);
	void __fastcall Desno7Click(TObject *Sender);
	void __fastcall Desno8Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TSpajanjeForma(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSpajanjeForma *SpajanjeForma;
//---------------------------------------------------------------------------
#endif
