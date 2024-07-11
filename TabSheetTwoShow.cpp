#include <vcl.h>
#pragma hdrstop
#include "TabSheetTwoShow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

void __fastcall TForm1::TabSheetTwoShow(TObject *Sender)
{
    cmbWildcType->Items->Clear();
    ADOdsWildCard->Close();
    ADOdsWildCard->Open();
    while (!ADOdsWildCard->Eof) {
        cmbWildcType->Items->Add(ADOdsWildCard->FieldByName("Code")->AsString + " - " + ADOdsWildCard->FieldByName("FullName")->AsString);
        ADOdsWildCard->Next();
    }
    cmbWildcType->Text = "Choose a Wildcard-type";
}
