#include <iostream> 
#include <vector>
#include <string> 
#include <algorithm>
#include "caca_p.h"
using namespace std;

int main(){ 
	size_t  lin=20;
    string chave,str;
    vector<string> vect_str;
    vect_str.resize(lin); 
    
   for (size_t  i = 0; i < lin; ++i){//leitura da matriz de letras
    		getline (cin,str);
            vect_str[i]=str;
   }
//leitura das chaves
//chamada da funcao para cada chave 
    getline(cin,chave,'\n');
    while(chave != ""){
        procurarGeral(vect_str,chave,lin);
        getline(cin,chave,'\n');
    }
//saida das chaves
    for (size_t i = 0; i <lin ; ++i){
        cout <<vect_str[i]<< endl; 
    }
    
    return 0;
}	

