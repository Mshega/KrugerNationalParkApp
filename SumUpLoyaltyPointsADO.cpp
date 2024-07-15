void __fastcall TfrmKruger::btnTotLPincentNOSQLClick(TObject *Sender)
{
    // Close the ADO dataset to prepare for a new query
    ADOdsTemp->Close();
    ADOdsTemp->CommandText = "SELECT * FROM Clients WHERE WildCardNr IS NOT NULL"; // Set the SQL command for the dataset to select all records from Clients where WildCardNr is not NULL
    ADOdsTemp->Open(); // Open the dataset to execute the SQL command and retrieve records

    double totalIncentive = 0; // Initialize a variable to hold the total incentive, starting with zero

    while (!ADOdsTemp->Eof)  // Loop through each record in the dataset until the end of file (EOF) is reached
    {
        totalIncentive += ADOdsTemp->FieldByName("LoyaltyPoints")->AsInteger * 0.50; // Calculate the incentive by multiplying the LoyaltyPoints field value by 0.50
        ADOdsTemp->Next();  // Move to the next record in the dataset
    }
    ShowMessage("Total Incentive: " + FormatFloat("R #,##0.00", totalIncentive)); // Display a message dialog showing the total incentive formatted as currency
}
