import uhd
import numpy as np

usrp = uhd.usrp.MultiUSRP()
samples = np.ones(10000) + 1j*np.ones(10000)
duration = .25
center_freq = 860e6
sample_rate = 1e6
gain = 20

for i in range(10):
	center_freq = 860e6
	while center_freq < 950e6:
		center_freq += 1e6
		usrp.send_waveform(samples,duration,center_freq,sample_rate,[0],gain)

