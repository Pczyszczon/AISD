#include <iostream>
#include <list>
#include <string>
#include <random>

template <class T>
class HashTable
{
	private:
		int buckets;
		std::list<T> *table;
		
		int hash(T value)
		{
			return std::hash<std::string>()(value) % buckets; 
		}

		int hash2(std::string word)
		{
			const int p = 31;
			const int m = 10000;
			int p_pow = 1;
			int result = 0;
			for (char c : word)
			{
				result += ((c - '0') * p_pow) % m;
				p_pow = (p_pow * p) % m;
			}
			
			return result;
		}

	public:
		HashTable(int buckets)
		{
			this->buckets = buckets;
			table = new std::list<T>[buckets];
		}

		~HashTable()
		{
			delete []table;
		}

		void insert(T value)
		{
			table[hash(value)].push_back(value);
		}

		T find(T value)
		{
			int index = hash(value);
			auto i = table[index].begin();

			for (; i != table[index].end(); i++)
			{
				if (*i == value)
				{
					break;
				}
			}

			return *i;
		}

		void remove(T value)
		{
			int index = hash(value);
			auto i = table[index].begin();

			for (; i != table[index].end(); i++)
			{
				if (*i == value)
				{
					break;
				}
			}

			if (i != table[index].end())
			{
				table[index].erase(i);
			}
			
		}

		void print()
		{
			for (int i = 0; i < buckets; i++)
			{
				std::cout << "Bucket #" << i << std::endl;
				for(T element : table[i])
				{
					std::cout << element << " ";
				}
				std::cout << std::endl;
			}
		}

};

std::string getRandomWord() 
{
	char chars[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'};
	std::string word;
	for (int i=0; i<5; i++)
		word += chars[rand()%11];
	return word;
}

int main()
{
	HashTable<std::string> tab(7);
	std::list<std::string> first200words;

	for (int i=0; i<1000; i++)
	{
		std::string word = getRandomWord();
		tab.insert(word);
		if (i <= 200)
			first200words.push_back(word);
	}
	tab.print();

	for (auto it = first200words.begin(); it != first200words.end(); it++)
	{
		tab.remove(*it);
	}
	tab.print();
}