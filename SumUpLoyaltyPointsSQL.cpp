void __fastcall TfrmKruger::btnTotLPincentSQLClick(TObject *Sender)
{
    // Close the ADO query to prepare for a new SQL statement
    ADOUseQuery2->Close();
    ADOUseQuery2->SQL->Clear();  // Clear any existing SQL statements from the ADO query
    ADOUseQuery2->SQL->Add("SELECT Format(SUM(LoyaltyPoints * 0.50), 'Currency') AS TotalIncentive FROM Clients WHERE WildCardNr IS NOT NULL"); // Set the SQL command for the ADO query to calculate the total incentive
    ADOUseQuery2->Open(); // Open the ADO query to execute the SQL command and retrieve the result

    ShowMessage("Total Incentive: " + ADOUseQuery2->FieldByName("TotalIncentive")->AsString); // Display a message dialog showing the total incentive formatted as currency
}

