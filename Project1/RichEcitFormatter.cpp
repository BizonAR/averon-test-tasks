#include "RichEditFormatter.h"

TRichEditFormatter::TRichEditFormatter() : CurrentRichEdit(nullptr) {}

void TRichEditFormatter::SetRichEdit(TRichEdit* RichEdit)
{
	CurrentRichEdit = RichEdit;
}

TCharFormat TRichEditFormatter::GetCharFormat()
{
	TCharFormat charFormat;
	memset(&charFormat, 0, sizeof(TCharFormat));
	charFormat.cbSize = sizeof(TCharFormat);

	if (CurrentRichEdit)
	{
		CurrentRichEdit->Perform(EM_GETCHARFORMAT, SCF_SELECTION,
			(LPARAM)&charFormat);
	}
	return charFormat;
}

void TRichEditFormatter::ApplyFormatting(bool Bold, bool Italic, bool Underline,
	bool Strikeout)
{
	if (CurrentRichEdit == nullptr)
		return;

	TCharFormat charFormat;
	memset(&charFormat, 0, sizeof(TCharFormat));
	charFormat.cbSize = sizeof(TCharFormat);
	charFormat.dwMask = CFM_BOLD | CFM_ITALIC | CFM_UNDERLINE
		| CFM_STRIKEOUT;

	charFormat.dwEffects = 0;

	if (Bold) charFormat.dwEffects |= CFE_BOLD;

	if (Italic) charFormat.dwEffects |= CFE_ITALIC;

	if (Underline) charFormat.dwEffects |= CFE_UNDERLINE;

	if (Strikeout) charFormat.dwEffects |= CFE_STRIKEOUT;


	CurrentRichEdit->Perform(EM_SETCHARFORMAT, SCF_SELECTION,
		(LPARAM)&charFormat);
}

void TRichEditFormatter::ToggleBold()
{
	TCharFormat charFormat = GetCharFormat();
	ApplyFormatting(!(charFormat.dwEffects & CFE_BOLD), charFormat.dwEffects
		& CFE_ITALIC, charFormat.dwEffects & CFE_UNDERLINE,
		charFormat.dwEffects & CFE_STRIKEOUT);
}

void TRichEditFormatter::ToggleItalic()
{
	TCharFormat charFormat = GetCharFormat();
	ApplyFormatting(charFormat.dwEffects & CFE_BOLD, !(charFormat.dwEffects
		& CFE_ITALIC), charFormat.dwEffects & CFE_UNDERLINE,
		charFormat.dwEffects & CFE_STRIKEOUT);
}

void TRichEditFormatter::ToggleUnderline()
{
	TCharFormat charFormat = GetCharFormat();
	ApplyFormatting(charFormat.dwEffects & CFE_BOLD, charFormat.dwEffects
		& CFE_ITALIC, !(charFormat.dwEffects & CFE_UNDERLINE),
		charFormat.dwEffects & CFE_STRIKEOUT);
}

void TRichEditFormatter::ToggleStrikeout()
{
	TCharFormat charFormat = GetCharFormat();
	ApplyFormatting(charFormat.dwEffects & CFE_BOLD, charFormat.dwEffects
	& 	CFE_ITALIC, charFormat.dwEffects & CFE_UNDERLINE,
	!(	charFormat.dwEffects & CFE_STRIKEOUT));
}

void TRichEditFormatter::UpdateButtonState(TToolButton* btnBold,
	TToolButton* btnItalic, TToolButton* btnUnderline,
	TToolButton* btnStrikeout)
{
	if (CurrentRichEdit == nullptr)
		return;

	TCharFormat charFormat = GetCharFormat();
	btnBold->Down = charFormat.dwEffects & CFE_BOLD;
	btnItalic->Down = charFormat.dwEffects & CFE_ITALIC;
	btnUnderline->Down = charFormat.dwEffects & CFE_UNDERLINE;
	btnStrikeout->Down = charFormat.dwEffects & CFE_STRIKEOUT;
}
