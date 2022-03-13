#include "Canvas.h"

Canvas::Canvas(int width, int height) { 
    this->nrLinii = height;
    this->nrColoane = width;
    Matrice = new char*[this->nrLinii];
    for(int i = 0; i < this->nrLinii; i++)
        Matrice[i] = new char[this->nrColoane];
    for(int i = 0; i < this->nrLinii; i++)
        for(int j = 0; j < this->nrColoane; j++)
            Matrice[i][j] = ' ';
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    for(int i = 0; i < 360; i++)
        SetPoint(cos(i * PI / 180) * ray + x, 2 * sin(i * PI / 180) * ray + y, ch);
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for(int i = 0; i <= 360; i++)
        DrawLine(x, y, cos(i * PI / 180) * ray + x, 2 * sin(i * PI / 180) * ray + y, ch);
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    DrawLine(left, top, right, top, ch);                // linia de sus
    DrawLine(right, top, right, bottom, ch);            // linia din dreapta
    DrawLine(left, top, left, bottom, ch);              // linia din stanga
    DrawLine(right, bottom, left, bottom, ch);          // linia de jos
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for(int i = top; i <= bottom; i++)
        DrawLine(left, i, right, i, ch); //umplu dreptunghiul cu linii orizontale
}

void Canvas::SetPoint(int x, int y, char ch) {
    Matrice[x][y] = ch;         //setez punctul de coordonate x si y, punand ch pe pozitia respectiva din matrice
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = abs(x2 - x1), dy = -abs(y2 - y1);
    int error = dx + dy;
    int sx = (x1 < x2) + (x1 >= x2) * (-1), sy = (y1 < y2) + (y1 >= y2) * (-1);
    bool ok = true;
    while(ok) {
        SetPoint(x1, y1, ch);
        if(x1 == x2 && y1 == y2)
            ok = false;
        else {
            int p = error * 2;
            if(p >= dy) {
                error += dy;
                x1 += sx;
            }
            if(p <= dx) {
                error += dx;
                y1 += sy;
            }
        }
    }
}

void Canvas::Print() {
    for (int i = 0; i < this->nrLinii; i++) {
        for (int j = 0; j < this->nrColoane; j++)
            cout << Matrice[i][j];
        cout << "\n";
    }
}

void Canvas::Clear() {
    for(int i = 0; i < this->nrLinii; i++)
        for(int j = 0; j < nrColoane; j++)
            Matrice[i][j] = ' ';
    for(int i = 0; i < this->nrLinii; i++)
        delete[] Matrice[i];
    delete[] Matrice;
}