#ifndef SUREADER
#define SUREADER
// Just a test procedure to test the compilation process.
int life();

// Reads the first trace header of a SU file. Requires the filename as input
// and generates a string for the first header.
char* SUREADER_read_trace_header(const char*);

#endif
