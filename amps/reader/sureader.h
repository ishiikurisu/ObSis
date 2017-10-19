#include "stdio.h"
#include "./header/suheader.h"

#ifndef SUREADER
#define SUREADER

// Gets the number of samples of a trace from a header.
int SUREADER_get_number_samples(trace_t*);

// Gets the number of traces within a header.
long SUREADER_get_number_traces(trace_t*);

// Executes the procedure to read the raw header data from a file pointer.
// Don't forget to `free` this struct.
trace_t* SUREADER_read_header(FILE*);

// Executes the procedure to read the raw trace from a file pointer based on
// previously read header data.
// Don't forget to `free` this array.
float* SUREADER_read_trace(FILE*, trace_t*);

// Creates a converted version of the given SU input file. It is a list of
// floats, where the first float is the number of traces, the second one is the
// number of samples in each trace. Then there are `ntr` following traces, each
// one with `ns` float numbers.
void SUREADER_su_to_bin(const char*, const char*);

#endif
