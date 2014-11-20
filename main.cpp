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
#include "subscriber.h"
#include "pusher.h"
#include "topic.h"
using namespace std;

Pusher<int> push;
Pusher<int> pusha;
Pusher<int> pushb;
Topic<int> test(1);
Subscriber<int> sub(test, push);
Subscriber<int> suba(test, pusha);
Subscriber<int> subb(test, pushb);
int main(){
    int i = 20;
    test.publish(i);
 }

