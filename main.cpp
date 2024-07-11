#include <vcl.h>
#pragma hdrstop
#include "Main.h"
#include "TabSheetTwoShow.h"
#include "SumUpLoyaltyPointsSQL.h"
#include "SumUpLoyaltyPointsADO.h"
#include "cmbWildcTypeChange.h"
#include "GenerateNewWildcardNumber.h"
#include "InsertNewWildcard.h"
#include "DisplayClientWildcards.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
