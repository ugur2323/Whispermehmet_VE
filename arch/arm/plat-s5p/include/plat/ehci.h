/*
 * Copyright (C) 2011 Samsung Electronics Co.Ltd
 * Author: Joonyoung Shim <jy0922.shim@samsung.com>
 *
 * This program is free software; you can redistribute  it and/or modify it
 * under  the terms of  the GNU General  Public License as published by the
 * Free Software Foundation;  either version 2 of the  License, or (at your
 * option) any later version.
 */

#ifndef __PLAT_S5P_EHCI_H
#define __PLAT_S5P_EHCI_H

struct s5p_ehci_platdata {
	int (*phy_init)(struct platform_device *pdev, int type);
	int (*phy_exit)(struct platform_device *pdev, int type);
	int (*phy_suspend)(struct platform_device *pdev, int type);
	int (*phy_resume)(struct platform_device *pdev, int type);
};

struct s5p_ohci_platdata {
	int (*phy_init)(struct platform_device *pdev, int type);
	int (*phy_exit)(struct platform_device *pdev, int type);
	int (*phy_suspend)(struct platform_device *pdev, int type);
	int (*phy_resume)(struct platform_device *pdev, int type);
};

struct s5p_usbswitch_platdata {
	unsigned gpio_host_detect;
	unsigned gpio_device_detect;
	unsigned gpio_host_vbus;
};

extern void s5p_ehci_set_platdata(struct s5p_ehci_platdata *pd);
extern void s5p_ohci_set_platdata(struct s5p_ohci_platdata *pd);

extern void s5p_usbswitch_set_platdata(struct s5p_usbswitch_platdata *pd);
#ifdef CONFIG_USBHUB_USB3503
int s5p_ehci_port_control(struct platform_device *pdev, int port, int enable);
#endif
#endif /* __PLAT_S5P_EHCI_H */
