#include "graphics2.h"
#include <cmath>
#include <iostream>

#define PI 3.14159265

using namespace std;

int unghi,lungime,culoare;
double r,minim;


///functia recursiva care deseneaza copacul
void DrawTree(int angle, double length, double x, double y) {
    ///unde vrem sa ne oprim
    if(length > minim) {

        ///calcularea noilor coordonate pt linia care pleaca din x,y
        double x2 = x + (double)(cos(PI * angle / 180) * length);
        double y2 = y + (double)(sin(PI * angle / 180) * length);

        ///culoare
        setcolor(culoare);

        ///desenare linie
        line(x, y, x2, y2);

        ///cele 2 functii pt stanga si dreapta
        DrawTree(angle - unghi, length * r, x2, y2);
        DrawTree(angle + unghi, length * r, x2, y2);

    }
}

int main() {

    ///citire date
    cout<<"lingimea initiala a liniei(int): ";
    cin>>lungime;
    cout<<"\nlungimea minima pe care o va avea linia(double): ";
    cin>>minim;
    cout<<"\nunghiul dintre linii(int): ";
    cin>>unghi;
    cout<<"\nraportul intre iteratii(double 0<r<1): ";
    cin>>r;
    cout<<"\nculoarea copacului(int 0<=cul<=15): ";
    cin>>culoare;

    int driver, mode;

    ///initializare ecran
    initgraph(&driver, &mode, "", 800, 800);

    ///poz de la care incepem
    int x = getmaxx() / 2;
    int y = getmaxy() / 2;

    ///desenare copac
    DrawTree(-90, lungime, x, y+100);

    ///oprire cand se apasa o tasta
    while( !kbhit() );
    ///inchidere ecran
    closegraph();

    return 0;
}
