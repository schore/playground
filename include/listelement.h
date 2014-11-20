/**
 * @file
 * @author gorg
 * @version 0.0
 * @date Fri 14 Nov 2014 11:25:28 PM CET
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
 * @section list
 *
 * @description
 * This is a simple wrapper for a list element. Only minor functionallity added
 * in this class but with the virtal method a function pointer can be avoided
 */

#ifndef __LIST_ELEMENT_H__
#define __LIST_ELEMENT_H__

#include "errorhelper.h"

//@todo include default param header
#ifndef DEFAULT_PRIORITY
#define DEFAULT_PRIORITY 100
#endif

/**
 * This class is a simple wrapper. Priority is used for hook this Element
 * in an ordered list
 */
class ListElement
{
public:
    /**
     * Constructor
     *
     * @param priority element will be hooked in a ordererd List. Higher
     *          priority means the Element will be executed first.
     * @return error code
     */
    ListElement (const int priority=DEFAULT_PRIORITY);
    virtual ~ListElement () {}


    /**
     * This function has to be overwritten by the implementation
     * This is only a typesafe callback handler
     *
     * @param msg pointer to message, message is only valid during the
     * execution of the callback
     * @param size of the message
     * @return error code
     */
    virtual ErrorCode callback(const void *msg = NULL, int len=0) { return NoError; }

    /**
     * Simple getter
     * @return Priority of the list element
     */
    int getPriority() const { return this->priority; }

private:
    /**
     * Priority of the ListElement, bigger number means higher priority and
     * is execute first.
     */
    const int priority;
};




#endif //__LIST_ELEMENT_H__
