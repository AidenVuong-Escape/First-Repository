#include <iostream>

int Square(int x); // Tells the compiler the function exists and what its signature is, but does not provide the implementation.

int main()
{
	std::cout << "Square of 7 is " << Square(7) << "\n";
	return 0;
}

int Square(int x)
{
	return x * x;
}