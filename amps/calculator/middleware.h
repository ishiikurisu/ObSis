#ifndef MIDDLEWARE_H
#define MIDDLEWARE_H

#include "../reader/sureader.h"
#include "../reader/tttreader.h"

// Tests if the compilation is working.
void MIDDLE_debug(su_t*, travel_t*);

// Generates the middle cube necessary for completing the Kirchhoff's
// migration.
travel_t* MIDDLE_generate_middle_cube(su_t*, travel_t*);

#endif /* end of include guard: MIDDLEWARE_H */
