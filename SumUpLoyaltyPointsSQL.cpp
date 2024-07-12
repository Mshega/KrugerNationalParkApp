void __fastcall TfrmKruger::btnTotLPincentSQLClick(TObject *Sender)
{
    ADOUseQuery2->Close();
    ADOUseQuery2->SQL->Clear();
    ADOUseQuery2->SQL->Add("SELECT Format(SUM(LoyaltyPoints * 0.50), 'Currency') AS TotalIncentive FROM Clients WHERE WildCardNr IS NOT NULL");
    ADOUseQuery2->Open();
    ShowMessage("Total Incentive: " + ADOUseQuery2->FieldByName("TotalIncentive")->AsString);
}
