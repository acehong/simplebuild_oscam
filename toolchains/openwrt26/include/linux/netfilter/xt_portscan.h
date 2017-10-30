#ifndef _LINUX_XT_PORTSCAN_H
#define _LINUX_XT_PORTSCAN_H 1

struct xt_portscan_info {
	unsigned int match_stealth, match_syn, match_cn, match_gr;
};

#endif /* _LINUX_XT_PORTSCAN_H */
