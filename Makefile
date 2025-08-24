.ONESHELL:
SHELL           =/bin/bash
MAKEFLAGS       += $(if $(VERBOSE),,--no-print-directory)
MINMAKEVERSION  =3.82
$(if $(findstring $(MINMAKEVERSION),$(firstword $(sort $(MINMAKEVERSION) $(MAKE_VERSION)))),,$(error The Makefile requires minimal GNU make version:$(MINMAKEVERSION) and you are using:$(MAKE_VERSION)))

ROOTODIR=/tmp/hellworld
INSTALLDIR=$(ROOTODIR)/install
ODIR=$(ROOTODIR)/build
PROJECT=helloworld

all:
	rm -rf $(ROOTODIR) $(INSTALLDIR)
	mkdir -p $(ODIR)
	rm -rf $(ODIR)/* 

	echo "Configuring '$(PROJECT)' Build Process"
	cmake -S $(CURDIR) -B $(ODIR) \
		-DCMAKE_INSTALL_PREFIX=$(INSTALLDIR) \
		$(if $(SHARED),-DBUILD_SHARED_LIBS=ON,)

	echo "Building '$(PROJECT)"
	cmake --build $(ODIR) --target install
	tree $(INSTALLDIR)
	$(ODIR)/app/hello_app
