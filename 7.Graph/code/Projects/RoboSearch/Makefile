
MAIN := Examples/main.c
# MAIN := Examples/test.c
TARGET := $(notdir $(basename $(MAIN)))


h_files := include/State-Environment.h \
		   include/System.h \
		   include/BFS-DFS.h \
		   include/Queue.h \
		   include/Stack.h

# h_files := include/test.h

c_srcs := $(patsubst include/%.h,src/%.c,$(h_files))
c_objs := $(patsubst src/%.c,objs/%.o,$(c_srcs))

include_dirs := include
linking_libs := m

I_options := $(include_dirs:%=-I%)
l_options := $(linking_libs:%=-l%)

compile_options := -g -O0 -gdwarf-2 $(I_options)
linking_options := $(l_options)


# Compile srcs
objs/%.o : src/%.c $(h_files)
	@echo [INFO]: Compile $< to $@
	@mkdir -p $(dir $@)
	@gcc -c $< -o $@ $(compile_options)

# Compile TARGET
objs/$(TARGET).o : $(MAIN) 
	@echo [INFO]: Compile $< to $@
	@mkdir -p $(dir $@)
	@gcc -c $< -o $@ $(compile_options)


workspace/$(TARGET).exe : objs/$(TARGET).o $(c_objs)
	@echo [INFO]: Linking $^ to $@
	@mkdir -p $(dir $@)
	@gcc $^ -o $@ $(linking_options)

all : workspace/$(TARGET).exe

run : workspace/$(TARGET).exe
	@./$<


debug :
	@echo $(c_srcs)
	@echo $(c_objs)


clean :
	@rm -rf objs lib workspace/*.exe

.PHONY : debug clean run