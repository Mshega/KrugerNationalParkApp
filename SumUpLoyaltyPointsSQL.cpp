#include <vcl.h>
#pragma hdrstop
#include "SumUpLoyaltyPointsSQL.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

void __fastcall TForm1::SumUpLoyaltyPointsSQLClick(TObject *Sender)
{
    ADOUseQuery2->Close();
    ADOUseQuery2->SQL->Clear();
    ADOUseQuery2->SQL->Add("SELECT Format(SUM(LoyaltyPoints * 0.50), 'Currency') AS TotalIncentive FROM Clients WHERE WildCardNr IS NOT NULL");
    ADOUseQuery2->Open();
    ShowMessage("Total Incentive: " + ADOUseQuery2->FieldByName("TotalIncentive")->AsString);
}
