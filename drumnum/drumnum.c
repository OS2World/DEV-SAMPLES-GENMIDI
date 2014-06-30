/* DrumNum.c
 *
 * An example of using GENMIDI.DLL, a DLL that has functions to retrieve
 * General MIDI Patch names, Drum Key names, and Controller names from
 * their respective MIDI values, and vice versa.
 *
 * This example shows how to call the DLL function MidiGetDrumStr to retrieve
 * the General MIDI Drum Key name for a given MIDI note number. When
 * running the program, supply a number from 0 to 127 inclusive. The program
 * will print the respective GM Drum Key name for that note number. For
 * example, note #36 is "Kick 1".
 *
 * Typing a number > 127 causes all defined Drum Key names to be displayed.
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
    ULONG    drum;
    UCHAR * str;
    UCHAR     i;

    /* Check if any parameters were given, if not, display some help info */
    if (argc < 2)
    {
	_cputs("Displays the General MIDI Drum key Name for the specified note number.\r\n\nSyntax is '");
	_cputs(argv[0]);
	_cputs( " note'.\r\n    where note is a note number from 0 to 127 inclusive.\r\n");
	_cputs( "    For example, note 36 is 'Kick 1'.\r\n");
	_cputs( "    Specifying a number > 127 displays all defined Drum Key Names.\r\n\n");
	_cputs("Version 1.0\r\n");
	exit(0);
    }

    /* Get the note number (as a binary value) */
    drum = atoi(argv[1]);

    /* See if he wants all defined Drum Key Names displayed. If so, print 3 upon each line */
    if (drum > 127)
    {
	i=0;
	for (drum=0; drum<128; drum++)
	{
	    if (i && !(i%3))
	    {
		_printf("\r\n");
		i=0;
	    }

	    str = MidiGetDrumStr(0, drum);

	    /* Is this a defined Drum Key? If so, then the returned string isn't null */
	    if (*str)
	    {
		printf("%3u %-16s", drum, str);
		++i;
	    }
	}
    }

    /* Print just the 1 GM Drum Key Name */
    else
    {
	str = MidiGetDrumStr(0, drum);
	if (!(*str)) str = "is undefined.";
	printf("%u %s\r\n", drum, str);
    }

    exit(0);
}
