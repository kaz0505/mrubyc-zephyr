/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <mrubyc.h>

#define LED0_NODE DT_ALIAS(led0)
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

int main(void)
{
	printf("Hello World! %s\n", CONFIG_BOARD_TARGET);
	printf("mruby/c version: %s\n", MRUBYC_VERSION);

	if (!gpio_is_ready_dt(&led)) {
		return 0;
	}

	if (gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE) < 0) {
		return 0;
	}

	while (1) {
		gpio_pin_toggle_dt(&led);
		k_sleep(K_MSEC(500));
	}

	return 0;
}
