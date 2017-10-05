#include "stdio.h"

#ifndef SUREADER
#define SUREADER

// Gets the number of samples of a trace from a header.
int SUREADER_get_number_samples(char*);

// Executes the procedure to read the raw header data from a file pointer.
char* SUREADER_read_header(FILE*);

// Executes the procedure to read the raw trace from a file pointer based on
// previously read header data.
char* SUREADER_read_trace(FILE*, char*);

// Draws some raw data on screen.
void SUREADER_draw_something(char*, int);

// Draws the header information as a numbered list.
void SUREADER_draw_header(char*);

#endif
