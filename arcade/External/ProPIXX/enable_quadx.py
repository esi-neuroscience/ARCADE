from pypixxlib._libdpx import DPxSelectDevice, DPxSetReg16, DPxUpdateRegCache
import ctypes
from pypixxlib.propixx import PROPixx
 
 
dev = PROPixx()
dev.setDlpSequencerProgram('QUAD4X')
dev.setVesaFreeRun(True)
dev.updateRegisterCache()
DPxSelectDevice('PROPixx') # Select the PROPixx
DPxSetReg16(ctypes.c_uint(0x18C),ctypes.c_uint(1))
DPxUpdateRegCache()