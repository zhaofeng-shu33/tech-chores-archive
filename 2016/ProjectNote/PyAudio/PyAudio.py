import wave
f=wave.open("H:/PythonDemo/mix.wav","rb")
par=f.getparams()
data=f.readframes(par[3])
f.close()
import numpy as np
a=np.fromstring(data,dtype=np.short);
