//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
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
__published:	// IDE-managed Components
	TRichEdit *RichEdit1;
	TRichEdit *RichEdit2;
	TToolBar *ToolBar1;
	TToolButton *btnBold;
	TToolButton *btnItalic;
	TToolButton *btnUnderline;
	TToolButton *btnStrikeout;
	TSplitter *Splitter1;
	TToolButton *btnFontColor;
	TToolButton *btnSave;
	TColorDialog *ColorDialog1;
	TToolButton *btnLoadPlainText;
	TToolButton *btnLoadFormattedText;
	TToolButton *btnGenerateHTML;
	void __fastcall RichEdit1SelectionChange(TObject *Sender);
	void __fastcall RichEdit2SelectionChange(TObject *Sender);
	void __fastcall btnBoldClick(TObject *Sender);
	void __fastcall btnItalicClick(TObject *Sender);
	void __fastcall btnStrikeoutClick(TObject *Sender);
	void __fastcall btnUnderlineClick(TObject *Sender);
	void __fastcall btnFontColorClick(TObject *Sender);
	void __fastcall btnSaveClick(TObject *Sender);
	void __fastcall btnLoadPlainTextClick(TObject *Sender);
	void __fastcall btnLoadFormattedTextClick(TObject *Sender);
	void __fastcall btnGenerateHTMLClick(TObject *Sender);
private:	// User declarations
	TRichEditFormatter Formatter;
	struct FormatRange
	{
        int Start;
        int Length;
        bool Bold;
        bool Italic;
        bool Underline;
        bool Strikeout;
		TColor FontColor;

		FormatRange(int s, int l, bool b, bool i, bool u, bool st, TColor fc)
			: Start(s), Length(l), Bold(b), Italic(i), Underline(u),
			Strikeout(st), FontColor(fc) {}
	};
	void SaveRichEditData(TRichEdit* RichEdit, const String& TextFile,
		const String& FormatFile);
	void LoadRichEditData(TRichEdit* RichEdit, const String& TextFile,
		const String& FormatFile);
	String GenerateHTMLFromRichEdit(TRichEdit* RichEdit);
	String ColorToWeb(TColor color);
	bool IsSameFormatting(TTextAttributes* attr, bool bold, bool italic,
		bool underline, bool strikeout, TColor color);
	bool LoadPlainText(TRichEdit* RichEdit, const String& TextFile);
	bool LoadFormattedText(TRichEdit* RichEdit, const String& TextFile,
		const String& FormatFile);
	String GenerateHTMLFromFiles(const String& TextFile,
		const String& FormatFile);
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
