void __fastcall TfrmKruger::btnWCnewNumClick(TObject *Sender)
{
    // Make the panel visible to show bottom data
    pnlBottomData->Visible = true;

    // Clear the label showing the current WC number
    lblWCnum->Caption = "";

    // Initialize string for leading zeroes
    AnsiString zeroes = "000000";

    // Initialize variables for WC number generation
    WCnum = "";
    AnsiString WCtemp = "";
    int WCnumNext = 0;

    // Validate if a wild card type has been selected
    if (cmbWildcType->ItemIndex > -1)
    {
        // Construct SQL query to fetch the maximum WildCardNr from ClientWildCards
        AnsiString TempSQL = "Select Max(WildCardNr) as LastNum from ClientWildCards ";

        // Close, clear, and open the query to fetch the maximum WildCardNr
        DMod->ADOUseQuery2->Close();
        DMod->ADOUseQuery2->SQL->Clear();
        DMod->ADOUseQuery2->SQL->Add(TempSQL);
        DMod->ADOUseQuery2->Open();

        // Retrieve the last WildCardNr from the query result
        WCnum = DMod->ADOUseQuery2->Fields->FieldByName("LastNum")->AsAnsiString;
        lblWCnum->Caption = WCnum;

        // Generate the next WildCardNr
        // It must start with "W" followed by 7 digits
        WCtemp = WCnum.Delete(1, 1); // Remove leading "W"
        int i = 1;
        while (WCtemp[i++] == '0')
            WCtemp.Delete(1, 1); // Remove leading zeroes

        WCnumNext = StrToInt(WCtemp) + 1; // Increment the number
        WCnum = IntToStr(WCnumNext);

        // Format the WCnum with leading "W" and leading zeroes
        WCnum = "W" + zeroes.SubString(1, 7 - WCnum.Length()) + WCnum;
        
        // Display the generated WC number in the edit control
        edtWCnumNew->Text = WCnum;
        
        // Show the insert button
        btnInsert->Show();
    }
}
