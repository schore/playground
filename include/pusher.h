/**
 * @file
 * @author gorg
 * @version 0.0
 * @date Thu 20 Nov 2014 08:22:15 PM CET
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
 * just a base class for receiver from Topic
 */

#ifndef __pusher_h__
#define __pusher_h__

#include "errorhelper.h"

template <class T>
class Pusher
{
public:
    Pusher () {}
    virtual ~Pusher () {}

    ErrorCode callback(T *) {
        return NoError;
    }
private:
};


#endif //__pusher_h__
