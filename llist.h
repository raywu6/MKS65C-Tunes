// Raymond Wu
// Systems pd10
// Project sickMusicPlayer
// R 2018-10-18

// struct prototype
struct song_node {
  char name[100];
  char artist[100];
  struct song_node *next;
};

// music library
struct song_node * table[27];

// methods
struct song_node * insert_front (struct song_node * , char * , char *);

struct song_node * insert_abc (struct song_node * , char * , char *);

void print_list (struct song_node *);

struct song_node * find_song_list (struct song_node * , char * , char *);

struct song_node * find_first_song_by_artist (struct song_node * , char *);

struct song_node * random_song (struct song_node *);

struct song_node * remove_song (struct song_node * , char * , char *);

struct song_node * free_list (struct song_node *);

void print_list (struct song_node *);
