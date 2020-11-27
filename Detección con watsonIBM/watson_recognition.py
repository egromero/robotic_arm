from credentials import  *
import json
from ibm_watson import VisualRecognitionV3
from ibm_cloud_sdk_core.authenticators import IAMAuthenticator
import time

authenticator = IAMAuthenticator(CREDENTIALS['apikey'])
visual_recognition = VisualRecognitionV3(
    version='2018-03-19',
    authenticator=authenticator
)

visual_recognition.set_service_url(CREDENTIALS['url'])

def get_data(path):
	with open(path, 'rb') as images_file:
	    classes = visual_recognition.classify(
	        images_file=images_file).get_result()
	    return json.dumps(classes)

#if __name__ == '__main__':
while(True):
	#s = get_data('Detección con watsonIBM/imgs/mandarin.jpeg')
	s = get_data('img.png')
	#print(s)
	data = open("algo.txt", "r")
	a = int(data.readline().strip())
	data.close()
	if a>= 5000000:
		print("platano")
	elif a>=2000000:
		if "tangerine" in s or "orange" in s or "citrus" in s:
			print("naranja")
		else:
			print("manzana")
	elif a>=800000:
		print("mandarina")
	
	time.sleep(1)
	
		