/* Problema 5:

    Ex5: Elaborați un cod C/C++ care va citi din fișierul mesaj.txt două enunțuri. 
    Afișați șirul obținut prin concatenarea enunțului al doilea la primul..

*/



#include <iostream>
#include <string> 
#include <fstream>



//Fisierul il cream manual si citim din el.



using namespace std;

int main(){

    ifstream cfile("mesaj.txt");


    //Verificam daca fisierul a fost deschis

    if(!cfile.is_open()){
        cerr << "Errorare: Fisierul nu este deschis";
        return 1;
    }




    string continut;
    string linie;


    while(getline(cfile, linie)){
        continut += linie;
    }
    cout << "Acesta este continutul concatinat: " << continut;

    cfile.close();

    ofstream ifile("mesaj.txt");

    ifile << continut;

    ifile.close();

    return 0;
}