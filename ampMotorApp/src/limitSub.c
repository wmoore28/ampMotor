/**
 * limitSub.c
 *
 * Return the limit switch status from the input readback.  Don't use the alarm 
 * code because it latches.
 *
 * Inputs:
 *  INPA - X1/X2 condition for trip (closed/open)
 *  INPB - input readback
 *  INPC - bit mask to compare against
 *
 *  [Bit masks for INPC]
 *      X1/CW   = 0x1
 *      X2/CCW  = 0x2
 *      X3/HOME = 0x4
 *
 * Output:
 *  0 = off limit, 1 = on limit
 *
 * Author: Wesley Moore (wmoore@jlab.org)
 * Date:   Sept 2013
 */
#include <registryFunction.h>
#include <subRecord.h>
#include <epicsExport.h>

#define cond (psub->a)
#define inp  ((int) psub->b)
#define mask ((int) psub->c)
#define out  (psub->val)

long limitSubInit(struct subRecord *psub) {
    return(0);
}

long limitSub(struct subRecord *psub) {
    if (cond == 0) {
        if ((inp & mask) == 0) {
            out = 1;
        } else {
            out = 0;
        }
    } else if (cond == 1) {
        if (inp & mask) {
            out = 1;
        } else {
            out = 0;
        }
    } else {
        out = 0;
    }
    return(0);
}

epicsRegisterFunction(limitSubInit);
epicsRegisterFunction(limitSub);

