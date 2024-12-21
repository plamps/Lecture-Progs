#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

enum state_codes { entry, run, jump };

enum input { A, U, other };
struct transition {
    enum state_codes src_state;
    enum input       in_code;
    enum state_codes dst_state;
};

/* Πίνακας μεταβάσεων */
struct transition state_transitions[] = {
    {entry, A,     jump},
    {entry, other, entry},
    {entry, U,     run},
    {jump,  other, entry},
    {jump,  U,     run},
    {jump,  A,     jump},
    {run,   other, entry},
    {run,   U,     run},
    {run,   A,     jump}
};

#define EXIT_STATE entry
#define ENTRY_STATE entry

/* Δηλώσεις συναρτήσεων */
void entry_state(void);
void jump_state(void);
void run_state(void);
enum state_codes lookup_transitions(enum state_codes, enum input);

/* Πίνακας δεικτών σε συναρτήσεις. Πρέπει να είναι σε
συμφωνία η σειρά των συναρτήσεων με τα state_codes */
void (* state[])(void) = { entry_state, run_state, jump_state};

int main() {
    enum state_codes cur_state = ENTRY_STATE;
    uint8_t in;
    void (* state_fun)(void);

    for (;;) {
        state_fun = state[cur_state];
        state_fun();
        scanf("%"SCNu8, &in);
        /* Αν βρεθεί στην τερματική κατάσταση το πρόγραμμα τελειώνει */
        cur_state = lookup_transitions(cur_state, in);
        if (EXIT_STATE == cur_state)  {
            printf("Entertainment is over, bye!\n"); 
            break;
        }
    }
    return EXIT_SUCCESS;
}

/* Συναρτήσεις που εκτελούνται όταν μια ΜΠΚ φτάνει 
σε μια κατάσταση */
void entry_state(void) {
    printf("Entry state. Staying still\n");
}

void run_state(void) {
    printf("Running...\n");
}

void jump_state(void) {
    printf("Jumping...\n");
}

/* Συνάρτηση που επιστρέφει τη νέα κατάσταση, με βάση την τρέχουσα 
κατάσταση και την είσοδο */
enum state_codes lookup_transitions(enum state_codes state, enum input in) {
    int i, size;
    size = sizeof(state_transitions)/sizeof(state_transitions[0]);
    switch (in) {
        case 0: { // input: A
            for (i=0; i<size; i++) {
                if ((state_transitions[i].src_state==state) && (state_transitions[i].in_code==in)) {
                    return state_transitions[i].dst_state;
                }
            }

            break;
        }
        case 1: { //input: U
            for (i=0; i<size; i++) {
                if  ((state_transitions[i].src_state==state) && (state_transitions[i].in_code==in))  {
                    return state_transitions[i].dst_state;
                }
            }
            break;
        }
        case 2: { //οποιαδήποτε είσοδος
            for (i=0; i<size; i++) {
                if  ((state_transitions[i].src_state==state) && (state_transitions[i].in_code==in))  {
                    return state_transitions[i].dst_state;
                }
            }
            break;
        }
        default: {
            printf("Wrong input\n");
            return state;
        }
    }
}