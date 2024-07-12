// Function to insert a new WildCard record
void __fastcall TfrmKruger::btnInsertClick(TObject *Sender)
{
    // insert with SQL add current date - use an appropriate SQL-related component
    if (cmbWCtype->ItemIndex > -1) // validate selection
    {
        AnsiString comboLn = cmbWCtype->Text;
        AnsiString WCtype = comboLn.SubString(1, comboLn.Pos("-")-2); 
        AnsiString paid = comboLn.SubString(comboLn.Pos("-")+3, 30);  //exclude'R'
        
        AnsiString sql = "INSERT INTO ClientWildCards(WildCardNr, LastReviewalDate, WildCardType, ";
            sql += " AmountPaid, MaxPax) VALUES (:WC, :Ldate, :WCT, :Paid, :MaxP)"; 
        
        DMod->ADOCommand->CommandText = sql;
        DMod->ADOCommand->Parameters->ParamByName("WC")->Value = edtWCnumNew->Text;
        DMod->ADOCommand->Parameters->ParamByName("Ldate")->Value = Date(); 
        DMod->ADOCommand->Parameters->ParamByName("WCT")->Value = WCtype; 
        DMod->ADOCommand->Parameters->ParamByName("Paid")->Value = paid; 
        DMod->ADOCommand->Parameters->ParamByName("MaxP")->Value = IntToStr(spedtMaxP->Value); 
        
        if (DMod->ADOCommand->Execute() > 0) 
            ShowMessage("New Client Wildcard recorded!"); 
    }
    else
        MessageDlg("First select a 'Wildcard Type'!", mtWarning, TMsgDlgButtons()<<mbOK, 0); 
        btnShowLrecord->Show(); 
}
