#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musiclib.h"  // which includes "llist.h"

// Raymond Wu
// Systems pd10
// Project sickMusicPlayer
// R 2018-10-18

int get_letter_index (char * artist) {

  if ( strncmp(artist , "A", 1) >= 0 &&
       strncmp(artist , "Z", 1) <= 0    ) {
    return (int) *artist - 65;
  }
  
  else if ( strncmp(artist , "a", 1) >= 0 &&
	    strncmp(artist , "z", 1) <= 0    ) {
    return (int) *artist - 97;
  }
  
  else
    return 26;
} 

void add_song (struct song_node *table[27], char *newName, char *newArtist) {
  int arrayIndex = get_letter_index(newArtist);

  table[arrayIndex] = insert_abc( table[arrayIndex] , newName , newArtist );
}

struct song_node * find_song_library (struct song_node *table[27], char *specName, char *specArtist) {
  int arrayIndex = get_letter_index(specArtist);

  return find_song_list( table[arrayIndex] , specName , specArtist );
}

struct song_node * find_artist (struct song_node *table[27], char *specArtist) {
  int arrayIndex = get_letter_index(specArtist);

  return find_first_song_by_artist( table[arrayIndex] , specArtist );
}

void print_all_by_letter (struct song_node * table[27], char *specLetter) {
  int arrayIndex = get_letter_index(specLetter);

  print_list( table[arrayIndex] );
}

void print_all_by_artist (struct song_node * table[27], char *specArtist) {
  int arrayIndex = get_letter_index(specArtist);
  struct song_node *n = table[arrayIndex];
  
  printf("[");

  while (n) {
    if ( strcmp(n->artist , specArtist) == 0 )
      printf("[%s, %s],", n->name, n->artist);
    n = n->next;
  }

  printf("]\n");
}

void print_library (struct song_node *table[27]) {
  int i;
  for (i=0 ; i<27 ; i++) {
    printf("%d: ", i);
    print_list( table[i] );
  }
}

void shuffle (struct song_node * table[27]) {
  printf("[");

  int randNumOfSongs = rand();
  randNumOfSongs = (int) randNumOfSongs % 10; // let's not get too crazy here...

  int count;
  for (count=0 ; count<randNumOfSongs ; count++) {
    int arrayIndex = rand() % 27;
    struct song_node *randomSelection = random_song(table[arrayIndex]);
    if (randomSelection)
      printf("[%s, %s],", randomSelection->name, randomSelection->artist);
  }

  printf("]\n");
}


struct song_node * delete_song (struct song_node * table[27], char *specName, char *specArtist) {
  int arrayIndex = get_letter_index(specArtist);

  return remove_song( table[arrayIndex], specName, specArtist );
}

void clear_library (struct song_node * table[27]) {
  int i;
  for (i=0 ; i<27 ; i++) {
    table[i] = NULL;
  }

}
