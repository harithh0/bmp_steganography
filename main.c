#include <stdio.h>

int main() {

  FILE *fileptr;

  unsigned char header[54]; // 54 bytes
  fileptr = fopen("blackbuck.bmp", "rb");
  fread(header, sizeof(unsigned char), 54, fileptr);

  int dataOffset =
      header[10] | (header[11] << 8) | (header[12] << 16) | (header[13] << 24);

  int width =
      header[18] | (header[19] << 8) | (header[20] << 16) | (header[21] << 24);

  int height =
      header[22] | (header[23] << 8) | (header[24] << 16) | (header[25] << 24);

  printf("Width: %d\n", width);
  printf("Height: %d\n", height);
  printf("Pixel Data Starts At Byte: %d\n", dataOffset);
  return 0;
}
