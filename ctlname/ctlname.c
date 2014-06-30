/* CtlName.c
 *
 * An example of using GENMIDI.DLL, a DLL that has functions to retrieve
 * General MIDI Patch names, Drum Key names, and Controller names from
 * their respective MIDI values, and vice versa.
 *
 * This example shows how to call the DLL function MidiGetCtlNum to retrieve
 * the MIDI controller number for a given General MIDI Controller name. When
 * running the program, supply a defined Controller Name. The program will
 * print the respective controller number for that Controller name if a match
 * is found. For example, "Mod H" or "Mod" is controller #1. Otherwise, a
 * message is printed that the name is not found.
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
    UCHAR    ctl;

    /* Check if any parameters were given, if not, display some help info */
    if (argc < 2)
    {
	_cputs("Displays the controller number for a specified General MIDI Controller Name.\r\n\nSyntax is '");
	_cputs(argv[0]);
	_cputs( " name'.\r\n    where name is a Controller Name (use double quotes if it contains spaces).\r\n");
	_cputs( "    For example, \"Mod H\" is controller 1.\r\n\n");
	_cputs("Version 1.0\r\n");
	exit(0);
    }

    /* Find a match to the supplied Controller Name */
    ctl = MidiGetCtlNum(argv[1]);

    /* Is this a defined Controller name? If so, then the returned controller number isn't 0xFF */
    if (ctl == 0xFF)
    {
	printf("\"%s\" is not one of the defined names.\r\n", argv[1]);
    }

    /* Print the controller number (and also get the full Controller name in case the user supplied a substring) */
    else
    {
	printf("\"%s\" is controller number %u.\r\n", MidiGetCtlStr(ctl), ctl);
    }

    exit(0);
}
