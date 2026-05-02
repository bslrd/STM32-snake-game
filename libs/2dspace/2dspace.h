/**
 * @file 2dspace.h
 * @brief Definition of 2D space orientation types.
 *
 * @author bslrd
 * @date 2026
 *
 *
 *  SPDX-License-Identifier: MIT
 */



#ifndef INC_2DSPACE_H_
#define INC_2DSPACE_H_

/**
 * @brief Movement direction type.
 */
typedef enum
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NONE
}direction_t;

/**
 * @brief X-Y position type.
 */
typedef struct
{
	int x;
	int y;
}vec2_t;

#endif /* SRC_2DSPACE_H_ */
