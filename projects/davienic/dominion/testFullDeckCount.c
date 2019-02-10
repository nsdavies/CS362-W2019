#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds

    printf("TESTING testFullDeckCount():\n");
    for (p = 0; p < numPlayer; p++)
    {
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
#if (NOISY_TEST == 1)
            printf("\nTest player %d with %d card(s).\n", p, handCount*3);
#endif
            memset(&G, 23, sizeof(struct gameState));   // clear the game state
            r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

            int coppers[handCount];
            for (i = 0; i < handCount; i++)
            {
                coppers[i] = 0;
            }

            G.handCount[p] = handCount;
            G.deckCount[p] = handCount;
            G.discardCount[p] = handCount;

            //0
            memcpy(G.hand[p], coppers, sizeof(int) * handCount); // set all the cards to copper
            memcpy(G.deck[p], coppers, sizeof(int) * handCount); // set all the cards to copper
            memcpy(G.discard[p], coppers, sizeof(int) * handCount); // set all the cards to copper

#if (NOISY_TEST == 1)
            printf("G.handCount[p] = %d, expected = %d\n", G.handCount[p], handCount);
            printf("G.deck[p] = %d, expected = %d\n", G.deckCount[p], handCount);
            printf("G.discard[p] = %d, expected = %d\n", G.discardCount[p], handCount);

            //printf("G.playedCards[p] = %d, expected = %d\n", G.discard[p], handCount);
#endif
            for(int i = 0; i < numPlayer; i++)
            {
                if (p == i)
                {
                    //printf("full deck count: %d p: %d\n", fullDeckCount(p, 0, &G), p);
                    assert(fullDeckCount(p, 0, &G) == handCount*3);
                }
                else
                {
                    
                }
            }
        }
    }

    printf("All tests passed!\n");

    return 0;
}
