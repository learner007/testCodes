// reads 0 to N-1 samples from raw file (mono)
// assumes 16bit samples

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {


// read in_buf from test file
// Note: The input files must be in 16bit, stereo, 48000 Hz, raw(PCM) format
  FILE *in_buffer_file;
  in_buffer_file = fopen("test.raw", "r+b");

  if(in_buffer_file == NULL) {
    printf("\n test.raw does not exist");
    exit;
  }


  fseek(in_buffer_file, 0, SEEK_SET); // put pointer in required starting position 

  short int* buffer; // 2 bytes
  int N = 900
  buffer = (short int*) malloc (2*N);
  fread(mix_buffer, 2, N, in_buffer_file); 

  fclose(in_buffer_file);

// test if file is read correctly
  FILE * filetmp = fopen("test.txt", "w");

  for (int k = 0; k <= N; k++) { // MUST start from k = 0
    fprintf(filetmp, "\n buffer[%d] = %d %f", k, buffer[k], float(buffer[k])/32768);  //16bit amplitude max value=2^(16-1)
  }

}
