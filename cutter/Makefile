ObjSuf        = o
SrcSuf        = cxx
ExeSuf        =
DllSuf        = so
EVENTLIB      = $(EVENTO)
OutPutOpt     = -o
 
ROOTCFLAGS    = $(shell root-config --cflags)
ROOTLIBS      = $(shell root-config --libs)
ROOTGLIBS     = $(shell root-config --glibs)
 
# Solaris
CXX           = c++
CXXFLAGS      = -I$(EVT_INC) -I$(COMMON_INC)
#or next line for CC5
#CXXFLAGS      = -O -KPIC -D__SunOS_5_6 -library=iostream,no%Cstd
LD            = c++
#or next line for CC5
#LDFLAGS       = -g -library=iostream,no%Cstd -o
LDFLAGS       = -g -O2 -Wp,-MD -L$(EVT_LIB)
SOFLAGS       = -shared
 
 
CXXFLAGS     += $(ROOTCFLAGS)
LIBS          = $(ROOTLIBS)
GLIBS         = $(ROOTGLIBS)
EVENTLIBS     = -lEvent
 
#------------------------------------------------------------------------------
 
NMONITORO      = noise.$(ObjSuf)
NMONITORS      = noise.$(SrcSuf)
NMONITOR       = noise$(ExeSuf)

 
OBJS          = $(NMONITORO)
 
PROGRAMS      = $(NMONITOR)
 
all:            $(PROGRAMS)
 
test:		test.o 
		$(LD) $(LDFLAGS) test.o $(GLIBS) $(EVENTLIBS) $(OutPutOpt) test

DC_monitor:		DC_monitor.o 
		$(LD) $(LDFLAGS) DC_monitor.o $(GLIBS) $(EVENTLIBS) $(OutPutOpt) DC_monitor

dc_faker:	dc_faker.o 
		$(LD) $(LDFLAGS) dc_faker.o $(GLIBS) $(EVENTLIBS) $(OutPutOpt) dc_faker

dc_cutter:	dc_cutter.o 
		$(LD) $(LDFLAGS) dc_cutter.o $(GLIBS) $(EVENTLIBS) $(OutPutOpt) dc_cutter

emc_swap:	emc_swap.o 
		$(LD) $(LDFLAGS) emc_swap.o $(GLIBS) $(EVENTLIBS) $(OutPutOpt) emc_swap

noise:		noise.o 
		$(LD) $(LDFLAGS) noise.o $(GLIBS) $(EVENTLIBS) $(OutPutOpt) noise

packet:		packet.o 
		$(LD) $(LDFLAGS) packet.o $(GLIBS) $(EVENTLIBS) $(OutPutOpt) packet

efficiency:	efficiency.o 
		$(LD) $(LDFLAGS) efficiency.o $(GLIBS) $(EVENTLIBS) $(OutPutOpt) efficiency

phy:	        phy.o 
		$(LD) $(LDFLAGS) phy.o $(GLIBS) $(EVENTLIBS) $(OutPutOpt) phy

$(DCMONITOR):   $(DCMONITORO)
		$(LD) $(LDFLAGS) $(DCMONITORO) $(GLIBS) $(EVENTLIBS) $(OutPutOpt) $(DCMONITOR)
		@echo "$(DCMONITOR) done"
		@echo "Ready to rock and roll !"
		@rm -f $(OBJS) *Dict.* core
 
clean:
		@rm -f $(OBJS) *Dict.* core
 
.SUFFIXES: .$(SrcSuf)
 
###
 
.$(SrcSuf).$(ObjSuf):
	$(CXX) $(CXXFLAGS) -c $<








