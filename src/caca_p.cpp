#include <iostream> 
#include <vector>
#include <string> 
#include "caca_p.h"
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
void procurarVertical (vector <string > &vtr1 ,string & chave,size_t  lin) {
    string str_aux;
    char c;
    for (size_t  i = 0; i < lin; ++i){
        for (size_t j = 0; j < lin; ++j){
            if(vtr1[i][j]==chave[0]&& i+chave.length()<20){
                for ( size_t k = 0; k <chave.length() ; ++k){
                    c=vtr1[i+k][j];
                    str_aux.push_back(c);
                }
                if(str_aux==chave){
                    for (size_t k =0 ; k < chave.length(); ++k){
                        vtr1[i+k][j] -= 32 ;
                    }
                
                }          
          
            }
        str_aux.erase();
        }    
    }

}
void procurarGeral(vector <string > &vtr1 ,string & chave,size_t  lin){
        procurarHorizontal(vtr1,chave,lin);
        procurarVertical(vtr1,chave,lin);
        antchave(chave);
        procurarHorizontal(vtr1,chave,lin);
        procurarVertical(vtr1,chave,lin);
}