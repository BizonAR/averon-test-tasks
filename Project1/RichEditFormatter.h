#ifndef RichEditFormatterH
#define RichEditFormatterH

#include <Vcl.ComCtrls.hpp>

class TRichEditFormatter {
private:
    TRichEdit* CurrentRichEdit;
public:
    TRichEditFormatter();
    void SetRichEdit(TRichEdit* RichEdit);
    TCharFormat GetCharFormat();
	void ApplyFormatting(bool Bold, bool Italic, bool Underline,
	bool Strikeout);
	void ToggleBold();
	void ToggleItalic();
    void ToggleUnderline();
    void ToggleStrikeout();
	void UpdateButtonState(TToolButton* btnBold, TToolButton* btnItalic,
		TToolButton* btnUnderline, TToolButton* btnStrikeout);
};

#endif
