#include<stdio.h>
#include "atm.h"

void display_notes(unsigned int notes) { 
  unsigned short denominations[] = {2000, 500, 100, 50, 20, 10, 5, 1};
  unsigned int denomination_pos = 0xf0000000;
  unsigned int count = 0;
  for (int i=0; i<8; i++) {
    count = notes & denomination_pos;
    count && printf("%d notes of Rs. %d\n", (count >> ((7-i)*4)), denominations[i]);
    denomination_pos = denomination_pos >> 4;
  }
}

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

