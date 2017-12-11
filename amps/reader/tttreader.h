#ifndef TTT_READER_H
#define TTT_READER_H

/*
Travel time table definition. Contains 4 fields:
- nx: how many samples there are in the groun direction
- nz: how many samples there are in the underground direction
- ntr: how many time samples there are
- table: a 3D table containing [ntr][nx][nz] samples
*/
typedef struct {
    int nx;
    int nz;
    long ntr;
    float*** table;
} travel_t;

/*
Create a new empty time travel table.
*/
travel_t* TTTREADER_new();

/*
Creates a new and empty time travel table with the required dimensions.
Arguments:
- int nx
- int nz
- long ntr
*/
travel_t* TTTREADER_alloc(int, int, long);

/*
Reads the travel time from a file.
*/
travel_t* TTTREADER_read(const char[], int, int, long);

/*
Frees the given struct.
*/
void TTTREADER_free(travel_t*);

#endif /* end of include guard: TTT_READER_H */
