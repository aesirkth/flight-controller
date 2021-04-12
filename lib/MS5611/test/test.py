"""
Script to convert the pressure and temperature from D1 and D2 values

This script uses floating point operations to avoid integer rounding inaccuracies
The outputs of this script is used in test/test_main.cpp to verify the library methods
"""


# Examples values for the calibration register
# Taken from datasheet
C1 = 40127
C2 = 36924
C3 = 23317
C4 = 23282
C5 = 33464
C6 = 28312

# List of values for D1 and D2
D1D2 = ((9085466, 8569150),  # From datasheet
        (8734466, 6869150),
        (3971650, 8995673),
        (4675350, 7518340),
        (6027840, 8190420),
        (9764720, 9390420),
        )


def convert(D1, D2):
    dT = D2 - (C5 * 256)
    TEMP = 2000 + ((dT*C6) / 8388608)

    OFF = (C2 * 65536) + ((C4*dT) / 128)
    SENS = (C1 * 32768) + ((C3*dT) / 256)

    T2 = 0
    OFF2 = 0
    SENS2 = 0

    if TEMP < 2000:
        T2 = (dT**2) / 2147483648
        OFF2 = (5*(TEMP-2000)**2) / 2
        SENS2 = OFF2 / 2

        if TEMP < -1500:
            OFF2 += 7*(TEMP+1500)**2
            SENS2 += 11*(TEMP+1500)**2 / 2

    TEMP -= T2
    OFF -= OFF2
    SENS -= SENS2

    P = ((D1*SENS) / 2097152)
    P = (P - OFF) / 32768

    return TEMP, P


for i, (D1, D2) in enumerate(D1D2):
    print("{} D1:   {:<9d}\tD2:   {:<9d}".format(i, D1, D2))
    t, p = convert(D1, D2)
    print("  Pres: {:<9.2f}\tTemp: {:<9.2f} ".format(p, t))
