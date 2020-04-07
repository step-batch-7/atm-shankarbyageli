#include "atm.h"

unsigned int get_money(unsigned short amount) {
  unsigned int notes_count = 0x00000000;
  if(amount > 31999) return notes_count;
  unsigned short denominations[] = {2000, 500, 100, 50, 20, 10, 5, 1};
  for (int i=0; i<8; i++) {
    notes_count = notes_count << 4;
    notes_count += amount / denominations[i];
    amount %= denominations[i];
  }
  return notes_count;
}

