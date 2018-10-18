#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musiclib.h"  // which includes "llist.h"

// Raymond Wu
// Systems pd10
// Project sickMusicPlayer
// R 2018-10-18

int get_letter_index (char * artist) {
  if ( strcmp(&artist[0] , "A") >= 0 &&
       strcmp(&artist[0] , "Z") <= 0    ) {
    return (int) artist[0] - 65;
  }
  
  else if ( strcmp(&artist[0] , "a") >= 0 &&
	    strcmp(&artist[0] , "z") <= 0    ) {
    return (int) artist[0] - 97;
  }
  
  else
    return 26;
} 

void add_song (struct song_node *table[27], char *newName, char *newArtist) {
  int arrayIndex = get_letter_index(newArtist);

  table[arrayIndex] = insert_abc( table[arrayIndex] , newName , newArtist );
}

void print_library (struct song_node *table[27]) {
  int i;
  for (i=0 ; i<27 ; i++) {
    printf("%d: ", i);
    print_list( table[i] );
  }
}
