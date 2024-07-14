// Function to display updated client wildcards
void __fastcall TfrmKruger::btnShowLrecordClick(TObject *Sender)
{
    // Open the dataset containing ClientWildCards data
    DMod->ADOdsClientWildCards->Open();

    // Move to the last record in the dataset to ensure the latest (added) record is visible
    DMod->ADOdsClientWildCards->Last();

    // Set the DataSource of dbgrdClientData to the dataset containing ClientWildCards data
    dbgrdClientData->DataSource = DMod->DSClientWildCards;
}

