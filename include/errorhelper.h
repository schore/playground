/**
 * @file
 * @author gorg
 * @version 0.0
 * @date Fri 14 Nov 2014 03:22:47 PM CET
 * @section LICENCE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 *
 * @section DESCRIPTION
 *
 * Just a few errorCodes and Debug Helper
 */


#ifndef __ERROR_HELPER_H__
#define __ERROR_HELPER_H__

enum ErrorCode {
    NoError,
    ParamError,

    //Error Code for List
    ListNoHookFound,
    ListHookFailed,
    ListAlreadyHooked,
    ListFull,
};

#include <iostream>
#define ASSERT(EXPR, ERRCODE, STDOUT) if(!(EXPR)) \
    {\
         std::cout << STDOUT << std::endl;\
       return ERRCODE;\
    }

#define EXHANDLE(EXPR, ERRCODE) if((EXPR)) return ERRCODE


#endif
