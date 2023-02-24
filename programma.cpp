// file matricole.txt
//  11485 Marius
//  11486 Andrei
//  11487 Marco
// file straordinari
//  11485 10
//  11486 20
//  11487 30
// file stipendi
//  11485 1000
//  11486 2000
//  11487 3000

#include <iostream>
#include <fstream>

using namespace std;

void findNameByCod(string cod)
{

    // file matricole.txt
    //  11485 Marius
    //  11486 Andrei
    //  11487 Marco

    ifstream fileMatricole("matricola.txt");
    if (fileMatricole.is_open())
    {
        cout << "File matricole.txt aperto correttamente" << endl;
        string nome = "";
        string line;
        while (getline(fileMatricole, line))
        {
            for (int i = 0; i < 6; i++)
            {


                if (line[i] != cod[i])
                {
                    break;
                }
                else if (i == 4)
                {
                    for (int j = 6; j < line.length(); j++)
                    {
                        nome += line[j];
                    }

                    // il nome si trova dal carattere 7 fino alla fine della linea
                    // ho trovato, mi devo mettere il nome in nome
                    //  senza usare la funzione substr
                }
            }
        }
        cout << "La matricola: " << cod << " corrisponde al nome: " << nome << endl;
    }
    else
    {
        cout << "Impossibile aprire il file matricole.txt" << endl;
    }
}

void findSalaryByCod(string cod)
{
    ifstream fileStipendio("stipendio.txt");
    
    string stipendio="";

        if (fileStipendio.is_open())
    {
        cout << "File stipendio.txt aperto correttamente" << endl;
        string nome = "";
        string line;
        while (getline(fileStipendio, line))
        {
            for (int i = 0; i < 6; i++)
            {


                if (line[i] != cod[i])
                {
                    break;
                }
                else if (i == 4)
                {
                    for (int j = 6; j < line.length(); j++)
                    {
                        nome += line[j];
                    }

                    // il nome si trova dal carattere 7 fino alla fine della linea
                    // ho trovato, mi devo mettere il nome in nome
                    //  senza usare la funzione substr
                }
            }
        }
        cout << "La matricola " << cod << " corrisponde allo stipendio: " << nome << endl;
    }
    else
    {
        cout << "Impossibile aprire il file stipendio.txt" << endl;
    }

}

void findSalaryByName(string name)
{
    cout << "sono findSalaryByName" << endl;
}

int main()
{
    cout << "Benvenuto nel programma di calcolo stipendi" << endl;

    bool flag = true;
    while (flag)
    {
        cout << "------------------------------------------------------" << endl;
        cout << "Inserisci il numero della funzionalità che vuoi attivare: " << endl;
        cout << "1. Matricola -> Nome" << endl;
        cout << "2. Matricola -> Stipendio" << endl;
        cout << "3. Nome -> Stipendio" << endl;
        int scelta = 1; //TODO : ELIMINA QUI
        //cin >> scelta;          
        cout << "Inserisci quello che vuoi cercare: ";
        string input;
        cin >> input;

        if (scelta < 1 || scelta > 3)
        {
            cout << "Scelta non valida" << endl;
        }
        else
        {
            if (scelta == 1 && input.length() == 5)
            {
                findNameByCod(input);
                flag = false;
            }
            else if (scelta == 2 && input.length() == 5)
            {
                findSalaryByCod(input);
                flag = false;
            }
            else if (scelta == 3)
            {
                findSalaryByName(input);
                flag = false;
            }
            else
            {
                cout << "Scelta non valida" << endl;
            }
        }
    }

    cout << "Fine" << endl;
}