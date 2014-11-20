/**
 * @file
 * @author gorg
 * @version 0.0
 * @date Tue 18 Nov 2014 09:45:22 PM CET
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
 * A topic middleware with publisher subscriber protocol
 */

#ifndef __topic_h__
#define __topic_h__

#include "errorhelper.h"

class ListHook;
class GenSubscriber;

class GenTopic
{
public:
    GenTopic (int topicId) ;
    virtual ~GenTopic () {};

    ListHook **getHook() {return &this->pSubscriber;}

    ErrorCode publish(void *msg, int len);
    ErrorCode hookToTopic(GenSubscriber *pSubscriber);
private:
    ListHook *pSubscriber;
};

template <class T>
class Topic : public GenTopic
{
public:
    Topic (int topicId):
        GenTopic(topicId)
    {}

    virtual ~Topic () {};

    ErrorCode publish(T &msg) {
        return GenTopic::publish(&msg, sizeof(T));
    }

private:

    /* data */
};


#endif //__topic_h__
