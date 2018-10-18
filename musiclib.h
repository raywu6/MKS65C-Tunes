#include "llist.h"

// Raymond Wu
// Systems pd10
// Project sickMusicPlayer
// R 2018-10-18

// methods
void add_song (struct song_node * table[27] , char * , char *);

struct song_node * find_song_library (struct song_node * table[27] , char * , char *);

struct song_node * find_artist (struct song_node * table[27] , char *);

void print_all_by_letter (struct song_node * table[27] , char *);

void print_all_by_artist (struct song_node * table[27] , char *);

void print_library (struct song_node * table[27]);

void shuffle (struct song_node * table[27]);

struct song_node * delete_song (struct song_node * table[27] , char * , char *);

void clear_library (struct song_node * table[27]);
