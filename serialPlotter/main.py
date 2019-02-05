import serial
from plots import TimePlot
from matplotlib import pyplot as plt

if __name__ == '__main__':

    fig, axes = plt.subplots(2, 2)
    
    for i, ax in enumerate(axes.flatten()):
        ax.set(title='Channel ' + str(i), xlabel='Time', ylabel='ADC value')
    fig.tight_layout()
    
    plots = [ TimePlot(ax) for ax in axes.flatten() ]

    ser = serial.Serial(port='/dev/ttyUSB0', baudrate=115200)

    t=0
    while ser.is_open:
        channels = str(ser.readline(), 'ascii').replace("\r\n","").split(',')
        
        for i, ch in enumerate(channels):
            plots[i].add(t, int(ch))

        t = t + 1

        plt.pause(0.01)
    
    plt.show()
        
        