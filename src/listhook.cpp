/**
 * @file
 * @author gorg
 * @version 0.0
 * @date Sat 15 Nov 2014 12:19:09 AM CET
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
 */

#include "listhook.h"
#include "listelement.h"

ListHook::ListHook(ListElement &parent, ListHook * &hook) :
    parent(parent)
{
    ListHook *pList = hook;

    //Intialisation
    this->next = NULL;

    //no elements in the list
    if (hook == NULL) {
        hook = this;
    }
    else {
        //First element in the list
        if (this->parent.getPriority() > pList->parent.getPriority())
        {
            this->next = hook;
            hook = this;
        }
        else while(true) {
            //End of List reached
            if (pList->getNext() == NULL ) {
                pList->next = this;
                break;
            }
            if (this->parent.getPriority() > pList->getNext()->parent.getPriority()) {
                this->next = pList->getNext();
                pList->next = this;
                break;
            }

            //next iteration
            pList = pList->getNext();
        }
    }
}

