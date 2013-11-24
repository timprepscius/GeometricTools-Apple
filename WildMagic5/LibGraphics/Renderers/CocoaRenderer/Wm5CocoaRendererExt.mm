//
//  IPhoneRendererExt.m
//  LibGraphics
//
//  Created by Timothy Prepscius on 1/14/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "Wm5CocoaRendererExt.h"

//----------------------------------------------------------------------------
// For function extension support on Mac OS X.
//----------------------------------------------------------------------------

/*
GL_API void* GL_APIENTRY eglGetProcAddress( const char* fname );

extern "C"
{
    //----------------------------------------------------------------------------
    void* GTGetFunctionPointer (const char* function)
    {
        char* symbolName;
        
        // Prepend a '_' for the Unix C symbol mangling convention.
        symbolName = (char*)malloc(strlen((const char*)function) + 2);
        strcpy(symbolName + 1,(const char*)function);
        symbolName[0] = '_';
        
        return eglGetProcAddress(symbolName);
    }
    //----------------------------------------------------------------------------
}

*/

#ifdef __APPLE__
#include <mach-o/dyld.h>
#include <cstdlib>
#include <cstring>

extern "C"
{
//----------------------------------------------------------------------------
void* GTGetFunctionPointer (const char* function)
{
    NSSymbol symbol;
    char* symbolName;

    // Prepend a '_' for the Unix C symbol mangling convention.
    symbolName = (char*)malloc(strlen((const char*)function) + 2);
    strcpy(symbolName + 1,(const char*)function);
    symbolName[0] = '_';

    symbol = 0;
    if (NSIsSymbolNameDefined(symbolName))
	{
        symbol = NSLookupAndBindSymbol(symbolName);
	}

    free(symbolName);
    return symbol ? NSAddressOfSymbol(symbol) : 0;
}
//----------------------------------------------------------------------------
}
#endif
