/*************************************************************************
 * Copyright (c) 2014 eProsima. All rights reserved.
 *
 * This copy of eProsima Fast RTPS is licensed to you under the terms described in the
 * FASTRTPS_LIBRARY_LICENSE file included in this distribution.
 *
 *************************************************************************/

/**
 * @file RTPSAsReliableSocketReader.hpp
 *
 */

#ifndef _TEST_BLACKBOX_RTPSASRELIABLEWITHREGISTRATIONREADER_HPP_
#define _TEST_BLACKBOX_RTPSASRELIABLEWITHREGISTRATIONREADER_HPP_

#include "RTPSWithRegistrationReader.hpp" 

class RTPSAsReliableWithRegistrationReader : public RTPSWithRegistrationReader
{
    public:
        void configReader(ReaderAttributes &rattr, eprosima::fastrtps::ReaderQos &rqos)
        {
            rattr.endpoint.reliabilityKind = RELIABLE;
            rqos.m_reliability.kind = eprosima::fastrtps::RELIABLE_RELIABILITY_QOS;
        };
};

#endif // _TEST_BLACKBOX_RTPSASRELIABLEWITHREGISTRATIONREADER_HPP_
