#include <iostream> 
#include <vector>
#include <string> 
#include <algorithm>
#include <stdio.h>
using namespace std;

void procurarHorizontal (string & str ,string & chave) {
    size_t posicao;
    posicao = str.find(chave);
    for (size_t i = posicao; i < chave.size()+posicao; i++)
        str[i] = toupper(str[i]);

}
int main(){ 
	int lin=20,col=20,contador=0;
    string str,chave;
    vector<vector<char> > vtr1;
    vtr1.reserve(lin); 
    
    for (int j = 0; j<lin ; j++) {
        vtr1[j].reserve(col);
    
    }

    for (int j = 0; j < lin; ++j){
    	for (int k = 0; k <col; ++k){
    		cin >> vtr1[j][k];
    	}
    }

    while(contador<19){
        getline(cin,chave,'\n');
        
        for (int j = 0; j < lin; ++j){
            for (int k = 0; k <col; ++k){
                str.push_back(vtr1[j][k]);
            }
            procurarHorizontal(str,chave);
            str.erase();
        }
        contador++;
    }
    return 0;
}	

