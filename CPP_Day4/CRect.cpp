#include <iostream>
#include "CRect.h"

using namespace std;

CRect::CRect(int left, int top, int right, int bottom)
{
	m_nLeft = left;
	m_nTop = top;
	m_nRight = right;
	m_nBottom = bottom;
}

CRect::~CRect()
{
}

void CRect::Display()
{
	cout << "CRect" << endl;
	cout << "Left = " << m_nLeft<< endl;
	cout << "Top = " << m_nTop << endl;
	cout << "Right = " << m_nRight << endl;
	cout << "Bottom = " << m_nBottom << endl;
}