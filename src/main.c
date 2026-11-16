/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdint.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include "mrubyc.h"

#define MRBC_MEMORY_SIZE (1024 * 40)

static uint8_t memory_pool[MRBC_MEMORY_SIZE] __aligned(4);
extern const uint8_t blink[];

int main(void)
{
	mrbc_init(memory_pool, MRBC_MEMORY_SIZE);
	if (mrbc_create_task(blink, NULL) == NULL) {
		printk("Failed to create mruby/c task\n");
		return -1;
	}

	return mrbc_run();
}
