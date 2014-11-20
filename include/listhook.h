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
 * @section list
 *
 * @description
 * Just a small list element
 *
 *
 */
#ifndef __LIST_HOOK_H__
#define __LIST_HOOK_H__

#include "errorhelper.h"
class ListElement;
/**
 * Just a Hook for the List Element the sepeartion offers the positbility
 * to hook one element in multible lists.
 *
 * This class is dedicated to one parent it is not possible to unhook any
 * item. This element will be fully initilized by initialisation.
 */
class ListHook
{
public:
    /**
     * Reference to the parent, public access possible. Makes it possible
     * to access the parent directly
     */
    ListElement &parent;

    /**
     * Constructor of List hook, initiate the hook and sort it into the
     * List. The position in the List is generated from the priority in
     * the ListElement.
     *
     * @param parent The element which should be hooked
     * @param hook the List in which this element should be hooked into
     */
    ListHook (ListElement &parent, ListHook * &hook);
    ListHook (ListElement &parent, ListHook **hook);
    virtual ~ListHook () {}

    ListHook *getNext() const { return this->next;}
private:
    /**
     * pointer to the next element in the list
     */
    void hookInit(ListElement &parent, ListHook ** hook);
    ListHook *next;
};

#define ITERATE_LIST(_TYPE, _HOOK, _VAR)    for (_TYPE * _VAR = _HOOK; _VAR != NULL; _VAR = _VAR->getNext())


#endif
