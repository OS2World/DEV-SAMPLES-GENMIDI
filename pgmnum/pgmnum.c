/* PgmNum.c
 *
 * An example of using GENMIDI.DLL, a DLL that has functions to retrieve
 * General MIDI Patch names, Drum Key names, and Controller names from
 * their respective MIDI values, and vice versa.
 *
 * This example shows how to call the DLL function MidiGetPgmStr to retrieve
 * the General MIDI Patch name for a given program number. When running
 * the program, supply a number from 1 to 128 inclusive. The program will
 * print the respective GM Patch name for that program number. For example,
 * program #1 is "Grand Piano".
 *
 * Typing a number of 0 results in all 128 GM Patch names being displayed.
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
    ULONG  pgm;
    UCHAR  i;

    /* Check if any parameters were given, if not, display some help info */
    if (argc < 2)
    {
	_cputs("Displays the General MIDI Patch Name for the specified program number.\r\n\nSyntax is '");
	_cputs(argv[0]);
	_cputs( " pgm'.\r\n    where pgm is a program number from 1 to 128 inclusive.\r\n");
	_cputs( "    For example, program 1 is 'Grand Piano'.\r\n");
	_cputs( "    Specifying a number of 0 displays all 128 GM Patch Names.\r\n\n");
	_cputs("Version 1.0\r\n");
	exit(0);
    }

    /* Get the program number (as a binary value) */
    pgm = atoi(argv[1]);

    /* Make sure that it's not > 128 */
    if (pgm > 128)
    {
	_cputs("MIDI Program numbers must be 1 to 128 inclusive.\r\n");
	exit(1);
    }

    /* See if he wants all 128 GM Names displayed. If so, print 4 upon each line */
    if (!pgm)
    {
	for (i=0; i<128; i++)
	{
	    if (!(i%4)) _printf("\r\n");
	    printf("%3u %-15s", i+1, MidiGetPgmStr(i));
	}
    }

    /* Print just the 1 GM Name */
    else
    {
	/* MIDI Program numbers actually must be 0 to 127, although the user normally
	    considers the first program to be 1 rather than 0.	Adjust for MidiGetPgmStr() */
	printf("%u %s\r\n", pgm, MidiGetPgmStr(pgm-1));
    }

    exit(0);
}
