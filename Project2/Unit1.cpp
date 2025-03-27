//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "RichEditFormatter.h"
#include <System.IOUtils.hpp>
#include <System.StrUtils.hpp>
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
void __fastcall TForm1::RichEdit1SelectionChange(TObject *Sender)
{
	Formatter.SetRichEdit(RichEdit1);

	Formatter.UpdateButtonState(btnBold, btnItalic, btnUnderline, btnStrikeout);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RichEdit2SelectionChange(TObject *Sender)
{
	Formatter.SetRichEdit(RichEdit2);

	Formatter.UpdateButtonState(btnBold, btnItalic, btnUnderline, btnStrikeout);
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

void __fastcall TForm1::btnFontColorClick(TObject *Sender)
{
	if (ColorDialog1->Execute())
	{
		Formatter.SetFontColor(ColorDialog1->Color);
		Formatter.UpdateButtonState(btnBold, btnItalic, btnUnderline,
			btnStrikeout);
	}
}
//---------------------------------------------------------------------------
void TForm1::SaveRichEditData(TRichEdit* RichEdit, const String& TextFile,
	const String& FormatFile)
{
	String plainText = RichEdit->Text;
	std::vector<FormatRange> formats;
	int len = plainText.Length();

	RichEdit->Perform(WM_SETREDRAW, (WPARAM)FALSE, (LPARAM)0);

	int i = 0;
	while (i < len)
	{
		RichEdit->SelStart = i;
		RichEdit->SelLength = 1;

		CHARFORMAT2 cf = {0};
        cf.cbSize = sizeof(CHARFORMAT2);
        RichEdit->Perform(EM_GETCHARFORMAT, SCF_SELECTION, (LPARAM)&cf);

		bool bold = cf.dwEffects & CFE_BOLD;
        bool italic = cf.dwEffects & CFE_ITALIC;
        bool underline = cf.dwEffects & CFE_UNDERLINE;
        bool strikeout = cf.dwEffects & CFE_STRIKEOUT;
		TColor color = static_cast<TColor>(cf.crTextColor);

		if (static_cast<int>(color) < 0)
        {
			color = static_cast<TColor>(GetSysColor(color & 0x000000FF));
		}

		int start = i;
        i++;
        if (i < len)
        {
            RichEdit->SelStart = i;
            RichEdit->SelLength = 1;
			RichEdit->Perform(EM_GETCHARFORMAT, SCF_SELECTION, (LPARAM)&cf);
        }
        while (i < len &&
               (cf.dwEffects & CFE_BOLD) == bold &&
               (cf.dwEffects & CFE_ITALIC) == italic &&
               (cf.dwEffects & CFE_UNDERLINE) == underline &&
			   (cf.dwEffects & CFE_STRIKEOUT) == strikeout &&
               cf.crTextColor == color)
        {
            i++;
            if (i < len)
            {
				RichEdit->SelStart = i;
				RichEdit->SelLength = 1;
				RichEdit->Perform(EM_GETCHARFORMAT, SCF_SELECTION, (LPARAM)&cf);
			}
		}

		formats.push_back(FormatRange(start, i - start, bold, italic,
			underline, strikeout, color));
	}

	RichEdit->Perform(WM_SETREDRAW, (WPARAM)TRUE, (LPARAM)0);
	RichEdit->Invalidate();

	TFile::WriteAllText(TextFile, plainText);

	TStringList *formatList = new TStringList();

    for (const auto& range : formats)
	{
		String line = String().Format("%d,%d,%d,%d,%d,%d,%d",
	ARRAYOFCONST((range.Start, range.Length, static_cast<int>(range.Bold),
	static_cast<int>(range.Italic), static_cast<int>(range.Underline),
	static_cast<int>(range.Strikeout), static_cast<int>(range.FontColor))));

		formatList->Add(line);
    }
	formatList->SaveToFile(FormatFile);
	delete formatList;
}
//---------------------------------------------------------------------------
bool TForm1::IsSameFormatting(TTextAttributes* attr, bool bold, bool italic,
	bool underline, bool strikeout, TColor color)
{
	return attr->Style.Contains(fsBold) == bold &&
		   attr->Style.Contains(fsItalic) == italic &&
		   attr->Style.Contains(fsUnderline) == underline &&
		   attr->Style.Contains(fsStrikeOut) == strikeout &&
		   attr->Color == color;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnSaveClick(TObject *Sender)
{
	SaveRichEditData(RichEdit1, "rich1_text.txt", "rich1_format.txt");
	SaveRichEditData(RichEdit2, "rich2_text.txt", "rich2_format.txt");
	ShowMessage("Данные сохранены");
}
//---------------------------------------------------------------------------
bool TForm1::LoadPlainText(TRichEdit* RichEdit, const String& TextFile)
{
	if (!FileExists(TextFile))
	{
		ShowMessage("Файл с текстом не найден: " + TextFile);
		return false;
	}

	RichEdit->Lines->Clear();
	RichEdit->Lines->Text = TFile::ReadAllText(TextFile);
	return true;
}
//---------------------------------------------------------------------------
bool TForm1::LoadFormattedText(TRichEdit* RichEdit, const String& TextFile,
	const String& FormatFile)
{
    if (!FileExists(TextFile))
	{
		ShowMessage("Файл с текстом не найден: " + TextFile);
		return false;
	}

    if (!FileExists(FormatFile))
    {
        ShowMessage("Файл с форматированием не найден: " + FormatFile);
		return false;
	}

	RichEdit->Lines->Clear();
	RichEdit->Lines->Text = TFile::ReadAllText(TextFile);

    TStringList *formatList = new TStringList();
	formatList->LoadFromFile(FormatFile);

    for (int i = 0; i < formatList->Count; i++)
    {
		TStringDynArray parts = SplitString(formatList->Strings[i], ",");
		int start = StrToInt(parts[0]);
        int length = StrToInt(parts[1]);
		bool bold = StrToInt(parts[2]);
        bool italic = StrToInt(parts[3]);
        bool underline = StrToInt(parts[4]);
		bool strikeout = StrToInt(parts[5]);
		TColor fontColor = (TColor)StrToInt(parts[6]);

		RichEdit->SelStart = start;
        RichEdit->SelLength = length;
        Formatter.SetRichEdit(RichEdit);
		Formatter.ApplyFormatting(bold, italic, underline, strikeout,
			fontColor);
	}
	delete formatList;

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnLoadPlainTextClick(TObject *Sender)
{
	if (LoadPlainText(RichEdit1, "rich1_text.txt") &&
		LoadPlainText(RichEdit2, "rich2_text.txt"))
	{
		ShowMessage("Чистый текст загружен");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnLoadFormattedTextClick(TObject *Sender)
{
	if (LoadFormattedText(RichEdit1, "rich1_text.txt", "rich1_format.txt") &&
	LoadFormattedText(RichEdit2, "rich2_text.txt", "rich2_format.txt"))
	{
		ShowMessage("Форматированный текст загружен");
	}
}
//---------------------------------------------------------------------------
String TForm1::ColorToWeb(TColor color)
{
    int r = GetRValue(color);
	int g = GetGValue(color);
    int b = GetBValue(color);
    return String().Format("#%2.2X%2.2X%2.2X", ARRAYOFCONST((r, g, b)));
}
//---------------------------------------------------------------------------
String TForm1::GenerateHTMLFromFiles(const String& TextFile,
	const String& FormatFile)
{
    if (!FileExists(TextFile) || !FileExists(FormatFile))
    {
        return "<html><body><p>Ошибка: один из файлов не найден.</p></body></html>";
	}
	String plainText = TFile::ReadAllText(TextFile);
    TStringList *formatList = new TStringList();
	formatList->LoadFromFile(FormatFile);

    String htmlContent = "<html><body>";
	int pos = 0;

    for (int i = 0; i < formatList->Count; i++)
	{
		TStringDynArray parts = SplitString(formatList->Strings[i], ",");
		int start = StrToInt(parts[0]);
        int length = StrToInt(parts[1]);
        bool bold = StrToInt(parts[2]);
        bool italic = StrToInt(parts[3]);
        bool underline = StrToInt(parts[4]);
		bool strikeout = StrToInt(parts[5]);
		TColor fontColor = (TColor)StrToInt(parts[6]);

		if (pos < start)
			htmlContent += plainText.SubString(pos + 1, start - pos);

		if (fontColor != clBlack)
			htmlContent += "<span style=\"color:" + ColorToWeb(fontColor) + "\">";
        if (bold) htmlContent += "<b>";
        if (italic) htmlContent += "<i>";
        if (underline) htmlContent += "<u>";
		if (strikeout) htmlContent += "<strike>";

		htmlContent += plainText.SubString(start + 1, length);

        if (strikeout) htmlContent += "</strike>";
        if (underline) htmlContent += "</u>";
		if (italic) htmlContent += "</i>";
        if (bold) htmlContent += "</b>";
		if (fontColor != clBlack) htmlContent += "</span>";

		pos = start + length;
	}

    if (pos < plainText.Length())
		htmlContent += plainText.SubString(pos + 1, plainText.Length() - pos);

    htmlContent += "</body></html>";
	delete formatList;
	return htmlContent;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnGenerateHTMLClick(TObject *Sender)
{
    String html1 = GenerateHTMLFromFiles("rich1_text.txt", "rich1_format.txt");
    String html2 = GenerateHTMLFromFiles("rich2_text.txt", "rich2_format.txt");
    TFile::WriteAllText("output1.html", html1);
    TFile::WriteAllText("output2.html", html2);
	ShowMessage("HTML-файлы сгенерированы: output1.html и output2.html");
}
//---------------------------------------------------------------------------

