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
 * if custom scheduler is not used then use a default scheduler
 */
#ifndef NBP_CUSTOM_SCHEDULER

/*
 * TODO: add docs
 */
#ifdef NBP_MT_SCHEDULER
#include "basic_mt_scheduler.h"
#endif // end if NBP_MT_SCHEDULER

/*
 * TODO: add docs
 */
#ifdef NBP_SCHEDULER
#include "basic_scheduler.h"
#endif // end if NBP_SCHEDULER

#endif // end if NBP_CUSTOM_SCHEDULER

#endif // end if NBP_PRIVATE_SCHEDULER_H
