void __fastcall TfrmKruger::btnTotLPincentNOSQLClick(TObject *Sender)
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
