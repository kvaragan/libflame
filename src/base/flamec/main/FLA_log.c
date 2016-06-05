#include <stdio.h>
#include "FLA_log.h"

#if FLA_DTL_DUMP_ENABLE
  FILE *fpDump;
  static char *pchLOG_FILE = FLA_DTL_DUMP_FILE;

  /* Global file pointer for dumping the results */
   FLA_FAL_FILE *gpDumpFilePointer = NULL;


void LOG_Initialize  ()
{
  /* Create/Open the file to log the dump data */
    gpDumpFilePointer = fopen(pchLOG_FILE, "wb");
  if(NULL == gpDumpFilePointer )
    {
      /* Unable to open the specified file.*/
        FLA_DEBUGPRINT("Unable to create the dump file %s\n", pchLOG_FILE);
      return;
    }

  fpDump = gpDumpFilePointer;

} /* end of LOG_Initialize */


void LOG_Uninitialize ()
{
  fclose(gpDumpFilePointer);
  gpDumpFilePointer = NULL;
}//


void LOG_DumpData (
                    void*             pvBuffer,
                    unsigned int      ui32BufferSize,
                    unsigned char     ui8DataType,
                    char*             pi8String,
                    unsigned char     i8OutputType
                  )
{
    unsigned int j;

    /* Pointer to store the buffer */
    unsigned int *pui32Array; 
    unsigned int *pui32SixteenBitArray;
    unsigned char  *pui8CharArray;
    char   *pi8CharString;

    /* If dump file pointer is equal to NULL return with out dumping data */
    /* to file */
    if (NULL == gpDumpFilePointer)
    {
        FLA_DEBUGPRINT("File does not exists to dump the data \n");
        return;
    }

    /* The string message */
    if (pi8String != NULL)
    {
        fprintf(gpDumpFilePointer, "%s :", pi8String);
    }

    /* Assuming that if the Data type for character = 1
    * the Data type for unsigned short int = 2
    * the data type for uint32 = 4
    * the data type for string = 3
    */
    if (ui8DataType == FLA_STRING_DATA_TYPE)
    {
        /* Typecast the void buffer to character buffer */
        pi8CharString = (char *)pvBuffer;
        fprintf(gpDumpFilePointer, "%s :", pi8CharString);
        fprintf(gpDumpFilePointer, "\n");
    }

    if (ui8DataType == FLA_CHAR_DATA_TYPE)
    {
        /* Typecast the void buffer to character buffer */
        pui8CharArray = (unsigned char *)pvBuffer;

        for (j = 0; j < ui32BufferSize; j++)
        {
            if (i8OutputType == FLA_LOG_HEX_VALUE)
            {
                fprintf(gpDumpFilePointer, "\n%0x", ((unsigned char *)pui8CharArray)[j]);
            }
            else
            {
                fprintf(gpDumpFilePointer, "\n%d", ((unsigned char *)pui8CharArray)[j]);
            }
        }
        fprintf(gpDumpFilePointer, "\n");
    }
    if (ui8DataType == FLA_UINT16_DATA_TYPE)
    {
        /* Typecast the void buffer to uint32 bit buffer */
        pui32SixteenBitArray = (unsigned int *)pvBuffer;

        /* dump the data in the file line by line */
        for (j = 0; j < ui32BufferSize; j++)
        {
            if (i8OutputType == FLA_LOG_HEX_VALUE)
            {
                fprintf(gpDumpFilePointer, "\n%0x",
                    ((unsigned int *)pui32SixteenBitArray)[j]);
            }
            else
            {
                fprintf(gpDumpFilePointer, "\n%d",
                    ((unsigned int *)pui32SixteenBitArray)[j]);
            }
        }
        fprintf(gpDumpFilePointer, "\n");

    } /* End of if */

    if (ui8DataType == FLA_UINT32_DATA_TYPE)
    {
        /* Typecast the void buffer to uint32 buffer */
        pui32Array = (unsigned int *)pvBuffer;

        /* dump the data in the file line by line */
        for (j = 0; j < ui32BufferSize; j++)
        {
           
            if (i8OutputType == FLA_LOG_HEX_VALUE)
            {
                fprintf(gpDumpFilePointer, "\n%0x", ((unsigned int *)pui32Array)[j]);
            }
            else
            {
                fprintf(gpDumpFilePointer, "\n%d", ((unsigned int *)pui32Array)[j]);
            }
        }
        fprintf(gpDumpFilePointer, "\n");
    } /* End of if */

} /* end of DTL_DumpData */


#endif



