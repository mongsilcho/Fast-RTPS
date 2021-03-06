/*************************************************************************
 * Copyright (c) 2014 eProsima. All rights reserved.
 *
 * This copy of eProsima Fast RTPS is licensed to you under the terms described in the
 * FASTRTPS_LIBRARY_LICENSE file included in this distribution.
 *
 *************************************************************************/

/**
 * @file PubSubHelloWorldWriter.hpp
 *
 */

#ifndef _TEST_BLACKBOX_PUBSUBHELLOWORLDWRITER_HPP_
#define _TEST_BLACKBOX_PUBSUBHELLOWORLDWRITER_HPP_

#include "types/HelloWorldType.h"

#include <fastrtps/fastrtps_fwd.h>
#include <fastrtps/publisher/PublisherListener.h>
#include <fastrtps/attributes/PublisherAttributes.h>

#include <string>
#include <list>
#include <condition_variable>

using namespace eprosima::fastrtps::rtps;

class PubSubHelloWorldWriter 
{
    class Listener :public PublisherListener
    {
        public:

            Listener(PubSubHelloWorldWriter &writer) : writer_(writer){};
            ~Listener(){};
            void onPublicationMatched(Publisher* /*pub*/, MatchingInfo &info)
            {
                if (info.status == MATCHED_MATCHING)
                    writer_.matched();
            }

        private:

            Listener& operator=(const Listener&) NON_COPYABLE_CXX11;

            PubSubHelloWorldWriter &writer_;

    } listener_;

    public:
        PubSubHelloWorldWriter();
        virtual ~PubSubHelloWorldWriter();
        void init();
        bool isInitialized() const { return initialized_; }
        void send(const std::list<uint16_t> &msgs);
        void matched();
        void waitDiscovery();
        virtual void configPublisher(PublisherAttributes &puattr) = 0;

    private:

        PubSubHelloWorldWriter& operator=(const PubSubHelloWorldWriter&)NON_COPYABLE_CXX11;

        Participant *participant_;
        Publisher *publisher_;
        bool initialized_;
        std::mutex mutex_;
        std::condition_variable cv_;
        unsigned int matched_;
        HelloWorldType type_;
};

#endif // _TEST_BLACKBOX_PUBSUBHELLOWORLDWRITER_HPP_
