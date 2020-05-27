#ifndef AUXILIARY_H_
#define AUXILIARY_H_
#include<string>
#include<map>
#include<vector>

void ShowMenu();
void ReadCommand(std::string& cmd);
bool CheckCommand(const std::string& cmd);
void ProcessText(std::map<char, size_t>& count_char);
void CMDI_Init();

#endif