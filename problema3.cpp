/* Problema 3:

Ex3: Elaborați un program C/C++ care va permite citirea unui șir de cifre de la tastatură până la întâlnirea caracterului "$". 
După citire datele se scriu într-un fișier text și se preiau din fișierul respectiv, apoi se calculează suma valorilor numerice.


*/




#include <iostream>
#include <string>
#include <fstream>
#include <sstream>



using namespace std;


int WinMain(){

    ifstream inFile("problema3numere.txt");

    string linie;
    string numere;


    while(getline(inFile,linie) && linie != "$"){
        numere = numere + " " + linie;
    }
    inFile.close(); 


    //Preluarea datelor din fisier
    ofstream rezFile("numereRezultat.txt");

    rezFile << "Numerele: " << numere;



    //Convertirea unui string in mai multe variabile integer

    int count = 0,s;

    stringstream ss(numere);

    for(int i = 0; i < numere.length(); i++){
        if(isdigit(numere[i])){
            count++;
        }
    }

    int* vector = new int[count];
    int current;
    int numCount = 0;

    while(ss >> current){
        vector[numCount] = current;
        numCount++;
    }

    for(int i = 0; i < numCount; i++){
        s += vector[i];
    }

    //Afisarea rezultatului la consola si la fisier
    cout << s;
    rezFile << "Suma: " << s;



    rezFile.close();
    delete[] vector;


    return 0;
}


