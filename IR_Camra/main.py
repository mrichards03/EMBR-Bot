import cv2
import numpy as np
from flask import Flask, Response

app = Flask(__name__)

def generate_frames():
    cameraID = 0
    vc = cv2.VideoCapture(cameraID)

    if vc.isOpened(): # try to get the first frame
        rval, frame = vc.read()
    else:
        rval = False

    while rval:
        frame_v = cv2.cvtColor(frame, cv2.COLOR_RGB2HSV)[:,:,2]

        blurredBrightness = cv2.bilateralFilter(frame_v,9,150,150)
        thresh = 50
        edges = cv2.Canny(blurredBrightness,thresh,thresh*2, L2gradient=True)

        _,mask = cv2.threshold(blurredBrightness,200,1,cv2.THRESH_BINARY)
        erodeSize = 5
        dilateSize = 7
        eroded = cv2.erode(mask, np.ones((erodeSize, erodeSize)))
        mask = cv2.dilate(eroded, np.ones((dilateSize, dilateSize)))

        # Convert mask and edges to RGB before merging
        mask_rgb = cv2.cvtColor(mask, cv2.COLOR_GRAY2RGB)
        edges_rgb = cv2.cvtColor(edges, cv2.COLOR_GRAY2RGB)

        # Merge mask and edges with original frame
        result_frame = cv2.resize(mask_rgb | edges_rgb | frame, (640, 480), interpolation=cv2.INTER_CUBIC)

        # Convert frame to bytes
        ret, buffer = cv2.imencode('.jpg', result_frame)
        frame_bytes = buffer.tobytes()

        yield (b'--frame\r\n'
               b'Content-Type: image/jpeg\r\n\r\n' + frame_bytes + b'\r\n')

        rval, frame = vc.read()

@app.route('/')
def index():
    return "Video Stream"

@app.route('/video_feed')
def video_feed():
    return Response(generate_frames(), mimetype='multipart/x-mixed-replace; boundary=frame')

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=5000, debug=True)
