from os import listdir
from abc import ABC

IIO_PATH = "/sys/bus/iio/devices/"


class Sensor(ABC):
    def __init__(self, sensor_type: str):
        self.sensor_type = sensor_type


class Sensor3D(Sensor, ABC):
    def __init__(self):
        super().__init__("3d")
        self.x = 0.0
        self.y = 0.0
        self.z = 0.0


class Accel(Sensor3D):
    def __init__(self):
        super().__init__()
        self.sensor_type = "accel"


class Gyro(Sensor3D):
    def __init__(self):
        super().__init__()
        self.sensor_type = "anglvel"


class Temp(Sensor3D):
    def __init__(self):
        super().__init__()
        self.sensor_type = "temp"


sensor_types = [
    "accel",
    "anglvel",
    "magn",
    "temp",
    "press",
    "prox",
]


def enumerate():
    iio_files = listdir(IIO_PATH)
