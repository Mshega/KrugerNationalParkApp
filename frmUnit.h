//---------------------------------------------------------------------------

#ifndef frmExamUnitH
#define frmExamUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Samples.Spin.hpp>
//---------------------------------------------------------------------------
class TfrmKruger : public TForm
{
__published:	// IDE-managed Components
	TPanel *pnlTop;
	TImage *Image1;
	TPageControl *pgctrlPage;
	TStatusBar *StatusBar;
	TTabSheet *tbsTwo;
	TTabSheet *tbsOne;
	TDBGrid *dbgrdClientData;
	TLabel *Label1;
	TLabel *Label11;
	TPanel *pnlTopData;
	TLabel *Label20;
	TDBGrid *DBGridClients;
	TButton *btnTotLPincentSQL;
	TButton *btnTotLPincentNOSQL;
	TComboBox *cmbWildcType;
	TPanel *pnlConnect;
	TImage *imgConnect;
	TLabel *lblConnect;
	TImage *Image3;
	TLabel *Label2;
	TEdit *edtClients;
	TLabel *Label5;
	TImage *Image2;
	TPanel *pnlBottomData;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *lblWCnum;
	TEdit *edtWCnumNew;
	TPanel *pnlData;
	TLabel *Label3;
	TLabel *Label4;
	TComboBox *cmbWCtype;
	TSpinEdit *spedtMaxP;
	TButton *btnWCnewNum;
	TButton *btnInsert;
	TLabel *Label6;
	TLabel *Label7;
	TButton *btnShowLrecord;
	void __fastcall tbsTwoShow(TObject *Sender);
	void __fastcall btnTotLPincentSQLClick(TObject *Sender);
	void __fastcall btnTotLPincentNOSQLClick(TObject *Sender);
	void __fastcall cmbWildcTypeChange(TObject *Sender);
	void __fastcall imgConnectClick(TObject *Sender);
	void __fastcall btnInsertClick(TObject *Sender);
	void __fastcall btnWCnewNumClick(TObject *Sender);
	void __fastcall btnShowLrecordClick(TObject *Sender);

private:	// User declarations
public:		// User declarations

	AnsiString WCnum;
	__fastcall TfrmKruger(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmKruger *frmKruger;
//---------------------------------------------------------------------------
#endif
