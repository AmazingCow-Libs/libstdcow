/*----------------------------------------------------------------------------**
**               █      █                                                     **
**               ████████                                                     **
**             ██        ██                                                   **
**            ███  █  █  ███        cowlog.h                                  **
**            █ █        █ █        libstdcow                                 **
**             ████████████                                                   **
**           █              █       Copyright (c) 2016                        **
**          █     █    █     █      AmazingCow - www.AmazingCow.com           **
**          █     █    █     █                                                **
**           █              █       N2OMatt - n2omatt@amazingcow.com          **
**             ████████████         www.amazingcow.com/n2omatt                **
**                                                                            **
**                  This software is licensed as GPLv3                        **
**                 CHECK THE COPYING FILE TO MORE DETAILS                     **
**                                                                            **
**    Permission is granted to anyone to use this software for any purpose,   **
**   including commercial applications, and to alter it and redistribute it   **
**               freely, subject to the following restrictions:               **
**                                                                            **
**     0. You **CANNOT** change the type of the license.                      **
**     1. The origin of this software must not be misrepresented;             **
**        you must not claim that you wrote the original software.            **
**     2. If you use this software in a product, an acknowledgment in the     **
**        product IS HIGHLY APPRECIATED, both in source and binary forms.     **
**        (See opensource.AmazingCow.com/acknowledgment.html for details).    **
**        If you will not acknowledge, just send us a email. We'll be         **
**        *VERY* happy to see our work being used by other people. :)         **
**        The email is: acknowledgment_opensource@AmazingCow.com              **
**     3. Altered source versions must be plainly marked as such,             **
**        and must not be misrepresented as being the original software.      **
**     4. This notice may not be removed or altered from any source           **
**        distribution.                                                       **
**     5. Most important, you must have fun. ;)                               **
**                                                                            **
**      Visit opensource.amazingcow.com for more open-source projects.        **
**                                                                            **
**                                  Enjoy :)                                  **
**----------------------------------------------------------------------------*/

#ifndef __libstdcow_include_cowlog_h__
#define __libstdcow_include_cowlog_h__

/* std */
#include <stdio.h>


/* Function Prototypes */
/**
@brief this is what log macros will call.
@warning DO NOT CALL IT DIRECTLY.
@see COW_LOG, COW_PRINT, COW_DLOG
*/
void _cow_log(FILE *f, int flush,
              const char *prefix, const char *fmt, ...);


/* Macro Definitions */
/**
@brief
    It will act like a printf(3), flushing the stdout after
    print the message. \n
    COW_LOG will put a cowlog: before the message. \n
    COW_LOG is enabled regardless of build mode.
@param
    fmt - The format string - Like printf(3).
@param
    ... - Variadic arguments list - Like printf(3).
@see
    COW_PRINT, COW_DLOG
*/
#define COW_LOG(_fmt_, ...)                  \
    _cow_log(stdout, 1,                      \
             "cowlog", (_fmt_), ##__VA_ARGS__)


/**
@brief
    It will act like a printf(3), flushing the stdout after print the message. \n
    Unlike COW_LOG, this macro will not put anything before the message. \n
    COW_PRINT is enabled regardless of build mode.
@param
    fmt - The format string - Like printf(3).
@param
    ... - Variadic arguments list - Like printf(3).
@see
    COW_LOG, COW_DLOG
*/
#define COW_PRINT(_fmt_, ...) \
    _cow_log(stdout, 1, NULL, (_fmt_), ##__VA_ARGS__)




#ifdef NDEBUG
    #define COW_DLOG(_fmt_, ...) do {} while(0)

#else
    /* Macro Definitions */
    /**
    @brief
        It will act like a printf(3), flushing the stdout after
        print the message. \n
        COW_DLOG will put a cowdebuglog: before the message. \n
        COW_DLOG is enabled only in non NDEBUG builds.
    @param
        fmt - The format string - Like printf(3).
    @param
        ... - Variadic arguments list - Like printf(3).
    @see
        COW_LOG, COW_PRINT
*/
    #define COW_DLOG(_fmt_, ...)                        \
        _cow_log(stdout, 1,                             \
                 "cowdebuglog",( _fmt_), ##__VA_ARGS__)

#endif /* NDEBUG */

#endif /* __libstdcow_include_cowlog_h__ */
