/*
No Bugs in Production (NBP)
Copyright (C) 2019-present Alin Enachescu

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NBP_PRIVATE_SCHEDULER_H
#define NBP_PRIVATE_SCHEDULER_H

/*
 * Make sure there is only one defined scheduler
 */
#undef NBP_PRIVATE_SCHEDULER_TYPE

#ifdef NBP_CUSTOM_SCHEDULER
#define NBP_PRIVATE_SCHEDULER_TYPE
#endif // end if NBP_CUSTOM_SCHEDULER

#ifdef NBP_FIFO_MT_SCHEDULER
#ifdef NBP_PRIVATE_SCHEDULER_TYPE
#error "Cannot enabe NBP_FIFO_MT_SCHEDULER because another scheduler is enabled"
#else // NBP_PRIVATE_SCHEDULER_TYPE not defined
#define NBP_PRIVATE_SCHEDULER_TYPE
#define NBP_MT_SUPPORT
#endif // end if NBP_PRIVATE_SCHEDULER_TYPE
#endif // end if NBP_FIFO_MT_SCHEDULER

#ifdef NBP_SCHEDULER
#ifdef NBP_PRIVATE_SCHEDULER_TYPE
#error "Cannot enabe NBP_SCHEDULER because another scheduler is enabled"
#else // NBP_PRIVATE_SCHEDULER_TYPE not defined
#define NBP_PRIVATE_SCHEDULER_TYPE
#endif // end if NBP_PRIVATE_SCHEDULER_TYPE
#endif // end if NBP_SCHEDULER

/*
 * If no scheduler is defined then define the default scheduler
 */
#ifndef NBP_PRIVATE_SCHEDULER_TYPE
#define NBP_SCHEDULER
#endif // end if NBP_PRIVATE_SCHEDULER_TYPE

#undef NBP_PRIVATE_SCHEDULER_TYPE

#ifdef NBP_LIBRARY_MAIN

/*
 * TODO: add docs
 */
#ifdef NBP_CUSTOM_SCHEDULER
#error "Not supported"
#endif // end if NBP_CUSTOM_SCHEDULER

/*
 * TODO: add docs
 */
#ifdef NBP_FIFO_MT_SCHEDULER
#error "Not supported"
#endif // end if NBP_FIFO_MT_SCHEDULER

/*
 * TODO: add docs
 */
#ifdef NBP_SCHEDULER
#include "basic_scheduler.h"
#endif // end if NBP_SCHEDULER

#endif // end if NBP_LIBRARY_MAIN

#endif // end if NBP_PRIVATE_SCHEDULER_H
