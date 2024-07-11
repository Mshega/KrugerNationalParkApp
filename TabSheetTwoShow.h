#ifndef TABSHEETTWOSHOW_H
#define TABSHEETTWOSHOW_H

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>

class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TComboBox *cmbWildcType;
    TADODataSet *ADOdsWildCard;
    void __fastcall TabSheetTwoShow(TObject *Sender);
};

#endif
