// CW4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Kontrolka {

private:
    string etykieta;


protected:
    void Naglowek() {
        cout << etykieta;
    }

public:
    Kontrolka(string e) : etykieta(e) {}

    string getEtykieta() {
        return etykieta;
    }


    virtual string  Dialog() = 0;


};


class LiniaEdycyjna : public Kontrolka {
private:
    int dlugosc;

public:
       
 
            
    int getDlugosc() {
        return dlugosc;
    }

    string Dialog() {
        Naglowek();
        return Edycja();
    }

protected:



    string Edycja();
};





class ListaWyboru : public Kontrolka{
private:
    int licznosc;
    vector<string> opcje;
public:
    string Dialog();


protected: 
    string Wybor();


};

class LiniaZLista : public LiniaEdycyjna, public ListaWyboru {
public: 
    string Dialog;
};

int main()
{


}

