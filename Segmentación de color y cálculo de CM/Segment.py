import numpy as np
import cv2
import time

nCam = 1
cap = cv2.VideoCapture(nCam) 

if cap.isOpened():
	cap.open(nCam)	
	
cv2.namedWindow('frame1')
cv2.moveWindow('frame1', 30, 100)

cv2.namedWindow('frame2')
cv2.moveWindow('frame2', 700, 100)

cv2.namedWindow('frame3')
cv2.moveWindow('frame3', 365, 150)

lower_color_red = np.array([155,80,80]) #rangos donde se puede encontrar el rojo
upper_color_red = np.array([175,255,255]) 

lower_color_yellow = np.array([20, 100, 100]) #amarillo
upper_color_yellow = np.array([30, 255, 255])

lower_color_orange = np.array([4, 175, 191]) #naranjo
upper_color_orange = np.array([33, 255, 255])


lower_color_pink = np.array([0, 33, 199]) #rosado
upper_color_pink = np.array([176, 255, 255])

lower_color_green = np.array([30, 51, 127]) #verde
upper_color_green = np.array([78, 255, 255])

font = cv2.FONT_HERSHEY_SIMPLEX

while(True):
	ret, frame = cap.read()
	hsv_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV) #Cambia los espacios de colores
	
	mask0 = cv2.inRange(hsv_frame, lower_color_orange, upper_color_orange) #Crea una mascara que reconoce colores que están entre los creados anteriormente y los vuelve balnco
	mask1 = cv2.inRange(hsv_frame, lower_color_yellow, upper_color_yellow)
	mask2 = cv2.inRange(hsv_frame, lower_color_red, upper_color_red)
	mask3 = cv2.inRange(hsv_frame, lower_color_pink, upper_color_pink)
	mask4 = cv2.inRange(hsv_frame, lower_color_green, upper_color_green)
	mask_color = mask1 + mask0 + mask2 +mask3 + mask4
	hsv_frame_mask = cv2.bitwise_and(frame,frame, mask= mask0 + mask1 + mask2 + mask3 + mask4) #La máscara anterior la multiplica por los colores originales  
	
	cx0, cy0 = 0, 0
	M0 = cv2.moments(mask_color)
	if M0['m00']!=0:
		cx0 = int(M0['m10']/M0['m00'])
		cy0 = int(M0['m01']/M0['m00'])
	cv2.circle(frame, (cx0, cy0), 4, (0,0,255), -1)
	print(cx0, cy0)

	
	
	if cv2.waitKey(1) & 0xFF == 27:
		break


cap.release()
cv2.destroyAllWindows()	