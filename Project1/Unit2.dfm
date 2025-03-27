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
  TextHeight = 15
  object Splitter1: TSplitter
    Left = 0
    Top = 179
    Width = 624
    Height = 1
    Cursor = crVSplit
    Align = alTop
    ExplicitWidth = 262
  end
  object RichEdit1: TRichEdit
    Left = 0
    Top = 29
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
    OnEnter = RichEditEnter
    ExplicitTop = 52
  end
  object RichEdit2: TRichEdit
    Left = 0
    Top = 180
    Width = 624
    Height = 261
    Align = alClient
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 1
    OnEnter = RichEditEnter
    ExplicitTop = 203
    ExplicitHeight = 238
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 624
    Height = 29
    AutoSize = True
    ButtonHeight = 23
    ButtonWidth = 89
    Caption = 'ToolBar1'
    EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
    Flat = False
    ShowCaptions = True
    TabOrder = 2
    ExplicitHeight = 52
    object btnBold: TToolButton
      Left = 0
      Top = 0
      Caption = #1046#1080#1088#1085#1099#1081
      ImageIndex = 0
      Style = tbsCheck
      OnClick = btnBoldClick
    end
    object btnItalic: TToolButton
      Left = 89
      Top = 0
      Caption = #1050#1091#1088#1089#1080#1074
      ImageIndex = 7
      Style = tbsCheck
      OnClick = btnItalicClick
    end
    object btnUnderline: TToolButton
      Left = 178
      Top = 0
      Caption = #1055#1086#1076#1095#1105#1088#1082#1085#1091#1090#1099#1081
      ImageIndex = 8
      Style = tbsCheck
      OnClick = btnUnderlineClick
    end
    object btnStrikeout: TToolButton
      Left = 267
      Top = 0
      Caption = #1047#1072#1095#1105#1088#1082#1085#1091#1090#1099#1081
      ImageIndex = 6
      Style = tbsCheck
      OnClick = btnStrikeoutClick
    end
  end
end
