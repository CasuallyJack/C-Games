/* A Library for conversions between sweeps and years.
 * 
 * CasuallyJack 2024
 * 
 * Homestuck created by Andrew Hussie
 *
 * 2.17 years is about the length of one sweep, and was determined by dividing
 * the troll's introduction ages in years by their ages in sweeps (13/6),
 * resulting in 2.166..7 as the quotient. I also divided the age of Karkat during
 * the credits (20/9.31) but got a quotient of 2.14822771214. I also divided Terezi's
 * estimated age during the credits (16/7.38) and got 2.16802168022, so I decided to stick
 * with 2.17.
 *
 * With this, keep in mind the result is only an estimate and is likely not exact.
 *
 * When an amount of sweeps are multiplied by 2.17, the product will be said sweep's in years.
 *
 * All information on ages were sourced from the MS Paint Adventures wiki and Homestuck proper:
 * (https://mspaintadventures.fandom.com/wiki/MS_Paint_Adventures_Wiki)
 */ 
#define YEARSINSWEEPS 2.17

double sweepsToYears(double sweeps)
{
    /* Years = Sweeps * 2.17 */

    double years = sweeps * YEARSINSWEEPS;

    return years;
}

double yearsToSweeps(double years)
{
    /* Sweeps = Years / 2.17 */

    double sweeps = years / YEARSINSWEEPS;

    return sweeps;
}
