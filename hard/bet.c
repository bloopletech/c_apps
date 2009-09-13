#include "bet.h"

//this function returns the payoff for a bet b, given a bet of size amount.
float payoff(bet* b, float amount)
{
   int type = b->type;
   if(type >= BET_0 && type <= BET_36)
   {
      return BET_0_PAYOFF;
   }
   else if(type >= BET_ROW3 && type <= BET_ROW36)
   {
      return BET_ROW3_PAYOFF;
   }
   else if(type >= BET_ODD && type <= BET_EVEN)
   {
      return BET_ODD_PAYOFF;
   }
   else if(type >= BET_1TO18 && type <= BET_19TO36)
   {
      return BET_1TO18_PAYOFF;
   }
   else if(type == BET_5NUM)
   {
      return BET_5NUM_PAYOFF;
   }
   else
   {
      return -1;
   }
}

//this function returns 1 if and only if the bet in b will return a payoff.
//hit is the value the ball landed on.
int didPayoff(bet* b, int hit)
{
   int type = b->type;
   switch(type)
   {
      case 0: return (hit == 0) ? 1 : 0; break;
      case 1: return (hit == 1) ? 1 : 0; break;
      case 2: return (hit == 2) ? 1 : 0; break;
      case 3: return (hit == 3) ? 1 : 0; break;
      case 4: return (hit == 4) ? 1 : 0; break;
      case 5: return (hit == 5) ? 1 : 0; break;
      case 6: return (hit == 6) ? 1 : 0; break;
      case 7: return (hit == 7) ? 1 : 0; break;
      case 8: return (hit == 8) ? 1 : 0; break;
      case 9: return (hit == 9) ? 1 : 0; break;
      case 10: return (hit == 10) ? 1 : 0; break;
      case 11: return (hit == 11) ? 1 : 0; break;
      case 12: return (hit == 12) ? 1 : 0; break;
      case 13: return (hit == 13) ? 1 : 0; break;
      case 14: return (hit == 14) ? 1 : 0; break;
      case 15: return (hit == 15) ? 1 : 0; break;
      case 16: return (hit == 16) ? 1 : 0; break;
      case 17: return (hit == 17) ? 1 : 0; break;
      case 18: return (hit == 18) ? 1 : 0; break;
      case 19: return (hit == 19) ? 1 : 0; break;
      case 20: return (hit == 20) ? 1 : 0; break;
      case 21: return (hit == 21) ? 1 : 0; break;
      case 22: return (hit == 22) ? 1 : 0; break;
      case 23: return (hit == 23) ? 1 : 0; break;
      case 24: return (hit == 24) ? 1 : 0; break;
      case 25: return (hit == 25) ? 1 : 0; break;
      case 26: return (hit == 26) ? 1 : 0; break;
      case 27: return (hit == 27) ? 1 : 0; break;
      case 28: return (hit == 28) ? 1 : 0; break;
      case 29: return (hit == 29) ? 1 : 0; break;
      case 30: return (hit == 30) ? 1 : 0; break;
      case 31: return (hit == 31) ? 1 : 0; break;
      case 32: return (hit == 32) ? 1 : 0; break;
      case 33: return (hit == 33) ? 1 : 0; break;
      case 34: return (hit == 34) ? 1 : 0; break;
      case 35: return (hit == 35) ? 1 : 0; break;
      case 36: return (hit == 36) ? 1 : 0; break;

      case BET_ROW3: return (hit >= 1 && hit <= 3) ? 1 : 0; break;
      case BET_ROW6: return (hit >= 4 && hit <= 6) ? 1 : 0; break;
      case BET_ROW9: return (hit >= 7 && hit <= 9) ? 1 : 0; break;
      case BET_ROW12: return (hit >= 10 && hit <= 12) ? 1 : 0; break;
      case BET_ROW15: return (hit >= 13 && hit <= 15) ? 1 : 0; break;
      case BET_ROW18: return (hit >= 16 && hit <= 18) ? 1 : 0; break;
      case BET_ROW21: return (hit >= 19 && hit <= 21) ? 1 : 0; break;
      case BET_ROW24: return (hit >= 22 && hit <= 24) ? 1 : 0; break;
      case BET_ROW27: return (hit >= 25 && hit <= 27) ? 1 : 0; break;
      case BET_ROW30: return (hit >= 28 && hit <= 30) ? 1 : 0; break;
      case BET_ROW33: return (hit >= 31 && hit <= 33) ? 1 : 0; break;
      case BET_ROW36: return (hit >= 34 && hit <= 36) ? 1 : 0; break;

      case BET_COLUMN1: return (hit == 1
                             || hit == 4
                             || hit == 7
                             || hit == 10
                             || hit == 13
                             || hit == 16
                             || hit == 19
                             || hit == 22
                             || hit == 25
                             || hit == 28
                             || hit == 31
                             || hit == 34) ? 1 : 0; break;
      case BET_COLUMN2: return (hit == 2
                             || hit == 5
                             || hit == 8
                             || hit == 11
                             || hit == 14
                             || hit == 17
                             || hit == 20
                             || hit == 23
                             || hit == 26
                             || hit == 29
                             || hit == 32
                             || hit == 35) ? 1 : 0; break;
      case BET_COLUMN3: return (hit == 3
                             || hit == 6
                             || hit == 9
                             || hit == 12
                             || hit == 15
                             || hit == 18
                             || hit == 21
                             || hit == 24
                             || hit == 27
                             || hit == 30
                             || hit == 33
                             || hit == 36) ? 1 : 0; break;

      case BET_FIRST12: return (hit >= 1 && hit <= 12) ? 1 : 0; break;
      case BET_MIDDLE12: return (hit >= 13 && hit <= 24) ? 1 : 0; break;
      case BET_LAST12: return (hit >= 25 && hit <= 36) ? 1 : 0; break;

      case BET_ODD: return (hit %2 != 0) 1 : 0; break;
      case BET_EVEN: return (hit % 2 == 0) 1 : 0; break;

      case BET_RED: return (hit == 1
                         || hit == 3
                         || hit == 5
                         || hit == 7
                         || hit == 9
                         || hit == 12
                         || hit == 14
                         || hit == 16
                         || hit == 18
                         || hit == 18
                         || hit == 19
                         || hit == 21
                         || hit == 23
                         || hit == 25
                         || hit == 27
                         || hit == 30
                         || hit == 32
                         || hit == 34
                         || hit == 36) ? 1 : 0; break;
      case BET_BLACK return (hit == 2
                          || hit == 4
                          || hit == 6
                          || hit == 8
                          || hit == 10
                          || hit == 11
                          || hit == 13
                          || hit == 15
                          || hit == 17
                          || hit == 20
                          || hit == 22
                          || hit == 24
                          || hit == 26
                          || hit == 28
                          || hit == 29
                          || hit == 31
                          || hit == 33
                          || hit == 35) ? 1 : 0; break;

      case BET_1TO18: return (hit >= 1 && hit <= 18) ? 1 : 0; break;
      case BET_19TO36: return (hit >= 19 && hit <= 36) ? 1 : 0; break;

      case BET_5NUM: return (hit >= 0 && hit <= 3) ? 1 : 0; break;

      default: return 0;
   }
}


//this function returns 1 if and only if the bet in b will return a payoff.
//hit is the value the ball landed on.
float getPayoff(bet* b, int hit)
{
   int type = b->type;
   float amount = b->amount;
   switch(type)
   {
      case 0: return (hit == 0) ? amount * BET_0_PAYOFF : 0; break;
      case 1: return (hit == 1) ? amount * BET_1_PAYOFF : 0; break;
      case 2: return (hit == 2) ? amount * BET_2_PAYOFF : 0; break;
      case 3: return (hit == 3) ? amount * BET_3_PAYOFF : 0; break;
      case 4: return (hit == 4) ? amount * BET_4_PAYOFF : 0; break;
      case 5: return (hit == 5) ? amount * BET_5_PAYOFF : 0; break;
      case 6: return (hit == 6) ? amount * BET_6_PAYOFF : 0; break;
      case 7: return (hit == 7) ? amount * BET_7_PAYOFF : 0; break;
      case 8: return (hit == 8) ? amount * BET_8_PAYOFF : 0; break;
      case 9: return (hit == 9) ? amount * BET_9_PAYOFF : 0; break;
      case 10: return (hit == 10) ? amount * BET_10_PAYOFF : 0; break;
      case 11: return (hit == 11) ? amount * BET_11_PAYOFF : 0; break;
      case 12: return (hit == 12) ? amount * BET_12_PAYOFF : 0; break;
      case 13: return (hit == 13) ? amount * BET_13_PAYOFF : 0; break;
      case 14: return (hit == 14) ? amount * BET_14_PAYOFF : 0; break;
      case 15: return (hit == 15) ? amount * BET_15_PAYOFF : 0; break;
      case 16: return (hit == 16) ? amount * BET_16_PAYOFF : 0; break;
      case 17: return (hit == 17) ? amount * BET_17_PAYOFF : 0; break;
      case 18: return (hit == 18) ? amount * BET_18_PAYOFF : 0; break;
      case 19: return (hit == 19) ? amount * BET_19_PAYOFF : 0; break;
      case 20: return (hit == 20) ? amount * BET_20_PAYOFF : 0; break;
      case 21: return (hit == 21) ? amount * BET_21_PAYOFF : 0; break;
      case 22: return (hit == 22) ? amount * BET_22_PAYOFF : 0; break;
      case 23: return (hit == 23) ? amount * BET_23_PAYOFF : 0; break;
      case 24: return (hit == 24) ? amount * BET_24_PAYOFF : 0; break;
      case 25: return (hit == 25) ? amount * BET_25_PAYOFF : 0; break;
      case 26: return (hit == 26) ? amount * BET_26_PAYOFF : 0; break;
      case 27: return (hit == 27) ? amount * BET_27_PAYOFF : 0; break;
      case 28: return (hit == 28) ? amount * BET_28_PAYOFF : 0; break;
      case 29: return (hit == 29) ? amount * BET_29_PAYOFF : 0; break;
      case 30: return (hit == 30) ? amount * BET_30_PAYOFF : 0; break;
      case 31: return (hit == 31) ? amount * BET_31_PAYOFF : 0; break;
      case 32: return (hit == 32) ? amount * BET_32_PAYOFF : 0; break;
      case 33: return (hit == 33) ? amount * BET_33_PAYOFF : 0; break;
      case 34: return (hit == 34) ? amount * BET_34_PAYOFF : 0; break;
      case 35: return (hit == 35) ? amount * BET_35_PAYOFF : 0; break;
      case 36: return (hit == 36) ? amount * BET_36_PAYOFF : 0; break;

      case BET_ROW3: return (hit >= 1 && hit <= 3) ? amount * BET_ROW3_PAYOFF : 0; break;
      case BET_ROW6: return (hit >= 4 && hit <= 6) ? amount * BET_ROW6_PAYOFF : 0; break;
      case BET_ROW9: return (hit >= 7 && hit <= 9) ? amount * BET_ROW9_PAYOFF : 0; break;
      case BET_ROW12: return (hit >= 10 && hit <= 12) ? amount * BET_ROW12_PAYOFF : 0; break;
      case BET_ROW15: return (hit >= 13 && hit <= 15) ? amount * BET_ROW15_PAYOFF : 0; break;
      case BET_ROW18: return (hit >= 16 && hit <= 18) ? amount * BET_ROW18_PAYOFF : 0; break;
      case BET_ROW21: return (hit >= 19 && hit <= 21) ? amount * BET_ROW21_PAYOFF : 0; break;
      case BET_ROW24: return (hit >= 22 && hit <= 24) ? amount * BET_ROW24_PAYOFF : 0; break;
      case BET_ROW27: return (hit >= 25 && hit <= 27) ? amount * BET_ROW27_PAYOFF : 0; break;
      case BET_ROW30: return (hit >= 28 && hit <= 30) ? amount * BET_ROW30_PAYOFF : 0; break;
      case BET_ROW33: return (hit >= 31 && hit <= 33) ? amount * BET_ROW33_PAYOFF : 0; break;
      case BET_ROW36: return (hit >= 34 && hit <= 36) ? amount * BET_ROW36_PAYOFF : 0; break;

      case BET_COLUMN1: return (hit == 1
                             || hit == 4
                             || hit == 7
                             || hit == 10
                             || hit == 13
                             || hit == 16
                             || hit == 19
                             || hit == 22
                             || hit == 25
                             || hit == 28
                             || hit == 31
                             || hit == 34) ? amount * BET_COLUMN1_PAYOFF : 0; break;
      case BET_COLUMN2: return (hit == 2
                             || hit == 5
                             || hit == 8
                             || hit == 11
                             || hit == 14
                             || hit == 17
                             || hit == 20
                             || hit == 23
                             || hit == 26
                             || hit == 29
                             || hit == 32
                             || hit == 35) ? amount * BET_COLUMN2_PAYOFF : 0; break;
      case BET_COLUMN3: return (hit == 3
                             || hit == 6
                             || hit == 9
                             || hit == 12
                             || hit == 15
                             || hit == 18
                             || hit == 21
                             || hit == 24
                             || hit == 27
                             || hit == 30
                             || hit == 33
                             || hit == 36) ? amount * BET_COLUMN3_PAYOFF : 0; break;

      case BET_FIRST12: return (hit >= 1 && hit <= 12) ? amount * BET_FIRST12_PAYOFF : 0; break;
      case BET_MIDDLE12: return (hit >= 13 && hit <= 24) ? amount * BET_MIDDLE12_PAYOFF : 0; break;
      case BET_LAST12: return (hit >= 25 && hit <= 36) ? amount * BET_LAST12_PAYOFF : 0; break;

      case BET_ODD: return ((hit != 0) && !divisible(hit, 2)) amount * BET_ODD_PAYOFF : 0; break;
      case BET_EVEN: return ((hit != 0) && divisible(hit, 2)) amount * BET_EVEN_PAYOFF : 0; break;

      case BET_RED: return (hit == 1
                         || hit == 3
                         || hit == 5
                         || hit == 7
                         || hit == 9
                         || hit == 12
                         || hit == 14
                         || hit == 16
                         || hit == 18
                         || hit == 18
                         || hit == 19
                         || hit == 21
                         || hit == 23
                         || hit == 25
                         || hit == 27
                         || hit == 30
                         || hit == 32
                         || hit == 34
                         || hit == 36) ? amount * BET_RED_PAYOFF : 0; break;
      case BET_BLACK return (hit == 2
                          || hit == 4
                          || hit == 6
                          || hit == 8
                          || hit == 10
                          || hit == 11
                          || hit == 13
                          || hit == 15
                          || hit == 17
                          || hit == 20
                          || hit == 22
                          || hit == 24
                          || hit == 26
                          || hit == 28
                          || hit == 29
                          || hit == 31
                          || hit == 33
                          || hit == 35) ? amount * BET_BLACK_PAYOFF : 0; break;

      case BET_1TO18: return (hit >= 1 && hit <= 18) ? amount * BET_1TO18_PAYOFF : 0; break;
      case BET_19TO36: return (hit >= 19 && hit <= 36) ? amount * BET_19TO36_PAYOFF : 0; break;

      case BET_5NUM: return (hit >= 0 && hit <= 3) ? amount * BET_5NUM_PAYOFF : 0; break;

      default: return 0;
   }
}

int divisible(int a, int b)
{
   while(a >= b)
   {
      a -= b;
   }
   return (a == 0);
}
