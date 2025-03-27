#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "RichEditFormatter.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Formatter.SetRichEdit(RichEdit1);
	RichEdit1->SelAttributes->Color = clBlack;
	RichEdit2->SelAttributes->Color = clBlack;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnBoldClick(TObject *Sender)
{
	Formatter.ToggleBold();
    Formatter.UpdateButtonState(btnBold, btnItalic, btnUnderline, btnStrikeout);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnItalicClick(TObject *Sender)
{
	Formatter.ToggleItalic();
    Formatter.UpdateButtonState(btnBold, btnItalic, btnUnderline, btnStrikeout);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnStrikeoutClick(TObject *Sender)
{
	Formatter.ToggleStrikeout();
    Formatter.UpdateButtonState(btnBold, btnItalic, btnUnderline, btnStrikeout);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnUnderlineClick(TObject *Sender)
{
	Formatter.ToggleUnderline();
	Formatter.UpdateButtonState(btnBold, btnItalic, btnUnderline, btnStrikeout);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RichEditEnter(TObject *Sender)
{
	TRichEdit *edit = dynamic_cast<TRichEdit*>(Sender);
	if (edit)
	{
		Formatter.SetRichEdit(edit);
		Formatter.UpdateButtonState(btnBold, btnItalic, btnUnderline,
			btnStrikeout);
	}
}
//---------------------------------------------------------------------------
