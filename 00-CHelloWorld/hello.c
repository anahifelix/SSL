#include <stdio.h>
int main() {
  FILE *punteroArchivo = fopen("output.txt","w");
  fprintf(punteroArchivo, "Hola mundo en txt!");
  fclose(punteroArchivo);

  printf("HOLA MUNDOOO!!");
  
  return 0;
}
