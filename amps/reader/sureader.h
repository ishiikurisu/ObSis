#ifndef SUREADER
#define SUREADER

// Reads the first trace header of a SU file. Requires the filename as input
// and generates a string for the first header.
char* SUREADER_read_trace_header(const char*);

// Gets the number of samples of a trace from a header.
int SUREADER_get_number_samples(char*);

// Draws the header information as a numbered list.
void SUREADER_draw_header(char*);

// Reads the raw bytes from the first trace from a SU file.
char* SUREADER_read_raw_trace(const char*);

#endif
