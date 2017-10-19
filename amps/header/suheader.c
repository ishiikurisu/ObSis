/*  KModeling - Kirchhoff Modeling for Seismic Waves
 *  Copyright (C) 2009 Luis A. D'Afonseca <luis.dafonseca@gebrproject.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $Id: suheader.c 2 2009-10-28 17:01:52Z akiles $
 */

#include "suheader.h"

/* Set all SU header values to zero
 *---------------------------------------------------------------------------*/
void
null_su_header (trace_t * header)
{
    header->tracl = 0;
    header->tracr = 0;
    header->fldr = 0;
    header->tracf = 0;
    header->ep = 0;
    header->cdp = 0;
    header->cdpt = 0;
    header->trid = 0;
    header->nvs = 0;
    header->nhs = 0;
    header->duse = 0;
    header->offset = 0;
    header->gelev = 0;
    header->selev = 0;
    header->sdepth = 0;
    header->gdel = 0;
    header->sdel = 0;
    header->swdep = 0;
    header->gwdep = 0;
    header->scalel = 0;
    header->scalco = 1;
    header->sx = 0;
    header->sy = 0;
    header->gx = 0;
    header->gy = 0;
    header->counit = 0;
    header->wevel = 0;
    header->swevel = 0;
    header->sut = 0;
    header->gut = 0;
    header->sstat = 0;
    header->gstat = 0;
    header->tstat = 0;
    header->laga = 0;
    header->lagb = 0;
    header->delrt = 0;
    header->muts = 0;
    header->mute = 0;
    header->ns = 0;
    header->dt = 0;
    header->gain = 0;
    header->igc = 0;
    header->igi = 0;
    header->corr = 0;
    header->sfs = 0;
    header->sfe = 0;
    header->slen = 0;
    header->styp = 0;
    header->stas = 0;
    header->stae = 0;
    header->tatyp = 0;
    header->afilf = 0;
    header->afils = 0;
    header->nofilf = 0;
    header->nofils = 0;
    header->lcf = 0;
    header->hcf = 0;
    header->lcs = 0;
    header->hcs = 0;
    header->year = 0;
    header->day = 0;
    header->hour = 0;
    header->minute = 0;
    header->sec = 0;
    header->timbas = 0;
    header->trwf = 0;
    header->grnors = 0;
    header->grnofr = 0;
    header->grnlof = 0;
    header->gaps = 0;
    header->otrav = 0;
    header->d1 = 0;
    header->f1 = 0;
    header->d2 = 0;
    header->f2 = 0;
    header->ungpow = 0;
    header->unscale = 0;
    header->ntr = 0;
    header->mark = 0;
    header->shortpad = 0;

    header->unass[0] = 0;
    header->unass[1] = 0;
    header->unass[2] = 0;
    header->unass[3] = 0;
    header->unass[4] = 0;
    header->unass[5] = 0;
    header->unass[6] = 0;
    header->unass[7] = 0;
    header->unass[8] = 0;
    header->unass[9] = 0;
    header->unass[10] = 0;
    header->unass[11] = 0;
    header->unass[12] = 0;
    header->unass[13] = 0;
}

/*-- End of File ------------------------------------------------------------*/
