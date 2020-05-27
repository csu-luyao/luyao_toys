#include<iostream>
#include<string>
#include<vector>
#include<map>
#include"pro_function.h"
#include"HFMTree.h"

std::string cmd;
std::map<char, size_t> count_char;
std::map<size_t, std::string> char_code;
bool flag_init = false;
Node* root = NULL;

int main(void)
{
	ShowMenu();
	while (true)
	{
		ReadCommand(cmd);
		RunCMD(cmd,count_char,flag_init,char_code,root);
	}
}