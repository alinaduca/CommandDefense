#define _CRT_SECURE_NO_WARNINGS
#include "MyLibrary.h"
#include <cstdio>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <fstream>
#include <cstdarg>

void MyLibrary::print_books()
{
    output_stream << "Found " << books_number << " books" << endl;
    for (int i = 0; i < books_number; i++)
        output_stream << "Book: " << i << " " << books[i] << endl;
}

MyLibrary::~MyLibrary()
{
    delete[] books;
}

void MyLibrary::update_books_id_by_index(int book_index, int book_id)
{
    if (book_index < books_number)
        this->books[book_index] = book_id;
}

MyLibrary::MyLibrary(ostream& output_stream) : output_stream(output_stream)
{
    this->books_number  = -1;
    this->books         = nullptr;
}

MyLibrary::MyLibrary(ostream& output_stream, int books_number, int* books) : output_stream(output_stream)
{
    this->books_number  = books_number;
    this->books          = new int[books_number];
    for (int i = 0; i < books_number; i++)
        this->books[i] = books[i];
}

MyLibrary::MyLibrary(ostream& output_stream, int books_number, int min, int max) : output_stream(output_stream)
{
    this->books_number = books_number;
    this->books        = new int[books_number];
    for (int i = 0; i < books_number; i++)
        this->books[i] = rand() % (max - min) + min;
}

MyLibrary::MyLibrary(ostream& output_stream, const char* books_values) : output_stream(output_stream)
{
    char* s = new char[strlen(books_values) + 1];
    strcpy(s, books_values);
    int number = 0;
    for (int i = 0; s[i]; i++)
        if (s[i] == ';')
            number++;
    this->books_number = number + 1;
    this->books        = new int[this->books_number];
    char* p            = strtok(s, ";");
    number             = 0;
    while (p)
    {
        int id = 0;
        for (int i = 0; p[i]; i++)
            id = id * 10 + p[i] - '0';
        this->books[number++] = id;
        p = strtok(NULL, ";");
    }
}

MyLibrary::MyLibrary(ostream& output_stream, int books_count, ...) : output_stream(output_stream)
{
    this->books_number = books_count;
    this->books        = new int[books_count];
    va_list args;
    va_start(args, books_count);
    for (int i = 0; i < books_count; i++)
        this->books[i] = va_arg(args, int);
    va_end(args);
}

MyLibrary::MyLibrary(const MyLibrary& other) : MyLibrary(other.output_stream, other.books_number, other.books) { }
 
//MyLibrary::MyLibrary(const MyLibrary& other) : output_stream(other.output_stream)
//{
//
//    this->books_number = other.books_number;
//    this->books        = new int[this->books_number];
//    for (int i = 0; i < this->books_number; i++)
//        this->books[i] = other.books[i];
//}
