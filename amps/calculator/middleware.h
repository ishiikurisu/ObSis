#ifndef MIDDLEWARE_H
#define MIDDLEWARE_H

#include "../reader/sureader.h"
#include "../reader/tttreader.h"

// Tests if the compilation is working.
void MIDDLE_debug(su_t*, travel_t*);

// Writes a sample Grace image to a file.
void MIDDLE_sample_draw(const char*);

#endif /* end of include guard: MIDDLEWARE_H */
