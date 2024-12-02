OUTDIR=$(PWD)/build

EXE=$(OUTDIR)/aoc23
TEST_EXE=$(OUTDIR)/mainTest


CMAKE_FLAGS= -B$(OUTDIR)
CMAKE_FLAGS+=-G Ninja
CMAKE_FLAGS+=-DCMAKE_BUILD_TYPE=Debug
.PHONY:cmake
cmake:
	cmake $(CMAKE_FLAGS)

.PHONY:build
build:
	cmake --build $(OUTDIR) -j `nproc`

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