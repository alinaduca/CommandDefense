#pragma once
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;
//implementati constructorii de mai jos
//adaugati urmatoarele functii:
//       - get_books_count -> returneaza numarul de carti
//       - get_book_index_by_id -> returneaza cartea de pe id-ul dat ca parametru, sau -1 daca nu exista
//       -> cele 2 functii ar trebuie sa faca codul de la final sa compileze

class MyLibrary
{
    ostream& output_stream;//referinta la obiectul de afisare
    int books_number;//cate carti avem in vector, -1 daca nu avem nimic
    int* books;//vector de carti alocat dinamic
public:
    //constructor in care setam doar obiectul pe care il vom folosi pentru afisare, ar trebui initializate TOATE variabilele
    MyLibrary(ostream& output_stream);

    ////lista intializare: obiectul pe care il vom folosi pentru afisare, numar de carti, vector de id-uri de carti --> aloca memorie pentru vector si copiaza numerele
    MyLibrary(ostream& output_stream, int books_number, int* books);

    // constructor in care setam doar obiectul pe care il vom folosi pentru afisare, numarul de carti, min si max --> generare un vector de books_number intre min si max ca valori
    MyLibrary(ostream& output_stream, int books_number, int min, int max);

    //books values are separated by ';' in the books_values
    MyLibrary(ostream& output_stream, const char* books_values);

    //variadic args
    MyLibrary(ostream& output_stream, int books_count, ...);

    //nu aveti voie sa modifcati aceasta functie
    void print_books();

    //nu aveti voie sa modifcati aceasta functie
    ~MyLibrary();
    
    //nu aveti voie sa modifcati aceasta functie
    void update_books_id_by_index(int book_index, int book_id);

    MyLibrary(const MyLibrary& other);

    int get_book_index_by_id(int id) const
    {
        if (id > -1 && id < this->books_number)
            return this->books[id];
        return -1;
    }

    int get_books_count() const
    {
        return this->books_number;
    }
};