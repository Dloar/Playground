import picamera
from time import sleep
camera = picamera.PiCamera()

camera.start_preview()
sleep(5)
camera.capture('/home/pi/Documents/Pictures/imag.jpg' )
camera.stop_preview()
print('Done')
