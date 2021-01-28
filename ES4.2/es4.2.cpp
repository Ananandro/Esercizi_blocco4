#include <iostream>
#include <cctype>
#include <cstring>
#define LMAX 100


using namespace std;


int lungStringa(char* s){

    for(int i=0; i<LMAX; i++){

        if(s[i] == '\0') return (i);

    }

    return -1;
}


void inserzSeparatore(char* s, char* out, char sep, const int &len){

    int x = 0;

    for(int i=0; i <= len; i++){

        out[x] = s[i];
        out[x+1] = sep;
        x += 2;
    }

}


int wordCounter(char* s, const int &len){

    int num=1;

    for(int i=0; i <= len; i++){

        if((s[i] == ' ') && (s[i+1] != ' ')) num++;
        
        }

    return num;
}


void lcsCounter(char* s, int &lettere, int &cifre, int &punteggiatura, const int &len){

    for(int i=0; i <= len; i++){

        if(isalpha(s[i]) > 0) lettere++;
        if(isdigit(s[i]) > 0) cifre++;
        if(ispunct(s[i]) > 0) punteggiatura++;

    }
}


void trovaoccorrenze(char* s, int asciii[], int &occorrenzemax, const int &len){

    for(int i=0; i<=len; i++){

        asciii[int(s[i])] ++;
    }

    int max = 0;

    for(int z=0; z<127; z++){

        if(asciii[z] > max){

            occorrenzemax = z;
            max = asciii[z];
        }

    }

}




int main(){

    char stringa[LMAX];
    int lunghezza;
    char stringa2[2*LMAX];
    char separatore;
    int wordnum;
    int numlett = 0;
    int numcifr = 0;
    int numpunt = 0;
    int ascii[127] = {0};
    int maxoccorrenze;

    cout << "Inserisci una frase di max 99 caratteri (NB: usare solo caratteri della tabella ASCII NON ESTESA)." << endl;
    cin.getline(stringa, 100);
    cout << "Ora inserisci carattere di separazione: " << endl;
    cin >> separatore;

    lunghezza = lungStringa(stringa);

    cout << "La stringa e' lunga " << lunghezza << " caratteri." << endl;

    inserzSeparatore(stringa, stringa2, separatore, lunghezza);

    cout << "La stringa modificata con il separatore e':" << endl;

    for(int i=0; i <= (lunghezza*2 + 1); i++){

        cout << stringa2[i];
    }

    cout << endl << "La stringa invertita e':" << endl;

    for(int i=(lunghezza-1); i>=0; i--){

        cout << stringa[i];
    }

    wordnum = wordCounter(stringa, lunghezza);

    cout << endl << "La stringa e' composta da " << wordnum << " parole." << endl;

    lcsCounter(stringa, numlett, numcifr, numpunt, lunghezza);

    cout << "Nella stringa sono presenti " << numlett << " lettere, " << numcifr << " cifre e " << numpunt << " segni di punteggiatura." << endl;

    trovaoccorrenze(stringa, ascii, maxoccorrenze, lunghezza);

    cout << "Il carattere che si e' ripetuto piu' volte e' " << char(maxoccorrenze) << ", che si e' ripetuto " << ascii[maxoccorrenze] << " volte e che corrisponde a " << maxoccorrenze << " sulla tabella ASCII non estesa." << endl;

    return 0; 
}