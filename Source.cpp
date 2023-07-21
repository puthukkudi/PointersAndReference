
/*
* Below Class illustrate the use of pointers and reference  when passed as parameter.
*/

#include <iostream>
using namespace std;


class String
{
private : 
	char* m_Buffer;
	size_t m_Size;

public:
	String():m_Buffer(nullptr), m_Size(0) {}

	String(const char* str)
	{
		cout << "Parameterized !" << endl;
		m_Size = strlen(str);
		m_Buffer = new char[m_Size];
		memcpy(m_Buffer, str, m_Size);
		m_Buffer[m_Size] = 0;
	}

	String(const String& str)
	{
		cout << "Copied!" << endl;
		m_Size = str.m_Size;
		m_Buffer = new char[m_Size];
		memcpy(m_Buffer, str.m_Buffer, m_Size);
		m_Buffer[m_Size] = 0;
	}

	String& operator=(const String& str)
	{
		cout << "Assigned!" << endl;
		m_Size = str.m_Size;
		m_Buffer = new char[m_Size];
		memcpy(m_Buffer, str.m_Buffer, m_Size);
		m_Buffer[m_Size] = 0;
		return *this;
	}

	~String()
	{
		delete []m_Buffer;
	}
};


int main()
{
	String s1 = "hello"; // Create object S1 : Parameterized constructor is called
	String s2; // Create object s2 : Default constructor is called
	s2 = s1; // = Operator overload is called
	String s3(s1); // Create object s3 : Copy constructor is called

	String* s4 = new String("hello"); // Create pointer s4 to new string object : Parameterized constructor is called
	String* s5 = new String(); // Create pointer s5 to new string object : Default constructor is called
	*s5 = *s4; // Assign value at  pointer s4 to value at pointer s5 : = Operator overload is called is called
	String *s6 = new String(*s4); // Create pointer s6 to new string object : copy constructor is called
	cin.get();
}
