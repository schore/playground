/**
 * @file
 * @author gorg
 * @version 0.0
 * @date Thu 13 Nov 2014 01:39:38 PM CET
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
 *
 */
#ifndef __LIST_H__
#define __LIST_H__

//@todo include default param header
#ifndef DEFAULT_PRIORITY
#define DEFAULT_PRIORITY 100
#endif

/**
 * Base Class for List
 *
 */
class List
{
public:
    List (List* &hook,
            const char *name = "Anonymous",
            int priority = DEFAULT_PRIORITY);
    virtual ~List ();

    List *getNext() const {return this->next;}
    void setNext(List *next) {this->next = next;}
    int getPriority() const {return this->priority;}

    const char* getName() const {return this->name;}
private:
    List *next;
    unsigned int priority;
    const char *name;
};

#define ITERATE_LIST(_TYPE, _HOOK, _VAR)    for (_TYPE * _VAR = _HOOK; _VAR != NULL; _VAR = _VAR->getNext())


#endif
