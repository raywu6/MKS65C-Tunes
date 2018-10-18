#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

// Raymond Wu
// Systems p10
// Project sickMusicPlayer
// R 2018-10-18

// insert nodes at the front
struct song_node * insert_front (struct song_node *node_pointer , char *newName , char *newArtist) {
  // create node
  struct song_node *newNode = malloc( sizeof(struct song_node) );
  strcpy(newNode->name, newName);
  strcpy(newNode->artist, newArtist);
  newNode->next = node_pointer;  // append to beginning of list

  return newNode;
}

// insert nodes in order
// alphabetical by artist then by song
struct song_node * insert_abc (struct song_node *node_pointer , char *newName, char *newArtist) {
  struct song_node *retNode = node_pointer;

  if ( node_pointer == NULL )
    return insert_front (node_pointer , newName , newArtist);
    
  // create node
  struct song_node *newNode = malloc( sizeof(struct song_node) );
  strcpy(newNode->name, newName);
  strcpy(newNode->artist, newArtist);
  newNode->next = NULL;
  
  struct song_node *follower = NULL;
  struct song_node *traverser = node_pointer; // start from front of given list

  while (traverser) {

    if ( strcasecmp(traverser->artist , newArtist) >= 0 &&
	 strcasecmp(traverser->name   , newName  ) >= 0     ) {

      newNode->next = traverser;

      if (follower) {
	follower->next = newNode;
	return retNode;
      }

      // only reach here if equivalent to insert_front
      return newNode;
    }

    else {
      follower = traverser;
      traverser = traverser->next;
    }
    
  } // end while

  // reach here if adding the alphabetically last in list
  
  follower->next = newNode;
  return retNode;
}


// print the entire list
void print_list (struct song_node *n) {

  printf("[");
  
  // can't use n->next b/c n might be NULL
  while (n) {
    printf("[%s, %s],", n->name, n->artist);
    n = n->next;
  }
  
  printf("]\n");
}

// find and return a pointer to a node based on artist and song name
struct song_node * find_song_list (struct song_node *node_pointer, char *specName, char *specArtist) {
  struct song_node *retNode = node_pointer;

  while (retNode) {

    if ( strcasecmp(retNode->name   , specName  ) == 0 &&
	 strcasecmp(retNode->artist , specArtist) == 0     ) {
      return retNode;
    }

    else {
      retNode = retNode->next;
    }
    
  } // end while

  // only reach here if not found
  return NULL;
  
}

// find and return a pointer to the first song of an artist based on artist name
struct song_node * find_first_song_by_artist (struct song_node *node_pointer, char *specArtist) {
  struct song_node *retNode = node_pointer;

  while (retNode) {
    if ( strcasecmp(retNode->artist , specArtist) == 0 )
      return retNode;

    else
      retNode = retNode->next;
  }

  return NULL;
}

// return a pointer to random element in the list
struct song_node * random_song (struct song_node *node_pointer) {
  struct song_node *retNode = node_pointer;

  // random number
  int randomIndex = rand();
  
  // need to find length of list
  int length = 0;
  while (retNode) {
    length++;
    retNode = retNode->next;
  }

  // reset retNode to beginning of list
  retNode = node_pointer;

  if (length == 0)
    // don't try to do modulo 0
    return retNode;

  // use mod to make random # w/in bounds of indices...
  randomIndex = randomIndex % length;

  // move to reach random index
  int i;
  for (i=0 ; i<randomIndex ; i++) {
    retNode = retNode->next;
  }

  return retNode;
}

// remove a single specified node from the list
struct song_node * remove_song (struct song_node *node_pointer, char *specName, char *specArtist) {
  struct song_node *retNode = node_pointer;

  struct song_node *traverser = node_pointer;
  struct song_node *follower = NULL;
  
  while (traverser) {
    if ( strcasecmp(traverser->artist , specArtist) == 0 &&
	 strcasecmp(traverser->name   , specName  ) == 0     ) {

      if (follower) {
	follower->next = traverser->next;
	free(traverser);
	return retNode;
      }
      else {
	// only reach here if remove 1st node in list
	follower = retNode;
	retNode = retNode->next;
	free(follower);
	return retNode;
      }
    }

    else {
      follower = traverser;
      traverser = traverser->next;
    }
    
  } // end while

  return retNode; // returns orig. list w/ no change
}

// free the entire list
struct song_node * free_list (struct song_node *n) {
  struct song_node *follower = n;
  
  while (n) {
    n = n->next;
    free(follower);
    follower = n;
  }

  return n;
}
