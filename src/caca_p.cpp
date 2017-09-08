#include <iostream> 
#include <vector>
#include <string> 
#include "caca_p.h"
void antchave(string & chave){
    string str_aux=chave;
    size_t i=0,j=chave.length();
    
    while(i<chave.length()||j>0){
        chave[i]=str_aux[j-1]; 
    i++,j--;
    }
}
void procurarHorizontal (vector <string > &vect_funcion ,string & chave,size_t  lin) {
    for (size_t  i = 0; i < lin; ++i){
        size_t  posicao = vect_funcion[i].find(chave);     
        for (size_t j = posicao; j < chave.length()+posicao; j++){
            vect_funcion[i][j] -= 32;
            
        }

    }

}
void procurarVertical (vector <string > &vect_funcion ,string & chave,size_t  lin) {
    string str_aux;
    char c;
    for (size_t  i = 0; i < lin; ++i){
        for (size_t j = 0; j < lin; ++j){
            if(vect_funcion[i][j]==chave[0]&& i+chave.length()<20){
                for ( size_t k = 0; k <chave.length() ; ++k){
                    c=vect_funcion[i+k][j];
                    str_aux.push_back(c);
                }
                if(str_aux==chave){
                    for (size_t k =0 ; k < chave.length(); ++k){
                        vect_funcion[i+k][j] -= 32 ;
                    }
                
                }          
          
            }
        str_aux.erase();
        }    
    }

}
void procurarDiagonal(vector <string > &vect_funcion ,string & chave,size_t  lin){
    string str_aux;
    char c;
    int q;
    for (size_t  i = 0; i < lin; ++i){
        for (size_t j = 0; j < lin; ++j){
            if(vect_funcion[i][j]==chave[0] && i+chave.length()<20 && j+chave.length()<20  && j-chave.length()>=0 && i-chave.length()>=0){
                for(q = 0 ; q<4 ; q++){                     
                    str_aux.erase();
                    if(q==0){
                        for (size_t x = 0; x < chave.length(); ++x){
                                c=vect_funcion[i+x][j+x];
                                str_aux.push_back(c);
                            }
                        }
                        if(str_aux==chave){
                            for (size_t x = 0 ; x < chave.length(); ++x){
                                    vect_funcion[i+x][j+x] -= 32 ;
                            }
                        }
                        
                    }
                    str_aux.erase();
                    if(q==1){
                        for (size_t x = 0; x < chave.length(); ++x){
                                c=vect_funcion[i+x][j-x];
                                str_aux.push_back(c);
                        }
                        if(str_aux==chave){
                            for (size_t x = 0 ; x < chave.length(); ++x){
                                    vect_funcion[i+x][j-x] -= 32 ;
                                
                            }
                        }    
                    }
                    str_aux.erase();
                    if(q==2){
                        for (size_t x = 0; x < chave.length(); ++x){
                                c=vect_funcion[i-x][j-x];
                                str_aux.push_back(c);
                        }
                        if(str_aux==chave){
                            for (size_t x = 0 ; x < chave.length(); ++x){
                                    vect_funcion[i-x][j-x] -= 32 ;
                            }
                        }
                    }
                    str_aux.erase();
                    if(q==3){
                        for (size_t x = 0; x < chave.length(); ++x){
                                c=vect_funcion[i-x][j+x];
                                str_aux.push_back(c);
                        }
                        if(str_aux==chave){
                            for (size_t x = 0 ; x < chave.length(); ++x){
                                    vect_funcion[i-x][j+x] -= 32 ;
                            }
                        }
                    q++; 
                }
                       
            }
        }
    } 
}
void procurarGeral(vector <string > &vect_funcion ,string & chave,size_t  lin){
        procurarHorizontal(vect_funcion,chave,lin);
        procurarVertical(vect_funcion,chave,lin);
        procurarDiagonal(vect_funcion,chave,lin);
        antchave(chave);
        procurarHorizontal(vect_funcion,chave,lin);
        procurarVertical(vect_funcion,chave,lin);
        procurarDiagonal(vect_funcion,chave,lin);
}