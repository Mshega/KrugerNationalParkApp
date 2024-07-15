void __fastcall TfrmKruger::btnTotLPincentNOSQLClick(TObject *Sender)
{
    // Close the ADO dataset to prepare for a new query
    ADOdsTemp->Close();

    // Set the SQL command for the dataset to select all records from Clients where WildCardNr is not NULL
    ADOdsTemp->CommandText = "SELECT * FROM Clients WHERE WildCardNr IS NOT NULL";

    // Open the dataset to execute the SQL command and retrieve records
    ADOdsTemp->Open();

    // Initialize a variable to hold the total incentive, starting with zero
    double totalIncentive = 0;

    // Loop through each record in the dataset until the end of file (EOF) is reached
    while (!ADOdsTemp->Eof) {
        // Calculate the incentive by multiplying the LoyaltyPoints field value by 0.50
        totalIncentive += ADOdsTemp->FieldByName("LoyaltyPoints")->AsInteger * 0.50;

        // Move to the next record in the dataset
        ADOdsTemp->Next();
    }

    // Display a message dialog showing the total incentive formatted as currency
    ShowMessage("Total Incentive: " + FormatFloat("R #,##0.00", totalIncentive));
}
