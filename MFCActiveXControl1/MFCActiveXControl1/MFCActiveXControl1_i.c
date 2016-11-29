

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Mon Nov 28 13:59:07 2016
 */
/* Compiler settings for MFCActiveXControl1.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_MFCActiveXControl1Lib,0x104B3123,0x52D3,0x4E77,0x9E,0x1A,0x55,0xF3,0x62,0x9F,0x95,0x1D);


MIDL_DEFINE_GUID(IID, DIID__DMFCActiveXControl1,0x2B846E9F,0xDF8A,0x4D99,0xB8,0x9D,0xA5,0x32,0xA6,0x27,0x6C,0xB7);


MIDL_DEFINE_GUID(IID, DIID__DMFCActiveXControl1Events,0x8BB1B5A6,0xFE1B,0x4234,0x8E,0x8A,0x5B,0x69,0x45,0x70,0x93,0x6D);


MIDL_DEFINE_GUID(CLSID, CLSID_MFCActiveXControl1,0xF1D13F33,0xD072,0x4DB9,0x85,0xE4,0x97,0x0F,0x73,0x38,0x11,0x16);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



