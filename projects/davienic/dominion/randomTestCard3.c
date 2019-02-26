/*
 * cardtest4.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "outpost"

int main()
{
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[11] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room, outpost};
    srand(time(NULL));

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);

    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

    // ----------- TEST 1: choice1 = 1 = +2 cards --------------
    printf("TEST:  +1 outpost +1 discarded card\n");

    // copy the game state to a test case

    for(int i = 0; i < 1000; i++)
    {
        int cardCount = rand() % 7;

        for (int i = 0; i < cardCount; i++)
        {
            G.hand[thisPlayer][i] = rand() % 7;
        }
        G.handCount[thisPlayer] = cardCount;
        G.deckCount[thisPlayer] = cardCount;

        memcpy(&testG, &G, sizeof(struct gameState));
        choice1 = 1;
        cardEffect(outpost, choice1, choice2, choice3, &testG, handpos, &bonus);

        newCards = 0;
        xtraCoins = 0;
        printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
        printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
        printf("outPostPlayed = %d, expected = %d\n", testG.outpostPlayed, G.outpostPlayed + 1);
        assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
        assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
        assert(testG.outpostPlayed == G.outpostPlayed + 1);
    }

    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

    return 0;
}
