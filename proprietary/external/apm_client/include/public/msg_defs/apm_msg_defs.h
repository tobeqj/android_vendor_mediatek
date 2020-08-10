typedef enum {
    APM_MSG_FOO_BAR = 0,
    APM_MSG_PKM_VOLTE_SIP = 1,
    APM_MSG_PKM_VOLTE_RTP = 2,
    APM_MSG_PKM_VOLTE_DNS = 3,
    APM_MSG_PKM_VOLTE_OTHERS = 4,
    APM_MSG_PKM_NONVOLTE_DNS = 5,
    APM_MSG_PKM_NONVOLTE_INTERNET = 6,
    APM_MSG_PKM_WIFI_NATT_KEEP_ALIVE = 7,
    APM_MSG_PKM_WIFI_ISAKMP = 8,
    APM_MSG_PKM_WIFI_SIP = 9,
    APM_MSG_PKM_WIFI_RTP = 10,
    APM_MSG_PKM_WIFI_DNS = 11,
    APM_MSG_PKM_WIFI_INTERNET = 12,
    APM_MSG_SUPL_STATISTICS = 13,
    APM_MSG_SUPL_MESSAGE = 14,
    APM_MSG_LOCATION_MESSAGE = 15,
    APM_MSG_WIFI_INFO = 16,
    APM_MSG_WIFI_SCAN = 17,
    APM_MSG_WIFI_CONNECTION_INFO = 18,
    APM_MSG_WIFI_POWER_SAVE = 19,
    APM_MSG_WIFI_DHCP_FAILURE = 20,
    APM_MSG_NETWORK_SERVICE_STATE = 21
} apmMsgId_e;