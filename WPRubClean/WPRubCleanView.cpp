// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://msdn.microsoft.com/officeui.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// WPRubCleanView.cpp : implementation of the CWPRubCleanView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "WPRubClean.h"
#endif

#include "WPRubCleanDoc.h"
#include "WPRubCleanView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWPRubCleanView

IMPLEMENT_DYNCREATE(CWPRubCleanView, CView)

BEGIN_MESSAGE_MAP(CWPRubCleanView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CWPRubCleanView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CWPRubCleanView construction/destruction

CWPRubCleanView::CWPRubCleanView()
{
	// TODO: add construction code here

}

CWPRubCleanView::~CWPRubCleanView()
{
}

BOOL CWPRubCleanView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CWPRubCleanView drawing

void CWPRubCleanView::OnDraw(CDC* /*pDC*/)
{
	CWPRubCleanDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CWPRubCleanView printing


void CWPRubCleanView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CWPRubCleanView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWPRubCleanView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWPRubCleanView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CWPRubCleanView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CWPRubCleanView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CWPRubCleanView diagnostics

#ifdef _DEBUG
void CWPRubCleanView::AssertValid() const
{
	CView::AssertValid();
}

void CWPRubCleanView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWPRubCleanDoc* CWPRubCleanView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWPRubCleanDoc)));
	return (CWPRubCleanDoc*)m_pDocument;
}
#endif //_DEBUG


// CWPRubCleanView message handlers
