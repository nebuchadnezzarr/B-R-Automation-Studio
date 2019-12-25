(********************************************************************
 * COPYRIGHT -- Bernecker + Rainer
 ********************************************************************
 * Library: AsIOTime
 * File: AsIOTime.fun
 * Author: B+R
 ********************************************************************
 * Functions and function blocks of library AsIOTime
 ********************************************************************)
                                                                      
{REDUND_OK} {REDUND_UNREPLICABLE} FUNCTION AsIOTimeStamp : DINT (* Get current SystemTime stamp in microseconds *)
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION AsIOTimeCyclicStart : DINT (* Get SystemTime at start of cyclic ressource *)
END_FUNCTION