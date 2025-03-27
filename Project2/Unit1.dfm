object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  StyleName = 'Windows'
  TextHeight = 15
  object Splitter1: TSplitter
    Left = 0
    Top = 202
    Width = 624
    Height = 1
    Cursor = crVSplit
    Align = alTop
    ExplicitTop = 179
    ExplicitWidth = 262
  end
  object RichEdit1: TRichEdit
    Left = 0
    Top = 52
    Width = 624
    Height = 150
    Align = alTop
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 0
    OnSelectionChange = RichEdit1SelectionChange
  end
  object RichEdit2: TRichEdit
    Left = 0
    Top = 203
    Width = 624
    Height = 238
    Align = alClient
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 1
    OnSelectionChange = RichEdit2SelectionChange
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 624
    Height = 52
    AutoSize = True
    ButtonHeight = 23
    ButtonWidth = 114
    Caption = 'ToolBar1'
    EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
    Flat = False
    ShowCaptions = True
    TabOrder = 2
    object btnBold: TToolButton
      Left = 0
      Top = 0
      Caption = #1046#1080#1088#1085#1099#1081
      ImageIndex = 0
      Style = tbsCheck
      OnClick = btnBoldClick
    end
    object btnItalic: TToolButton
      Left = 114
      Top = 0
      Caption = #1050#1091#1088#1089#1080#1074
      ImageIndex = 7
      Style = tbsCheck
      OnClick = btnItalicClick
    end
    object btnUnderline: TToolButton
      Left = 228
      Top = 0
      Caption = #1055#1086#1076#1095#1105#1088#1082#1085#1091#1090#1099#1081
      ImageIndex = 8
      Style = tbsCheck
      OnClick = btnUnderlineClick
    end
    object btnStrikeout: TToolButton
      Left = 342
      Top = 0
      Caption = #1047#1072#1095#1105#1088#1082#1085#1091#1090#1099#1081
      ImageIndex = 6
      Style = tbsCheck
      OnClick = btnStrikeoutClick
    end
    object btnFontColor: TToolButton
      Left = 456
      Top = 0
      Caption = #1062#1074#1077#1090' '#1096#1088#1080#1092#1090#1072
      ImageIndex = 1
      Wrap = True
      OnClick = btnFontColorClick
    end
    object btnSave: TToolButton
      Left = 0
      Top = 23
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      ImageIndex = 4
      OnClick = btnSaveClick
    end
    object btnGenerateHTML: TToolButton
      Left = 114
      Top = 23
      Caption = #1043#1077#1085'. html'
      ImageIndex = 2
      OnClick = btnGenerateHTMLClick
    end
    object btnLoadPlainText: TToolButton
      Left = 228
      Top = 23
      Caption = #1047#1072#1075#1088#1091#1079#1082#1072' '#1073#1077#1079' '#1092#1086#1088#1084'.'
      ImageIndex = 5
      OnClick = btnLoadPlainTextClick
    end
    object btnLoadFormattedText: TToolButton
      Left = 342
      Top = 23
      Caption = #1047#1072#1075#1088#1091#1079#1082#1072' '#1089' '#1092#1086#1088#1084'.'
      ImageIndex = 3
      OnClick = btnLoadFormattedTextClick
    end
  end
  object ColorDialog1: TColorDialog
    Left = 480
    Top = 24
  end
end
