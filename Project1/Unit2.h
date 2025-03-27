#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
#include "RichEditFormatter.h"
#include <System.ImageList.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:
    TRichEdit *RichEdit1;
    TRichEdit *RichEdit2;
    TSplitter *Splitter1;
    TToolBar *ToolBar1;
    TToolButton *btnBold;
    TToolButton *btnItalic;
    TToolButton *btnUnderline;
    TToolButton *btnStrikeout;
    void __fastcall btnBoldClick(TObject *Sender);
    void __fastcall btnItalicClick(TObject *Sender);
    void __fastcall btnStrikeoutClick(TObject *Sender);
	void __fastcall btnUnderlineClick(TObject *Sender);
    void __fastcall RichEditEnter(TObject *Sender);
private:
    TRichEditFormatter Formatter;
public:
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
