/* Πρόγραμμα-παιχνίδι που υπολογίζει τα δεδομένα 
ανάκτησης σε μια συστοιχία δύο δίσκων RAID και 
ανακτά τα περιεχόμενα όποιου από τους δύο δίσκους
αστοχήσει */

#include <stdio.h>
#include <inttypes.h>
#include <ctype.h>

#define SIZE 20

/* Διαβάζει μια σειρά έως n χαρακτήρες από το
πληκτρολόγιο παραβλέποντας τυχόν κενά που 
βρίσκονται στην αρχή και αποθηκεύει τους
χαρακτήρες ως ακεραίους στον πίνακα intArray */
uint8_t readLine(int intArray[], int n) {
  int ch;
  uint8_t i = 0;

  while (isspace(ch = getchar()))
    ;
  while (ch != '\n' && ch != EOF) {
    if (i < n)
      intArray[i++] = ch;
    ch = getchar();
  }
  return i;
}

/* Υπολογίζει τα περιεχόμενα RAID 5 του δίσκου raid κάνοντας
XOR στα περιεχόμενα των ακολουθιών ακεραίων input1 και input2 */
void calculateRAID(int input1[], int input2[], int raid[], int numElems) {

    for (int i=0; i<numElems; i++) {
    raid[i] = input1[i] ^ input2[i];
  }

}

/* Ανακτά τα περιεχόμενα του δίσκου disk (1 ή 2) κάνοντας XOR 
τα δεδομένα εισόδου (input2 ή input1 αντίστοιχα) με τα περιεχόμενα 
του δίσκου raid */
void retrieveDiskContents(int input1[], int input2[], int raid[], uint8_t disk, int numElems) {

  switch (disk) {
    case 1:  
      for (int i=0; i < numElems; i++) {
        input1[i] = raid[i] ^ input2[i];
        printf("%c", (char)input1[i]);
      }
    break;
    case 2:       
      for (int i=0; i < numElems; i++) {
        input2[i] = raid[i] ^ input1[i];
        printf("%c", (char)input2[i]);
      }
    break;
    default: printf("Disk must be 1 or 2\n");
  }

}

int main(void) {
  int disk1[SIZE] = {0}, disk2[SIZE] = {0}, raid[SIZE] = {0};
  uint8_t s1=0, s2=0, maxLength;
  
  printf("Give disk 1 contents: ");
  s1=readLine(disk1, SIZE);

  printf("Give disk 2 contents: ");
  s2=readLine(disk2, SIZE);

  maxLength = s1>s2?s1:s2;
  printf("maxLength is %d\n", maxLength);

  calculateRAID(disk1, disk2, raid, maxLength);

  printf("Input1 is lost! Retrieving input1...\n");
  retrieveDiskContents(disk1, disk2, raid, 1, maxLength);
  
  return 0;
}