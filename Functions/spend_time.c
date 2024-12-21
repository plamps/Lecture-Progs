void spend_time(int at_least, int max) {
    int i, rnd;
    int x = 0;

    srand(time(NULL)); /* Αρχικοποίηση του random seed */
    
    /* Βρες ένα τυχαίο αριθμό, για τον οποίο ισχύει: at_least <= rnd <= max  */
    rnd = (rand()%(max-at_least+1))+(at_least); 
    
    for (i=0; i<rnd; i++) { /* τυχαίος υπολογισμός...*/
        if (i%2 == 0) {
            x = x + i; 
        }
        else {
            x = x - i;
        }
    }
}