#include <vcl.h>
#pragma hdrstop
#include "cmbWildcTypeChange.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

void __fastcall TForm1::cmbWildcTypeChange(TObject *Sender)
{
    String selectedType = cmbWildcType->Text.SubString(1, 6); // Assuming the code length is 6 characters
    ADOUseQuery1->Close();
    ADOUseQuery1->SQL->Clear();
    ADOUseQuery1->SQL->Add("SELECT * FROM Clients WHERE WildCardNr IN (SELECT WildCardNr FROM ClientWildCards WHERE WildCardType = :Type)");
    ADOUseQuery1->Parameters->ParamByName("Type")->Value = selectedType;
    ADOUseQuery1->Open();
    lblClientCount->Caption = "Count: " + IntToStr(ADOUseQuery1->RecordCount);
}
