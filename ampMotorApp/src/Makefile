TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS BELOW HERE

# Install ampMotorSupport.dbd into <top>/dbd
DBD += ampMotorSupport.dbd

ampMotorSupport_DBD += base.dbd
ampMotorSupport_DBD += sCalcoutRecord.dbd
ampMotorSupport_DBD += drvAsynIPPort.dbd
ampMotorSupport_DBD += stream.dbd
ampMotorSupport_DBD += streamSynApps.dbd
ampMotorSupport_DBD += ampMotorSNC.dbd

# Build an IOC support library
LIBRARY_IOC += ampMotorSupport

# Compile and add the code to the support library
ampMotorSupport_SRCS += limitSub.c

ampMotorSupport_LIBS += calc
ampMotorSupport_LIBS += stream streamSynApps
ampMotorSupport_LIBS += asyn
ampMotorSupport_LIBS += $(EPICS_BASE_IOC_LIBS)

# Build the IOC application
PROD_IOC = ampMotor

# ampMotor.dbd will be created and installed
DBD += ampMotor.dbd

# ampMotor.dbd will include these files:
ampMotor_DBD += base.dbd
ampMotor_DBD += ampMotorSupport.dbd

# ampMotor_registerRecordDeviceDriver.cpp derives from ampMotor.dbd
ampMotor_SRCS += ampMotor_registerRecordDeviceDriver.cpp

# Build the main IOC entry point where needed
ampMotor_SRCS_DEFAULT += ampMotorMain.cpp
ampMotor_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#ampMotor_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Link in the code from our support library
ampMotor_LIBS += ampMotorSupport
ampMotor_LIBS += calc
ampMotor_LIBS += stream streamSynApps
ampMotor_LIBS += asyn
ampMotor_LIBS += $(EPICS_BASE_IOC_LIBS)

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD EXTRA GNUMAKE RULES BELOW HERE

