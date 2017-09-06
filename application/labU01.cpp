#include <iostream> 
#include <vector>
#include <string> 
#include <algorithm>
#include <stdio.h>
using namespace std;
void antchave(string & chave){
    string aux=chave;
    size_t i=0,j=chave.length();
    
    while(i<chave.length()||j>0){
        chave[i]=aux[j-1]; 
    i++,j--;
    }
}
void procurarHorizontal (vector <string > &vtr1 ,string & chave,size_t  lin) {
    for (size_t  i = 0; i < lin; ++i){
        size_t  posicao = vtr1[i].find(chave);     
        for (size_t j = posicao; j < chave.length()+posicao; j++){
            vtr1[i][j] -= 32;
            
        }

    }

}
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
        procurarHorizontal(vtr1,chave,lin);
        antchave(chave);
        procurarHorizontal(vtr1,chave,lin);
        getline(cin,chave,'\n');
    }
    for (size_t i = 0; i <lin ; ++i){
        cout <<vtr1[i]<< endl; 
    }
    return 0;
}	

