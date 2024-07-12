// Function to display updated client wildcards
void __fastcall TfrmKruger::btnShowLrecordClick(TObject *Sender)
{
    // make sure that the last (added) record is visible 
    
    DMod->ADOdsClientWildCards->Open(); 
    DMod->ADOdsClientWildCards->Last(); 
    dbgrdClientData->DataSource = DMod->DSClientWildCards;
}
