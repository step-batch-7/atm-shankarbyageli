#include<stdio.h>
#include "atm.h"

void display_notes(unsigned int notes) { 
  unsigned short denominations[] = DENOMINATIONS;
  unsigned int count = 0;
  for (int i=0; i<8; i++) {
    count = (notes << (i*4)) >> 28;
    count && printf("%d %s of Rs. %d\n", count, count > 1 ? "notes" : "note", denominations[i]);
  }
}

unsigned int get_money(unsigned short amount) {
  unsigned int notes_count = 0x0;
  if(amount > 31999) {
    return notes_count;
  }
  unsigned short denominations[] = DENOMINATIONS;
  for (int i=0; i<8; i++) {
    notes_count <<= 4;
    notes_count |= amount / denominations[i];
    amount %= denominations[i];
  }
  return notes_count;
}

