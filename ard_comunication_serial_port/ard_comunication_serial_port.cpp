#include <Windows.h>
#include "pch.h"
#include <time.h>
#include <string>
#include <iostream>

using namespace System;
using namespace System::IO::Ports;
using namespace std;
String^ Pomiar(); 

//DEFINICJA KLAS
ref class Roslina {
public:
    int goal_moist = 0;
};
ref class Kaktus:public Roslina //dziedziczenie
{
public:
    int goal_moist = 5;

};
ref class Storczyk :public Roslina {
public:
    int goal_mois = 15;
};



int main()
{
    //START PROGRAMU
    String^ ostatni_pomiar; 
    int wybor;
    ostatni_pomiar = Pomiar();
    Console::WriteLine(ostatni_pomiar);
    Kaktus^ kaktus = gcnew Kaktus();
    Storczyk^ storczyk = gcnew Storczyk();
    cout << "SIEMA to program"<<endl;
    cout << "Wybierz roslinke do przebadania:" << endl;
    cout << "1.Kaktus\n2.Palma\n3.Storczyk\n4.Wyjdz z programu" << endl;
    cin >> wybor;
    ostatni_pomiar = Pomiar();
    int liczba_ostatni_pomiar = System::Convert::ToInt32(ostatni_pomiar);
    while (wybor != 4) {
        switch (wybor) {
        case 1:
            
            if (liczba_ostatni_pomiar < kaktus->goal_moist) {
                cout << "ZA MALO WODY" << endl;
            }
            else {
                cout << "JEST GIT" << endl;
                cout << "SIEMA to program" << endl;
                cout << "Wybierz roslinke do przebadania:" << endl;
                cout << "1.Kaktus\n2.Palma\n3.Storczyk\n4.Wyjdz z programu" << endl;
                cin >> wybor;
                ostatni_pomiar = Pomiar();
                int liczba_ostatni_pomiar = System::Convert::ToInt32(ostatni_pomiar);
            }
            break;

        case 2:
            
            if (liczba_ostatni_pomiar < storczyk->goal_moist) {
                cout << "ZA MALO WODY" << endl;
            }
            else {
                cout << "JEST GIT" << endl;
                cout << "SIEMA to program" << endl;
                cout << "Wybierz roslinke do przebadania:" << endl;
                cout << "1.Kaktus\n2.Palma\n3.Storczyk\n4.Wyjdz z programu" << endl;
                cin >> wybor;
                ostatni_pomiar = Pomiar();
                int liczba_ostatni_pomiar = System::Convert::ToInt32(ostatni_pomiar);

            }
            break;


        }
    }
    return 0;
}





//DEFINICJA FUNKCJI

String^ Pomiar() { 
    String^ wynik_pomiaru;

    SerialPort serialPort;
    serialPort.BaudRate = 9600;
    serialPort.PortName = "COM7";

    serialPort.Open();
    serialPort.Write("A");

    wynik_pomiaru = serialPort.ReadLine();
    serialPort.Close();

    return wynik_pomiaru; // Return the value
}
