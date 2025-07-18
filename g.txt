[
    {
        "remarks": "💦 1 - VLESS - Domain : 443",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 443,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/KfVEdIklaQnxvz4D?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BUtTErFly.wAfaVA7973.workErs.Dev"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 2 - VLESS - Domain : 443",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:www.speedtest.net"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:www.speedtest.net"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "www.speedtest.net",
                            "port": 443,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/nOkoYQX7fHazaWWb?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "bUTteRFly.wAFAva7973.woRkERs.dEv"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 3 - VLESS - IPv4 : 443",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "104.21.44.32",
                            "port": 443,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/oIrsQeX2iWQTKyWw?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BUtTerflY.WaFaVa7973.wORkErS.dEv"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 4 - VLESS - IPv4 : 443",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "172.67.194.87",
                            "port": 443,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/WVpvykNqYuJWfdiT?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "buTTErFLY.WAfAVa7973.WOrkERS.DEv"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 5 - VLESS - IPv6 : 443",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 443,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/lzSvK43AYVxm7ELq?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BUtterFly.waFava7973.WORkErs.dEV"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 6 - VLESS - IPv6 : 443",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 443,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/vX05BSRITHXoCESX?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "bUTteRflY.wAfaVA7973.WoRkErS.DEV"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 7 - VLESS - Domain : 2053",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 2053,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/Do12AVNA4hy8pez5?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BuTTERflY.wAfaVA7973.workeRS.DEV"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 8 - VLESS - Domain : 2053",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:www.speedtest.net"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:www.speedtest.net"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "www.speedtest.net",
                            "port": 2053,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/UqgrXOfSgqAjTY1e?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "buTTerFly.WAFava7973.WOrKeRS.DeV"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 9 - VLESS - IPv4 : 2053",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "104.21.44.32",
                            "port": 2053,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/glqwpaEMrj56bmjE?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "buTTeRflY.WAFaVA7973.woRKeRs.Dev"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 10 - VLESS - IPv4 : 2053",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "172.67.194.87",
                            "port": 2053,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/bFTBj6pX9cS6GQDb?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "bUttErflY.WaFaVa7973.WORKeRs.dEv"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 11 - VLESS - IPv6 : 2053",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 2053,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/x1R1HHjyA3LntzjL?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BuTTErfLy.WAFAva7973.WOrKErs.DEV"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 12 - VLESS - IPv6 : 2053",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 2053,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/MQdi2wU8GTrQT6C3?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "bUtTerFLy.wAfavA7973.workErS.deV"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 13 - VLESS - Domain : 2083",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 2083,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/MoKVNzvhdnfzg0U9?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "bUtTeRFly.WAfavA7973.WORKerS.dev"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 14 - VLESS - Domain : 2083",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:www.speedtest.net"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:www.speedtest.net"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "www.speedtest.net",
                            "port": 2083,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/K4ctioi3LcvBcC3w?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "buTterFLY.WAFAvA7973.workErs.dEV"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 15 - VLESS - IPv4 : 2083",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "104.21.44.32",
                            "port": 2083,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/z4VTMKztQFp4pifv?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BuTTerFLY.WAfava7973.WOrkeRS.dev"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 16 - VLESS - IPv4 : 2083",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "172.67.194.87",
                            "port": 2083,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/IdYGgcPYKAHEPr8J?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "bUTtErFLy.WaFaVA7973.wOrKERS.deV"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 17 - VLESS - IPv6 : 2083",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 2083,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/5hPmdnqlKlIsXP9v?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BUtTERFly.WAfava7973.WoRkERS.DEv"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 18 - VLESS - IPv6 : 2083",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 2083,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/kNxj4w9WK7K1FfMA?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "bUtterFlY.wAfAva7973.WORKers.DeV"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 19 - VLESS - Domain : 80",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 80,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/8jDq1IaMlwrjYMu7?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 20 - VLESS - Domain : 80",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:www.speedtest.net"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:www.speedtest.net"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "www.speedtest.net",
                            "port": 80,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/gBsgyrPxJTFM09Hr?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 21 - VLESS - IPv4 : 80",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "104.21.44.32",
                            "port": 80,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/99lu5Aw9lGqPemXa?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 22 - VLESS - IPv4 : 80",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "172.67.194.87",
                            "port": 80,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/gNTrejmOtmkDbcNr?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 23 - VLESS - IPv6 : 80",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 80,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/dzslaD5LeMGgJLuz?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 24 - VLESS - IPv6 : 80",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 80,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/whIRoEAP2Bvb1RCT?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 25 - VLESS - Domain : 2052",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 2052,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/eNlL7ub0KZGd9C07?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 26 - VLESS - Domain : 2052",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:www.speedtest.net"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:www.speedtest.net"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "www.speedtest.net",
                            "port": 2052,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/EWnrUvfimE3dGyho?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 27 - VLESS - IPv4 : 2052",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "104.21.44.32",
                            "port": 2052,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/5hV5pADUmDpowiFR?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 28 - VLESS - IPv4 : 2052",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "172.67.194.87",
                            "port": 2052,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/wv6vKI6OFBhR5zPp?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 29 - VLESS - IPv6 : 2052",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 2052,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/74ULEnp5MVQyoCdM?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 30 - VLESS - IPv6 : 2052",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 2052,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/8562ghCAzdyKZotp?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 31 - VLESS - Domain : 2082",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 2082,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/p1bE2cTsgoS5kiuu?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 32 - VLESS - Domain : 2082",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:www.speedtest.net"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:www.speedtest.net"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "www.speedtest.net",
                            "port": 2082,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/r5jeMGPCnEGwPDws?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 33 - VLESS - IPv4 : 2082",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "104.21.44.32",
                            "port": 2082,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/lXk6wNoqdolFwFNZ?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 34 - VLESS - IPv4 : 2082",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "172.67.194.87",
                            "port": 2082,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/to5xXZcrQaznzdOq?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 35 - VLESS - IPv6 : 2082",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 2082,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/wndcOQXOxe6OPzG1?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 36 - VLESS - IPv6 : 2082",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 2082,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/jYRRbmI8Ce49wBIG?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 1 - Trojan - Domain : 443",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 443,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trMLH5eQLL1Q4IxWDr?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BuTterFlY.wafava7973.wOrKERS.DEv"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 2 - Trojan - Domain : 443",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:www.speedtest.net"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:www.speedtest.net"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "www.speedtest.net",
                            "port": 443,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/tr9dXH0aiOrpNHWhww?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BUTterFlY.wafAVA7973.WORkErS.dEV"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 3 - Trojan - IPv4 : 443",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "104.21.44.32",
                            "port": 443,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trWz0dTaicxNCDIPmc?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "ButTeRFLY.waFAVa7973.WorKERs.DEV"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 4 - Trojan - IPv4 : 443",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "172.67.194.87",
                            "port": 443,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trCTAIoPKXBrQnxoqy?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "bUttERFly.WAfaVA7973.WorKeRs.Dev"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 5 - Trojan - IPv6 : 443",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 443,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trwh02OVPsAKNg7U4X?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "buTtERFlY.WafAVA7973.WORkeRs.dEv"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 6 - Trojan - IPv6 : 443",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 443,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trf637HUrS50nwQhME?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "bUtTERFLy.WAfAvA7973.WOrKerS.dEv"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 7 - Trojan - Domain : 2053",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 2053,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trtb7u5k9TcN1Mwu4c?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "buTteRfLY.wAFavA7973.WOrkerS.DEv"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 8 - Trojan - Domain : 2053",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:www.speedtest.net"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:www.speedtest.net"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "www.speedtest.net",
                            "port": 2053,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/tr88Svpt15PHQoiBJ3?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "ButTERFLY.wafAVA7973.workERs.deV"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 9 - Trojan - IPv4 : 2053",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "104.21.44.32",
                            "port": 2053,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trRvKYzLoolduTwUOV?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BuTTERFly.WAfaVA7973.wORKeRs.DeV"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 10 - Trojan - IPv4 : 2053",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "172.67.194.87",
                            "port": 2053,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/tr5btaWCTqlpq2EKC8?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "bUTterFlY.waFAvA7973.WORKERS.DEv"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 11 - Trojan - IPv6 : 2053",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 2053,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trf27cxO3EpMKiDrux?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "ButtErFLy.WafAVa7973.WorKers.DeV"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 12 - Trojan - IPv6 : 2053",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 2053,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trDgquqcNZN2lsJhhP?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BuTTeRfly.WAfAVa7973.woRKERs.deV"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 13 - Trojan - Domain : 2083",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 2083,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trvmjgyNc2yuqpzrVl?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "ButteRFLy.wAFAva7973.woRKeRs.DEV"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 14 - Trojan - Domain : 2083",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:www.speedtest.net"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:www.speedtest.net"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "www.speedtest.net",
                            "port": 2083,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trBqXmr3687ro7wOVb?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "ButterFLY.wAFaVA7973.wOrKErs.dEv"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 15 - Trojan - IPv4 : 2083",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "104.21.44.32",
                            "port": 2083,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trTzhqdXnycyNKIlpi?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BUTTerfLY.wafAva7973.WorkERs.DEv"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 16 - Trojan - IPv4 : 2083",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "172.67.194.87",
                            "port": 2083,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trXTM6E6dQCKdbQup7?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "buTtErFLy.waFaVa7973.WoRKeRs.Dev"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 17 - Trojan - IPv6 : 2083",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 2083,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trEnSwBbyebbIv3RgJ?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BUtTERFLY.WAFAva7973.wOrKerS.DEV"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 18 - Trojan - IPv6 : 2083",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 2083,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trR33j1MC9HDdAnnnT?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "bUTtErfLy.wAfaVa7973.worKeRs.dEV"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 19 - Trojan - Domain : 80",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 80,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/tr1nYv8LYJYNzNrCvM?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 20 - Trojan - Domain : 80",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:www.speedtest.net"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:www.speedtest.net"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "www.speedtest.net",
                            "port": 80,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trJnIuugtfXmC5eVws?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 21 - Trojan - IPv4 : 80",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "104.21.44.32",
                            "port": 80,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/tr5UUtRMnNAp2h136Q?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 22 - Trojan - IPv4 : 80",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "172.67.194.87",
                            "port": 80,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trAoon6Vm34ur3vGZs?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 23 - Trojan - IPv6 : 80",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 80,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trLG9p1FeO4pmDOBDq?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 24 - Trojan - IPv6 : 80",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 80,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trti4UsjQvsAqGjhFI?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 25 - Trojan - Domain : 2052",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 2052,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trqbvgjK1Qr8cNMEJ0?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 26 - Trojan - Domain : 2052",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:www.speedtest.net"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:www.speedtest.net"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "www.speedtest.net",
                            "port": 2052,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trHtqq7ZzICWyt0gV7?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 27 - Trojan - IPv4 : 2052",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "104.21.44.32",
                            "port": 2052,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trU7nzXpyGt3p5Yzi1?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 28 - Trojan - IPv4 : 2052",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "172.67.194.87",
                            "port": 2052,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trH3gUTvdLoMOO28Yu?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 29 - Trojan - IPv6 : 2052",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 2052,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trYmdFpU0Fmduln2Qy?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 30 - Trojan - IPv6 : 2052",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 2052,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trcFxLiCU69FIWLPFX?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 31 - Trojan - Domain : 2082",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 2082,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/traqQDrdvLuExGOcuZ?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 32 - Trojan - Domain : 2082",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:www.speedtest.net"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:www.speedtest.net"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "www.speedtest.net",
                            "port": 2082,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trt6ELJ3BBhe7VxtJm?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 33 - Trojan - IPv4 : 2082",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "104.21.44.32",
                            "port": 2082,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/tr1rkP03efMqrbcQaC?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 34 - Trojan - IPv4 : 2082",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "172.67.194.87",
                            "port": 2082,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trTgBmzqLfLtkqw5Ft?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 35 - Trojan - IPv6 : 2082",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 2082,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trVPKJy8d5GeVbIKbC?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 36 - Trojan - IPv6 : 2082",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                "fakedns",
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 2082,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trQgEXiP9YuGCvfLRf?ed=2560"
                    }
                },
                "tag": "proxy"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "outboundTag": "proxy",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "outboundTag": "proxy",
                    "type": "field"
                }
            ]
        },
        "stats": {}
    },
    {
        "remarks": "💦 BPB - Best Ping 💥",
        "log": {
            "loglevel": "warning"
        },
        "dns": {
            "hosts": {
                "unfiltered.joindns4.eu": [
                    "86.54.11.200",
                    "86.54.11.100",
                    "2a13:1001::86:54:11:100",
                    "2a13:1001::86:54:11:200"
                ]
            },
            "servers": [
                {
                    "address": "fakedns",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev",
                        "full:www.speedtest.net"
                    ]
                },
                {
                    "address": "https://unfiltered.joindns4.eu/dns-query",
                    "tag": "remote-dns"
                },
                {
                    "address": "86.54.11.100",
                    "domains": [
                        "full:butterfly.wafava7973.workers.dev",
                        "full:www.speedtest.net"
                    ],
                    "skipFallback": true
                }
            ],
            "queryStrategy": "UseIP",
            "tag": "dns"
        },
        "inbounds": [
            {
                "port": 10808,
                "protocol": "socks",
                "settings": {
                    "auth": "noauth",
                    "udp": true,
                    "userLevel": 8
                },
                "sniffing": {
                    "destOverride": [
                        "http",
                        "tls",
                        "fakedns"
                    ],
                    "enabled": true,
                    "routeOnly": true
                },
                "tag": "socks-in"
            },
            {
                "port": 10853,
                "protocol": "dokodemo-door",
                "settings": {
                    "address": "1.1.1.1",
                    "network": "tcp,udp",
                    "port": 53
                },
                "tag": "dns-in"
            }
        ],
        "outbounds": [
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 443,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/KfVEdIklaQnxvz4D?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BUtTErFly.wAfaVA7973.workErs.Dev"
                    }
                },
                "tag": "prox-1"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "www.speedtest.net",
                            "port": 443,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/nOkoYQX7fHazaWWb?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "bUTteRFly.wAFAva7973.woRkERs.dEv"
                    }
                },
                "tag": "prox-2"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "104.21.44.32",
                            "port": 443,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/oIrsQeX2iWQTKyWw?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BUtTerflY.WaFaVa7973.wORkErS.dEv"
                    }
                },
                "tag": "prox-3"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "172.67.194.87",
                            "port": 443,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/WVpvykNqYuJWfdiT?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "buTTErFLY.WAfAVa7973.WOrkERS.DEv"
                    }
                },
                "tag": "prox-4"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 443,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/lzSvK43AYVxm7ELq?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BUtterFly.waFava7973.WORkErs.dEV"
                    }
                },
                "tag": "prox-5"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 443,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/vX05BSRITHXoCESX?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "bUTteRflY.wAfaVA7973.WoRkErS.DEV"
                    }
                },
                "tag": "prox-6"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 2053,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/Do12AVNA4hy8pez5?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BuTTERflY.wAfaVA7973.workeRS.DEV"
                    }
                },
                "tag": "prox-7"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "www.speedtest.net",
                            "port": 2053,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/UqgrXOfSgqAjTY1e?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "buTTerFly.WAFava7973.WOrKeRS.DeV"
                    }
                },
                "tag": "prox-8"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "104.21.44.32",
                            "port": 2053,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/glqwpaEMrj56bmjE?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "buTTeRflY.WAFaVA7973.woRKeRs.Dev"
                    }
                },
                "tag": "prox-9"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "172.67.194.87",
                            "port": 2053,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/bFTBj6pX9cS6GQDb?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "bUttErflY.WaFaVa7973.WORKeRs.dEv"
                    }
                },
                "tag": "prox-10"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 2053,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/x1R1HHjyA3LntzjL?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BuTTErfLy.WAFAva7973.WOrKErs.DEV"
                    }
                },
                "tag": "prox-11"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 2053,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/MQdi2wU8GTrQT6C3?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "bUtTerFLy.wAfavA7973.workErS.deV"
                    }
                },
                "tag": "prox-12"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 2083,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/MoKVNzvhdnfzg0U9?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "bUtTeRFly.WAfavA7973.WORKerS.dev"
                    }
                },
                "tag": "prox-13"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "www.speedtest.net",
                            "port": 2083,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/K4ctioi3LcvBcC3w?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "buTterFLY.WAFAvA7973.workErs.dEV"
                    }
                },
                "tag": "prox-14"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "104.21.44.32",
                            "port": 2083,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/z4VTMKztQFp4pifv?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BuTTerFLY.WAfava7973.WOrkeRS.dev"
                    }
                },
                "tag": "prox-15"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "172.67.194.87",
                            "port": 2083,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/IdYGgcPYKAHEPr8J?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "bUTtErFLy.WaFaVA7973.wOrKERS.deV"
                    }
                },
                "tag": "prox-16"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 2083,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/5hPmdnqlKlIsXP9v?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BUtTERFly.WAfava7973.WoRkERS.DEv"
                    }
                },
                "tag": "prox-17"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 2083,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/kNxj4w9WK7K1FfMA?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "bUtterFlY.wAfAva7973.WORKers.DeV"
                    }
                },
                "tag": "prox-18"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 80,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/8jDq1IaMlwrjYMu7?ed=2560"
                    }
                },
                "tag": "prox-19"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "www.speedtest.net",
                            "port": 80,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/gBsgyrPxJTFM09Hr?ed=2560"
                    }
                },
                "tag": "prox-20"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "104.21.44.32",
                            "port": 80,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/99lu5Aw9lGqPemXa?ed=2560"
                    }
                },
                "tag": "prox-21"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "172.67.194.87",
                            "port": 80,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/gNTrejmOtmkDbcNr?ed=2560"
                    }
                },
                "tag": "prox-22"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 80,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/dzslaD5LeMGgJLuz?ed=2560"
                    }
                },
                "tag": "prox-23"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 80,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/whIRoEAP2Bvb1RCT?ed=2560"
                    }
                },
                "tag": "prox-24"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 2052,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/eNlL7ub0KZGd9C07?ed=2560"
                    }
                },
                "tag": "prox-25"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "www.speedtest.net",
                            "port": 2052,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/EWnrUvfimE3dGyho?ed=2560"
                    }
                },
                "tag": "prox-26"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "104.21.44.32",
                            "port": 2052,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/5hV5pADUmDpowiFR?ed=2560"
                    }
                },
                "tag": "prox-27"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "172.67.194.87",
                            "port": 2052,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/wv6vKI6OFBhR5zPp?ed=2560"
                    }
                },
                "tag": "prox-28"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 2052,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/74ULEnp5MVQyoCdM?ed=2560"
                    }
                },
                "tag": "prox-29"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 2052,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/8562ghCAzdyKZotp?ed=2560"
                    }
                },
                "tag": "prox-30"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 2082,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/p1bE2cTsgoS5kiuu?ed=2560"
                    }
                },
                "tag": "prox-31"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "www.speedtest.net",
                            "port": 2082,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/r5jeMGPCnEGwPDws?ed=2560"
                    }
                },
                "tag": "prox-32"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "104.21.44.32",
                            "port": 2082,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/lXk6wNoqdolFwFNZ?ed=2560"
                    }
                },
                "tag": "prox-33"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "172.67.194.87",
                            "port": 2082,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/to5xXZcrQaznzdOq?ed=2560"
                    }
                },
                "tag": "prox-34"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 2082,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/wndcOQXOxe6OPzG1?ed=2560"
                    }
                },
                "tag": "prox-35"
            },
            {
                "protocol": "vless",
                "settings": {
                    "vnext": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 2082,
                            "users": [
                                {
                                    "id": "7e53a132-2f54-4085-a9d9-61017d721b15",
                                    "encryption": "none",
                                    "level": 8
                                }
                            ]
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/jYRRbmI8Ce49wBIG?ed=2560"
                    }
                },
                "tag": "prox-36"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 443,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trMLH5eQLL1Q4IxWDr?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BuTterFlY.wafava7973.wOrKERS.DEv"
                    }
                },
                "tag": "prox-37"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "www.speedtest.net",
                            "port": 443,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/tr9dXH0aiOrpNHWhww?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BUTterFlY.wafAVA7973.WORkErS.dEV"
                    }
                },
                "tag": "prox-38"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "104.21.44.32",
                            "port": 443,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trWz0dTaicxNCDIPmc?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "ButTeRFLY.waFAVa7973.WorKERs.DEV"
                    }
                },
                "tag": "prox-39"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "172.67.194.87",
                            "port": 443,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trCTAIoPKXBrQnxoqy?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "bUttERFly.WAfaVA7973.WorKeRs.Dev"
                    }
                },
                "tag": "prox-40"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 443,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trwh02OVPsAKNg7U4X?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "buTtERFlY.WafAVA7973.WORkeRs.dEv"
                    }
                },
                "tag": "prox-41"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 443,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trf637HUrS50nwQhME?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "bUtTERFLy.WAfAvA7973.WOrKerS.dEv"
                    }
                },
                "tag": "prox-42"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 2053,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trtb7u5k9TcN1Mwu4c?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "buTteRfLY.wAFavA7973.WOrkerS.DEv"
                    }
                },
                "tag": "prox-43"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "www.speedtest.net",
                            "port": 2053,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/tr88Svpt15PHQoiBJ3?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "ButTERFLY.wafAVA7973.workERs.deV"
                    }
                },
                "tag": "prox-44"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "104.21.44.32",
                            "port": 2053,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trRvKYzLoolduTwUOV?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BuTTERFly.WAfaVA7973.wORKeRs.DeV"
                    }
                },
                "tag": "prox-45"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "172.67.194.87",
                            "port": 2053,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/tr5btaWCTqlpq2EKC8?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "bUTterFlY.waFAvA7973.WORKERS.DEv"
                    }
                },
                "tag": "prox-46"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 2053,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trf27cxO3EpMKiDrux?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "ButtErFLy.WafAVa7973.WorKers.DeV"
                    }
                },
                "tag": "prox-47"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 2053,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trDgquqcNZN2lsJhhP?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BuTTeRfly.WAfAVa7973.woRKERs.deV"
                    }
                },
                "tag": "prox-48"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 2083,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trvmjgyNc2yuqpzrVl?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "ButteRFLy.wAFAva7973.woRKeRs.DEV"
                    }
                },
                "tag": "prox-49"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "www.speedtest.net",
                            "port": 2083,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trBqXmr3687ro7wOVb?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "ButterFLY.wAFaVA7973.wOrKErs.dEv"
                    }
                },
                "tag": "prox-50"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "104.21.44.32",
                            "port": 2083,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trTzhqdXnycyNKIlpi?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BUTTerfLY.wafAva7973.WorkERs.DEv"
                    }
                },
                "tag": "prox-51"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "172.67.194.87",
                            "port": 2083,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trXTM6E6dQCKdbQup7?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "buTtErFLy.waFaVa7973.WoRKeRs.Dev"
                    }
                },
                "tag": "prox-52"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 2083,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trEnSwBbyebbIv3RgJ?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "BUtTERFLY.WAFAva7973.wOrKerS.DEV"
                    }
                },
                "tag": "prox-53"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 2083,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "tls",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trR33j1MC9HDdAnnnT?ed=2560"
                    },
                    "tlsSettings": {
                        "allowInsecure": false,
                        "fingerprint": "randomized",
                        "alpn": [
                            "http/1.1"
                        ],
                        "serverName": "bUTtErfLy.wAfaVa7973.worKeRs.dEV"
                    }
                },
                "tag": "prox-54"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 80,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/tr1nYv8LYJYNzNrCvM?ed=2560"
                    }
                },
                "tag": "prox-55"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "www.speedtest.net",
                            "port": 80,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trJnIuugtfXmC5eVws?ed=2560"
                    }
                },
                "tag": "prox-56"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "104.21.44.32",
                            "port": 80,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/tr5UUtRMnNAp2h136Q?ed=2560"
                    }
                },
                "tag": "prox-57"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "172.67.194.87",
                            "port": 80,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trAoon6Vm34ur3vGZs?ed=2560"
                    }
                },
                "tag": "prox-58"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 80,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trLG9p1FeO4pmDOBDq?ed=2560"
                    }
                },
                "tag": "prox-59"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 80,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trti4UsjQvsAqGjhFI?ed=2560"
                    }
                },
                "tag": "prox-60"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 2052,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trqbvgjK1Qr8cNMEJ0?ed=2560"
                    }
                },
                "tag": "prox-61"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "www.speedtest.net",
                            "port": 2052,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trHtqq7ZzICWyt0gV7?ed=2560"
                    }
                },
                "tag": "prox-62"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "104.21.44.32",
                            "port": 2052,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trU7nzXpyGt3p5Yzi1?ed=2560"
                    }
                },
                "tag": "prox-63"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "172.67.194.87",
                            "port": 2052,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trH3gUTvdLoMOO28Yu?ed=2560"
                    }
                },
                "tag": "prox-64"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 2052,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trYmdFpU0Fmduln2Qy?ed=2560"
                    }
                },
                "tag": "prox-65"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 2052,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trcFxLiCU69FIWLPFX?ed=2560"
                    }
                },
                "tag": "prox-66"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "butterfly.wafava7973.workers.dev",
                            "port": 2082,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/traqQDrdvLuExGOcuZ?ed=2560"
                    }
                },
                "tag": "prox-67"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "www.speedtest.net",
                            "port": 2082,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trt6ELJ3BBhe7VxtJm?ed=2560"
                    }
                },
                "tag": "prox-68"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "104.21.44.32",
                            "port": 2082,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/tr1rkP03efMqrbcQaC?ed=2560"
                    }
                },
                "tag": "prox-69"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "172.67.194.87",
                            "port": 2082,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trTgBmzqLfLtkqw5Ft?ed=2560"
                    }
                },
                "tag": "prox-70"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3030::ac43:c257]",
                            "port": 2082,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trVPKJy8d5GeVbIKbC?ed=2560"
                    }
                },
                "tag": "prox-71"
            },
            {
                "protocol": "trojan",
                "settings": {
                    "servers": [
                        {
                            "address": "[2606:4700:3034::6815:2c20]",
                            "port": 2082,
                            "password": "5821469",
                            "level": 8
                        }
                    ]
                },
                "streamSettings": {
                    "network": "ws",
                    "security": "none",
                    "sockopt": {
                        "domainStrategy": "UseIPv4v6"
                    },
                    "wsSettings": {
                        "host": "butterfly.wafava7973.workers.dev",
                        "path": "/trQgEXiP9YuGCvfLRf?ed=2560"
                    }
                },
                "tag": "prox-72"
            },
            {
                "protocol": "dns",
                "tag": "dns-out"
            },
            {
                "protocol": "freedom",
                "settings": {
                    "domainStrategy": "UseIP"
                },
                "tag": "direct"
            },
            {
                "protocol": "blackhole",
                "settings": {
                    "response": {
                        "type": "http"
                    }
                },
                "tag": "block"
            }
        ],
        "policy": {
            "levels": {
                "8": {
                    "connIdle": 300,
                    "downlinkOnly": 1,
                    "handshake": 4,
                    "uplinkOnly": 1
                }
            },
            "system": {
                "statsOutboundUplink": true,
                "statsOutboundDownlink": true
            }
        },
        "routing": {
            "domainStrategy": "IPIfNonMatch",
            "rules": [
                {
                    "inboundTag": [
                        "dns-in"
                    ],
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "socks-in"
                    ],
                    "port": 53,
                    "outboundTag": "dns-out",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "remote-dns"
                    ],
                    "balancerTag": "all",
                    "type": "field"
                },
                {
                    "inboundTag": [
                        "dns"
                    ],
                    "outboundTag": "direct",
                    "type": "field"
                },
                {
                    "network": "udp",
                    "outboundTag": "block",
                    "type": "field"
                },
                {
                    "network": "tcp",
                    "balancerTag": "all",
                    "type": "field"
                }
            ],
            "balancers": [
                {
                    "tag": "all",
                    "selector": [
                        "prox"
                    ],
                    "strategy": {
                        "type": "leastPing"
                    },
                    "fallbackTag": "prox-2"
                }
            ]
        },
        "stats": {},
        "observatory": {
            "subjectSelector": [
                "prox"
            ],
            "probeUrl": "https://www.gstatic.com/generate_204",
            "probeInterval": "30s",
            "enableConcurrency": true
        }
    }
]
