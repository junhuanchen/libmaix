import time
from maix import camera, display, image
for i in range(10):
    hello_img = image.new(size = (240, 240), color = (0, 0, 0), mode = "RGB")
    hello_img.draw_string(30, 115, time.asctime(), scale = 1.0, color = (255, 255, 255), thickness = 1)
    display.show(hello_img)
    time.sleep(1)
