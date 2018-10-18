#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "musiclib.h"  // which includes "llist.h"

// Raymond Wu
// Systems p10
// Lab -- Linked List
// R 2018-10-18

int main() {

  // prepare them linked lists...
  
  struct song_node *mySongNode0;
  struct song_node *mySongNode1;

  mySongNode0 = NULL;
  mySongNode1 = NULL;

  printf("\n====================\n LINKED LIST TESTS\n====================\n");
  
  printf("\n**************** Testing print_list... ****************\n");
  
  printf("mySongNode0:\t");
  print_list(mySongNode0);  
  printf("mySongNode1:\t");
  print_list(mySongNode1);  
 
  
  printf("\n**************** Testing insert_front... ****************\n");

  printf("...Adding track to mySongNode0...\n");
  printf("mySongNode0:\t");
  mySongNode0 = insert_front(mySongNode0 , "Song2", "Some Systems Guy");
  print_list( mySongNode0 );

  printf("...Adding track to mySongNode0...\n");
  printf("mySongNode0:\t");
  mySongNode0 = insert_front(mySongNode0 , "song0", "Some Systems Guy");
  print_list( mySongNode0 );

  
  printf("...Adding track to mySongNode1...\n");
  printf("mySongNode1:\t");
  mySongNode1 = insert_front(mySongNode1 , "songC", "Some Systems Guy");
  print_list( mySongNode1 );

  printf("...Adding track to mySongNode1...\n");
  printf("mySongNode1:\t");
  mySongNode1 = insert_front(mySongNode1 , "songB", "some Systems Guy");
  print_list( mySongNode1 );


  
  printf("\n**************** Testing insert_abc... ****************\n");

  printf("...Adding track to mySongNode0...\n");
  printf("mySongNode0:\t");
  mySongNode0 = insert_abc(mySongNode0 , "song1", "some Systems Guy");
  print_list( mySongNode0 );

  printf("...Adding track to mySongNode1...\n");
  printf("mySongNode1:\t");
  mySongNode1 = insert_abc(mySongNode1 , "SongA", "Some Systems Guy");
  print_list( mySongNode1 );

  printf("...Adding track to mySongNode1...\n");
  printf("mySongNode1:\t");
  mySongNode1 = insert_abc(mySongNode1 , "SongE", "Some Systems Guy");
  print_list( mySongNode1 );


  printf("\n**************** Testing find_song_list... ****************\n");

  printf("...Finding song1 by some Systems Guy...\n");
  printf("I found \t%s!\n", find_song_list(mySongNode0, "song1", "some Systems Guy")->name);

  printf("...Finding songa by Some systems guy...\n");
  printf("I found \t%s!\n", find_song_list(mySongNode1, "songa", "some systems guy")->name);

  printf("...Finding songe by some systems Guy...\n");
  printf("I found \t%s!\n", find_song_list(mySongNode1, "songe", "some systems Guy")->name);
  
  printf("...Finding songxnotfound by some Systems guy...\n");
  printf("I found \t%s!\n", find_song_list(mySongNode1, "songxnotfound", "some Systems guy")->name);

  
  printf("\n**************** Testing find_first_song_by_artist... ****************\n");

  printf("...Finding 1st song by some sYsTemS gUy in mySongNode0...\n");
  printf("I found \t%s!\n", find_first_song_by_artist(mySongNode0, "some sYsTemS gUy")->name);

  printf("...Finding 1st song by some sYsTemS gUy in mySongNode1...\n");
  printf("I found \t%s!\n", find_first_song_by_artist(mySongNode1, "some sYsTemS gUy")->name);

  printf("...Finding 1st song by Not-existing-artist in mySongNode0...\n");
  printf("I found \t%s!\n", find_first_song_by_artist(mySongNode0, "Not-existing-artist")->name);

    
  printf("\n**************** Testing random_song... ****************\n");

  srand( time(NULL) );

  printf("...Finding random song in mySongNode0...\n");
  printf("I found \t%s!\n", random_song(mySongNode0)->name);

  printf("...Finding random song in mySongNode1...\n");
  printf("I found \t%s!\n", random_song(mySongNode1)->name);

  
  printf("\n**************** Testing random_song... ****************\n");

  printf("...Removing song0 by Some Systems Guy in mySongNode0...\n");
  printf("mySongNode0:\t");
  mySongNode0 = remove_song(mySongNode0, "song0", "Some Systems Guy");
  print_list(mySongNode0);

  printf("...Removing songB by some sYsTems Guy in mySongNode1...\n");
  printf("mySongNode1:\t");
  mySongNode1 = remove_song(mySongNode1, "songB", "some sYsTems Guy");
  print_list(mySongNode1);
 
  printf("...Removing songE by Some Systems Guy in mySongNode1...\n");
  printf("mySongNode1:\t");
  mySongNode1 = remove_song(mySongNode1, "songE", "Some Systems Guy");
  print_list(mySongNode1);

  printf("...Removing songDoesNotExist by some systems guy in mySongNode0...\n");
  printf("mySongNode0:\t");
  mySongNode1 = remove_song(mySongNode1, "songDoesNotExist", "some systems guy");
  print_list(mySongNode1);
 
  printf("\n**************** Testing free_list... ****************\n");

  printf("...Freeing mySongNode0...\n");
  printf("mySongNode0:\t");
  mySongNode0 = free_list(mySongNode0);
  print_list( mySongNode0 );  // []

  printf("...Freeing mySongNode1...\n");
  printf("mySongNode1:\t");
  mySongNode1 = free_list(mySongNode1);
  print_list( mySongNode1 );  // []

  
  printf("\n====================\n MUSIC LIBRARY TESTS\n====================\n");

  struct song_node * table[27];
  int i;
  for (i=0 ; i<27 ; i++) {
    table[i] = NULL;
  }

  printf("Library:\n");
  print_library(table);
  
  printf("\n**************** Testing add_song... ****************\n");

  printf("...Adding songs to music library...");
  add_song(table, "Song A", "Apple");
  print_library(table);
  
  return 0;
}
