#include  <stdio.h>
#define  NUM_RANKS  13
#define  NUM_SUITS  4
#define  NUM_CARDS  5
/*  전역변수  */
int  num_in_rank[NUM_RANKS + 1];
int  num_in_suit[NUM_SUITS];
void  analyze_hand(void) {
    if (check_straight()) {
        printf("straight ");
    }
    if (check_flush()) {
        printf("flush ");
    }
    if (check_flush() || check_straight()) {
        printf("\n");
        return;
    }
    if (check_four_cards()) {
        printf("four of a kind\n");
        return;
    }
    if (check_three_cards()) {
        if (count_pairs() > 0) {
            printf("full house\n");
            return;
        }
        else {
            printf("three of a kind\n");
            return;
        }
    }
    else {
        if (count_pairs() == 0) {
            printf("high card\n");
        }
        else {
            printf("%d pair(s)\n");
        }
    }
    
}
void  init_data() {
    int  rank, suit;
    for (rank = 0; rank < NUM_RANKS; rank++)
        num_in_rank[rank] = 0;
    for (suit = 0; suit < NUM_SUITS; suit++)
        num_in_suit[suit] = 0;
}
void  read_cards(void) {
    char  ch, rank_ch, suit_ch;
    int  rank, suit;
    init_data();
    int  cards_read = 0;
    while (cards_read < NUM_CARDS) {
        printf("Enter  a  card:  ");
        scanf("  %c", &rank_ch);
        switch (rank_ch) {
        case  'a':  rank = 1; break;
        case  '2':  rank = 2; break;
        case '3':  rank = 3; break;
        case  '4':  rank = 4; break;
        case  '5':  rank = 5; break;
        case  '6':  rank = 6; break;
        case  '7':  rank = 7; break;
        case  '8':  rank = 8; break;
        case  '9':  rank = 9; break;
        case  't':  rank = 10; break;
        case  'j':  rank = 11; break;
        case  'q':  rank = 12; break;
        case  'k':rank = 13; break;
        }
        scanf("  %c", &suit_ch);
        switch (suit_ch) {
        case  'c':suit = 0; break;
        case  'd':suit = 1; break;
        case  'h':suit = 2; break;
        case  's':suit = 3; break;
        }
        num_in_rank[rank]++;
        num_in_suit[suit]++;
        cards_read++;
    }
}
int  check_flush() {
    for (int i = 0; i < NUM_SUITS; i++) {
        if (num_in_suit[i] >= 5) {
            return 1;
        }
    }
    return 0;
}
int  check_straight() {
    int stack = 0;
    for (int i = 0; i < NUM_RANKS + 1; i++) {
        if (num_in_rank[i] > 0) {
            stack += 1;
        }
        else {
            stack = 0;
        }
        if (stack == 5) {
            return 1;
        }
    }
    return 0;
}
int  check_four_cards() {
    for (int i = 0; i < NUM_RANKS + 1; i++) {
        if (num_in_rank[i] == 4) {
            return 1;
        }
    }
    return 0;
}
int  check_three_cards() {
    for (int i = 0; i < NUM_RANKS + 1; i++) {
        if (num_in_rank[i] == 3) {
            return 1;
        }
    }
    return 0;
}
int  count_pairs() {  //  one  pair이면  1,  two  pair이면  2,  아니면  0을  return한다.
    int pairs = 0;
    for (int i = 0; i < NUM_RANKS + 1; i++) {
        if (num_in_rank[i] == 2) {
            pairs += 1;
        }
    }
    return pairs;
}
int  main(void) {
    while (1) {
        read_cards();  analyze_hand(); getchar(); getchar();
    }
}
