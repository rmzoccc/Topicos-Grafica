#include<iostream>
#include "BMP.h"

int main() {

    //Lectura y modificacion
	BMP bmp("A.bmp");
	bmp.fill_region(0, 0, 50, 50, 0, 0, 255, 255);
	bmp.fill_region(150, 0, 100, 150, 0, 255, 0, 255);
	bmp.write("A_result.bmp");

	BMP bmp1("B.bmp");
	bmp1.fill_region(0, 0, 50, 50, 0, 0, 255, 255);
	bmp1.fill_region(150, 0, 100, 150, 0, 255, 0, 255);
	bmp1.write("B_result.bmp");

	BMP bmp2("C.bmp");
	bmp2.fill_region(0, 0, 100, 200, 0, 0, 255, 255);
	bmp2.fill_region(150, 0, 209, 203, 0, 255, 0, 255);
	bmp2.write("C_result.bmp");

	BMP bmp3("D.bmp");
	bmp3.fill_region(0, 0, 100, 200, 0, 0, 255, 255);
	bmp3.write("D_result.bmp");


	return 0;
}
