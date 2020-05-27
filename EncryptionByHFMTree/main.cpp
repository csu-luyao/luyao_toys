#include<iostream>
#include<string>
#include<vector>
#include<map>
#include"auxiliary.h"
#include"HFMTree.h"

std::string cmd;
std::map<char, size_t> count_char;

int main(void)
{
	ShowMenu();
	ReadCommand(cmd);
	ProcessText(count_char);
	std::map<char, size_t>::iterator itmp = count_char.begin();
	while (itmp != count_char.end())
	{
		if (itmp->first == ' ')
		{
			std::cout << "char: Space" << itmp->first << "\n" << "num: " << itmp->second << std::endl;
		}
		else if (itmp->first == '\n')
		{
			std::cout << "char: " << "Enter" << "\n" << "num: " << itmp->second << std::endl;
		}
		else
		{
			std::cout << "char: " << itmp->first << "\n" << "num: " << itmp->second << std::endl;
		}
		++itmp;
	}
}