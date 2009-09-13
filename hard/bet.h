
#define BET_SINGLE 0
#define BET_0 0
#define BET_0_PAYOFF 35
#define BET_1 1
#define BET_1_PAYOFF 35
#define BET_2 2
#define BET_2_PAYOFF 35
#define BET_3 3
#define BET_3_PAYOFF 35
#define BET_4 4
#define BET_4_PAYOFF 35
#define BET_5 5
#define BET_5_PAYOFF 35
#define BET_6 6
#define BET_6_PAYOFF 35
#define BET_7 7
#define BET_7_PAYOFF 35
#define BET_8 8
#define BET_8_PAYOFF 35
#define BET_9 9
#define BET_9_PAYOFF 35
#define BET_10 10
#define BET_10_PAYOFF 35
#define BET_11 11
#define BET_11_PAYOFF 35
#define BET_12 12
#define BET_12_PAYOFF 35
#define BET_13 13
#define BET_13_PAYOFF 35
#define BET_14 14
#define BET_14_PAYOFF 35
#define BET_15 15
#define BET_15_PAYOFF 35
#define BET_16 16
#define BET_16_PAYOFF 35
#define BET_17 17
#define BET_17_PAYOFF 35
#define BET_18 18
#define BET_18_PAYOFF 35
#define BET_19 19
#define BET_19_PAYOFF 35
#define BET_20 20
#define BET_20_PAYOFF 35
#define BET_21 21
#define BET_21_PAYOFF 35
#define BET_22 22
#define BET_22_PAYOFF 35
#define BET_23 23
#define BET_23_PAYOFF 35
#define BET_24 24
#define BET_24_PAYOFF 35
#define BET_25 25
#define BET_25_PAYOFF 35
#define BET_26 26
#define BET_26_PAYOFF 35
#define BET_27 27
#define BET_27_PAYOFF 35
#define BET_28 28
#define BET_28_PAYOFF 35
#define BET_29 29
#define BET_29_PAYOFF 35
#define BET_30 30
#define BET_30_PAYOFF 35
#define BET_31 31
#define BET_31_PAYOFF 35
#define BET_32 32
#define BET_32_PAYOFF 35
#define BET_33 33
#define BET_33_PAYOFF 35
#define BET_34 34
#define BET_34_PAYOFF 35
#define BET_35 35
#define BET_35_PAYOFF 35
#define BET_36 36
#define BET_36_PAYOFF 35


#define BET_ROWS 40
#define BET_ROW3 40
#define BET_ROW3_PAYOFF 11
#define BET_ROW6 41
#define BET_ROW6_PAYOFF 11
#define BET_ROW9 42
#define BET_ROW9_PAYOFF 11
#define BET_ROW12 43 
#define BET_ROW12_PAYOFF 11
#define BET_ROW15 44
#define BET_ROW15_PAYOFF 11
#define BET_ROW18 45
#define BET_ROW18_PAYOFF 11
#define BET_ROW21 46
#define BET_ROW21_PAYOFF 11
#define BET_ROW24 47
#define BET_ROW24_PAYOFF 11
#define BET_ROW27 48
#define BET_ROW27_PAYOFF 11
#define BET_ROW30 49
#define BET_ROW30_PAYOFF 11
#define BET_ROW33 50
#define BET_ROW33_PAYOFF 11
#define BET_ROW36 51
#define BET_ROW36_PAYOFF 11

#define BET_COLUMN1 60
#define BET_COLUMN1_PAYOFF 2
#define BET_COLUMN2 61
#define BET_COLUMN2_PAYOFF 2
#define BET_COLUMN3 62

#define BET_FIRST12 70
#define BET_FIRST12_PAYOFF 2
#define BET_MIDDLE12 71
#define BET_MIDDLE12_PAYOFF 2
#define BET_LAST12 72
#define BET_LAST12_PAYOFF 2

#define BET_ODD 80
#define BET_ODD_PAYOFF 1
#define BET_EVEN 81
#define BET_EVEN_PAYOFF 1

#define BET_RED 90
#define BET_RED_PAYOFF 1
#define BET_BLACK 91
#define BET_BLACK_PAYOFF 1

#define BET_1TO18 100
#define BET_1TO18_PAYOFF 1
#define BET_19TO36 101
#define BET_19TP36_PAYOFF 1

#define BET_5NUM 110
#define BET_5NUM_PAYOFF 6

typedef struct
{
   int type;
   float amount;
} bet;


float payoff(bet*, float);
int didPayoff(bet*, int);
float getPayoff(bet*, int);
int divisible(int, int);
