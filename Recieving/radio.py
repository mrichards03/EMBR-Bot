from pymavlink import mavutil

# Setup MAVLink connection (UDP listener in this case)
connection = mavutil.mavlink_connection('COM18', 57600)

def decode_attitude_message():
    while True:
        # Wait for an ATTITUDE message
        msg = connection.recv_match(type='ATTITUDE', blocking=True)
        if msg:
            # Once received, decode it
            print("Received ATTITUDE message:")
            print(f"  Timestamp: {msg.time_boot_ms} ms")
            print(f"  Roll: {msg.roll} radians")
            print(f"  Pitch: {msg.pitch} radians")
            print(f"  Yaw: {msg.yaw} radians")
            print(f"  Rollspeed: {msg.rollspeed} rad/s")
            print(f"  Pitchspeed: {msg.pitchspeed} rad/s")
            print(f"  Yawspeed: {msg.yawspeed} rad/s")

if __name__ == '__main__':
    decode_attitude_message()