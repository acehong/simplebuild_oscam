#if defined(CONFIG_IP_NF_CONNTRACK) || defined(CONFIG_IP_NF_CONNTRACK_MODULE)
#	include <linux/netfilter_ipv4/ip_conntrack.h>
#else /* linux-2.6.20+ */
#	include <net/netfilter/nf_nat_rule.h>
#endif
