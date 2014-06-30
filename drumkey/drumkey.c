/* DrumKey.c
 *
 * An example of using GENMIDI.DLL, a DLL that has functions to retrieve
 * General MIDI Patch names, Drum Key names, and Controller names from
 * their respective MIDI values, and vice versa.
 *
 * This example shows how to call the DLL function MidiGetDrumNum to retrieve
 * the MIDI note number for a given General MIDI Drum Key name. When
 * running the program, supply a defined Drum Key Name. The program
 * will print the respective note number for that GM Drum Key name if a match is
 * found. For example, "Kick 1" is note #36. Otherwise, a message is printed
 * that the name is not found.
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
    UCHAR    drum;

    /* Check if any parameters were given, if not, display some help info */
    if (argc < 2)
    {
	_cputs("Displays the note number for a specified General MIDI Drum Key Name.\r\n\nSyntax is '");
	_cputs(argv[0]);
	_cputs( " key'.\r\n    where key is a Drum Key Name (use double quotes if it contains spaces).\r\n");
	_cputs( "    For example, \"Kick 1\" is note 36.\r\n\n");
	_cputs("Version 1.0\r\n");
	exit(0);
    }

    /* Find a match to the supplied Drum Key Name */
    drum = MidiGetDrumNum(0, argv[1]);

    /* Is this a defined Drum Key? If so, then the returned note number isn't 0xFF */
    if (drum == 0xFF)
    {
	printf("\"%s\" is not one of the defined names.\r\n", argv[1]);
    }

    /* Print the note number (and also get the full Drum Key name in case the user supplied a substring) */
    else
    {
	printf("\"%s\" is note number %u.\r\n", MidiGetDrumStr(0, drum), drum);
    }

    exit(0);
}
