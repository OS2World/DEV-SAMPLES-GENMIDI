/* CtlNum.c
 *
 * An example of using GENMIDI.DLL, a DLL that has functions to retrieve
 * General MIDI Patch names, Drum Key names, and Controller names from
 * their respective MIDI values, and vice versa.
 *
 * This example shows how to call the DLL function MidiGetCtlStr to retrieve
 * the General MIDI Controller name for a given controller number. When
 * running the program, supply a number from 0 to 127 inclusive. The program
 * will print the respective GM Controller name for that controller number. For
 * example, controller #1 is "Mod H" (ie, Modulation MSB).
 *
 * Typing a number > 127 causes all defined Controllers to be displayed.
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
    ULONG    ctl;
    UCHAR * str;
    UCHAR     i;

    /* Check if any parameters were given, if not, display some help info */
    if (argc < 2)
    {
	_cputs("Displays the General MIDI Controller Name for the specified controller number.\r\n\nSyntax is '");
	_cputs(argv[0]);
	_cputs( " ctl'.\r\n    where ctl is a controller number from 0 to 127 inclusive.\r\n");
	_cputs( "    For example, controller 1 is 'Mod H' (ie, Modulation MSB).\r\n");
	_cputs( "    Specifying a number > 127 displays all defined Controller Names.\r\n\n");
	_cputs("Version 1.0\r\n");
	exit(0);
    }

    /* Get the controller number (as a binary value) */
    ctl = atoi(argv[1]);

    /* See if he wants all defined Controller Names displayed. If so, print 3 upon each line */
    if (ctl > 127)
    {
	i=0;
	for (ctl=0; ctl<128; ctl++)
	{
	    if (i && !(i%3))
	    {
		_printf("\r\n");
		i=0;
	    }

	    str = MidiGetCtlStr(ctl);

	    /* Is this a defined controller? If so, then the returned string isn't null */
	    if (*str)
	    {
		printf("%3u %-9s", ctl, str);
		++i;
	    }
	}
    }

    /* Print just the 1 GM Controller Name */
    else
    {
	str = MidiGetCtlStr(ctl);
	if (!(*str)) str = "is undefined.";
	printf("%u %s\r\n", ctl, str);
    }

    exit(0);
}
