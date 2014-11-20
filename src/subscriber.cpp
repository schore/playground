/**
 * @file
 * @author gorg
 * @version 0.0
 * @date Wed 19 Nov 2014 07:11:07 PM CET
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
 * @section pubsub
 *
 * A simple publisher subscriber protocol
 */

#include "topic.h"
#include "subscriber.h"
GenSubscriber::GenSubscriber(GenTopic &top) :
   ListHook(*this, top.getHook()), ListElement(1) {}
