#ifndef AUXILIARY_H_
#define AUXILIARY_H_
#include<string>
#include<map>
#include<vector>
#include"HFMTree.h"

void ShowMenu();
int stoint(std::string s);
bool CheckInt(std::string s);
void ReadCommand(std::string& cmd);
bool CheckCommand(const std::string& cmd);
void CMDE_Code(std::map<char, size_t>& count_char, 
	std::map<size_t, std::string>& char_code, Node*& root);
void CMDI_Initialization(std::map<char, size_t>& count_char, 
	std::map<size_t, std::string>& char_code, Node*& root);
void CMDP_Print(std::map<char, size_t>& count_char, std::map<size_t, std::string>& char_code);
void CMDQ_Quit();
void DisplayHfmKV(std::map<char, size_t>& count_char, std::map<size_t, std::string>& code_char);
void RunCMD(const std::string& cmd, std::map<char, size_t>& count_char,
	bool& flag_init, std::map<size_t, std::string>& code_char, Node*& root);

#endif