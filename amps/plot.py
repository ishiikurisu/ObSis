import sys
import matplotlib.pyplot as plt
import numpy as np
import struct

def read_float(fp):
    return struct.unpack('f', fp.read(4))[0]

if __name__ == '__main__':
    fileinput = sys.argv[1]
    fileoutput = fileinput.split('.')[0] + '.png'
    outlet = []

    with open(fileinput, 'rb') as fp:
        ntr = read_float(fp)
        ns = read_float(fp)
        for _ in range(int(ntr)):
            trace = []
            for _ in range(int(ns)):
                trace.append(read_float(fp))
            outlet.append(trace)

    x = np.linspace(0, 1, ns)
    y = np.linspace(0, 1, ntr)
    X, Y = np.meshgrid(x, y)
    Z = outlet
    plt.contour(X, Y, Z)
    plt.savefig(fileoutput, dpi=200)
    plt.clf()
