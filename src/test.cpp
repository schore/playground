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
 * I want to use it at work ;-)
 */
#include <iostream>
#include <func_2.h>
using namespace std;
/**
 * DESCRIPTION
 *
 * @param a value a
 * @param b value b 
 * @return result
 */
int foo(int a, int b) {
    return a + b;
}


/**
 * DESCRIPTION
 *
 * @param 
 * @return error code
 */ 
int main(){
    for (int i = 0; i < 10; i++) {
       cout << foo(1,i) << endl;
       cout << func_2(i,foo(1,i)) << endl;
    }

    cout << func_2(1,3) << endl;
}

