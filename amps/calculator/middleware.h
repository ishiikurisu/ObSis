#ifndef MIDDLEWARE_H
#define MIDDLEWARE_H

#include "../reader/sureader.h"
#include "../reader/tttreader.h"

// Tests if the compilation is working.
void MIDDLE_debug(su_t*, travel_t*);

// Draws a trace from the table. The file will be structured as a grace plot.
void MIDDLE_draw_trace_from_table(travel_t*, int, int, const char*);

#endif /* end of include guard: MIDDLEWARE_H */
