#include <iostream> 
#include <vector>
#include <string> 
#include <algorithm>
#include "caca_p.h"
using namespace std;

int main(){ 
	size_t  lin=20;
    string chave,lixo;
    vector<string> vtr1;
    vtr1.resize(lin); 
    
   for (size_t  i = 0; i < lin; ++i){
    		getline (cin,lixo);
            vtr1[i]=lixo;
   }

    
    getline(cin,chave,'\n');
    while(chave != ""){
        procurarGeral(vtr1,chave,lin);
        getline(cin,chave,'\n');
    }
    for (size_t i = 0; i <lin ; ++i){
        cout <<vtr1[i]<< endl; 
    }
    return 0;
}	

