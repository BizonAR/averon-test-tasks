#ifndef RichEditFormatterH
#define RichEditFormatterH

#include <Vcl.ComCtrls.hpp>

 struct FormatRange {
    int Start;
    int Length;
    bool Bold;
    bool Italic;
    bool Underline;
    bool Strikeout;
    TColor FontColor;

    FormatRange(int start, int length, bool bold, bool italic,
                bool underline, bool strikeout, TColor color)
        : Start(start), Length(length), Bold(bold), Italic(italic),
          Underline(underline), Strikeout(strikeout), FontColor(color) {}
};

class TRichEditFormatter {
private:
    TRichEdit* CurrentRichEdit;
public:
    TRichEditFormatter();
    void SetRichEdit(TRichEdit* RichEdit);
    TCharFormat GetCharFormat();
	void ApplyFormatting(bool Bold, bool Italic, bool Underline,
	bool Strikeout, TColor FontColor);
	void ToggleBold();
	void ToggleItalic();
    void ToggleUnderline();
    void ToggleStrikeout();
	void UpdateButtonState(TToolButton* btnBold, TToolButton* btnItalic,
		TToolButton* btnUnderline, TToolButton* btnStrikeout);
	void SetFontColor(TColor Color);
};

#endif
