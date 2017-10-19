#include "stdio.h"
#include "./header/suheader.h"

#ifndef SUREADER
#define SUREADER

// Gets the number of samples of a trace from a header.
int SUREADER_get_number_samples(trace_t*);

// Gets the number of traces within a header.
long SUREADER_get_number_traces(trace_t*);

// Executes the procedure to read the raw header data from a file pointer.
trace_t* SUREADER_read_header(FILE*);

// Executes the procedure to read the raw trace from a file pointer based on
// previously read header data.
float* SUREADER_read_trace(FILE*, trace_t*);

#endif
