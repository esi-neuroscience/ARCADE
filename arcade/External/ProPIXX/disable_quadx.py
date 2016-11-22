from pypixxlib._libdpx import DPxSelectDevice, DPxSetReg16, DPxUpdateRegCache
import ctypes
from pypixxlib.propixx import PROPixx
 
 
dev = PROPixx()
dev.setDlpSequencerProgram('RGB')
dev.setVesaFreeRun(False)
dev.updateRegisterCache()
DPxSelectDevice('PROPixx') # Select the PROPixx
DPxSetReg16(ctypes.c_uint(0x18C),ctypes.c_uint(1))
DPxUpdateRegCache()