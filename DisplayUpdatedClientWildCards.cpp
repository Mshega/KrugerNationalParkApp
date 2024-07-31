// Function to display updated client wildcards
void __fastcall TfrmKruger::btnShowLrecordClick(TObject *Sender)
{
    DMod->ADOdsClientWildCards->Open(); // Open the dataset containing ClientWildCards data
    DMod->ADOdsClientWildCards->Last();  // Move to the last record in the dataset to ensure the latest (added) record is visible
    
    dbgrdClientData->DataSource = DMod->DSClientWildCards;  // Set the DataSource of dbgrdClientData to the dataset containing ClientWildCards data
}

