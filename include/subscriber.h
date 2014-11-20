/**
 * @file
 * @author gorg
 * @version 0.0
 * @date Tue 18 Nov 2014 10:12:58 PM CET
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
 * Just a simple subscriber two an topic
 */

#ifndef __subscriber_h__
#define __subscriber_h__

#include "errorhelper.h"
#include "list.h"
#include "pusher.h"

class GenTopic;
template <class T> class Topic;

class GenSubscriber : public ListHook, public ListElement
{
public:
    GenSubscriber (GenTopic &top);
    virtual ~GenSubscriber () {}

    virtual ErrorCode callback(void *, int len) { return NoError; }

};

template <class T>
class Subscriber : public GenSubscriber
{
public:
    Subscriber (Topic<T> &top, Pusher<T> &push):
        GenSubscriber(top),
        push(push)
    {}

    ErrorCode callback(T* pToData) {
        return push.callback(pToData);
    }

    ErrorCode callback(const void * pToData, int len) {
       EXHANDLE(len != sizeof(T), SubParamFail);
       EXHANDLE(pToData == NULL, SubDataNULL);
       return this->callback((T*)pToData);
    }

    virtual ~Subscriber () {}

private:
    Pusher<T> &push;
};

#endif //__subscriber_h__
