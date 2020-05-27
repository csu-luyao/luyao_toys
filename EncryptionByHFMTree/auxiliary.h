#ifndef AUXILIARY_H_
#define AUXILIARY_H_
#include<string>
#include<map>
#include<vector>
#include"HFMTree.h"

void ShowMenu();
void ReadCommand(std::string& cmd);
bool CheckCommand(const std::string& cmd);
void CMDE_Code(std::map<char, size_t>& count_char, HuffmanTree& hfmt);
void CMDI_Initialization(std::map<char, size_t>& count_char);
void CMDQ_Quit();
void DisplayHfmKV(std::map<char, size_t>& count_char);
void RunCMD(const std::string& cmd, std::map<char, size_t>& count_char,bool flag_init);

#endif