"""Nomad Class Handler for Interaction with NomadBLDC Board"""

#  DataContainers.py
#
#  Created on: March 28, 2020
#      Author: Quincy Jones
# 
#  Copyright (c) <2020> <Quincy Jones - quincy@implementedrobotics.com/>
#  Permission is hereby granted, free of charge, to any person obtaining a
#  copy of this software and associated documentation files (the "Software"),
#  to deal in the Software without restriction, including without limitation
#  the rights to use, copy, modify, merge, publish, distribute, sublicense,
#  and/or sell copies of the Software, and to permit persons to whom the Software
#  is furnished to do so, subject to the following conditions:
#  The above copyright notice and this permission notice shall be included in all
#  copies or substantial portions of the Software.
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
#  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
#  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


import struct
from dataclasses import dataclass
from typing import List

@dataclass
class LogPacket:
    log_length: int = None
    log_string: str = None

    @classmethod
    def unpack(cls, data):
        return struct.unpack(f"<{data[0]}s", data[1:])[0].decode("utf-8")

@dataclass
class DeviceStats:
    __fmt = "<BBIffff"
    fault: int = None
    control_status: int = None
    uptime: int = None
    voltage_bus: float = None
    driver_temp: float = None
    fet_temp: float = None
    motor_temp: float = None

    @classmethod
    def unpack(cls, data):
        unpacked = struct.unpack(cls.__fmt, data)
        return DeviceStats(*unpacked)

@dataclass
class DeviceInfo:
    fw_major: int = None
    fw_minor: int = None
    device_id: 'typing.Any' = None

@dataclass
class MotorConfig:
    __fmt = "<I8fiffi"
    num_pole_pairs: int = None
    phase_resistance: float = None
    phase_inductance_d: float = None
    phase_inductance_q: float = None
    K_v: float = None
    flux_linkage: float = None
    K_t: float = None
    K_t_out: float = None
    gear_ratio: float = None
    phase_order: int = None
    calib_current: float = None
    calib_voltage: float = None
    calibrated: int = None

    @classmethod
    def unpack(cls, data):
        unpacked = struct.unpack(cls.__fmt, data)
        return MotorConfig(*unpacked)


@dataclass
class ControllerConfig:
    __fmt = "<16fI"
    k_d: float = None
    k_q: float = None
    k_i_d: float = None
    k_i_q: float = None
    alpha: float = None
    overmodulation: float = None
    velocity_limit: float = None
    position_limit: float = None
    torque_limit: float = None
    current_limit: float = None
    current_bandwidth: float = None
    K_p_min: float = None
    K_p_max: float = None
    K_d_min: float = None
    K_d_max: float = None
    pwm_freq: float = None
    foc_ccl_divider: int = None

    @classmethod
    def unpack(cls, data):
        unpacked = struct.unpack(cls.__fmt, data)
        return ControllerConfig(*unpacked)

@dataclass
class EncoderConfig:
    __fmt = "<ffi128b"
    offset_elec: float = None
    offset_mech: float = None
    cpr: int = None
    #direction: int = None
    offset_lut: List[int] = None

    @classmethod
    def unpack(cls, data):
        unpacked = struct.unpack(cls.__fmt, data)
        #print("ENCODER")
        #print(unpacked[0])
        #print(unpacked[1])
        #print(unpacked[2])
        #print([*unpacked[3:]])
        return EncoderConfig(unpacked[0], unpacked[1], unpacked[2], [*unpacked[3:]])

@dataclass
class FloatMeasurement:
    __fmt = "<Bf"
    status: int = None
    measurement: float = None

    @classmethod
    def unpack(cls, data):
        unpacked = struct.unpack(cls.__fmt, data)
        return FloatMeasurement(*unpacked)

@dataclass
class IntMeasurement:
    __fmt = "<BI"
    status: int = None
    measurement: int = None

    @classmethod
    def unpack(cls, data):
        unpacked = struct.unpack(cls.__fmt, data)
        return IntMeasurement(*unpacked)
