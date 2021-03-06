/*************************************************************************
 * Copyright (c) 2014 eProsima. All rights reserved.
 *
 * This copy of eProsima Fast RTPS is licensed to you under the terms described in the
 * FASTRTPS_LIBRARY_LICENSE file included in this distribution.
 *
 *************************************************************************/

/**
 * @file ResourceEvent.h
 *
 */

#ifndef RESOURCEEVENT_H_
#define RESOURCEEVENT_H_
#ifndef DOXYGEN_SHOULD_SKIP_THIS_PUBLIC



namespace boost
{
class thread;
namespace asio
{
class io_service;
}
}


namespace eprosima {
namespace fastrtps{
namespace rtps {

class RTPSParticipantImpl;

/**
 * Class ResourceEvent used to manage the temporal events.
 *@ingroup MANAGEMENT_MODULE
 */
class ResourceEvent {
public:
	ResourceEvent();
	virtual ~ResourceEvent();

	/**
	* Get the associated IO service
	* @return Associated IO service
	*/
	boost::asio::io_service* getIOService(){return mp_io_service;};

	//!Thread
	boost::thread* mp_b_thread;
	//!IO service
	boost::asio::io_service* mp_io_service;
	//!
	void * mp_work;

	/**
	 * Method to initialize the thread.
	 * @param p 
	 */
	void init_thread(RTPSParticipantImpl*p);
	/**
	 * Task to announce the correctness of the thread.
	 */
	void announce_thread();

	//!Method to run the tasks
	void run_io_service();

	//!Pointer to the RTPSParticipantImpl.
	RTPSParticipantImpl* mp_RTPSParticipantImpl;
};
}
}
} /* namespace eprosima */
#endif
#endif /* RESOURCEEVENT_H_ */
