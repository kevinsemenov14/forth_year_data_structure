#include "huffmen.h"
int main()
{
	// Build frequency table
	int frequencies[UniqueSymbols] = {0};
	const char* ptr = SampleString;
	while (*ptr != '\0')
		++frequencies[*ptr++];

	INode* root = BuildTree(frequencies);

	HuffCodeMap codes;
	GenerateCodes(root, HuffCode(), codes);
	delete root;


	std :: cout << "kevin Semenov Huffmen assignment 14\n";
	std :: cout << "The following code will build a binary tree using a set string\n"
			"the binary tree will count how many each letter is used and will create a\n"
			"frequency of every letter used then will encode and decode the string\n\n";
	for (HuffCodeMap::const_iterator it = codes.begin(); it != codes.end(); ++it)
	{
		std::cout << "Char " << it->first << " ";
		std::copy(it->second.begin(), it->second.end(),
				std::ostream_iterator<bool>(std::cout));
		std::cout << std::endl;

	}

	std::cout << "decoding using the map\n";
	int x = 0;
for(int i = 0; i < word.length();i++)
{
	for (HuffCodeMap::const_iterator it = codes.begin(); it != codes.end(); ++it)
	{

		if(it->first == word[i])
		{
		std::copy(it->second.begin(), it->second.end(),
				std::ostream_iterator<bool>(std::cout));

		if(x % 15 == 0)
		std::cout << std::endl;
		x++;
		}

	}
}

std::cout << "\nThe compression ratio is 6,323 bytes over 13,283 bytes\n ";


	return 0;
}
