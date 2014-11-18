/**
 * @file
 * @author gorg
 * @version 0.0
 * @date Tue 18 Nov 2014 07:36:32 PM CET
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
 * @section Test
 *
 * Test for list
 */

#include <UnitTest++/UnitTest++.h>
#include "list.h"

SUITE(ListTests) {
    TEST(ListCheck) {
        ListHook *hooka = NULL;
        ListHook *hookb = NULL;

        int last_prio;

        class ListChildA : public ListElement
        {
        public:
            ListChildA () : ListElement(){}

            virtual ErrorCode callback() {
                return NoError;
            }
        } childA;

        class ListChildB : public ListElement
        {
        public:
            ListChildB () : ListElement(20){}

            virtual ErrorCode callback() {
                return NoError;
            }
        } childB;


        class ListChildC : public ListElement
        {
        public:
            ListChildC () : ListElement(25){}

            virtual ErrorCode callback() {
                return NoError;
            }
        } childC;


        ListHook a(childA, hooka);
        ListHook b(childB, hooka);
        ListHook c(childC, hooka);

        ListHook d(childA, hookb);
        ListHook e(childB, hookb);
        ListHook f(childA, hookb);


        last_prio = hooka->parent.getPriority();
        for (ListHook *pHook = hooka; pHook != NULL; pHook = pHook->getNext() )
        {
            CHECK(pHook->parent.getPriority() <= last_prio);
            last_prio = pHook->parent.getPriority();
        }

        last_prio = hookb->parent.getPriority();
        for (ListHook *pHook = hookb; pHook != NULL; pHook = pHook->getNext() )
        {
            CHECK(pHook->parent.getPriority() <= last_prio);
            last_prio = pHook->parent.getPriority();
        }

        CHECK(true);
    }
}

int main() {
    return UnitTest::RunAllTests();
}
