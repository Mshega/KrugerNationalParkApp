#include <vcl.h>
#pragma hdrstop
#include "GenerateNewWildcardNumber.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

void __fastcall TForm1::GenerateNewWildcardNumberClick(TObject *Sender)
{
    ADOdsTemp->Close();
    ADOdsTemp->CommandText = "SELECT MAX(WildCardNr) AS LastWildCardNr FROM ClientWildCards";
    ADOdsTemp->Open();
    String lastWildCardNr = ADOdsTemp->FieldByName("LastWildCardNr")->AsString;
    String newWildCardNr = "W" + IntToStr(StrToInt(lastWildCardNr.SubString(2, lastWildCardNr.Length()-1)) + 1);
    lblLastWildCardNr->Caption = lastWildCardNr;
    edtNewWildCardNr->Text = newWildCardNr;
}
