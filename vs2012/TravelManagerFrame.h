#pragma once

#include <wx/wx.h>
#include <wx/notebook.h>
#include <wx/listctrl.h>
#include <wx/srchctrl.h>
#include <wx/richtext/richtextctrl.h>
#include <InputBox.h>
#include <Date.h>

class TravelManagerFrame : public wxFrame
{
public:
    TravelManagerFrame(const wxString& title);
	~TravelManagerFrame();

protected:
	wxMenuBar* m_mnuBar;
	wxMenu* m_mnuFile;
	wxMenu* m_mnuHelp;
	wxNotebook* m_tabMain;
	wxPanel* m_shtManager;
	wxComboBox* m_cbTour;
	wxNotebook* m_tabManage;
	wxPanel* m_shtMCust;
	wxListCtrl* m_lstMCus;
	wxPanel* m_shtMOfficer;
	wxListCtrl* m_lstMOfficer;
	wxPanel* m_shtMTrans;
	wxListCtrl* m_lstMTrans;
	wxPanel* m_shtMRoute;
	wxRichTextCtrl* m_rctMRout;
	wxPanel* m_shtCust;
	wxSearchCtrl* m_stextCus;
	wxListCtrl* m_lstCus;
	wxButton* m_btnCusAdd;
	wxButton* m_btnCusEdit;
	wxButton* m_btnCusRemove;
	wxPanel* m_shtOfficer;
	wxSearchCtrl* m_stextOfficer;
	wxListCtrl* m_lstOfficer;
	wxButton* m_btnOfficerAdd;
	wxButton* m_btnOfficerEdit;
	wxButton* m_btnOfficerRemove;
	wxPanel* m_shtTrans;
	wxSearchCtrl* m_stextTrans;
	wxListCtrl* m_lstTrans;
	wxButton* m_btnTransAdd;
	wxButton* m_btnTransEdit;
	wxButton* m_btnTransRemove;
	wxPanel* m_shtMap;
	wxStaticBitmap* m_imgMap;
	wxButton* m_btnPlaceAdd;
	wxButton* m_btnPlaceEdit;
	wxButton* m_btnPlaceRemove;
	wxStatusBar* m_sttBar;

	// Virtual event handlers, overide them in your derived class
	virtual void SelectCombo( wxCommandEvent& event );
	virtual void AddCustomer( wxCommandEvent& event );
	virtual void EditCustomer( wxCommandEvent& event );
	virtual void RemoveCustomer( wxCommandEvent& event );
	virtual void AddOfficer( wxCommandEvent& event );
	virtual void EditOfficer( wxCommandEvent& event );
	virtual void RemoveOfficer( wxCommandEvent& event );
	virtual void AddTransport( wxCommandEvent& event );
	virtual void EditTransport( wxCommandEvent& event );
	virtual void RemoveTransport( wxCommandEvent& event );
	virtual void AddPlace( wxCommandEvent& event );
	virtual void EditPlace( wxCommandEvent& event );
	virtual void RemovePlace( wxCommandEvent& event );
};