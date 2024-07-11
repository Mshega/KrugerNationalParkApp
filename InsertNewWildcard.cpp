#include <vcl.h>
#pragma hdrstop

#include "InsertNewWildCardRecord.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// Function to insert a new WildCard record
void __fastcall TForm1::InsertNewWildcardClick(TObject *Sender)
{
    if (cmbWildCardType->Text == "" || spnAmountToPay->Value == 0) {
        ShowMessage("Please select a Wildcard Type and Amount to pay.");
        return;
    }

    String newWildCardNr = edtNewWildCardNr->Text;
    String wildCardType = cmbWildCardType->Text.SubString(1, cmbWildCardType->Text.Pos(" - ") - 1);
    double amountToPay = spnAmountToPay->Value;

    ADOCommand->CommandText = "INSERT INTO ClientWildCards (WildCardNr, WildCardType, AmountPaid, LastReviewalDate) VALUES (:WildCardNr, :WildCardType, :AmountPaid, :LastReviewalDate)";
    ADOCommand->Parameters->ParamByName("WildCardNr")->Value = newWildCardNr;
    ADOCommand->Parameters->ParamByName("WildCardType")->Value = wildCardType;
    ADOCommand->Parameters->ParamByName("AmountPaid")->Value = amountToPay;
    ADOCommand->Parameters->ParamByName("LastReviewalDate")->Value = Date();
    ADOCommand->Execute();

    ShowMessage("New Wildcard record added successfully.");
}
