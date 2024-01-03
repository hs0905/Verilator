
ifneq ($(words $(CURDIR)),1)
 $(error Unsupported: GNU Make cannot build in directories containing spaces, build elsewhere: '$(CURDIR)')
endif

ifeq ($(VERILATOR_ROOT),)
VERILATOR = verilator
else
export VERILATOR_ROOT
VERILATOR = $(VERILATOR_ROOT)/bin/verilator
endif

default:
	@echo "-- Verilator hello-world simple example"
	@echo "-- VERILATE & BUILD --------"
	$(VERILATOR) -cc --exe --build -j cnt.sv sim_main.cpp
	@echo "-- RUN ---------------------"
	obj_dir/Vcnt
	@echo "-- DONE --------------------"
	@echo "Note: Once this example is understood, see examples/make_tracing_c."
	@echo "Note: See also https://verilator.org/guide/latest/examples.html"


maintainer-copy::
clean mostlyclean distclean maintainer-clean::
	-rm -rf obj_dir *.log *.dmp *.vpd core
