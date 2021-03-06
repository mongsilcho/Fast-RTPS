/*************************************************************************
 * Copyright (c) 2014 eProsima. All rights reserved.
 *
 * This copy of eProsima Fast RTPS is licensed to you under the terms described in the
 * FASTRTPS_LIBRARY_LICENSE file included in this distribution.
 *
 *************************************************************************/

/**
 * @file StringMatching.h
 *
 */

#ifndef STRINGMATCHING_H_
#define STRINGMATCHING_H_
#ifndef DOXYGEN_SHOULD_SKIP_THIS_PUBLIC
namespace eprosima {
namespace fastrtps{
namespace rtps {
/**
 * Class StringMatching used to match different strings against each other as defined by the POSIX fnmatch API (1003.2-1992
section B.6).
 @ingroup UTILITIES_MODULE
 */
class StringMatching {
public:
	StringMatching();
	virtual ~StringMatching();
	/** Static method to match two strings.
	* It checks the string specified by the input argument to see if it matches the pattern specified by the pattern argument.
	*/
	static bool matchString(const char* pattern,const char* input);
	//FIXME: 	CONVERTIR EN INLINE
};
}
} /* namespace rtps */
} /* namespace eprosima */
#endif
#endif /* STRINGMATCHING_H_ */
