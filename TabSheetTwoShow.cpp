void __fastcall TfrmKruger::tbsTwoShow(TObject *Sender)
{
    cmbWildcType->Items->Clear();
    ADOdsWildCard->Close();
    ADOdsWildCard->Open();
    while (!ADOdsWildCard->Eof) 
    {
        cmbWildcType->Items->Add(ADOdsWildCard->FieldByName("Code")->AsString + " - " + ADOdsWildCard->FieldByName("FullName")->AsString);
        ADOdsWildCard->Next();
    }
    cmbWildcType->Text = "Choose a Wildcard-type";
}
