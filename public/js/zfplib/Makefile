
CXX = g++
CXXFLAGS = -fPIC -g -DPOSIX
OBJECTS = ZekaFP.o ZekaFP_cmds.o ZekaFP_error.o SerialA.o
STATICLIB = ../lib/zfplib.a
SOSMALLNAME = libzfp.so
SONAME = libzfp.so.1
SHARELIB = libzfp.so.3.0.9
SHARELIBPATH = /usr/local/lib

zfplib: $(OBJECTS)
	mkdir ../lib ; \
	ar rcs $(STATICLIB) $(OBJECTS) && \
	$(CXX) -shared -W1,-soname,$(SONAME) -o $(SHARELIB) $(OBJECTS) -lc

SerialA.o: posix/SerialA.cpp \
		posix/SerialA.h
	$(CXX) $(CXXFLAGS) -c posix/SerialA.cpp

ZekaFP.o: common/ZekaFP.cpp 	\
		common/ZekaFPint.h 	\
		../include/ZekaFP.h 		\
		../include/ZekaFPdefs.h
	$(CXX) $(CXXFLAGS) -c common/ZekaFP.cpp

ZekaFP_cmds.o: common/ZekaFP_cmds.cpp	\
		common/ZekaFPint.h 	\
		../include/ZekaFP.h 		\
		../include/ZekaFPdefs.h
	$(CXX) $(CXXFLAGS) -c common/ZekaFP_cmds.cpp

ZekaFP_error.o: common/ZekaFP_error.cpp \
		common/ZekaFPint.h 	\
		../include/ZekaFP.h 		\
		../include/ZekaFPdefs.h
	$(CXX) $(CXXFLAGS) -c common/ZekaFP_error.cpp

clean:
	rm *.o *~ $(STATICLIB) $(SHARELIB)

install: zfplib
	cp $(SHARELIB) $(SHARELIBPATH) ;\
	cd $(SHARELIBPATH) ;\
	rm $(SONAME) ;\
	rm $(SOSMALLNAME) ;\
	ln -s $(SHARELIB) $(SONAME) ; \
	ln -s $(SHARELIB) $(SOSMALLNAME) ; \
	cd - ;\
	ldconfig -n $(SHARELIBPATH)
