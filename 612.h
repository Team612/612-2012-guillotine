/* 612.h
 *
 * Copyright (c) 2011, 2012 Chantilly Robotics <chantilly612@gmail.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * Project-Wide defines!
 */

#ifndef INC_612_H
#define INC_612_H

#include <stdint.h>

typedef uint32_t uinteger;
typedef uint32_t state_t;
typedef uint8_t module_t;
typedef uint8_t range_t;

enum GLOBAL_ROBOT_STATE {
	STATE_DRIVING = 0,
	STATE_SHOOTING = 1,
    STATE_AIMING = 2,
    STATE_RESTING = 3
};

void perror_612_(const char*, int, const char *);

#define perror_612(sym) perror_612_(__FILE__, __LINE__, sym)

const bool DEBUG_612 = true;

#endif
