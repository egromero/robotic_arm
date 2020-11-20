from credentials import  *
import json
from ibm_watson import VisualRecognitionV3
from ibm_cloud_sdk_core.authenticators import IAMAuthenticator

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

if __name__ == '__main__':
	print(get_data('./imgs/apple.jpeg'))