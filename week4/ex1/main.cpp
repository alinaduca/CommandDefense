#include "MyLibrary.h"
#define _CRT_SECURE_NO_WARNINGS

int main(int argc, char* argv[])
{
    MyLibrary l1 = { cout };
    l1.print_books();//Ar trebui sa printeaze "Found -1 books"// -1 daca nu avem nimic

    int l2_ids[] = { 3356, 2213, 5723, 1246, 12573, 6424, 85573, 2235113, 2241 };
    MyLibrary l2 = { cout ,9,l2_ids };
    l2.print_books();//Ar trebui sa printeaze "Found 9 books"
    
    //Cand decomentati codul de aici va incepe sa crape, dar de ce?, urmari secvential ce se intampla dupa ce implementati
    MyLibrary l2_copy = l2;
    cout << "Before update" << endl;
    cout << "Library l2: Book index 0 " << l2.get_book_index_by_id(0) << endl; //valoare asteptata 3356 (fiind valoarea de pe index-ul 0)
    cout << "Library l2_copy: Book index 0 " << l2_copy.get_book_index_by_id(0) << endl;//valoare asteptata 3356 (fiind valoarea de pe index-ul 0)
    l2_copy.update_books_id_by_index(0, 20);
    cout << "Library l2: Book index 0 " << l2.get_book_index_by_id(0) << endl;//3356
    cout << "Library l2_copy: Book index 0 " << l2_copy.get_book_index_by_id(0) << endl;//20
    //Ce se intampla? unde e problema? Implementati constructorul lipsa

    MyLibrary l3 = { cout ,20,15,200 };
    l3.print_books();//Ar trebui sa printeaze "Found 20 books"

    MyLibrary l4 = { cout, "12;13;15;16" };
    l4.print_books();//Ar trebui sa printeaze "Found 4 books"

    MyLibrary l5 = { cout, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    l5.print_books();//Ar trebui sa printeaze "Found 10 books"
    
    //La final decomantati functiile si implementati -- nu aveti voie sa modificati liniile de mai jos (doar sa le decomentati)
    const MyLibrary& l = l5;
    cout << "Found book number: " << l.get_books_count() << endl;
    cout << "Found book id: " << l.get_book_index_by_id(3) << endl;
    cout << "Found book id: " << l.get_book_index_by_id(10) << endl;
    return 0;
}