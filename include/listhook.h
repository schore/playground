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
    ListElement &parent;

    ListHook (ListElement &parent, ListHook * &hook);
    virtual ~ListHook () {}

    ListHook *getNext() const { return this->getNext();}
private:
    ListHook *next;
};

//#define ITERATE_LIST(_TYPE, _HOOK, _VAR)    for (_TYPE * _VAR = _HOOK; _VAR != NULL; _VAR = _VAR->getNext(_HOOK))


#endif
