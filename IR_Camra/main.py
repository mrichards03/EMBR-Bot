import cv2 as cv
import numpy as np
from pylepton import Lepton
from flask import Flask, Response

app = Flask(__name__)

def generate_frames():
    while True:
        a,_ = Lepton.capture()

        cv.normalize(a, a, 0, 65535, cv.NORM_MINMAX) # extend contrast
        np.right_shift(a, 8, a) # fit data into 8 bits

        ret, frame = cv.imencode('.jpg', np.uint8(a))
        yield (b'--frame\r\n' b'Content-Type: image/jpeg\r\n\r\n' + frame.tobytes() + b'\r\n')

@app.route('/')
def index():
    return Response(generate_frames(), mimetype='multipart/x-mixed-replace; boundary=frame')

if __name__ == '__main__':
    app.run(debug=True)
