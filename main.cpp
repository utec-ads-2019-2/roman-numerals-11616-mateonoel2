#include <iostream>
#include <stack>
#define unt unsigned int
using namespace std;
char numeros[10] = {'0','1','2','3','4','5','6','7','8','9'};

bool esNum(char x){
    for(char c : numeros)
        if(x == c) return true;
    return false;
}

unt charToNum(char x){
    return x - 48;
}

void toRoman(string x){
    unt contador = 1;
    unt num = 0;
    stack<string> respuesta;
    for(int i = x.size()-1; i>=0; i--){
        num = charToNum(x[i]);
        switch (contador){
            case 1:
                if(num <= 3){
                    for(unt j = 0; j<num; j++) respuesta.push("I");
                }
                else if(num==4){
                    respuesta.push("IV");
                }
                else if(num>4 and num<9){
                    for(unt j = 5; j<num; j++) respuesta.push("I");
                    respuesta.push("V");
                }
                else if(num==9){
                    respuesta.push("IX");
                }
                break;
            case 2:
                if(num <= 3){
                    for(unt j = 0; j<num; j++) respuesta.push("X");
                }
                else if(num==4){
                    respuesta.push("XL");
                }
                else if(num>4 and num<9){
                    for(unt j = 5; j<num; j++) respuesta.push("X");
                    respuesta.push("L");
                }
                else if(num==9){
                    respuesta.push("XC");
                }
                break;
            case 3:
                if(num <= 3){
                    for(unt j = 0; j<num; j++) respuesta.push("C");
                }
                else if(num==4){
                    respuesta.push("CD");
                }
                else if(num>4 and num<9){
                    for(unt j = 5; j<num; j++) respuesta.push("C");
                    respuesta.push("D");
                }
                else if(num==9){
                    respuesta.push("CM");
                }
                break;
            case 4:
                if(num <= 3){
                    for(unt j = 0; j<num; j++) respuesta.push("M");
                }
                break;
        }
            contador++;
    }

    while(!respuesta.empty()){
        cout<<respuesta.top();
        respuesta.pop();
    }
    cout<<'\n';
}

unt toNum(char actual, char next){
    if(actual=='I'){
        if(next=='V' or next=='X')
            return -1;
        return 1;}
    else if(actual=='V')
        return 5;
    else if(actual=='X'){
        if(next=='L' or next=='C')
            return -10;
        return 10;}
    else if(actual=='C'){
        if(next=='D' or next=='M')
            return -100;
        return 100;}
    else if(actual=='M')
        return 1000;
    else if(actual=='D')
        return 500;
    else
        return 50;
}

void toArabic(string x){
    unt result=0;
    for(size_t i=0,j=1;i<x.size();i++,j++){
        result+=toNum(x[i],x[j]);
    }
    cout<<result<<'\n';
}

void transformar(string x){
    if(esNum(x[0])) toRoman(x);
    else toArabic(x);
}

int main() {
    string x;
    while(cin>>x){
        transformar(x);
    }
    return 0;
}