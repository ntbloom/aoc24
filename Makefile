OUTDIR=$(PWD)/build

EXE=$(OUTDIR)/aoc23
TEST_EXE=$(OUTDIR)/mainTest

.PHONY:cmake
cmake:
	cmake -B$(OUTDIR) -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"

.PHONY:build
build:
	make -C $(OUTDIR) -j 14

.PHONY:clean
clean:
	rm -rf $(OUTDIR)

.PHONY:all
all: clean cmake build

.PHONY:answer
ifdef puzzle
answer:
	@$(EXE) -d $(day) -p $(puzzle) #|| echo "usage: make day=X puzzle=Y"
else
answer:
	@$(EXE) -d $(day) -p 1
	@$(EXE) -d $(day) -p 2
endif

.PHONY:test
test:
	$(OUTDIR)/mainTest

.DEFAULT_GOAL:= build