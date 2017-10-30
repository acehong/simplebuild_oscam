#ifndef _LINUX_XT_CHAOS_H
#define _LINUX_XT_CHAOS_H 1

enum xt_chaos_variant {
	XTCHAOS_NORMAL,
	XTCHAOS_TARPIT,
	XTCHAOS_DELUDE,
};

struct xt_chaos_info {
	enum xt_chaos_variant variant;
};

#endif /* _LINUX_XT_CHAOS_H */
