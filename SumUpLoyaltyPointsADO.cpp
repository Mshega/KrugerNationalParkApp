#include <vcl.h>
#pragma hdrstop
#include "SumUpLoyaltyPointsADO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

void __fastcall TForm1::SumUpLoyaltyPointsADOClick(TObject *Sender)
{
    ADOdsTemp->Close();
    ADOdsTemp->CommandText = "SELECT * FROM Clients WHERE WildCardNr IS NOT NULL";
    ADOdsTemp->Open();
    double totalIncentive = 0;
    while (!ADOdsTemp->Eof) {
        totalIncentive += ADOdsTemp->FieldByName("LoyaltyPoints")->AsInteger * 0.50;
        ADOdsTemp->Next();
    }
    ShowMessage("Total Incentive: " + FormatFloat("R #,##0.00", totalIncentive));
}
