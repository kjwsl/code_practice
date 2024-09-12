import os
from random import class

class Sensor3D:
    def __init__(self, sensor_name: str):
        self.sensor_name = sensor_name
        self.x = 0.0
        self.y = 0.0
        self.z = 0.0

    def set_to_random(self):
        

def main():
    OUT_DIR = r"/tmp/"

    os.mkfifo()
