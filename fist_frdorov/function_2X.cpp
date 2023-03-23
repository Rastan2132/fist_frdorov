#include "Header.h"

Uzond** create(int rows, int cols) {
	Uzond** Uzonds = new Uzond * [rows];
	for (int i = 0; i < rows; i++) {
		Uzonds[i] = new Uzond[cols];
	}
	return Uzonds;
}