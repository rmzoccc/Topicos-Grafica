// sumamatriz.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <ctime>

using namespace std;

#define fil  1024
#define col 506 // mi sistema solo acepta hasta 506 no llega a 512 pues no compila.


void sumamatriz(unsigned int m[fil][col]) {
    int *p;
    p=new int [col];
    for (int i = 0; i < col; i++) {
        p[i] = 0;
        for (int j = 0; j < fil; j++)
        {
            p[i] = p[i] + m[j][i];
        }
    }
     unsigned int temp = 0;
    for (int h = 0; h < col; h++) {
        cout << p[h] << " ";
        temp = temp + p[h];
    }
    cout << endl;
    cout << temp << endl;
    free(p);
}

int main()
{
    unsigned int m[fil][col];
 for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j++)
            m[i][j] = 1;
    }
    unsigned t0, t1;
    t0 = clock();
    sumamatriz(m);
    t1 = clock();
    double time = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << "Tiempo de ejecución: " << time << endl;
    return 0;
}
