/**
 * @file
 * @author gorg
 * @version 0.0
 * @date Wed 12 Nov 2014 11:22:03 PM CET
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
 * This is a simple Testprogramm for whatever
 * The main features are only test for my vim scripts
 * In my opinion it is a really powerfull editor
 * maybe I want to use it at work ;-)
 */

#include <iostream>
#include "list.h"
using namespace std;

ListHook *hooka = NULL;
ListHook *hookb = NULL;

class ListChildA : public ListElement
{
public:
    ListChildA () : ListElement(){}

    virtual ErrorCode callback() {
        cout << "List Child A" << endl;
        return NoError;
    }
} childA;

class ListChildB : public ListElement
{
public:
    ListChildB () : ListElement(20){}

    virtual ErrorCode callback() {
        cout << "List Child B" << endl;
        return NoError;
    }
} childB;


class ListChildC : public ListElement
{
public:
    ListChildC () : ListElement(25){}

    virtual ErrorCode callback() {
        cout << "List Child C" << endl;
        return NoError;
    }
} childC;


ListHook a(childA, hooka);
ListHook b(childB, hooka);
ListHook c(childC, hooka);

ListHook d(childA, hookb);
ListHook e(childB, hookb);
ListHook f(childA, hookb);

int main(){
    cout << "hello!" << endl;
    for (ListHook *pHook = hooka; pHook != NULL; pHook = pHook->getNext() )
    {
       pHook->parent.callback();
       cout << pHook->parent.getPriority() << endl;
    }

    for (ListHook *pHook = hookb; pHook != NULL; pHook = pHook->getNext() )
    {
       pHook->parent.callback();
       cout << pHook->parent.getPriority() << endl;
    }
 }

