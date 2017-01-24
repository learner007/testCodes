// reads 0 to N-1 samples from raw file (stereo)
// assumes 16bit samples

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {


// read in_buf from test file
  FILE *in_buffer_file;
  in_buffer_file = fopen("test.raw", "r+b");

  if(in_buffer_file == NULL) {
    printf("\n test.raw does not exist");
    exit;
  }


  fseek(in_buffer_file, 0, SEEK_SET); // put pointer in required starting position 

  short int* buffer; // each sample 2 bytes
  int N = 900
  buffer = (short int*) malloc (4*N);
  fread(mix_buffer, 2, 2*N, in_buffer_file); 

  fclose(in_buffer_file);

// test if file is read correctly
  FILE * filetmp = fopen("test.txt", "w");

  for (int k = 0; k <= 2*900; k = (k+2) ) { // MUST start from k = 0
    if ( (k & 1) == 0) { // true if even; checks if last binary digit is zero
      fprintf(filetmp, "\n Left buffer[%d] = %d %04x %f Right buffer[%d] = %d %04x %f", k, buffer[k], buffer[k], float(buffer[k])/32768, k+1, buffer[k+1],  buffer[k+1], float(buffer[k+1])/32768);
    }


}
