#ifndef __LINUX_NL80211_H
#define __LINUX_NL80211_H
/*
 * 802.11 netlink interface public header
 *
 * Copyright 2006, 2007 Johannes Berg <johannes@sipsolutions.net>
 */

/**
 * enum nl80211_commands - supported nl80211 commands
 * @NL80211_CMD_UNSPEC: unspecified command to catch errors
 * @NL80211_CMD_RENAME_WIPHY: rename a wiphy, needs
 *	%NL80211_ATTR_WIPHY and %NL80211_ATTR_WIPHY_NAME
 * @NL80211_CMD_WIPHY_NEWNAME: rename notification
 * @NL80211_CMD_GET_CMDLIST: TO BE DEFINED PROPERLY. currently the code makes
 *	it depend on the wiphy only but it really should depend on the
 *	interface type too....
 * @NL80211_CMD_NEW_CMDLIST: command list result
 * @NL80211_CMD_ADD_VIRTUAL_INTERFACE: create a virtual interface for the
 *	wiphy identified by an %NL80211_ATTR_WIPHY attribute with the given
 *	%NL80211_ATTR_IFTYPE and %NL80211_ATTR_IFNAME.
 * @NL80211_CMD_DEL_VIRTUAL_INTERFACE: destroy a virtual interface identified
 *	by %NL80211_ATTR_IFINDEX.
 * @NL80211_CMD_CHANGE_VIRTUAL_INTERFACE: change type of virtual interface to
 *	the type given by %NL80211_ATTR_IFTYPE, the interface is identified by
 *	%NL80211_ATTR_IFINDEX.
 * @NL80211_CMD_GET_WIPHYS: request a list of all wiphys present in the system
 * @NL80211_CMD_NEW_WIPHYS: returned list of all wiphys
 * @NL80211_CMD_GET_INTERFACES: request a list of all interfaces belonging to
 *	the wiphy identified by %NL80211_ATTR_WIPHY
 * @NL80211_CMD_NEW_INTERFACES: result for %NL80211_CMD_GET_INTERFACES
 * @NL80211_CMD_INITIATE_SCAN: initiate a scan with the passed parameters. THe
 *	parameters may contain %NL80211_ATTR_FLAG_SCAN_ACTIVE,
 *	%NL80211_ATTR_PHYMODE and a list of channels in an
 *	%NL80211_ATTR_CHANNEL_LIST attribute (an array of nested attributes)
 *	containing %NL80211_ATTR_CHANNEL, %NL80211_ATTR_PHYMODE, and possibly
 *	%NL80211_ATTR_FLAG_SCAN_ACTIVE. The outer %NL80211_ATTR_FLAG_SCAN_ACTIVE
 *	is ignored when a channel list is present.
 * @NL80211_CMD_SCAN_RESULT: scan result, contains an array in
 *	%NL80211_ATTR_BSS_LIST.
 * @NL80211_CMD_ASSOCIATE: associate with the given parameters
 *	(%NL80211_ATTR_SSID is mandatory, %NL80211_ATTR_TIMEOUT_TU,
 *	%NL80211_ATTR_BSSID, %NL80211_ATTR_CHANNEL, %NL80211_ATTR_PHYMODE,
 *	and %NL80211_ATTR_IE may be given)
 * @NL80211_CMD_ADD_KEY: add a key with given %NL80211_ATTR_KEY_DATA,
 * 	%NL80211_ATTR_KEY_ID, %NL80211_ATTR_KEY_TYPE, %NL80211_ATTR_MAC and
 *	%NL80211_ATTR_KEY_CIPHER attributes.
 * @NL80211_CMD_DEL_KEY: delete a key identified by %NL80211_ATTR_KEY_ID,
 *	%NL80211_ATTR_KEY_TYPE and %NL80211_ATTR_MAC or all keys.
 * @__NL80211_CMD_AFTER_LAST: internal use
 */
enum nl80211_commands {
/* don't change the order or add anything inbetween, this is ABI! */
	NL80211_CMD_UNSPEC,
	/* %input: wiphy, wiphy_name */
	NL80211_CMD_RENAME_WIPHY,
	NL80211_CMD_WIPHY_NEWNAME,
	/* %input: wiphy|ifindex */
	NL80211_CMD_GET_CMDLIST,
	NL80211_CMD_NEW_CMDLIST,
	/* %input: wiphy, ifname, {iftype} */
	NL80211_CMD_ADD_VIRTUAL_INTERFACE,
	/* %input: wiphy, ifindex */
	NL80211_CMD_DEL_VIRTUAL_INTERFACE,
	/* %input: ifindex, iftype */
	NL80211_CMD_CHANGE_VIRTUAL_INTERFACE,
	/* %input: */
	NL80211_CMD_GET_WIPHYS,
	NL80211_CMD_NEW_WIPHYS,
	/* %input: wiphy */
	NL80211_CMD_GET_INTERFACES,
	NL80211_CMD_NEW_INTERFACES,
	NL80211_CMD_INITIATE_SCAN,
	NL80211_CMD_SCAN_RESULT,
	NL80211_CMD_GET_ASSOCIATION,
	NL80211_CMD_ASSOCIATION_CHANGED,
	NL80211_CMD_ASSOCIATE,
	NL80211_CMD_DISASSOCIATE,
	NL80211_CMD_DEAUTH,
	NL80211_CMD_GET_AUTH_LIST,
	NL80211_CMD_NEW_AUTH_LIST,
	NL80211_CMD_AUTHENTICATION_CHANGED,
	NL80211_CMD_AP_SET_BEACON,
	NL80211_CMD_AP_ADD_STA,
	NL80211_CMD_AP_UPDATE_STA,
	NL80211_CMD_AP_GET_STA_INFO,
	NL80211_CMD_AP_SET_RATESETS,
	NL80211_CMD_ADD_KEY,
	NL80211_CMD_DEL_KEY,

	/* add commands here */

	/* used to define NL80211_CMD_MAX below */
	__NL80211_CMD_AFTER_LAST
};
#define NL80211_CMD_MAX (__NL80211_CMD_AFTER_LAST - 1)


/**
 * enum nl80211_attrs - nl80211 netlink attributes
 * @NL80211_ATTR_UNSPEC: unspecified attribute to catch errors
 * @NL80211_ATTR_IFINDEX: network interface index of the device to operate on
 * @NL80211_ATTR_IFNAME: network interface name
 * @NL80211_ATTR_WIPHY: index of wiphy to operate on, cf.
 *	/sys/class/ieee80211/<phyname>/index
 * @NL80211_ATTR_WIPHY_NAME: wiphy name (used for renaming)
 * @NL80211_ATTR_CMDS: list of u8's identifying commands a device supports
 * @NL80211_ATTR_IFTYPE: type of virtual interface, see &enum nl80211_iftype
 * @NL80211_ATTR_INTERFACE_LIST: interface array, nested netlink attribute
 * @NL80211_ATTR_WIPHY_LIST: wiphy array, nested netlink attribute
 * @NL80211_ATTR_BSSID: BSSID (must be 6 bytes)
 * @NL80211_ATTR_SSID: SSID (1-32 bytes)
 * @NL80211_ATTR_CHANNEL: channel number
 * @NL80211_ATTR_PHYMODE: PHY mode, see &enum nl80211_phymode
 * @NL80211_ATTR_CHANNEL_LIST: netlink nested attribute array containing scan
 *	parameters for channels
 * @NL80211_ATTR_BSS_LIST: nested attribute containing an array
 * @NL80211_ATTR_BSSTYPE: BSS type, see &enum nl80211_bsstype
 * @NL80211_ATTR_BEACON_PERIOD: beacon period
 * @NL80211_ATTR_DTIM_PERIOD: DTIM period
 * @NL80211_ATTR_TIMESTAMP: 64-bit timestamp of received beacon/probe response
 * @NL80211_ATTR_IE: information element(s), maximum length %NL80211_MAX_IE_LEN
 * @NL80211_ATTR_AUTH_ALGORITHM: authentication algorithm
 * @NL80211_ATTR_TIMEOUT_TU: timeout in TU (TO BE USED)
 * @NL80211_ATTR_REASON_CODE: 802.11 reason code
 * @NL80211_ATTR_ASSOCIATION_ID: association ID (u16, 1-2007)
 * @NL80211_ATTR_DEAUTHENTICATED: TO BE USED
 * @NL80211_ATTR_RX_SENSITIVITY: receiver sensitivity in dBm
 * @NL80211_ATTR_TRANSMIT_POWER: transmit power in mW
 * @NL80211_ATTR_FRAG_THRESHOLD: fragmentation threshold (bytes)
 * @NL80211_ATTR_FLAG_SCAN_ACTIVE: netlink flag indiciating active scan
 * @NL80211_ATTR_KEY_DATA: temporal key data
 * @NL80211_ATTR_KEY_ID: key ID (u8, 0-3)
 * @NL80211_ATTR_KEY_TYPE: key type (see &enum nl80211_keytype)
 * @NL80211_ATTR_MAC: MAC address
 * @NL80211_ATTR_KEY_CIPHER: key cipher suite (u32)
 * @__NL80211_ATTR_AFTER_LAST: internal use
 */
enum nl80211_attrs {
/* don't change the order or add anything inbetween, this is ABI! */
	NL80211_ATTR_UNSPEC,
	/* %type: u32 */
	NL80211_ATTR_IFINDEX,
	/* %type: nulstring */
	NL80211_ATTR_IFNAME,
	/* %type: u32 */
	NL80211_ATTR_WIPHY,
	/* %type: nulstring */
	NL80211_ATTR_WIPHY_NAME,
	NL80211_ATTR_CMDS,
	/* %type: u32 */
	NL80211_ATTR_IFTYPE,
	NL80211_ATTR_INTERFACE_LIST,
	NL80211_ATTR_WIPHY_LIST,
	NL80211_ATTR_BSSID,
	NL80211_ATTR_SSID,
	NL80211_ATTR_CHANNEL,
	NL80211_ATTR_PHYMODE,
	NL80211_ATTR_CHANNEL_LIST,
	NL80211_ATTR_BSS_LIST,
	NL80211_ATTR_BSSTYPE,
	NL80211_ATTR_BEACON_PERIOD,
	NL80211_ATTR_DTIM_PERIOD,
	NL80211_ATTR_TIMESTAMP,
	NL80211_ATTR_IE,
	NL80211_ATTR_AUTH_ALGORITHM,
	NL80211_ATTR_TIMEOUT_TU,
	NL80211_ATTR_REASON_CODE,
	NL80211_ATTR_ASSOCIATION_ID,
	NL80211_ATTR_DEAUTHENTICATED,
	NL80211_ATTR_RX_SENSITIVITY,
	NL80211_ATTR_TRANSMIT_POWER,
	NL80211_ATTR_FRAG_THRESHOLD,
	NL80211_ATTR_FLAG_SCAN_ACTIVE,

	NL80211_ATTR_KEY_DATA,
	NL80211_ATTR_KEY_ID,
	NL80211_ATTR_KEY_TYPE,
	NL80211_ATTR_MAC,
	NL80211_ATTR_KEY_CIPHER,

	NL80211_ATTR_BEACON_HEAD,
	NL80211_ATTR_BEACON_TAIL,

	/* add attributes here, update the policy in nl80211.c */

	/* used to define NL80211_ATTR_MAX below */
	__NL80211_ATTR_AFTER_LAST,
};
#define NL80211_ATTR_MAX (__NL80211_ATTR_AFTER_LAST - 1)

/**
 * enum nl80211_multicast_groups - multicast groups for nl80211
 * @NL80211_GROUP_CONFIG: members of this group are notified of
 *	configuration changes
 */
enum nl80211_multicast_groups {
	/* be notified of configuration changes like wiphy renames */
	NL80211_GROUP_CONFIG,

	/* add groups here */

	/* keep last */
	__NL80211_GROUP_AFTER_LAST
};
#define NL80211_GROUP_MAX (__NL80211_GROUP_AFTER_LAST - 1)

/*
 * maximum length of IE(s) passed in an NL80211_ATTR_IE.
 * this is an arbitrary limit, 774 means three full-length
 * IEs would fit... increase if necessary */
#define NL80211_MAX_IE_LEN 774

/*
 * maximum number of items in an ATTR_CHANNEL_LIST,
 * just to avoid too large allocations
 */
#define NL80211_MAX_CHANNEL_LIST_ITEM 200

/**
 * enum nl80211_iftype - (virtual) interface types
 * @NL80211_IFTYPE_UNSPECIFIED: unspecified type, driver decides
 * @NL80211_IFTYPE_ADHOC: independent BSS member
 * @NL80211_IFTYPE_STATION: managed BSS member
 * @NL80211_IFTYPE_AP: access point
 * @NL80211_IFTYPE_AP_VLAN: VLAN interface for access points
 * @NL80211_IFTYPE_WDS: wireless distribution interface
 * @NL80211_IFTYPE_MONITOR: monitor interface receiving all frames
 * @__NL80211_IFTYPE_AFTER_LAST: internal use
 *
 * These values are used with the NL80211_ATTR_IFTYPE
 * to set the type of an interface.
 *
 */
enum nl80211_iftype {
	NL80211_IFTYPE_UNSPECIFIED,
	NL80211_IFTYPE_ADHOC,
	NL80211_IFTYPE_STATION,
	NL80211_IFTYPE_AP,
	NL80211_IFTYPE_AP_VLAN,
	NL80211_IFTYPE_WDS,
	NL80211_IFTYPE_MONITOR,

	/* keep last */
	__NL80211_IFTYPE_AFTER_LAST
};
#define NL80211_IFTYPE_MAX (__NL80211_IFTYPE_AFTER_LAST - 1)

/**
 * enum nl80211_phymode - PHY modes
 * @NL80211_PHYMODE_A: 5 GHz PHY
 * @NL80211_PHYMODE_B: 2.4 GHz PHY (B mode)
 * @NL80211_PHYMODE_G: 2.4 GHz PHY (G, compatible with B)
 * @__NL80211_PHYMODE_AFTER_LAST: internal use
 *
 * These values are used for %NL80211_ATTR_PHYMODE.
 */
enum nl80211_phymode {
	NL80211_PHYMODE_A,
	NL80211_PHYMODE_B,
	NL80211_PHYMODE_G,

	/* keep last */
	__NL80211_PHYMODE_AFTER_LAST
};
#define NL80211_PHYMODE_MAX (__NL80211_PHYMODE_AFTER_LAST - 1)

/**
 * enum nl80211_bsstype - BSS types
 * @NL80211_BSSTYPE_INFRASTRUCTURE: infrastructure BSS
 * @NL80211_BSSTYPE_INDEPENDENT: independent BSS (ad-hoc network)
 * @__NL80211_BSSTYPE_AFTER_LAST: internal use
 *
 * These values are used for %NL80211_ATTR_BSSTYPE.
 */
enum nl80211_bsstype {
	NL80211_BSSTYPE_INFRASTRUCTURE,
	NL80211_BSSTYPE_INDEPENDENT,

	/* keep last */
	__NL80211_BSSTYPE_AFTER_LAST
};
#define NL80211_BSSTYPE_MAX (__NL80211_BSSTYPE_AFTER_LAST - 1)

/**
 * enum nl80211_keytype - key types
 * @NL80211_KEYTYPE_GROUP: group key
 * @NL80211_KEYTYPE_PAIRWISE: pairwise key
 * @NL80211_KEYTYPE_PEER: peer key
 */
enum nl80211_keytype {
	NL80211_KEYTYPE_GROUP,
	NL80211_KEYTYPE_PAIRWISE,
	NL80211_KEYTYPE_PEER,

	/* keep last */
	__NL80211_KEYTYPE_AFTER_LAST
};
#define NL80211_KEYTYPE_MAX (__NL80211_KEYTYPE_AFTER_LAST - 1)

#endif /* __LINUX_NL80211_H */
