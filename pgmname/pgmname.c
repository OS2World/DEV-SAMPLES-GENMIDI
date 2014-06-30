/* PgmName.c
 *
 * An example of using GENMIDI.DLL, a DLL that has functions to retrieve
 * General MIDI Patch names, Drum Key names, and Controller names from
 * their respective MIDI values, and vice versa.
 *
 * This example shows how to call the DLL function MidiGetPgmNum to retrieve
 * the MIDI program number for a given General MIDI Program name. When
 * running the program, supply a defined Program Name. The program will
 * print the respective program number for that Program name if a match
 * is found. For example, "Grand Piano" or "Piano" is program #1 (ie, actually
 * program 0). Otherwise, a message is printed that the name is not found.
 */

#define INCL_DOSPROCESS
#define INCL_WINSTDFILE
#define INCL_DOSMEMMGR
#define INCL_DOSFILEMGR

#include <os2.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "genmidi.h"


/* ********************************* main() ********************************* */

VOID main(int argc, char *argv[], char *envp[])
{
    UCHAR pgm;

    /* Check if any parameters were given, if not, display some help info */
    if (argc < 2)
    {
	_cputs("Displays the program number for a specified General MIDI Program Name.\r\n\nSyntax is '");
	_cputs(argv[0]);
	_cputs( " name'.\r\n    where name is a Program Name (use double quotes if it contains spaces).\r\n");
	_cputs( "    For example, \"Grand Piano\" is program 1 (actually program 0).\r\n\n");
	_cputs("Version 1.0\r\n");
	exit(0);
    }

    /* Find a match to the supplied Program Name */
    pgm = MidiGetPgmNum(argv[1]);

    /* Is this a defined Program name? If so, then the returned program number isn't 0xFF */
    if (pgm == 0xFF)
    {
	printf("\"%s\" is not one of the defined names.\r\n", argv[1]);
    }

    /* Print the program number (and also get the full Program name in case the user supplied a substring) */
    else
    {
	printf("\"%s\" is program %u. (%u if 0 is considered the first patch).\r\n", MidiGetPgmStr(pgm), pgm+1, pgm);
    }

    exit(0);
}
