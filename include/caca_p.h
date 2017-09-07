#ifndef __CACA_P_H__
#define __CACA_P_H__
#include <iostream>
#include <vector>

using namespace std;

void antchave(string & chave);
void procurarHorizontal (vector <string > &vtr1 ,string & chave,size_t  lin);
void procurarVertical (vector <string > &vtr1 ,string & chave,size_t  lin);
void procurarGeral(vector <string > &vtr1 ,string & chave,size_t  lin);
#endif