#include <iostream>


using namespace std;


bool eAbbondante(int x){

    int somma = 0;

    for(int z=1; z <= (x/2); z++){

        if((x%z) == 0){

            somma += z;
        }
    }

    if(somma > x) return true;
    else return false;

}


bool eDifettivo(int x){

    int somma = 0;

    for(int z=1; z <= (x/2); z++){

        if((x%z) == 0){

            somma += z;
        }
    }

    if(somma < x) return true;
    else return false;

}


bool eAbbondanteePrim(int x){

    int somma = 0;

    for(int z=1; z <= (x/2); z++){

        if((x%z) == 0){

            somma += z;

            if(eDifettivo(z) == false) return false;
        }
    }  

    if(somma > x) return true;
    else return false;
}


bool eSemiperfetto(int x){

    int somma = 0;

    for(int z=1; z <= (x/2); z++){

        if((x%z) == 0){

            somma += z;

            if(somma > x) return false;
            else if (somma == x) return true;
        }
    }

    return false;

}




int main(){

    int input;
    bool abbondante, difettivo, abbondante_primitivo, semiperfetto, bizzarro;

    cout << "Inserisci un numero e ti diro' le caratteristiche di tutti i numeri compresi tra 0 e quel numero." << endl;
    cin >> input;


    for(int i=1; i<=input; i++){

        abbondante_primitivo = eAbbondanteePrim(i);

        if(abbondante_primitivo == false){
            abbondante = eAbbondante(i);
        }

        if((abbondante_primitivo == false) && (abbondante == false)){
            difettivo = eDifettivo(i);
        }

        if(difettivo == false){
            semiperfetto = eSemiperfetto(i);
        }

        if((semiperfetto == true) && (abbondante == false) && (abbondante_primitivo == false)){
            bizzarro = true;
            semiperfetto = false;
        }

    cout << "Il numero " << i << " e': ";

        if(abbondante_primitivo == true) cout << "abbondante primitivo ";
        else if(abbondante == true) cout << "abbondate ";
        else if(difettivo == true) cout << "difettivo ";
        else if(semiperfetto == true) cout << "semiperfetto ";
        else if(bizzarro == true) cout << "bizzarro ";
        else cout << "brutto ";
        
        cout << endl;

        abbondante = abbondante_primitivo = semiperfetto = bizzarro = difettivo = false;
    }


    return 0;

}