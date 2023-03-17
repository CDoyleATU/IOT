from urllib.parse import urlencode
from urllib.request import Request, urlopen
import base64

notificationMessage = f'''
Total: €{12.35} 
€2 x{4}
€1 x{2}
€0.50 x{4}
€0.20 x{1}
€0.10 x{1}
€0.05 x{1}
'''
# # local image from drive
# file = 'logo.jpg'
# image = open(file, 'rb')
# image_read = image.read()
# image1 = base64.encodebytes(image_read)

# remote image from url
image2 = base64.b64encode(urlopen("https://www.google.de/images/branding/googlelogo/1x/googlelogo_color_272x92dp.png").read())

url = 'https://www.pushsafer.com/api'
post_fields = {
	"t" : 'Coin Counter',
	"m" : notificationMessage,
	"s" : 11,
	"v" : 3,
	"i" : 33,
	"c" : '#FF0000',
	"d" : 'a',
	"u" : 'https://www.pushsafer.com',
	"ut" : 'Open Pushsafer',
	"k" : 'aR0r0uGnTKP2p5XE1UzQ',
	# "p" : 'data:image/jpeg;base64,'+str(image1.decode('ascii')),
	"p2" : 'data:image/png;base64,'+str(image2.decode('ascii')),
	}

request = Request(url, urlencode(post_fields).encode())
json = urlopen(request).read().decode()
print(json)

