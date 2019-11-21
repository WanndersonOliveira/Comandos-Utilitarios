#include <stdio.h>
#include "utilitarios.h"

int main(int argc, char** argv){
	return copiar(*(argv+1), *(argv+2));
}
