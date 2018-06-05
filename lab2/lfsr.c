#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void lfsr_calculate(uint16_t *reg) {

  /* YOUR CODE HERE */
  uint16_t bit11 = ((1 << 5) & *reg) >> 5;
  uint16_t bit13 = ((1 << 3) & *reg) >> 3;
  uint16_t bit14 = ((1 << 2) & *reg) >> 2;
  uint16_t bit16 = ((1 << 0) & *reg) >> 0;
  *reg = *reg >> 1;
  uint16_t bit = bit11 ^ (bit13 ^ (bit14 ^ bit16));
  *reg = *reg | bit << 15;
}

int main() {
  int8_t *numbers = (int8_t*) malloc(sizeof(int8_t) * 65535);
  if (numbers == NULL) {
    printf("Memory allocation failed!");
    exit(1);
  }

  memset(numbers, 0, sizeof(int8_t) * 65535);
  uint16_t reg = 0x1;
  uint32_t count = 0;
  int i;

  do {
    count++;
    numbers[reg] = 1;
    if (count < 24) {
      printf("My number is: %u\n", reg);
    } else if (count == 24) {
      printf(" ... etc etc ... \n");
    }
    for (i = 0; i < 32; i++)
      lfsr_calculate(&reg);
  } while (numbers[reg] != 1);

  printf("Got %u numbers before cycling!\n", count);

  if (count == 65535) {
    printf("Congratulations! It works!\n");
  } else {
    printf("Did I miss something?\n");
  }

  free(numbers);

  return 0;
}

