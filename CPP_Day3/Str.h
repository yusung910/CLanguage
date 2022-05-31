// adding complete operator= member function and copy constructor

class String
{
public:
	

	String();
	String(const char* s);
	String(const String& s, int hp);		// copy constructor
	String(char ch, int n);
	~String();

	const String& operator=(const String& s); // operator= member fucntion
	int GetLength(void) const;
	void SetCharSerialNum();
	void Display(void) const;
private:
	static int m_nNum;
	char *m_cName;
	int m_nHp;
	int m_nLength;
};
