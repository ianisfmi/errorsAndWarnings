/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
int parameterTest(int a)
{
    std::cout<<"Simple non-consst parameter (Pass by value). Printing: a = " << a <<std::endl;
    return a;
}
/*
int parameterTest(const int a)
{
    std::cout<<"Simple const parameter (Pass by value). Printing a = " << a <<std::endl;
    return a;
}
*/
int parameterTest(int& a)
{
    std::cout<<"Non-const reference parameter (pass by reference). Printing a = " << a <<std::endl;
    return a;
}

int parameterTest(const int& a)
{
    std::cout<<"Const Reference parameter (pass by reference). Printing a = " << a <<std::endl;
    return a;
}


class testClass
{
public:
	testClass();
	testClass(const testClass& obj);
	int mFirst;
};

testClass::testClass()
{
	std::cout<<"firstClass default constructor" << std::endl;
}

testClass::testClass(const testClass& obj)
{
	std::cout<<"firstClass copy constructor" << std::endl;

}

testClass testFunc()
{
	testClass a;
	std::cout << "a.mFirst = " << a.mFirst << std::endl;
	return a;
}


int main()
{
	std::cout<<"Hello World" << std::endl;
	testClass b;
	b = testFunc();
	std::cout << "b.mFirst = " << b.mFirst << std::endl;
	
	parameterTest(5);
	int y = 6;
	parameterTest(y);
	const int z = 7;
	parameterTest(z);
	int& w = z;
	parameterTest(w);
	
	return 0;
}

/*
<source>: In function 'int main()':
<source>:69:22: error: call of overloaded 'parameterTest(int)' is ambiguous
   69 |         parameterTest(5);
      |         ~~~~~~~~~~~~~^~~
<source>:10:5: note: candidate: 'int parameterTest(int)'
   10 | int parameterTest(int a)
      |     ^~~~~~~~~~~~~
<source>:28:5: note: candidate: 'int parameterTest(const int&)'
   28 | int parameterTest(const int& a)
      |     ^~~~~~~~~~~~~
<source>:71:22: error: call of overloaded 'parameterTest(int&)' is ambiguous
   71 |         parameterTest(y);
      |         ~~~~~~~~~~~~~^~~
<source>:10:5: note: candidate: 'int parameterTest(int)'
   10 | int parameterTest(int a)
      |     ^~~~~~~~~~~~~
<source>:22:5: note: candidate: 'int parameterTest(int&)'
   22 | int parameterTest(int& a)
      |     ^~~~~~~~~~~~~
<source>:28:5: note: candidate: 'int parameterTest(const int&)'
   28 | int parameterTest(const int& a)
      |     ^~~~~~~~~~~~~
<source>:73:22: error: call of overloaded 'parameterTest(const int&)' is ambiguous
   73 |         parameterTest(z);
      |         ~~~~~~~~~~~~~^~~
<source>:10:5: note: candidate: 'int parameterTest(int)'
   10 | int parameterTest(int a)
      |     ^~~~~~~~~~~~~
<source>:28:5: note: candidate: 'int parameterTest(const int&)'
   28 | int parameterTest(const int& a)
      |     ^~~~~~~~~~~~~
<source>:74:18: error: binding reference of type 'int&' to 'const int' discards qualifiers
   74 |         int& w = z;
      |                  ^
<source>:75:22: error: call of overloaded 'parameterTest(int&)' is ambiguous
   75 |         parameterTest(w);
      |         ~~~~~~~~~~~~~^~~
<source>:10:5: note: candidate: 'int parameterTest(int)'
   10 | int parameterTest(int a)
      |     ^~~~~~~~~~~~~
<source>:22:5: note: candidate: 'int parameterTest(int&)'
   22 | int parameterTest(int& a)
      |     ^~~~~~~~~~~~~
<source>:28:5: note: candidate: 'int parameterTest(const int&)'
   28 | int parameterTest(const int& a)
      |     ^~~~~~~~~~~~~
Compiler returned: 1/*