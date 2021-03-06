#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/keyboardcode.o \
	${OBJECTDIR}/utilities.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../CodeBlocks/LittleLLVM/bin/Debug ../../CodeBlocks/LittleLLVM/bin/Debug/libCompilerFrameworkInCPP.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/keyboardcodelang.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/keyboardcodelang.exe: ../../CodeBlocks/LittleLLVM/bin/Debug/libCompilerFrameworkInCPP.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/keyboardcodelang.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/keyboardcodelang ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/keyboardcode.o: keyboardcode.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../CodeBlocks/LittleLLVM/include -I../../CodeBlocks/LittleLLVM -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/keyboardcode.o keyboardcode.cpp

${OBJECTDIR}/utilities.o: utilities.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../CodeBlocks/LittleLLVM/include -I../../CodeBlocks/LittleLLVM -I. -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/utilities.o utilities.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/keyboardcodelang.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
