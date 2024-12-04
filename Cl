port: 7890
socks-port: 7891
redir-port: 7892
mixed-port: 7893
tproxy-port: 7895
ipv6: false
mode: rule
log-level: silent
allow-lan: true
external-controller: 0.0.0.0:9090
secret: ""
bind-address: "*"
unified-delay: true
profile:
  store-selected: true
  store-fake-ip: true
dns:
  enable: true
  ipv6: false
  use-host: true
  enhanced-mode: fake-ip
  listen: 0.0.0.0:7874
  nameserver:
    - 8.8.8.8
    - 1.0.0.1
    - https://dns.google/dns-query
  fallback:
    - 1.1.1.1
    - 8.8.4.4
    - https://cloudflare-dns.com/dns-query
    - 112.215.203.254
  default-nameserver:
    - 8.8.8.8
    - 1.1.1.1
    - 112.215.203.254
  fake-ip-range: 198.18.0.1/16
  fake-ip-filter:
    - "*.lan"
    - "*.localdomain"
    - "*.example"
    - "*.invalid"
    - "*.localhost"
    - "*.test"
    - "*.local"
    - "*.home.arpa"
    - time.*.com
    - time.*.gov
    - time.*.edu.cn
    - time.*.apple.com
    - time1.*.com
    - time2.*.com
    - time3.*.com
    - time4.*.com
    - time5.*.com
    - time6.*.com
    - time7.*.com
    - ntp.*.com
    - ntp1.*.com
    - ntp2.*.com
    - ntp3.*.com
    - ntp4.*.com
    - ntp5.*.com
    - ntp6.*.com
    - ntp7.*.com
    - "*.time.edu.cn"
    - "*.ntp.org.cn"
    - +.pool.ntp.org
    - time1.cloud.tencent.com
    - music.163.com
    - "*.music.163.com"
    - "*.126.net"
    - musicapi.taihe.com
    - music.taihe.com
    - songsearch.kugou.com
    - trackercdn.kugou.com
    - "*.kuwo.cn"
    - api-jooxtt.sanook.com
    - api.joox.com
    - joox.com
    - y.qq.com
    - "*.y.qq.com"
    - streamoc.music.tc.qq.com
    - mobileoc.music.tc.qq.com
    - isure.stream.qqmusic.qq.com
    - dl.stream.qqmusic.qq.com
    - aqqmusic.tc.qq.com
    - amobile.music.tc.qq.com
    - "*.xiami.com"
    - "*.music.migu.cn"
    - music.migu.cn
    - "*.msftconnecttest.com"
    - "*.msftncsi.com"
    - msftconnecttest.com
    - msftncsi.com
    - localhost.ptlogin2.qq.com
    - localhost.sec.qq.com
    - +.srv.nintendo.net
    - +.stun.playstation.net
    - xbox.*.microsoft.com
    - xnotify.xboxlive.com
    - +.battlenet.com.cn
    - +.wotgame.cn
    - +.wggames.cn
    - +.wowsgame.cn
    - +.wargaming.net
    - proxy.golang.org
    - stun.*.*
    - stun.*.*.*
    - +.stun.*.*
    - +.stun.*.*.*
    - +.stun.*.*.*.*
    - heartbeat.belkin.com
    - "*.linksys.com"
    - "*.linksyssmartwifi.com"
    - "*.router.asus.com"
    - mesu.apple.com
    - swscan.apple.com
    - swquery.apple.com
    - swdownload.apple.com
    - swcdn.apple.com
    - swdist.apple.com
    - lens.l.google.com
    - stun.l.google.com
    - +.nflxvideo.net
    - "*.square-enix.com"
    - "*.finalfantasyxiv.com"
    - "*.ffxiv.com"
    - "*.mcdn.bilivideo.cn"
    - +.media.dssott.com
proxies:
  - name: "1 - VLESS - Domain : 443"
    server: samt.md7286rr.workers.dev
    port: 443
    type: vless
    uuid: 43acc712-7cbd-4f48-a437-7f64126b46b1
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: sAMT.md7286Rr.WorkerS.dEv
    network: ws
    ws-opts:
      path: /yyNcs6P21xLoDUH9?ed=2560
      headers:
        Host: samt.md7286rr.workers.dev
    udp: true
  - name: "2 - VLESS - Domain : 443"
    server: www.speedtest.net
    port: 443
    type: vless
    uuid: 43acc712-7cbd-4f48-a437-7f64126b46b1
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: sAmT.Md7286Rr.WorKERs.dEV
    network: ws
    ws-opts:
      path: /VCMFrhzMetkXJBK7?ed=2560
      headers:
        Host: samt.md7286rr.workers.dev
    udp: true
  - name: "3 - VLESS - IPv4 : 443"
    server: 188.114.97.3
    port: 443
    type: vless
    uuid: 43acc712-7cbd-4f48-a437-7f64126b46b1
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: SAmt.md7286rR.wOrKeRS.DEv
    network: ws
    ws-opts:
      path: /yYNVnHPQpYabBYux?ed=2560
      headers:
        Host: samt.md7286rr.workers.dev
    udp: true
  - name: "4 - VLESS - IPv4 : 443"
    server: 188.114.96.3
    port: 443
    type: vless
    uuid: 43acc712-7cbd-4f48-a437-7f64126b46b1
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: SaMt.mD7286rR.WoRkers.dEv
    network: ws
    ws-opts:
      path: /BLxtMTdDiaLdRES6?ed=2560
      headers:
        Host: samt.md7286rr.workers.dev
    udp: true
  - name: VMESS-sarm-ws
    server: oths.wikimi88549712.workers.dev
    port: 80
    type: vmess
    uuid: f3510a70-85b5-425b-8fa2-22fc24142dab
    alterId: 0
    cipher: auto
    tls: false
    skip-cert-verify: true
    servername: oths.wikimi88549712.workers.dev
    network: ws
    ws-opts:
      path: /de1.v4vmess.xyz/vmess-ws
      headers:
        Host: oths.wikimi88549712.workers.dev
    udp: true
  - name: VMESS-sarm-ws 2
    server: oths.wikimi88549712.workers.dev
    port: 443
    type: vmess
    uuid: f3510a70-85b5-425b-8fa2-22fc24142dab
    alterId: 0
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: oths.wikimi88549712.workers.dev
    network: ws
    ws-opts:
      path: /de1.v4vmess.xyz/vmess-ws
      headers:
        Host: oths.wikimi88549712.workers.dev
    udp: true
  - name: vmess-ws-tls
    server: oths.wikimi88549712.workers.dev
    port: 443
    type: vmess
    uuid: 497abd91-ef68-43a9-9db3-a84395569585
    alterId: 0
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: oths.wikimi88549712.workers.dev
    network: ws
    ws-opts:
      path: /de-freevmess.privateip.net/FREEVMESS
      headers:
        Host: oths.wikimi88549712.workers.dev
    udp: true
  - name: vpnhack-vpnhack-ws
    server: oths.wikimi88549712.workers.dev
    port: 443
    type: vmess
    uuid: ebfdc1c9-47fe-4eb8-bec7-73ffe7956851
    alterId: 0
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: oths.wikimi88549712.workers.dev
    network: ws
    ws-opts:
      path: /de1.vmessvh.site/vmess
      headers:
        Host: oths.wikimi88549712.workers.dev
    udp: true
  - name: VMESS-samm-ws-clone
    server: oths.wikimi88549712.workers.dev
    port: 443
    type: vmess
    uuid: 53444fa5-6e0d-4fef-bd92-83b48e9d605a
    alterId: 0
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: oths.wikimi88549712.workers.dev
    network: ws
    ws-opts:
      path: /ca1.v4vmess.xyz/vmess-ws
      headers:
        Host: oths.wikimi88549712.workers.dev
    udp: true
  - name: vmess-ws-tls 2
    server: oths.wikimi88549712.workers.dev
    port: 443
    type: vmess
    uuid: fa0c39fe-1c37-491b-afc8-d8538057b990
    alterId: 0
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: oths.wikimi88549712.workers.dev
    network: ws
    ws-opts:
      path: /nl2-full.privateip.net/RACEVPN
      headers:
        Host: oths.wikimi88549712.workers.dev
    udp: true
  - name: greenssh-gamw
    server: oths.wikimi88549712.workers.dev
    port: 443
    type: vmess
    uuid: 21485545-bc1a-4f6a-9f60-c0a38231182e
    alterId: 0
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: oths.wikimi88549712.workers.dev
    network: ws
    ws-opts:
      path: /de1-vmess.greenssh.org/vmess
      headers:
        Host: oths.wikimi88549712.workers.dev
    udp: true
  - name: greenssh-gamw 2
    server: oths.wikimi88549712.workers.dev
    port: 80
    type: vmess
    uuid: 21485545-bc1a-4f6a-9f60-c0a38231182e
    alterId: 0
    cipher: auto
    tls: false
    skip-cert-verify: true
    servername: de1-vmess.greenssh.org
    network: ws
    ws-opts:
      path: /de1-vmess.greenssh.org/vmess
      headers:
        Host: oths.wikimi88549712.workers.dev
    udp: true
  - name: freevpn.us-gham (v2-de-1.v2s.top)-clone
    server: oths.wikimi88549712.workers.dev
    port: 443
    type: vmess
    uuid: 7772bb24-976a-45ca-aa76-f4f1b7f50923
    alterId: 16
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: oths.wikimi88549712.workers.dev
    network: ws
    ws-opts:
      path: /v2-de-1.v2s.top/anything/freevpn.us-gham/vmess
      headers:
        Host: oths.wikimi88549712.workers.dev
    udp: true
  - name: Vmess USA LA 2024-12-10-clone
    server: oths.wikimi88549712.workers.dev
    port: 80
    type: vmess
    uuid: 481c42c0-b0e8-11ef-b330-205c6d5f5d78
    alterId: 0
    cipher: auto
    tls: false
    skip-cert-verify: true
    servername: us-21.hihu.net
    network: ws
    ws-opts:
      path: /mgrbq1ps
      headers:
        Host: us-21.hihu.net
    udp: true
  - name: majid2
    server: oths.wikimi88549712.workers.dev
    port: 443
    type: vmess
    uuid: a40d34c6-b77c-4648-9210-3e8d2f4226b5
    alterId: 16
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: oths.wikimi88549712.workers.dev
    network: ws
    ws-opts:
      path: /usv-3.openv2ray.com/opentunnel?user=opentunnel.net-ghams
      headers:
        Host: oths.wikimi88549712.workers.dev
    udp: true
  - name: opentunnel.net-ghams 2
    server: oths.wikimi88549712.workers.dev
    port: 80
    type: vmess
    uuid: a40d34c6-b77c-4648-9210-3e8d2f4226b5
    alterId: 16
    cipher: auto
    tls: false
    skip-cert-verify: true
    servername: oths.wikimi88549712.workers.dev
    network: ws
    ws-opts:
      path: /usv-3.openv2ray.com/opentunnel?user=opentunnel.net-ghams
      headers:
        Host: oths.wikimi88549712.workers.dev
    udp: true
  - name: United States (US) » GTHost » @Geek_Spot
    server: 69.50.95.174
    port: 5004
    type: ss
    cipher: aes-256-gcm
    password: g5MeD6Ft3CWlJId
    udp: true
  - name: United States (US) » TChosting LLC » @Geek_Spot
    server: 23.157.40.101
    port: 7307
    type: ss
    cipher: aes-256-gcm
    password: FoOiGlkAA9yPEGP
    udp: true
  - name: VMESS-samm-ws-clone 2
    server: oths.wikimi88549712.workers.dev
    port: 443
    type: vmess
    uuid: 53444fa5-6e0d-4fef-bd92-83b48e9d605a
    alterId: 0
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: oths.wikimi88549712.workers.dev
    network: ws
    ws-opts:
      path: /ca1.v4vmess.xyz/vmess-ws
      headers:
        Host: oths.wikimi88549712.workers.dev
    udp: true
  - name: vmess-ws-tls 3
    server: oths.wikimi88549712.workers.dev
    port: 443
    type: vmess
    uuid: fa0c39fe-1c37-491b-afc8-d8538057b990
    alterId: 0
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: oths.wikimi88549712.workers.dev
    network: ws
    ws-opts:
      path: /nl2-full.privateip.net/RACEVPN
      headers:
        Host: oths.wikimi88549712.workers.dev
    udp: true
  - name: VMESS-sarm-ws 3
    server: oths.wikimi88549712.workers.dev
    port: 80
    type: vmess
    uuid: f3510a70-85b5-425b-8fa2-22fc24142dab
    alterId: 0
    cipher: auto
    tls: false
    skip-cert-verify: true
    servername: oths.wikimi88549712.workers.dev
    network: ws
    ws-opts:
      path: /de1.v4vmess.xyz/vmess-ws
      headers:
        Host: oths.wikimi88549712.workers.dev
    udp: true
  - name: VMESS-sarm-ws 4
    server: oths.wikimi88549712.workers.dev
    port: 443
    type: vmess
    uuid: f3510a70-85b5-425b-8fa2-22fc24142dab
    alterId: 0
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: oths.wikimi88549712.workers.dev
    network: ws
    ws-opts:
      path: /de1.v4vmess.xyz/vmess-ws
      headers:
        Host: oths.wikimi88549712.workers.dev
    udp: true
  - name: vmess-ws-tls 4
    server: oths.wikimi88549712.workers.dev
    port: 443
    type: vmess
    uuid: 497abd91-ef68-43a9-9db3-a84395569585
    alterId: 0
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: oths.wikimi88549712.workers.dev
    network: ws
    ws-opts:
      path: /de-freevmess.privateip.net/FREEVMESS
      headers:
        Host: oths.wikimi88549712.workers.dev
    udp: true
  - name: vpnhack-vpnhack-ws 2
    server: oths.wikimi88549712.workers.dev
    port: 443
    type: vmess
    uuid: ebfdc1c9-47fe-4eb8-bec7-73ffe7956851
    alterId: 0
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: oths.wikimi88549712.workers.dev
    network: ws
    ws-opts:
      path: /de1.vmessvh.site/vmess
      headers:
        Host: oths.wikimi88549712.workers.dev
    udp: true
  - name: greenssh-gamw 3
    server: oths.wikimi88549712.workers.dev
    port: 443
    type: vmess
    uuid: 21485545-bc1a-4f6a-9f60-c0a38231182e
    alterId: 0
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: oths.wikimi88549712.workers.dev
    network: ws
    ws-opts:
      path: /de1-vmess.greenssh.org/vmess
      headers:
        Host: oths.wikimi88549712.workers.dev
    udp: true
  - name: greenssh-gamw 4
    server: oths.wikimi88549712.workers.dev
    port: 80
    type: vmess
    uuid: 21485545-bc1a-4f6a-9f60-c0a38231182e
    alterId: 0
    cipher: auto
    tls: false
    skip-cert-verify: true
    servername: de1-vmess.greenssh.org
    network: ws
    ws-opts:
      path: /de1-vmess.greenssh.org/vmess
      headers:
        Host: oths.wikimi88549712.workers.dev
    udp: true
  - name: freevpn.us-gham (v2-de-1.v2s.top)
    server: v2-de-1.v2s.top
    port: 443
    type: vmess
    uuid: 7772bb24-976a-45ca-aa76-f4f1b7f50923
    alterId: 16
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: creativecommons.org
    network: ws
    ws-opts:
      path: /anything/freevpn.us-gham/vmess
      headers:
        Host: v2-de-1.v2s.top
    udp: true
  - name: freevpn.us-gham (v2-de-1.v2s.top)-clone 2
    server: oths.wikimi88549712.workers.dev
    port: 443
    type: vmess
    uuid: 7772bb24-976a-45ca-aa76-f4f1b7f50923
    alterId: 16
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: oths.wikimi88549712.workers.dev
    network: ws
    ws-opts:
      path: /v2-de-1.v2s.top/anything/freevpn.us-gham/vmess
      headers:
        Host: oths.wikimi88549712.workers.dev
    udp: true
  - name: freevpn.us-gham (v2-de-1.v2s.top) 2
    server: v2-de-1.v2s.top
    port: 443
    type: vless
    uuid: 7772bb24-976a-45ca-aa76-f4f1b7f50923
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: creativecommons.org
    network: ws
    ws-opts:
      path: /anything/freevpn.us-gham/vless
      headers:
        Host: v2-de-1.v2s.top
    udp: true
  - name: freevpn.us-gham (v2-de-1.v2s.top) 3
    server: v2-de-1.v2s.top
    port: 443
    type: trojan
    password: 7772bb24-976a-45ca-aa76-f4f1b7f50923
    skip-cert-verify: true
    sni: creativecommons.org
    network: ws
    ws-opts:
      path: /anything/freevpn.us-gham/trojan
      headers:
        Host: v2-de-1.v2s.top
    udp: true
  - name: 443 Vmess USA LA 2024-12-10
    server: us-21.hihu.net
    port: 443
    type: vmess
    uuid: 481c42c0-b0e8-11ef-b330-205c6d5f5d78
    alterId: 0
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: ""
    network: ws
    ws-opts:
      path: /mgrbq1ps
      headers:
        Host: ""
    udp: true
  - name: Vmess USA LA 2024-12-10
    server: us-21.hihu.net
    port: 80
    type: vmess
    uuid: 481c42c0-b0e8-11ef-b330-205c6d5f5d78
    alterId: 0
    cipher: auto
    tls: false
    skip-cert-verify: true
    servername: ""
    network: ws
    ws-opts:
      path: /mgrbq1ps
      headers:
        Host: ""
    udp: true
  - name: Vmess USA LA 2024-12-10-clone 2
    server: oths.wikimi88549712.workers.dev
    port: 80
    type: vmess
    uuid: 481c42c0-b0e8-11ef-b330-205c6d5f5d78
    alterId: 0
    cipher: auto
    tls: false
    skip-cert-verify: true
    servername: us-21.hihu.net
    network: ws
    ws-opts:
      path: /mgrbq1ps
      headers:
        Host: us-21.hihu.net
    udp: true
  - name: opentunnel.net-ghams 3
    server: oths.wikimi88549712.workers.dev
    port: 443
    type: vmess
    uuid: a40d34c6-b77c-4648-9210-3e8d2f4226b5
    alterId: 16
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: oths.wikimi88549712.workers.dev
    network: ws
    ws-opts:
      path: /usv-3.openv2ray.com/opentunnel?user=opentunnel.net-ghams
      headers:
        Host: oths.wikimi88549712.workers.dev
    udp: true
  - name: opentunnel.net-ghams 4
    server: oths.wikimi88549712.workers.dev
    port: 80
    type: vmess
    uuid: a40d34c6-b77c-4648-9210-3e8d2f4226b5
    alterId: 16
    cipher: auto
    tls: false
    skip-cert-verify: true
    servername: oths.wikimi88549712.workers.dev
    network: ws
    ws-opts:
      path: /usv-3.openv2ray.com/opentunnel?user=opentunnel.net-ghams
      headers:
        Host: oths.wikimi88549712.workers.dev
    udp: true
proxy-groups:
  - type: 'url-test'
    name: 'Best Ping'
    interval: 60
    timeout: 2000
    max-failed-times: 101
    lazy: true
    proxies:
      - 'Vmess USA LA 2024-12-10-clone 2'
      - 'Vmess USA LA 2024-12-10'
      - '443 Vmess USA LA 2024-12-10'
      - 'freevpn.us-gham (v2-de-1.v2s.top) 3'
      - 'freevpn.us-gham (v2-de-1.v2s.top) 2'
      - 'greenssh-gamw 4'
      - 'greenssh-gamw 3'
      - 'vpnhack-vpnhack-ws 2'
      - 'vmess-ws-tls 4'
      - 'VMESS-sarm-ws 4'
      - 'VMESS-sarm-ws 3'
      - 'vmess-ws-tls 3'
      - 'VMESS-samm-ws-clone 2'
      - 'United States (US) » TChosting LLC » @Geek_Spot'
      - 'United States (US) » GTHost » @Geek_Spot'
      - 'opentunnel.net-ghams 2'
      - 'Vmess USA LA 2024-12-10-clone'
      - 'greenssh-gamw 2'
      - 'greenssh-gamw'
      - 'VMESS-samm-ws-clone'
      - 'vmess-ws-tls 2'
      - 'vpnhack-vpnhack-ws'
      - 'VMESS-sarm-ws 2'
      - 'vmess-ws-tls'
      - 'VMESS-sarm-ws'
      - '4 - VLESS - IPv4 : 443'
      - '3 - VLESS - IPv4 : 443'
      - '2 - VLESS - Domain : 443'
      - '1 - VLESS - Domain : 443'
rules:
  - 'GEOIP,ir,DIRECT'
  - 'MATCH,Best Ping'
