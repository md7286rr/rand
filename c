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
    server: opo.wiki-me.workers.dev
    port: 443
    type: vless
    uuid: 5c4d3589-e787-46fa-8279-73c5480579e7
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: OPo.WikI-me.WorkeRS.Dev
    network: ws
    ws-opts:
      path: /6CKYAOt63liTlvZS?ed=2560
      headers:
        Host: opo.wiki-me.workers.dev
    udp: true
  - name: "3 - VLESS - IPv4 : 443"
    server: 104.21.35.39
    port: 443
    type: vless
    uuid: 5c4d3589-e787-46fa-8279-73c5480579e7
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: opo.wIki-Me.WOrkeRS.dEv
    network: ws
    ws-opts:
      path: /weJCTljhxW1hu57f?ed=2560
      headers:
        Host: opo.wiki-me.workers.dev
    udp: true
  - name: "4 - VLESS - IPv4 : 443"
    server: 172.67.213.44
    port: 443
    type: vless
    uuid: 5c4d3589-e787-46fa-8279-73c5480579e7
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: Opo.wIkI-ME.wORkErs.DEV
    network: ws
    ws-opts:
      path: /uhMvBdVzdo3let8C?ed=2560
      headers:
        Host: opo.wiki-me.workers.dev
    udp: true
  - name: "2 - Trojan - Domain : 443"
    server: www.speedtest.net
    port: 443
    type: trojan
    password: pass1234
    skip-cert-verify: true
    sni: oPO.WIKi-me.WorkERs.DEv
    network: ws
    ws-opts:
      path: /trhPjmWdXc0mUmgm2H?ed=2560
      headers:
        Host: opo.wiki-me.workers.dev
    udp: true
  - name: "4 - Trojan - IPv4 : 443"
    server: 172.67.213.44
    port: 443
    type: trojan
    password: pass1234
    skip-cert-verify: true
    sni: Opo.wIkI-ME.wORkErs.DEV
    network: ws
    ws-opts:
      path: /truhMvBdVzdo3let8C?ed=2560
      headers:
        Host: opo.wiki-me.workers.dev
    udp: true
  - name: 12-Trojan-worker-fvw.wiki-me.woRKerS.deV
    server: fvw.wiki-me.workers.dev
    port: 2087
    type: trojan
    password: 106d581c-f829-59c6-a434-f1f985bc81ab
    skip-cert-verify: true
    sni: fvw.wiki-me.workers.dev
    network: ws
    ws-opts:
      path: trojan-ws/?ed=2048
      headers:
        Host: fvw.wiki-me.workers.dev
    udp: true
  - name: 12-Trojan-worker-fvw.wiki-me.woRKerS.deV 2
    server: fvw.wiki-me.workers.dev
    port: 443
    type: trojan
    password: 106d581c-f829-59c6-a434-f1f985bc81ab
    skip-cert-verify: true
    sni: fvw.wiki-me.workers.dev
    network: ws
    ws-opts:
      path: trojan-ws/?ed=2048
      headers:
        Host: fvw.wiki-me.workers.dev
    udp: true
  - name: 2-vless-worker-fvw.wiki-me.WorkErs.DEV
    server: fvw.wiki-me.workers.dev
    port: 2083
    type: vless
    uuid: 106d581c-f829-59c6-a434-f1f985bc81ab
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: fvw.wiki-me.WorkErs.DEV
    network: ws
    ws-opts:
      path: vless-ws/?ed=2048
      headers:
        Host: fvw.wiki-me.WorkErs.DEV
    udp: true
  - name: 12-vless-worker-fvw.wiki-me.woRKerS.deV
    server: fvw.wiki-me.workers.dev
    port: 443
    type: vless
    uuid: 106d581c-f829-59c6-a434-f1f985bc81ab
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: fvw.wiki-me.woRKerS.deV
    network: ws
    ws-opts:
      path: vless-ws/?ed=2048
      headers:
        Host: fvw.wiki-me.woRKerS.deV
    udp: true
  - name: 16-vless-worker-fvw.wiki-me.workERS.dev
    server: fvw.wiki-me.workers.dev
    port: 2096
    type: vless
    uuid: 106d581c-f829-59c6-a434-f1f985bc81ab
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: fvw.wiki-me.workERS.dev
    network: ws
    ws-opts:
      path: vless-ws/?ed=2048
      headers:
        Host: fvw.wiki-me.workERS.dev
    udp: true
  - name: "5 - Trojan - Clean IP : 443 2"
    server: zula.ir
    port: 443
    type: trojan
    password: pass1234
    skip-cert-verify: true
    sni: sky.ligiwex377.workers.dev
    network: ws
    ws-opts:
      path: /tr3ro9kOc0rHTm1c8J?ed=2560
      headers:
        Host: sky.ligiwex377.workers.dev
    udp: true
  - name: "2 - VLESS - Domain : 443 2"
    server: www.speedtest.net
    port: 443
    type: vless
    uuid: 1cb37b5d-776b-4a73-8de1-d91bbc3c409d
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: c2B8A7DD-SKY.LIGIWEX377.wOrkERs.dEv
    network: ws
    ws-opts:
      path: /d72eahbngKl401xX?ed=2560
      headers:
        Host: c2b8a7dd-sky.ligiwex377.workers.dev
    udp: true
  - name: "1 - VLESS - Domain : 443 2"
    server: c2b8a7dd-sky.ligiwex377.workers.dev
    port: 443
    type: vless
    uuid: 1cb37b5d-776b-4a73-8de1-d91bbc3c409d
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: C2b8A7dd-SKy.LiGiWEX377.WOrKers.deV
    network: ws
    ws-opts:
      path: /hyy0fyR1ho0MYS1C?ed=2560
      headers:
        Host: c2b8a7dd-sky.ligiwex377.workers.dev
    udp: true
  - name: "5 - VLESS - Clean IP : 443 2"
    server: zula.ir
    port: 443
    type: vless
    uuid: 1cb37b5d-776b-4a73-8de1-d91bbc3c409d
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: c2b8A7dD-SKy.LiGiwEX377.woRkERs.DeV
    network: ws
    ws-opts:
      path: /RaGyIUNa4jStKBL0?ed=2560
      headers:
        Host: c2b8a7dd-sky.ligiwex377.workers.dev
    udp: true
  - name: CF随机节点
    server: 104.24.155.215
    port: 443
    type: vless
    uuid: 6cd1732a-14c6-41cc-82a6-2b5d721d29e3
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: white-mode.ligiwex377.workers.dev
    network: ws
    ws-opts:
      path: /?ed=2560
      headers:
        Host: white-mode.ligiwex377.workers.dev
    udp: true
  - name: CF随机节点 2
    server: 172.64.92.167
    port: 443
    type: vless
    uuid: 6cd1732a-14c6-41cc-82a6-2b5d721d29e3
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: white-mode.ligiwex377.workers.dev
    network: ws
    ws-opts:
      path: /?ed=2560
      headers:
        Host: white-mode.ligiwex377.workers.dev
    udp: true
  - name: CFnat
    server: zula.ir
    port: 443
    type: vless
    uuid: 6cd1732a-14c6-41cc-82a6-2b5d721d29e3
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: white-mode.ligiwex377.workers.dev
    network: ws
    ws-opts:
      path: /?ed=2560
      headers:
        Host: white-mode.ligiwex377.workers.dev
    udp: true
  - name: CF随机节点 3
    server: 104.16.110.140
    port: 443
    type: vless
    uuid: 6cd1732a-14c6-41cc-82a6-2b5d721d29e3
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: white-mode.ligiwex377.workers.dev
    network: ws
    ws-opts:
      path: /?ed=2560
      headers:
        Host: white-mode.ligiwex377.workers.dev
    udp: true
  - name: edgetunnel
    server: visa.cn
    port: 443
    type: vless
    uuid: 6cd1732a-14c6-41cc-82a6-2b5d721d29e3
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: white-mode.ligiwex377.workers.dev
    network: ws
    ws-opts:
      path: /?ed=2560
      headers:
        Host: white-mode.ligiwex377.workers.dev
    udp: true
  - name: "3 - brojan - IPv4 : 443"
    server: 172.67.170.19
    port: 443
    type: trojan
    password: pass1234
    skip-cert-verify: true
    sni: pLAin.YaMEcak466.WORkeRs.DEV
    network: ws
    ws-opts:
      path: /trsBD3jKHoYFt6UhiX?ed=2560
      headers:
        Host: plain.yamecak466.workers.dev
    udp: true
  - name: "4 - brojan - IPv4 : 443"
    server: 104.21.39.80
    port: 443
    type: trojan
    password: pass1234
    skip-cert-verify: true
    sni: PLAiN.yAMEcaK466.WORKeRS.deV
    network: ws
    ws-opts:
      path: /trpGavFPPft8QBmZ1x?ed=2560
      headers:
        Host: plain.yamecak466.workers.dev
    udp: true
  - name: "3 - bless - IPv4 : 443"
    server: 172.67.170.19
    port: 443
    type: vless
    uuid: 62442194-d709-4891-a5c4-082f794fe6ce
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: pLAin.YaMEcak466.WORkeRs.DEV
    network: ws
    ws-opts:
      path: /sBD3jKHoYFt6UhiX?ed=2560
      headers:
        Host: plain.yamecak466.workers.dev
    udp: true
  - name: "4 - bless - IPv4 : 443"
    server: 104.21.39.80
    port: 443
    type: vless
    uuid: 62442194-d709-4891-a5c4-082f794fe6ce
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: PLAiN.yAMEcaK466.WORKeRS.deV
    network: ws
    ws-opts:
      path: /pGavFPPft8QBmZ1x?ed=2560
      headers:
        Host: plain.yamecak466.workers.dev
    udp: true
  - name: royal-royal.yamecak466.workers.dev-HTTPS-8443
    server: royal.yamecak466.workers.dev
    port: 8443
    type: vless
    uuid: 7c9151f9-9a31-49de-807d-bee51495514c
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: royal.yamecak466.workers.dev
    network: ws
    ws-opts:
      path: /?ed=2048
      headers:
        Host: royal.yamecak466.workers.dev
    udp: true
  - name: royal-japan.com-HTTPS-8443
    server: japan.com
    port: 8443
    type: vless
    uuid: 7c9151f9-9a31-49de-807d-bee51495514c
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: royal.yamecak466.workers.dev
    network: ws
    ws-opts:
      path: /?ed=2048
      headers:
        Host: royal.yamecak466.workers.dev
    udp: true
  - name: royal-royal.yamecak466.workers.dev-HTTPS-443
    server: royal.yamecak466.workers.dev
    port: 443
    type: vless
    uuid: 7c9151f9-9a31-49de-807d-bee51495514c
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: royal.yamecak466.workers.dev
    network: ws
    ws-opts:
      path: /?ed=2048
      headers:
        Host: royal.yamecak466.workers.dev
    udp: true
  - name: royal-royal.yamecak466.workers.dev-HTTPS-2096
    server: royal.yamecak466.workers.dev
    port: 2096
    type: vless
    uuid: 7c9151f9-9a31-49de-807d-bee51495514c
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: royal.yamecak466.workers.dev
    network: ws
    ws-opts:
      path: /?ed=2048
      headers:
        Host: royal.yamecak466.workers.dev
    udp: true
  - name: royal-royal.yamecak466.workers.dev-HTTPS-2053
    server: royal.yamecak466.workers.dev
    port: 2053
    type: vless
    uuid: 7c9151f9-9a31-49de-807d-bee51495514c
    cipher: auto
    tls: true
    skip-cert-verify: true
    servername: royal.yamecak466.workers.dev
    network: ws
    ws-opts:
      path: /?ed=2048
      headers:
        Host: royal.yamecak466.workers.dev
    udp: true
  - name: peasoftspeednode0022
    server: 103.106.2.243
    port: 2198
    type: vless
    uuid: 838f5273-5d2d-4630-a0f5-9cc8e4aef4d6
    cipher: auto
    tls: false
    skip-cert-verify: true
    servername: undefined
    udp: true
  - name: peasoftspeednode0023
    server: 188.119.112.3
    port: 2198
    type: vless
    uuid: 838f5273-5d2d-4630-a0f5-9cc8e4aef4d6
    cipher: auto
    tls: false
    skip-cert-verify: true
    servername: undefined
    udp: true
  - name: peasoftspeednode0027
    server: 185.236.233.55
    port: 2198
    type: vless
    uuid: 838f5273-5d2d-4630-a0f5-9cc8e4aef4d6
    cipher: auto
    tls: false
    skip-cert-verify: true
    servername: undefined
    udp: true
  - name: peasoftspeednode0024
    server: 80.92.206.33
    port: 2198
    type: vless
    uuid: 838f5273-5d2d-4630-a0f5-9cc8e4aef4d6
    cipher: auto
    tls: false
    skip-cert-verify: true
    servername: undefined
    udp: true
  - name: 🇺🇸 United States (US) 01
    server: 69.50.95.174
    port: 5004
    type: ss
    cipher: aes-256-gcm
    password: g5MeD6Ft3CWlJId
    udp: true
  - name: 🇺🇸 United States (US) 02
    server: 23.157.40.101
    port: 7307
    type: ss
    cipher: aes-256-gcm
    password: FoOiGlkAA9yPEGP
    udp: true
  - name: 🇺🇸 United States (US) 03
    server: 23.134.94.168
    port: 3389
    type: ss
    cipher: aes-256-gcm
    password: Y6R9pAtvxxzmGC
    udp: true
  - name: 🇺🇸 United States (US) 04
    server: 23.157.40.101
    port: 8008
    type: ss
    cipher: aes-256-gcm
    password: XKFKl2rULjIp74
    udp: true
  - name: CFEpeius
    server: 190.93.246.85
    port: 443
    type: trojan
    password: pass1234
    skip-cert-verify: true
    sni: silent.md1234rr.workers.dev
    network: ws
    ws-opts:
      path: /?ed=2560
      headers:
        Host: silent.md1234rr.workers.dev
    udp: true
  - name: CFEpeius 2
    server: 188.114.99.248
    port: 443
    type: trojan
    password: pass1234
    skip-cert-verify: true
    sni: silent.md1234rr.workers.dev
    network: ws
    ws-opts:
      path: /?ed=2560
      headers:
        Host: silent.md1234rr.workers.dev
    udp: true
  - name: epeius
    server: silent.md1234rr.workers.dev
    port: 443
    type: trojan
    password: pass1234
    skip-cert-verify: true
    sni: silent.md1234rr.workers.dev
    network: ws
    ws-opts:
      path: /?ed=2560
      headers:
        Host: silent.md1234rr.workers.dev
    udp: true
proxy-groups:
  - type: url-test
    name: "01"
    url: https://gstatic.com/generate_204
    interval: "120"
    lazy: true
    proxies:
      - "1 - VLESS - Domain : 443"
      - "3 - VLESS - IPv4 : 443"
      - "4 - VLESS - IPv4 : 443"
      - "2 - Trojan - Domain : 443"
      - "4 - Trojan - IPv4 : 443"
      - 12-Trojan-worker-fvw.wiki-me.woRKerS.deV
      - 12-Trojan-worker-fvw.wiki-me.woRKerS.deV 2
      - 2-vless-worker-fvw.wiki-me.WorkErs.DEV
      - 12-vless-worker-fvw.wiki-me.woRKerS.deV
      - 16-vless-worker-fvw.wiki-me.workERS.dev
  - type: url-test
    name: "02"
    url: https://gstatic.com/generate_204
    interval: "120"
    lazy: true
    proxies:
      - "5 - Trojan - Clean IP : 443 2"
      - "2 - VLESS - Domain : 443 2"
      - "1 - VLESS - Domain : 443 2"
      - "5 - VLESS - Clean IP : 443 2"
      - CF随机节点
      - CF随机节点 2
      - CFnat
      - CF随机节点 3
      - edgetunnel
  - type: url-test
    name: "03"
    url: https://gstatic.com/generate_204
    interval: "120"
    lazy: true
    proxies:
      - "3 - brojan - IPv4 : 443"
      - "4 - brojan - IPv4 : 443"
      - "3 - bless - IPv4 : 443"
      - "4 - bless - IPv4 : 443"
      - royal-royal.yamecak466.workers.dev-HTTPS-8443
      - royal-japan.com-HTTPS-8443
      - royal-royal.yamecak466.workers.dev-HTTPS-443
      - royal-royal.yamecak466.workers.dev-HTTPS-2096
      - royal-royal.yamecak466.workers.dev-HTTPS-2053
  - type: url-test
    name: "04"
    url: https://gstatic.com/generate_204
    interval: "120"
    lazy: true
    proxies:
      - CFEpeius
      - CFEpeius 2
      - epeius
  - type: select
    name: "05"
    lazy: true
    proxies:
      - 🇺🇸 United States (US) 01
      - 🇺🇸 United States (US) 02
      - 🇺🇸 United States (US) 03
      - 🇺🇸 United States (US) 04
  - type: url-test
    name: Ultra
    url: https://gstatic.com/generate_204
    interval: "60"
    proxies:
      - "01"
      - "02"
      - "03"
      - "04"
rules:
  - GEOIP,ir,DIRECT
  - DOMAIN,cdromance.org,DIRECT
  - DOMAIN,steamdb.info,DIRECT
  - MATCH,Ultra
