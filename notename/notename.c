/* NoteName.c
 *
 * An example of using GENMIDI.DLL, a DLL that has functions to retrieve
 * General MIDI Patch names, Drum Key names, and Controller names from
 * their respective MIDI values, and vice versa.
 *
 * This example shows how to call the DLL function MidiGetNoteNum to retrieve
 * the MIDI note number for a given note name. When running the program,
 * supply a defined Note Name (ie, "C 3"). The program will print the respective
 * note number for that note name. If blank spaces are used in the note name,
 * use double quotes.
 * If the note name is incorrectly specified, or out of range, a message is printed.
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
    UCHAR defOct;
    UCHAR note;
    UCHAR buf[6];

    /* Check if any parameters were given, if not, display some help info */
    if (argc < 2)
    {
	_cputs("Displays the note number for a specified note name (ie, \"C 3\").\r\n\nSyntax is '");
	_cputs(argv[0]);
	_cputs( " name'.\r\n    where name is a Note Name (use double quotes if it contains spaces).\r\n");
	_cputs( "    For example, \"C 3\" is note #60.\r\n\n");
	_cputs("Version 1.0\r\n");
	exit(0);
    }

    /* Find a match to the supplied Note Name */
    defOct = 0;
    note = MidiGetNoteNum(argv[1], &defOct, 0);

    /* Is this a defined note? If so, then the returned program number isn't 0xFE */
    if (note == 0xFE)
    {
	printf("\"%s\" is an improperly specified or non-existant note name.\r\n", argv[1]);
    }

    /* Is this within range? If so, then the returned program number isn't 0xFF */
    else if (note == 0xFF)
    {
	printf("\"%s\" is out of the MIDI note range.\r\n", argv[1]);
    }

    /* Print the note number (and also get the full note name in case the user didn't supply the octave) */
    else
    {
	MidiGetNoteStr(&buf[0], note, 0);
	printf("\"%s\" is note number %u.\r\n", &buf[0], note);
    }

    exit(0);
}
