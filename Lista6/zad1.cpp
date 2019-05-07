#include <iostream>
#include <string>

int hash(std::string word)
{
	const int p = 31;
	const int m = 977;
	int p_pow = 1;
	int result = 0;
	for (char c : word)
	{
		result += ((c - '0') * p_pow) % m;
		p_pow = (p_pow * p) % m;
	}
	
	return result;
}

int main()
{
	std::string words[] = {"Test", "tesT", "Abc", "abc", "asdsad"};
	
	for (std::string word : words)
	{
		std::cout << "Word: " << word << std::endl;
		std::cout << "Hash: " << hash(word) << std::endl;
	}
	
	return 0;
}