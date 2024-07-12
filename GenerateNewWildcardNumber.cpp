void __fastcall TfrmKruger::btnWCnewNumClick(TObject *Sender)
{
    pnlBottomData->Visible = true;                  
	lblWCnum->Caption = "";                         
	AnsiString zeroes = "000000"; 
    
    WCnum = "";
    AnsiString WCtemp = "";
    int WCnumNext = 0;

    if (cmbWildcType->ItemIndex > -1)  // validate - a selection has been made
    {
        AnsiString TempSQL = "Select Max(WildCardNr) as LastNum from ClientWildCards ";
        
        DMod->ADOUseQuery2->Close();
        DMod->ADOUseQuery2->SQL->Clear();
        DMod->ADOUseQuery2->SQL->Add(TempSQL); 
        DMod->ADOUseQuery2->Open();
        
        WCnum = DMod->ADOUseQuery2->Fields->FieldByName("LastNum")->AsAnsiString; 
        lblWCnum->Caption = WCnum;
        
        // Generate the "next" record’s PK - WC number
        // It must consist out of a leading "W" with 7 digits!
        
        WCtemp = WCnum.Delete(1,1); // delete leading "W"
        int i = 1;
   
        while (WCtemp[i++] == '0') 
            WCtemp.Delete(1,1);
        
        WCnumNext = StrToInt(WCtemp) + 1; 
        WCnum = IntToStr(WCnumNext);
        
        WCnum = "W" + zeroes.SubString(1, 7- WCnum.Length()) + WCnum; 
        edtWCnumNew->Text = WCnum;
        btnInsert->Show(); 
    }
}
