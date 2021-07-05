#include <iostream>
#include <ctime>
#include <cstdlib>
#include <clocale>

using namespace std;

void CopyMas(int* source, int* dest, int size)
{
	for (int i = 0; i < size; i++) 
	dest[i] = source[i];
}

bool CompMas(int* source, int* dest, int size)
{
	for (int i = 0; i < size; i++) 
	{
		if (source[i] != dest[i])
			return false;
		else
			return true;
	}
}

void TestCopyMas(int* source, int* dest, int size) 
{
	if (CompMas(source, dest, size))
		cout << "1";
	else
		cout << "0";
}

int main()
{
	const int size = 1000;

	int source[size], dest[size];
	
    for (int i = 0; i < size; i++) source[i] = rand() % 10;
	
	CopyMas(source, dest, size);
	TestCopyMas(source, dest, size);
	return 0;

}
