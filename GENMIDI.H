/* CTLEVT structure (There is 1 for each Defined MIDI Controller) */
typedef struct _CTLEVT
{
  UCHAR ctlnum;  /* # of the control */
  UCHAR desc[7]; /* mnuemonic description of ctl (ie, "Mod H " for modulation high) */
} CTLEVT;

/* Defined MIDI Controllers */
#define NUMMIDICTLS 51

/* # of GM Drums */
#define NUMMIDIDRUMS 47

extern CTLEVT MidiCtls[NUMMIDICTLS];

extern UCHAR * EXPENTRY MidiGetDrumStr(UCHAR * DrumArray, UCHAR NoteNum);
extern UCHAR EXPENTRY MidiGetDrumNum(UCHAR * DrumArray, UCHAR  * DrumName);
extern UCHAR * EXPENTRY MidiGetPgmStr(UCHAR PgmNum);
extern UCHAR EXPENTRY MidiGetPgmNum(UCHAR * PgmName);
extern UCHAR EXPENTRY MidiGetCtlNum(UCHAR * CtlName);
extern UCHAR EXPENTRY MidiGetCtlNum2(UCHAR * CtlArray, UCHAR  * CtlName);
extern UCHAR * EXPENTRY MidiGetCtlStr2(UCHAR * CtlArray, UCHAR CtlNum);
extern UCHAR * EXPENTRY MidiGetCtlStr(UCHAR CtlNum);
extern UCHAR EXPENTRY MidiGetNoteNum(UCHAR * NoteName, UCHAR * DefOct, UCHAR ** EndPtr);
extern ULONG EXPENTRY MidiGetNoteStr(UCHAR * Buffer, UCHAR NoteNum, CHAR Key);
