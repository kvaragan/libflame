/*

    Copyright (C) 2016, Advance Micro Devices

    This file is part of libflame and is available under the 3-Clause
    BSD license, which can be found in the LICENSE file at the top-level
    directory, or at http://opensource.org/licenses/BSD-3-Clause

*/

#ifndef _FLALOG_H_
#define _FLALOG_H_

/* Macro for dumping the log. if the user wants to enable dumping make this macro to 1 else 0 */
#define FLA_DTL_DUMP_ENABLE          1
#define FLA_DTL_CSV_ENABLE           1


#define FLA_DTL_DUMP_FILE  "dtldump.wri"
#define FLA_DTL_CSV_FILE   "dtlmetrics.csv"

/* The user can use below three macros for different data type to dump data
* or specify the size of data type in bytes macro for character data type */
#define FLA_CHAR_DATA_TYPE                   (1)

/* macro for unsigned short data type */
#define FLA_UINT16_DATA_TYPE                 (2)

/* macro for String data type */
#define FLA_STRING_DATA_TYPE                 (3)

/* macro for unsigned int data type */
#define FLA_UINT32_DATA_TYPE                 (4)

/* macro for printing Hex values */
#define FLA_LOG_HEX_VALUE                    ('x')

/* macro for printing Decimal values */
#define FLA_LOG_DECIMAL_VALUE                ('d')



/* Type definition for printf */
#define FLA_DEBUGPRINT printf

/* The type definition for FILE */
#define FLA_FAL_FILE                         FILE


#if FLA_DTL_DUMP_ENABLE
     #define FLA_LOG_INITIALIZE()        \
             LOG_Initialize();
#else
     #define FLA_LOG_INITIALIZE()
#endif


/* Macro for uninitializing the LOG prerequisite */
#if FLA_DTL_DUMP_ENABLE
    #define  FLA_LOG_UNINITIALIZE()                                         \
             LOG_Uninitialize ();
#else
/* Dummy macro definition if the LOG macro is not enabled */
    #define FLA_LOG_UNINITIALIZE()
#endif

#if FLA_DTL_DUMP_ENABLE
/* Macro to Dump the DATA  */
/* Buffer : Contains data to be dumped 
/* BufferSize: Number of bytes to be dumped
*  DataType : Specifies data type of the buffer
*/
#define FLA_LOG_DUMP(Buffer,BufferSize,DataType,String,OutputType)     \
   /* Call the Dump function to Dump the DATA */                           \
      LOG_DumpData (Buffer,                                                \
                    BufferSize,                                            \
                    DataType,                                              \
                    String,                                                \
                    OutputType                                             \
                   );
#else
/* Dummy macro definition if the FLA_DTL_DUMP_ENABLE macro is not enabled*/
#define FLA_LOG_DUMP(Buffer,BufferSize,DataType,String,OutputType)

#endif




#if FLA_DTL_DUMP_ENABLE
/* Prototypes for initializing and uninitializing the debug functions */
void LOG_Initialize(void);
void LOG_Uninitialize(void);

void LOG_DumpData(
                   void*             pvBuffer,
                   unsigned int      ui32BufferSize,
                   unsigned char     ui8DataType,
                   char*             pi8String,
                   unsigned char     i8OutputType
                 );
#endif


#endif /*_FLA_LOG_H_ */
