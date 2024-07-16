void __fastcall TfrmKruger::tbsTwoShow(TObject *Sender)
{
    cmbWildcType->Items->Clear(); // Clear the items in cmbWildcType ComboBox
    
    // Close and reopen the ADO dataset ADOdsWildCard to refresh data
    ADOdsWildCard->Close();
    ADOdsWildCard->Open();
    
    while (!ADOdsWildCard->Eof) // Populate cmbWildcType with items from ADO dataset
    {
        cmbWildcType->Items->Add(ADOdsWildCard->FieldByName("Code")->AsString + " - " + ADOdsWildCard->FieldByName("FullName")->AsString); // Add each item as a combination of "Code - FullName" to cmbWildcType
        
        ADOdsWildCard->Next(); // Move to the next record in the ADO dataset
    }
    cmbWildcType->Text = "Choose a Wildcard-type"; // Set the default text in cmbWildcType ComboBox
}

