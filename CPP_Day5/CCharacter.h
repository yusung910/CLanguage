#ifndef __CHARACTER_H__
#define __CHARACTER_H__

enum TYPE {
	E_C_NONE = -1,
	E_C_USER,
	E_C_MONSTER,
	E_C_MAX,
};

class CCharacter
{
public:
	CCharacter();
	virtual ~CCharacter();

	//// 가상함수
	virtual void	Display() = 0;
	int				GetType() { return m_nType; }
	int				GetValue() { return m_nValue; }

protected:
	int		m_nHP;
	int		m_nMana;
	int		m_nEXP;
	int		m_nLEVEL;
	int 	m_nPosArry[2];

	char*   m_pType;
	int		m_nType;
	int		m_nValue;
};

#endif