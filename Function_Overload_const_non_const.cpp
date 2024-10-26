#include <iostream>
int parameterTest(int a)
{
    std::cout<<"Simple non-consst parameter (Pass by value). Printing: a = " << a <<std::endl;
    return a;
}

int parameterTest(const int a)
{
    std::cout<<"Simple const parameter (Pass by value). Printing a = " << a <<std::endl;
    return a;
}

int main()
{
	parameterTest(5);
	int y = 6;
	parameterTest(y);
	
	return 0;
}

/*
The above code results in the following output when compiled
<source>:8:5: error: redefinition of 'int parameterTest(int)'
    8 | int parameterTest(const int a)
      |     ^~~~~~~~~~~~~
<source>:2:5: note: 'int parameterTest(int)' previously defined here
    2 | int parameterTest(int a)
      |     ^~~~~~~~~~~~~
Compiler returned: 1
*/