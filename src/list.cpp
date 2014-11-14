/**
 * @file
 * @author gorg
 * @version 0.0
 * @date Thu 13 Nov 2014 01:59:51 PM CET
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


#include "list.h"
#include <cstddef>

List::List (List* &hook,
            const char *name,
            int priority)
{
    List *pList = hook;

   
    //Intialisation
    this->priority = priority;
    this->name = name;
    this->next = NULL;

    //no elements in the list
    if (hook == NULL) {
        hook = this;
    }
    else {
        //First element in the list
        if (priority > hook->getPriority())
        {
            this->next = hook;
            hook = this;
        }
        else while(true) {
            //End of List reached
            if (pList->getNext() == NULL ) {
                pList->setNext(this);
                break;
            }
            if (priority > pList->getNext()->getPriority()) {
                this->next = pList->getNext();
                pList->setNext(this);
                break;
            }

            //next iteration
            pList = pList->getNext();
        }
    }
}


List::~List() {

}
