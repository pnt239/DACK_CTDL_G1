#include "TravelManagerFrame.h"

TravelManagerFrame::TravelManagerFrame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(726,458), wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL)
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont( wxFont( 10, 74, 90, 90, false, wxT("Segoe UI") ) );
	
	m_mnuBar = new wxMenuBar( 0 );
	m_mnuFile = new wxMenu();
	wxMenuItem* m_mnuItemSave;
	m_mnuItemSave = new wxMenuItem( m_mnuFile, wxID_ANY, wxString( wxT("&Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_mnuFile->Append( m_mnuItemSave );
	
	m_mnuBar->Append( m_mnuFile, wxT("&File") ); 
	
	m_mnuHelp = new wxMenu();
	wxMenuItem* m_mnuItemHelp;
	m_mnuItemHelp = new wxMenuItem( m_mnuHelp, wxID_ANY, wxString( wxT("&Content") ) , wxEmptyString, wxITEM_NORMAL );
	m_mnuHelp->Append( m_mnuItemHelp );
	
	m_mnuHelp->AppendSeparator();
	
	wxMenuItem* m_mnuItemAbout;
	m_mnuItemAbout = new wxMenuItem( m_mnuHelp, wxID_ANY, wxString( wxT("&About") ) , wxEmptyString, wxITEM_NORMAL );
	m_mnuHelp->Append( m_mnuItemAbout );
	
	m_mnuBar->Append( m_mnuHelp, wxT("&Help") ); 
	
	this->SetMenuBar( m_mnuBar );
	
	wxBoxSizer* bMain;
	bMain = new wxBoxSizer( wxVERTICAL );
	
	m_tabMain = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_shtManager = new wxPanel( m_tabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* b1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sb1;
	//sb1 = new wxStaticBoxSizer( new wxStaticBox( m_shtManager, wxID_ANY, wxString(L"\x43h\x1ECDn Tour \x63\x1EA7n qu\x1EA3n l\xFD") ), wxVERTICAL );
	sb1 = new wxStaticBoxSizer(wxVERTICAL, m_shtManager, wxString(L"\x43h\x1ECDn Tour \x63\x1EA7n qu\x1EA3n l\xFD"));
	m_cbTour = new wxComboBox( m_shtManager, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	sb1->Add( m_cbTour, 0, wxALL | wxEXPAND, 5 );
	
	b1->Add(sb1, wxSizerFlags().Expand());
	//b1->Add( sb1, 1, wxEXPAND, 5 );
	
	m_tabManage = new wxNotebook( m_shtManager, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_shtMCust = new wxPanel( m_tabManage, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* b1_2 = new wxBoxSizer( wxVERTICAL );
	
	m_lstMCus = new wxListCtrl( m_shtMCust, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ICON );
	b1_2->Add( m_lstMCus, 1, wxGROW | wxALL, 5 );
	
	
	m_shtMCust->SetSizer( b1_2 );
	m_shtMCust->Layout();
	b1_2->Fit( m_shtMCust );
	m_tabManage->AddPage( m_shtMCust, wxString(L"Kh\xE1\x63h h\xE0ng"), true );
	m_shtMOfficer = new wxPanel( m_tabManage, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* b1_3 = new wxBoxSizer( wxVERTICAL );
	
	m_lstMOfficer = new wxListCtrl( m_shtMOfficer, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ICON );
	b1_3->Add( m_lstMOfficer, 1, wxGROW | wxALL, 5 );
	
	
	m_shtMOfficer->SetSizer( b1_3 );
	m_shtMOfficer->Layout();
	b1_3->Fit( m_shtMOfficer );
	m_tabManage->AddPage( m_shtMOfficer, wxString(L"Nh\xE2n vi\xEAn"), false );
	m_shtMTrans = new wxPanel( m_tabManage, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* b1_4 = new wxBoxSizer( wxVERTICAL );
	
	m_lstMTrans = new wxListCtrl( m_shtMTrans, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ICON );
	b1_4->Add( m_lstMTrans, 1, wxGROW | wxALL, 5 );
	
	
	m_shtMTrans->SetSizer( b1_4 );
	m_shtMTrans->Layout();
	b1_4->Fit( m_shtMTrans );
	m_tabManage->AddPage( m_shtMTrans, wxString(L"Ph\x1B0\x1A1ng ti\x1EC7n"), false );
	m_shtMRoute = new wxPanel( m_tabManage, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* b1_5 = new wxBoxSizer( wxVERTICAL );
	
	m_rctMRout = new wxRichTextCtrl( m_shtMRoute, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxVSCROLL|wxHSCROLL|wxNO_BORDER|wxWANTS_CHARS );
	b1_5->Add( m_rctMRout, 1, wxEXPAND | wxALL, 5 );
	
	
	m_shtMRoute->SetSizer( b1_5 );
	m_shtMRoute->Layout();
	b1_5->Fit( m_shtMRoute );
	m_tabManage->AddPage( m_shtMRoute, wxString(L"L\x1ED9 tr\xECnh"), false );
	
	b1->Add( m_tabManage, 1, wxEXPAND | wxALL, 5 );
	
	
	m_shtManager->SetSizer( b1 );
	m_shtManager->Layout();
	b1->Fit( m_shtManager );
	m_tabMain->AddPage( m_shtManager, wxString(L"Qu\x1EA3n l\xFD \x63hung"), true );
	m_shtCust = new wxPanel( m_tabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* b2 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* b2_1 = new wxBoxSizer( wxHORIZONTAL );
	
	
	b2_1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_stextCus = new wxSearchCtrl( m_shtCust, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	b2_1->Add( m_stextCus, 0, wxALL, 5 );
	
	
	b2->Add( b2_1, wxSizerFlags().Expand());
	
	m_lstCus = new wxListCtrl( m_shtCust, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ICON );
	//b2->Add( m_lstCus, 0, wxALL | wxGROW, 5 );
	b2->Add(m_lstCus, 1, wxGROW | wxALL, 5);
	
	wxBoxSizer* b2_2;
	b2_2 = new wxBoxSizer( wxHORIZONTAL );
	
	
	b2_2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_btnCusAdd = new wxButton( m_shtCust, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	b2_2->Add( m_btnCusAdd, 0, wxALL, 5 );
	
	m_btnCusEdit = new wxButton( m_shtCust, wxID_ANY, wxT("Edit"), wxDefaultPosition, wxDefaultSize, 0 );
	b2_2->Add( m_btnCusEdit, 0, wxALL, 5 );
	
	m_btnCusRemove = new wxButton( m_shtCust, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	b2_2->Add( m_btnCusRemove, 0, wxALL, 5 );
	
	
	//b2->Add( b2_2, 1, wxEXPAND, 5 );
	b2->Add(b2_2, wxSizerFlags().Expand());
	
	
	m_shtCust->SetSizer( b2 );
	m_shtCust->Layout();
	b2->Fit( m_shtCust );
	m_tabMain->AddPage( m_shtCust, wxString(L"Kh\xE1\x63h h\xE0ng"), false );
	m_shtOfficer = new wxPanel( m_tabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* b3;
	b3 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* b3_1;
	b3_1 = new wxBoxSizer( wxHORIZONTAL );
	
	
	b3_1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_stextOfficer = new wxSearchCtrl( m_shtOfficer, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	b3_1->Add( m_stextOfficer, 0, wxALL, 5 );
	
	
	b3->Add( b3_1, wxSizerFlags().Expand());
	
	m_lstOfficer = new wxListCtrl( m_shtOfficer, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ICON );
	b3->Add( m_lstOfficer, 1, wxGROW | wxALL, 5 );
	
	wxBoxSizer* b3_2 = new wxBoxSizer( wxHORIZONTAL );
	
	
	b3_2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_btnOfficerAdd = new wxButton( m_shtOfficer, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	b3_2->Add( m_btnOfficerAdd, 0, wxALL, 5 );
	
	m_btnOfficerEdit = new wxButton( m_shtOfficer, wxID_ANY, wxT("Edit"), wxDefaultPosition, wxDefaultSize, 0 );
	b3_2->Add( m_btnOfficerEdit, 0, wxALL, 5 );
	
	m_btnOfficerRemove = new wxButton( m_shtOfficer, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	b3_2->Add( m_btnOfficerRemove, 0, wxALL, 5 );
	
	
	b3->Add( b3_2, wxSizerFlags().Expand());
	
	
	m_shtOfficer->SetSizer( b3 );
	m_shtOfficer->Layout();
	b3->Fit( m_shtOfficer );
	m_tabMain->AddPage( m_shtOfficer, wxString(L"Nh\xE2n vi\xEAn"), false );
	m_shtTrans = new wxPanel( m_tabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* b4;
	b4 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* b4_1 = new wxBoxSizer( wxHORIZONTAL );
	
	
	b4_1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_stextTrans = new wxSearchCtrl( m_shtTrans, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	b4_1->Add( m_stextTrans, 0, wxALL, 5 );
	
	
	b4->Add( b4_1, wxSizerFlags().Expand());
	
	m_lstTrans = new wxListCtrl( m_shtTrans, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ICON );
	b4->Add( m_lstTrans, 1, wxGROW | wxALL, 5 );
	
	wxBoxSizer* b4_2;
	b4_2 = new wxBoxSizer( wxHORIZONTAL );
	
	
	b4_2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_btnTransAdd = new wxButton( m_shtTrans, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	b4_2->Add( m_btnTransAdd, 0, wxALL, 5 );
	
	m_btnTransEdit = new wxButton( m_shtTrans, wxID_ANY, wxT("Edit"), wxDefaultPosition, wxDefaultSize, 0 );
	b4_2->Add( m_btnTransEdit, 0, wxALL, 5 );
	
	m_btnTransRemove = new wxButton( m_shtTrans, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	b4_2->Add( m_btnTransRemove, 0, wxALL, 5 );
	
	
	b4->Add( b4_2, wxSizerFlags().Expand());
	
	
	m_shtTrans->SetSizer( b4 );
	m_shtTrans->Layout();
	b4->Fit( m_shtTrans );
	m_tabMain->AddPage( m_shtTrans, wxString(L"Ph\x1B0\x1A1ng ti\x1EC7n"), false );
	m_shtMap = new wxPanel( m_tabMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* b5;
	b5 = new wxBoxSizer( wxVERTICAL );
	
	m_imgMap = new wxStaticBitmap( m_shtMap, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	b5->Add( m_imgMap, 0, wxALL, 5 );
	
	wxBoxSizer* b5_1;
	b5_1 = new wxBoxSizer( wxHORIZONTAL );
	
	
	b5_1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_btnPlaceAdd = new wxButton( m_shtMap, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	b5_1->Add( m_btnPlaceAdd, 0, wxALL, 5 );
	
	m_btnPlaceEdit = new wxButton( m_shtMap, wxID_ANY, wxT("Edit"), wxDefaultPosition, wxDefaultSize, 0 );
	b5_1->Add( m_btnPlaceEdit, 0, wxALL, 5 );
	
	m_btnPlaceRemove = new wxButton( m_shtMap, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	b5_1->Add( m_btnPlaceRemove, 0, wxALL, 5 );
	
	
	b5->Add( b5_1, 1, wxEXPAND, 5 );
	
	
	m_shtMap->SetSizer( b5 );
	m_shtMap->Layout();
	b5->Fit( m_shtMap );
	m_tabMain->AddPage( m_shtMap, wxString(L"\x42\x1EA3n \x111\x1ED3"), false );
	
	bMain->Add( m_tabMain, 1, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( bMain );
	this->Layout();
	m_sttBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );

	CDate test;
	test.Import(L"22/03/1994");
}

TravelManagerFrame::~TravelManagerFrame()
{
}