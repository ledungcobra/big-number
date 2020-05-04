﻿
// BigNumberDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "BigNumber.h"
#include "BigNumberDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <string>
#include "ExpressionProcessor.h"


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	
END_MESSAGE_MAP()


// CBigNumberDlg dialog



CBigNumberDlg::CBigNumberDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BIGNUMBER_DIALOG, pParent)
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBigNumberDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, ID_RECORD_FIRST, BTN_EQUAL);
	DDX_Control(pDX, IDC_BUTTON31, BTN_PLUS);
	DDX_Control(pDX, IDC_BUTTON26, BTN_SUBTRACT);
	DDX_Control(pDX, IDC_BUTTON21, BTN_MULTIPLY);
	DDX_Control(pDX, IDC_BUTTON16, BTN_DIVIDE);
	DDX_Control(pDX, IDC_BUTTON11, BTN_DELETE_ONE_CHAR);
	DDX_Control(pDX, IDC_BUTTON10, BTN_CLEAR_ALL);
	DDX_Control(pDX, IDC_BUTTON15, BTN_PERCENT);
	DDX_Control(pDX, IDC_BUTTON20, BTN_9);
	DDX_Control(pDX, IDC_BUTTON25, BTN_6);
	DDX_Control(pDX, IDC_BUTTON30, BTN_3);
	DDX_Control(pDX, IDC_BUTTON35, BTN_DOT);
	DDX_Control(pDX, IDC_BUTTON34, BTN_ZERO);
	DDX_Control(pDX, IDC_BUTTON29, BTN_2);
	DDX_Control(pDX, IDC_BUTTON24, BTN_5);
	DDX_Control(pDX, IDC_BUTTON19, BTN_8);
	DDX_Control(pDX, IDC_BUTTON14, BTN_CLOSE_PARENTHESES);
	DDX_Control(pDX, IDC_BUTTON9, BTN_SHIFT_RIGHT);
	DDX_Control(pDX, IDC_BUTTON8, BTN_SHIFT_LEFT);
	DDX_Control(pDX, IDC_BUTTON13, BTN_OPEN_PARETHESES);
	DDX_Control(pDX, IDC_BUTTON18, BTN_7);
	DDX_Control(pDX, IDC_BUTTON23, BTN_4);
	DDX_Control(pDX, IDC_BUTTON28, BTN_1);
	DDX_Control(pDX, IDC_BUTTON33, BTN_POS_OR_NEGATIVE);
	DDX_Control(pDX, IDC_BUTTON7, BTN_A);
	DDX_Control(pDX, IDC_BUTTON12, BTN_B);
	DDX_Control(pDX, IDC_BUTTON22, BTN_D);
	DDX_Control(pDX, IDC_BUTTON17, BTN_C);
	DDX_Control(pDX, IDC_BUTTON27, BTN_E);
	DDX_Control(pDX, IDC_BUTTON32, BTN_F);
	DDX_Control(pDX, AFX_ID_PREVIEW_NUMPAGE, EDT_Expression);
	DDX_Control(pDX, AFX_ID_PREVIEW_CLOSE, EDT_Result);
	DDX_Control(pDX, IDC_BUTTON42, BTN_DEC_EX);
	DDX_Control(pDX, IDC_BUTTON43, BTN_HEX_EX);
	DDX_Control(pDX, IDC_BUTTON44, BTN_BIN_EX);
}

BEGIN_MESSAGE_MAP(CBigNumberDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//D
	ON_BN_CLICKED(ID_RECORD_FIRST, &CBigNumberDlg::OnBnClickedEqual)
	ON_BN_CLICKED(IDC_BUTTON28, &CBigNumberDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_BUTTON29, &CBigNumberDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_BUTTON30, &CBigNumberDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_BUTTON23, &CBigNumberDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_BUTTON24, &CBigNumberDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_BUTTON25, &CBigNumberDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_BUTTON18, &CBigNumberDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_BUTTON19, &CBigNumberDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_BUTTON20, &CBigNumberDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_BUTTON34, &CBigNumberDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_BUTTON35, &CBigNumberDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_BUTTON31, &CBigNumberDlg::OnBnClickedPlus)
	ON_BN_CLICKED(IDC_BUTTON26, &CBigNumberDlg::OnBnClickedSubtract)
	ON_BN_CLICKED(IDC_BUTTON21, &CBigNumberDlg::OnBnClickedMultiply)
	ON_BN_CLICKED(IDC_BUTTON16, &CBigNumberDlg::OnBnClickedDivide)
	ON_BN_CLICKED(IDC_BUTTON11, &CBigNumberDlg::OnBnClickedClearOneChar)
	ON_BN_CLICKED(IDC_BUTTON10, &CBigNumberDlg::OnBnClickedClearAll)
	ON_BN_CLICKED(IDC_BUTTON9, &CBigNumberDlg::OnBnClickedShiftRight)
	ON_BN_CLICKED(IDC_BUTTON8, &CBigNumberDlg::OnBnClickedShiftLeft)
	ON_BN_CLICKED(IDC_BUTTON14, &CBigNumberDlg::OnBnClickedCloseParentheses)
	ON_BN_CLICKED(IDC_BUTTON13, &CBigNumberDlg::OnBnClickedOpenParentheses)
	ON_BN_CLICKED(IDC_BUTTON33, &CBigNumberDlg::OnBnClickedPosOrNegative)
	ON_BN_CLICKED(IDC_BUTTON32, &CBigNumberDlg::OnBnClickedF)
	ON_BN_CLICKED(IDC_BUTTON27, &CBigNumberDlg::OnBnClickedE)
	ON_BN_CLICKED(IDC_BUTTON22, &CBigNumberDlg::OnBnClickedD)
	ON_BN_CLICKED(IDC_BUTTON17, &CBigNumberDlg::OnBnClickedC)
	ON_BN_CLICKED(IDC_BUTTON12, &CBigNumberDlg::OnBnClickedB)
	ON_BN_CLICKED(IDC_BUTTON7, &CBigNumberDlg::OnBnClickedA)
	ON_BN_CLICKED(IDC_BUTTON37, &CBigNumberDlg::OnBnClickedAND)
	ON_BN_CLICKED(IDC_BUTTON36, &CBigNumberDlg::OnBnClickedOR)
	ON_BN_CLICKED(IDC_BUTTON38, &CBigNumberDlg::OnBnClickedXOR)
	ON_BN_CLICKED(IDC_BUTTON39, &CBigNumberDlg::OnBnClickedNOT)
	ON_BN_CLICKED(IDC_BUTTON40, &CBigNumberDlg::OnBnClickedROR)
	ON_BN_CLICKED(IDC_BUTTON41, &CBigNumberDlg::OnBnClickedROL)
	ON_BN_CLICKED(IDC_BUTTON42, &CBigNumberDlg::OnBnClickedDecEx)
	ON_BN_CLICKED(IDC_BUTTON43, &CBigNumberDlg::OnBnClickedHexEx)
	ON_BN_CLICKED(IDC_BUTTON44, &CBigNumberDlg::OnBnClickedBinEx)
	//D
END_MESSAGE_MAP()


// CBigNumberDlg message handlers

BOOL CBigNumberDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CheckRadioButton(IDC_RADIO5, IDC_RADIO7, IDC_RADIO5);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBigNumberDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBigNumberDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
		dc.FillSolidRect(rect, RGB(36, 36, 37));
	}
	else
	{
		CDialogEx::OnPaint();
		
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBigNumberDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CString CBigNumberDlg::ConvertStringToCString(std::string input)
{
	return CString(input.c_str());
}

std::string CBigNumberDlg::ConvertCStringToString(CString cstring)
{
	CT2A t(cstring);
	std::string result(t);
	return result;
}

void CBigNumberDlg::UpdateUI()
{
	EDT_Expression.SetWindowTextW(expression);
	EDT_Result.SetWindowTextW(result);

	if (exMode == HEX) {
		OnHexMode();
	}
	else if (exMode == DEC) {
		OnDecMode();
	}
	else if(exMode == BIN) {
		OnBinMode();
	}
};




void CBigNumberDlg::OnBnClickedEqual()
{

	UpdateResult();

	
}

void CBigNumberDlg::UpdateResult()
{

	if (exMode == DEC) {

		ExpressionProcessor expressHandle(ConvertCStringToString(expression));
		result = ConvertStringToCString(expressHandle.GetResult().toString());


		if (DEC == resultMode) {
			return;
		}
		else if (HEX == resultMode) {
			Qint resultQint(expressHandle.GetResult());
			result = ConvertStringToCString(resultQint.DecToHex());
		}
		else if (BIN == resultMode) {
			Qint resultQint(expressHandle.GetResult());
			std::string resultBin = "";
			for (int i = 0; i < 128; i++) {
				resultBin += resultQint.DecToBin()[i] ? '1' : '0';
			}
			result = ConvertStringToCString(resultBin);
		}
		UpdateUI();
	}
	else {

	}

}


void CBigNumberDlg::OnBnClicked1()
{
	if(!CheckValidInput(NUMBER)) return;
	expression += _T("1");
	UpdateUI();

}


void CBigNumberDlg::OnBnClicked2()
{
	if (!CheckValidInput(NUMBER)) return;
	expression += _T("2");
	UpdateUI();
}


void CBigNumberDlg::OnBnClicked3()
{
	if (!CheckValidInput(NUMBER)) return;
	expression += _T("3");
	UpdateUI();
}


void CBigNumberDlg::OnBnClicked4()
{
	if (!CheckValidInput(NUMBER)) return;
	expression += _T("4");
	UpdateUI();
}


void CBigNumberDlg::OnBnClicked5()
{
	if (!CheckValidInput(NUMBER)) return;
	expression += _T("5");
	UpdateUI();
}


void CBigNumberDlg::OnBnClicked6()
{
	if (!CheckValidInput(NUMBER)) return;
	expression += _T("6");
	UpdateUI();
}


void CBigNumberDlg::OnBnClicked7()
{
	if (!CheckValidInput(NUMBER)) return;
	expression += _T("7");
	UpdateUI();
}


void CBigNumberDlg::OnBnClicked8()
{
	if (!CheckValidInput(NUMBER)) return;
	expression += _T("8");
	UpdateUI();
}


void CBigNumberDlg::OnBnClicked9()
{
	if (!CheckValidInput(NUMBER)) return;
	expression += _T("9");
	UpdateUI();
}


void CBigNumberDlg::OnBnClicked0()
{
	if (!CheckValidInput(NUMBER)) return;
	expression += _T("0");
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedDot()
{
	//Trường hợp nhập 1 dấu chấm
	if (!CheckValidInput(DOT)) return;
	expression += _T(".");
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedPlus()
{
	//Trường hợp nhập + không có số hạng
	CheckValidInput(OPERATOR);
	expression += _T("+");
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedSubtract()
{
	CheckValidInput(OPERATOR);
	expression += _T("-");
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedMultiply()
{
	CheckValidInput(OPERATOR);
	expression += _T("X");
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedDivide()
{
	CheckValidInput(OPERATOR);
	expression += _T("÷");
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedClearOneChar()
{
	if (expression.GetLength() >= 1) {
		expression.Delete(expression.GetLength() - 1, 1);
		UpdateUI();
	}
	
}


void CBigNumberDlg::OnBnClickedClearAll()
{
	expression = _T("");
	result = _T("");
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedShiftRight()
{
	CheckValidInput(OPERATOR);
	expression += _T(">>");
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedShiftLeft()
{
	CheckValidInput(OPERATOR);
	expression += _T("<<");
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedCloseParentheses()
{
	CheckValidInput(CLOSE_PARENTHESES);
	expression += _T(")");
	UpdateUI();
}



void CBigNumberDlg::OnBnClickedOpenParentheses()
{
	CheckValidInput(OPEN_PARENTHESES);
	expression += _T("(");
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedPosOrNegative()
{
	expression.Insert(0, _T("-("));
	expression.Insert(expression.GetLength(), _T(")"));
	UpdateUI();

}


void CBigNumberDlg::OnBnClickedF()
{
	expression += _T("F");
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedE()
{
	expression += _T("E");
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedD()
{
	expression += _T("D");
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedC()
{
	expression += _T("C");
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedB()
{
	expression += _T("B");
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedA()
{
	expression += _T("A");
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedAND()
{
	CheckValidInput(OPERATOR);
	expression += _T("&");
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedOR()
{
	CheckValidInput(OPERATOR);
	expression += _T("|");
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedXOR()
{
	CheckValidInput(OPERATOR);
	expression += _T("^");
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedNOT()
{
	CheckValidInput(OPERATOR);
	expression += _T("~");
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedROR()
{

	expression += _T("ror");
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedROL()
{
	expression += _T("rol");
	UpdateUI();
}



void CBigNumberDlg::OnBnClickedDecEx()
{
	BTN_DEC_EX.EnableWindow(FALSE);
	BTN_HEX_EX.EnableWindow(TRUE);
	BTN_BIN_EX.EnableWindow(TRUE);
	exMode = DEC;
	ResetUI();
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedHexEx()
{
	BTN_DEC_EX.EnableWindow(TRUE);
	BTN_HEX_EX.EnableWindow(FALSE);
	BTN_BIN_EX.EnableWindow(TRUE);
	exMode = HEX;
	ResetUI();
	UpdateUI();
}


void CBigNumberDlg::OnBnClickedBinEx()
{
	BTN_DEC_EX.EnableWindow(TRUE);
	BTN_HEX_EX.EnableWindow(TRUE);
	BTN_BIN_EX.EnableWindow(FALSE);
	exMode = BIN;
	ResetUI();
	UpdateUI();
}
