import cv2
from watson_recognition import get_data
import os

cam = cv2.VideoCapture(0)

cv2.namedWindow("picture")

img_counter = 0

while True:
    ret, frame = cam.read()
    if not ret:
        print("failed to grab frame")
        break
    cv2.imshow("test", frame)

    k = cv2.waitKey(1)
    if k%256 == 27:
        # ESC pressed
        print("Escape hit, closing...")
        break
    ##condición para tomar foto.   
        img_name = "opencv_frame_{}.png".format(img_counter)
        cv2.imwrite(img_name, frame)
        print("{} written!".format(img_name))
        data_image = get_data(img_name)
        print("data: {}".format(data_image))
        ## path actual de imagen, path nuevo. 
        os.rename(img_name, './imgs/'+img_name)
        img_counter += 1

cam.release()

cv2.destroyAllWindows()