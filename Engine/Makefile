# GNU Make solution makefile autogenerated by Premake
# Type "make help" for usage help

ifndef config
  config=debug
endif
export config

PROJECTS := Core Math Memory IO Thread File Audio Debugger Profile Framework Generics wxWidgetsSample

.PHONY: all clean help $(PROJECTS)

all: $(PROJECTS)

Core: 
	@echo "==== Building Core ($(config)) ===="
	@${MAKE} --no-print-directory -C . -f Core.make

Math: Core
	@echo "==== Building Math ($(config)) ===="
	@${MAKE} --no-print-directory -C . -f Math.make

Memory: 
	@echo "==== Building Memory ($(config)) ===="
	@${MAKE} --no-print-directory -C . -f Memory.make

IO: Core
	@echo "==== Building IO ($(config)) ===="
	@${MAKE} --no-print-directory -C . -f IO.make

Thread: Core
	@echo "==== Building Thread ($(config)) ===="
	@${MAKE} --no-print-directory -C . -f Thread.make

File: Core
	@echo "==== Building File ($(config)) ===="
	@${MAKE} --no-print-directory -C . -f File.make

Audio: Core
	@echo "==== Building Audio ($(config)) ===="
	@${MAKE} --no-print-directory -C . -f Audio.make

Debugger: Core
	@echo "==== Building Debugger ($(config)) ===="
	@${MAKE} --no-print-directory -C . -f Debugger.make

Profile: Core
	@echo "==== Building Profile ($(config)) ===="
	@${MAKE} --no-print-directory -C . -f Profile.make

Framework: Core
	@echo "==== Building Framework ($(config)) ===="
	@${MAKE} --no-print-directory -C . -f Framework.make

Generics: Core Memory
	@echo "==== Building Generics ($(config)) ===="
	@${MAKE} --no-print-directory -C . -f Generics.make

wxWidgetsSample: Core Audio
	@echo "==== Building wxWidgetsSample ($(config)) ===="
	@${MAKE} --no-print-directory -C . -f wxWidgetsSample.make

clean:
	@${MAKE} --no-print-directory -C . -f Core.make clean
	@${MAKE} --no-print-directory -C . -f Math.make clean
	@${MAKE} --no-print-directory -C . -f Memory.make clean
	@${MAKE} --no-print-directory -C . -f IO.make clean
	@${MAKE} --no-print-directory -C . -f Thread.make clean
	@${MAKE} --no-print-directory -C . -f File.make clean
	@${MAKE} --no-print-directory -C . -f Audio.make clean
	@${MAKE} --no-print-directory -C . -f Debugger.make clean
	@${MAKE} --no-print-directory -C . -f Profile.make clean
	@${MAKE} --no-print-directory -C . -f Framework.make clean
	@${MAKE} --no-print-directory -C . -f Generics.make clean
	@${MAKE} --no-print-directory -C . -f wxWidgetsSample.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "   debug"
	@echo "   release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   Core"
	@echo "   Math"
	@echo "   Memory"
	@echo "   IO"
	@echo "   Thread"
	@echo "   File"
	@echo "   Audio"
	@echo "   Debugger"
	@echo "   Profile"
	@echo "   Framework"
	@echo "   Generics"
	@echo "   wxWidgetsSample"
	@echo ""
	@echo "For more information, see http://industriousone.com/premake/quick-start"
