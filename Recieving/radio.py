from pymavlink import mavutil

# Setup MAVLink connection (UDP listener in this case)
# CHANGE DEPENDING ON YOUR DEVICE
connection = mavutil.mavlink_connection('COM9', 57600)

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


def decode_global_position_message():
    while True:
        # Wait for a GLOBAL_POSITION_INT message
        msg = connection.recv_match(type='GLOBAL_POSITION_INT', blocking=True)
        if msg:
            # Once received, decode it
            print("Received GLOBAL_POSITION_INT message:")
            print(f"  Timestamp: {msg.time_boot_ms} ms")
            print(f"  Latitude: {msg.lat / 1.0e7} degrees")
            print(f"  Longitude: {msg.lon / 1.0e7} degrees")
            print(f"  Altitude: {msg.alt / 1000.0} meters")
            print(f"  Relative Altitude: {msg.relative_alt / 1000.0} meters")
            print(f"  Ground X Speed: {msg.vx / 100.0} m/s")
            print(f"  Ground Y Speed: {msg.vy / 100.0} m/s")
            print(f"  Ground Z Speed: {msg.vz / 100.0} m/s")
            print(f"  Vehicle Heading: {msg.hdg / 100.0} degrees")


if __name__ == '__main__':
    decode_attitude_message()
    decode_global_position_message()
