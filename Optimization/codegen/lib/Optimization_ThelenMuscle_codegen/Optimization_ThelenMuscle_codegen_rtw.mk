###########################################################################
## Makefile generated for component 'Optimization_ThelenMuscle_codegen'. 
## 
## Makefile     : Optimization_ThelenMuscle_codegen_rtw.mk
## Generated on : Fri Mar 07 22:06:24 2025
## Final product: ./Optimization_ThelenMuscle_codegen.lib
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file
# MODELLIB                Static library target

PRODUCT_NAME              = Optimization_ThelenMuscle_codegen
MAKEFILE                  = Optimization_ThelenMuscle_codegen_rtw.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2024b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2024b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/jakub/MATLAB~1/GACR_E~1/01_PLA~1/UPPERL~1/EQUATI~1/OPTIMA~1
TGT_FCN_LIB               = ISO_C
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
COMPILER_COMMAND_FILE     = Optimization_ThelenMuscle_codegen_rtw_comp.rsp
CMD_FILE                  = Optimization_ThelenMuscle_codegen_rtw.rsp
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
MODELLIB                  = Optimization_ThelenMuscle_codegen.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          MinGW64 | gmake (64-bit Windows)
# Supported Version(s):    8.x
# ToolchainInfo Version:   2024b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS
# MINGW_ROOT
# MINGW_C_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS            = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align -Wno-stringop-overflow
WARN_FLAGS_MAX        = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS        = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align -Wno-stringop-overflow
CPP_WARN_FLAGS_MAX    = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow
MW_EXTERNLIB_DIR      = $(MATLAB_ROOT)/extern/lib/win64/mingw64
SHELL                 = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lws2_32

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC_PATH = $(MINGW_ROOT)
CC = "$(CC_PATH)/gcc"

# Linker: GNU Linker
LD_PATH = $(MINGW_ROOT)
LD = "$(LD_PATH)/g++"

# C++ Compiler: GNU C++ Compiler
CPP_PATH = $(MINGW_ROOT)
CPP = "$(CPP_PATH)/g++"

# C++ Linker: GNU C++ Linker
CPP_LD_PATH = $(MINGW_ROOT)
CPP_LD = "$(CPP_LD_PATH)/g++"

# Archiver: GNU Archiver
AR_PATH = $(MINGW_ROOT)
AR = "$(AR_PATH)/ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = $(MINGW_ROOT)
MAKE = "$(MAKE_PATH)/mingw32-make.exe"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(MINGW_C_STANDARD_OPTS) -m64 \
                       -O3
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -m64 \
                       -O3
CPP_LDFLAGS          =  -static -m64
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,--no-undefined \
                         -Wl,--out-implib,$(basename $(PRODUCT)).lib
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              =  -static -m64
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -j $(MAX_MAKE_JOBS) -l $(MAX_MAKE_LOAD_AVG) -Oline -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,--no-undefined \
                       -Wl,--out-implib,$(basename $(PRODUCT)).lib



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./Optimization_ThelenMuscle_codegen.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__USE_MINGW_ANSI_STDIO=1
DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=Optimization_ThelenMuscle_codegen

DEFINES = $(DEFINES_) $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/Optimization_ThelenMuscle_codegen_data.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/rt_nonfinite.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/rtGetNaN.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/rtGetInf.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/Optimization_ThelenMuscle_codegen_initialize.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/Optimization_ThelenMuscle_codegen_terminate.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/Optimization_ThelenMuscle_codegen.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/fmincon.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/xnrm2.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/finDiffEvalAndChkErr.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/setProblemType.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/modifyOverheadPhaseOne_.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/test_exit.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/xgeqp3.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/xzlarfg.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/xzlarf.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/computeQ_.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/sortLambdaQP.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/step.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/driver.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/PresolveWorkingSet.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/countsort.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/removeConstr.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/RemoveDependentIneq_.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/feasibleX0ForWorkingSet.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/maxConstraintViolation.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/phaseone.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/computeGrad_StoreHx.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/computeFval_ReuseHx.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/squareQ_appendCol.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/xrotg.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/deleteColMoveEnd.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/compute_deltax.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/solve.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/compute_lambda.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/addBoundToActiveSetMatrix_.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/linearForm_.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/addAeqConstr.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/relaxed.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/BFGSUpdate.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/computeConstraints_.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/computeFiniteDifferences.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/driver1.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/updateWorkingSetForNewQP.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/evalObjAndConstr.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/computeGradLag.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/xzgeqp3.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/feasibleratiotest.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/factorQR.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/xgemv.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/factorQRE.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/xpotrf.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/xgemm.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/fullColLDL2_.c $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/Optimization_ThelenMuscle_codegen_rtwutil.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = Optimization_ThelenMuscle_codegen_data.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj Optimization_ThelenMuscle_codegen_initialize.obj Optimization_ThelenMuscle_codegen_terminate.obj Optimization_ThelenMuscle_codegen.obj fmincon.obj xnrm2.obj finDiffEvalAndChkErr.obj setProblemType.obj modifyOverheadPhaseOne_.obj test_exit.obj xgeqp3.obj xzlarfg.obj xzlarf.obj computeQ_.obj sortLambdaQP.obj step.obj driver.obj PresolveWorkingSet.obj countsort.obj removeConstr.obj RemoveDependentIneq_.obj feasibleX0ForWorkingSet.obj maxConstraintViolation.obj phaseone.obj computeGrad_StoreHx.obj computeFval_ReuseHx.obj squareQ_appendCol.obj xrotg.obj deleteColMoveEnd.obj compute_deltax.obj solve.obj compute_lambda.obj addBoundToActiveSetMatrix_.obj linearForm_.obj addAeqConstr.obj relaxed.obj BFGSUpdate.obj computeConstraints_.obj computeFiniteDifferences.obj driver1.obj updateWorkingSetForNewQP.obj evalObjAndConstr.obj computeGradLag.obj xzgeqp3.obj feasibleratiotest.obj factorQR.obj xgemv.obj factorQRE.obj xpotrf.obj xgemm.obj fullColLDL2_.obj Optimization_ThelenMuscle_codegen_rtwutil.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_TFL = -msse2 -fno-predictive-commoning
CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_TFL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_TFL = -msse2 -fno-predictive-commoning
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_TFL) $(CPPFLAGS_BASIC)

#---------------------
# MEX C++ Compiler
#---------------------

MEX_CPP_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CPPFLAGS += $(MEX_CPP_Compiler_BASIC)

#-----------------
# MEX Compiler
#-----------------

MEX_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CFLAGS += $(MEX_Compiler_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


MINGW_C_STANDARD_OPTS = $(C_STANDARD_OPTS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) @$(CMD_FILE)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : %.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cc
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cxx
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.CPP
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c++
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.C
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


Optimization_ThelenMuscle_codegen_data.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/Optimization_ThelenMuscle_codegen_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_nonfinite.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/rt_nonfinite.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetNaN.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/rtGetNaN.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetInf.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/rtGetInf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Optimization_ThelenMuscle_codegen_initialize.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/Optimization_ThelenMuscle_codegen_initialize.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Optimization_ThelenMuscle_codegen_terminate.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/Optimization_ThelenMuscle_codegen_terminate.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Optimization_ThelenMuscle_codegen.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/Optimization_ThelenMuscle_codegen.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fmincon.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/fmincon.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xnrm2.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/xnrm2.c
	$(CC) $(CFLAGS) -o "$@" "$<"


finDiffEvalAndChkErr.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/finDiffEvalAndChkErr.c
	$(CC) $(CFLAGS) -o "$@" "$<"


setProblemType.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/setProblemType.c
	$(CC) $(CFLAGS) -o "$@" "$<"


modifyOverheadPhaseOne_.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/modifyOverheadPhaseOne_.c
	$(CC) $(CFLAGS) -o "$@" "$<"


test_exit.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/test_exit.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xgeqp3.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/xgeqp3.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xzlarfg.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/xzlarfg.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xzlarf.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/xzlarf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


computeQ_.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/computeQ_.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sortLambdaQP.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/sortLambdaQP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


step.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/step.c
	$(CC) $(CFLAGS) -o "$@" "$<"


driver.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/driver.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PresolveWorkingSet.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/PresolveWorkingSet.c
	$(CC) $(CFLAGS) -o "$@" "$<"


countsort.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/countsort.c
	$(CC) $(CFLAGS) -o "$@" "$<"


removeConstr.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/removeConstr.c
	$(CC) $(CFLAGS) -o "$@" "$<"


RemoveDependentIneq_.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/RemoveDependentIneq_.c
	$(CC) $(CFLAGS) -o "$@" "$<"


feasibleX0ForWorkingSet.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/feasibleX0ForWorkingSet.c
	$(CC) $(CFLAGS) -o "$@" "$<"


maxConstraintViolation.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/maxConstraintViolation.c
	$(CC) $(CFLAGS) -o "$@" "$<"


phaseone.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/phaseone.c
	$(CC) $(CFLAGS) -o "$@" "$<"


computeGrad_StoreHx.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/computeGrad_StoreHx.c
	$(CC) $(CFLAGS) -o "$@" "$<"


computeFval_ReuseHx.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/computeFval_ReuseHx.c
	$(CC) $(CFLAGS) -o "$@" "$<"


squareQ_appendCol.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/squareQ_appendCol.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xrotg.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/xrotg.c
	$(CC) $(CFLAGS) -o "$@" "$<"


deleteColMoveEnd.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/deleteColMoveEnd.c
	$(CC) $(CFLAGS) -o "$@" "$<"


compute_deltax.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/compute_deltax.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solve.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/solve.c
	$(CC) $(CFLAGS) -o "$@" "$<"


compute_lambda.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/compute_lambda.c
	$(CC) $(CFLAGS) -o "$@" "$<"


addBoundToActiveSetMatrix_.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/addBoundToActiveSetMatrix_.c
	$(CC) $(CFLAGS) -o "$@" "$<"


linearForm_.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/linearForm_.c
	$(CC) $(CFLAGS) -o "$@" "$<"


addAeqConstr.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/addAeqConstr.c
	$(CC) $(CFLAGS) -o "$@" "$<"


relaxed.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/relaxed.c
	$(CC) $(CFLAGS) -o "$@" "$<"


BFGSUpdate.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/BFGSUpdate.c
	$(CC) $(CFLAGS) -o "$@" "$<"


computeConstraints_.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/computeConstraints_.c
	$(CC) $(CFLAGS) -o "$@" "$<"


computeFiniteDifferences.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/computeFiniteDifferences.c
	$(CC) $(CFLAGS) -o "$@" "$<"


driver1.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/driver1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


updateWorkingSetForNewQP.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/updateWorkingSetForNewQP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


evalObjAndConstr.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/evalObjAndConstr.c
	$(CC) $(CFLAGS) -o "$@" "$<"


computeGradLag.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/computeGradLag.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xzgeqp3.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/xzgeqp3.c
	$(CC) $(CFLAGS) -o "$@" "$<"


feasibleratiotest.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/feasibleratiotest.c
	$(CC) $(CFLAGS) -o "$@" "$<"


factorQR.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/factorQR.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xgemv.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/xgemv.c
	$(CC) $(CFLAGS) -o "$@" "$<"


factorQRE.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/factorQRE.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xpotrf.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/xpotrf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xgemm.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/xgemm.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fullColLDL2_.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/fullColLDL2_.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Optimization_ThelenMuscle_codegen_rtwutil.obj : $(START_DIR)/codegen/lib/Optimization_ThelenMuscle_codegen/Optimization_ThelenMuscle_codegen_rtwutil.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


