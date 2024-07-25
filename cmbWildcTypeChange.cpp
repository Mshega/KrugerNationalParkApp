void __fastcall TfrmKruger::cmbWildcTypeChange(TObject *Sender)
{
    // Extract the selected wildcard type code from cmbWildcType ComboBox
    String cmbLine = cmbWildcType->Text.SubString(1, 6); // Assuming the code length is 6 characters

    ADOUseQuery1->Close(); // Close ADOUseQuery1 if it's open
    ADOUseQuery1->SQL->Clear(); // Clear any existing SQL commands in ADOUseQuery1
    ADOUseQuery1->SQL->Add("SELECT * FROM Clients WHERE WildCardNr IN (SELECT WildCardNr FROM ClientWildCards WHERE WildCardType = :Type)"); // Construct the SQL command to select clients based on the selected wildcard type
    ADOUseQuery1->Parameters->ParamByName("Type")->Value = cmbLine; // Bind the parameter :Type to the selected wildcard type value
    ADOUseQuery1->Open(); // Execute the query
    
    lblClientCount->Caption = "Count: " + IntToStr(ADOUseQuery1->RecordCount); // Update lblClientCount with the count of records returned by the query
}

