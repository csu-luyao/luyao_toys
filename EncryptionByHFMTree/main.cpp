#include<iostream>
#include<string>
#include<vector>
#include<map>
#include"auxiliary.h"
#include"HFMTree.h"

std::string cmd;
std::map<char, size_t> count_char;
std::map<size_t, std::string> char_code;
bool flag_init = false;
HuffmanTree hfmt(count_char);

int main(void)
{
	ShowMenu();
	while (true)
	{
		ReadCommand(cmd);
		RunCMD(cmd,count_char,flag_init);
	}
}