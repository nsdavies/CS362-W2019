/*
 * cardtest1.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest1: cardtest1.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "smithy"

int main()
{
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);

    printf("----------------- Random Test Card: %s ----------------\n", TESTCARD);

    // ----------- RANDOM TEST --------------

    // G.hand[thisPlayer][0] = 6;
    // G.hand[thisPlayer][1] = 0;
    // G.hand[thisPlayer][2] = 3;
    // G.hand[thisPlayer][3] = estate;
    // G.hand[thisPlayer][4] = feast;

    srand(time(NULL));

    for (int j = 0; j < 1000; j++)
    {

        int cardCount = rand() % 7;

        for (int i = 0; i < cardCount; i++)
        {
            G.hand[thisPlayer][i] = rand() % 7;
            //printf("card %d: %d\n", i,G.hand[thisPlayer][i]);
        }

        G.handCount[thisPlayer] = cardCount;

        //printf("pre call %d\n", testG.handCount[thisPlayer]);
        memcpy(&testG, &G, sizeof(struct gameState));
        //printf("post call %d\n", testG.handCount[thisPlayer]);

        cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

        printf("testG count = %d, expected = %d\n", testG.handCount[thisPlayer], cardCount + 2);
        assert(testG.handCount[thisPlayer] == cardCount + 2);
    }

    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

    return 0;
}
