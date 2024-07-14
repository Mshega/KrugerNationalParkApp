// Function to insert a new WildCard record
void __fastcall TfrmKruger::btnInsertClick(TObject *Sender)
{
    // Check if a WildCard type is selected in the combo box
    if (cmbWCtype->ItemIndex > -1) // validate selection
    {
        // Extract WildCard type and amount paid from combo box selection
        AnsiString comboLn = cmbWCtype->Text;
        AnsiString WCtype = comboLn.SubString(1, comboLn.Pos("-") - 2); 
        AnsiString paid = comboLn.SubString(comboLn.Pos("-") + 3, 30);  // exclude 'R'
        
        // Prepare SQL query to insert into ClientWildCards table
        AnsiString sql = "INSERT INTO ClientWildCards(WildCardNr, LastReviewalDate, WildCardType, ";
        sql += "AmountPaid, MaxPax) VALUES (:WC, :Ldate, :WCT, :Paid, :MaxP)";
        
        // Set the command text of ADOCommand to the SQL query
        DMod->ADOCommand->CommandText = sql;
        
        // Bind parameters to the query
        DMod->ADOCommand->Parameters->ParamByName("WC")->Value = edtWCnumNew->Text;
        DMod->ADOCommand->Parameters->ParamByName("Ldate")->Value = Date(); // Current date
        DMod->ADOCommand->Parameters->ParamByName("WCT")->Value = WCtype;   // WildCard type
        DMod->ADOCommand->Parameters->ParamByName("Paid")->Value = paid;    // Amount paid
        DMod->ADOCommand->Parameters->ParamByName("MaxP")->Value = IntToStr(spedtMaxP->Value); // MaxPax
        
        // Execute the SQL command and check if it was successful
        if (DMod->ADOCommand->Execute() > 0) 
        {
            // Show success message if the insertion was successful
            ShowMessage("New Client Wildcard recorded!");
        }
    }
    else
    {
        // Show a warning message if no WildCard type is selected
        MessageDlg("First select a 'Wildcard Type'!", mtWarning, TMsgDlgButtons() << mbOK, 0);
    }
    
    // Always show the 'Show' button after attempting to insert
    btnShowLrecord->Show();
}

