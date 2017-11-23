#ifndef TTT_READER_H
#define TTT_READER_H

/*
Travel time table definition. Contains 4 fields:
- dx: how many samples there are in the groun direction
- dz: how many samples there are in the underground direction
- dt: how many time samples there are
- table: a 3D table containing [dt][dx][dz] samples
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
Reads the travel time from a file.
*/
travel_t* TTTREADER_read(const char[], int, int, long);

/*
Frees the given struct.
*/
void TTTREADER_free(travel_t*);

#endif /* end of include guard: TTT_READER_H */
