#pragma once
#include <assert.h>
#include "disastrOS.h"
#include "disastrOS_globals.h"

void internal_preempt();

void internal_fork();

void internal_exit();

void internal_wait();

void internal_spawn();

void internal_shutdown();

void internal_schedule();

//ia declare the implementation of this syscall
void internal_revertAndPreempt();

void internal_exec();

void internal_vfork();
