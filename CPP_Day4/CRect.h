#pragma once
#ifndef __RECT_H__
#define __RECT_H__

class CRect
{
public:
	CRect(int left, int top, int right, int bottom);
	~CRect();

	void    Display();

protected:
	int		m_nLeft;
	int		m_nTop;
	int		m_nRight;
	int 	m_nBottom;
};

#endif