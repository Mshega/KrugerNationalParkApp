#include <vcl.h>
#pragma hdrstop

#include "DisplayUpdatedClientWildCards.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// Function to display updated client wildcards
void __fastcall TForm1::DisplayClientWildcardsClick(TObject *Sender)
{
    ADOUseQuery1->Close();
    ADOUseQuery1->SQL->Clear();
    ADOUseQuery1->SQL->Add("SELECT * FROM ClientWildCards");
    ADOUseQuery1->Open();
    ADOUseQuery1->Last(); // Move to the last record to make it visible
}
