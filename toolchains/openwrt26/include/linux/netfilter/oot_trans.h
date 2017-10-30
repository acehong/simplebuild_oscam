/* Out of tree workarounds */
#include <linux/version.h>
#if LINUX_VERSION_CODE <= KERNEL_VERSION(2, 6, 18)
#	define HAVE_MATCHINFOSIZE 1
#	define HAVE_TARGUSERINFO 1
#	define HAVE_TARGINFOSIZE 1
#endif
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 20)
#	define nfmark mark
#endif
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 21)
#	define tcp_v4_check(tcph, tcph_sz, s, d, csp) \
		tcp_v4_check((tcph_sz), (s), (d), (csp))
#endif
