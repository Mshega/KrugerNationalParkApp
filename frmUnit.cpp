#include <vcl.h>
#pragma hdrstop

#include "frmExamUnit.h"                 
#include "DMUnit.h"                      
#include "DateUtils.hpp"                 
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmKruger *frmKruger;
//---------------------------------------------------------------------------
__fastcall TfrmKruger::TfrmKruger(TComponent* Owner): TForm(Owner)
{
	FormatSettings.ShortDateFormat = "yyyy/mm/dd";      
	FormatSettings.DecimalSeparator = '.';              
	FormatSettings.DateSeparator = '/';                
	FormatSettings.TimeSeparator = ':';                 
	pgctrlPage->ActivePageIndex = 0;                    
}
