
files = main 4_DLinkList

c_srcs := $(files:%=src/%.c)
c_objs := $(patsubst src/%.c,objs/%.o,$(c_srcs))

include_paths  := /datav/shared/Education/2_Cpp/5_DataStructureAndAlgorithm/1_List/
library_paths  := 
link_libraries := 


I_options := $(include_paths:%=-I%)
l_options := $(link_libraries:%=l%)
L_options := $(library_paths:%=L%)
r_options := $(library_paths:%=-Wl,-rpath=%)
# -fno-stack-protector
compile_options := -g -O3 -w ${I_options}
linking_options := ${l_options} ${L_options} ${r_options}

objs/%.o : src/%.c
	@echo Compile $^
	@mkdir -p $(dir $@)
	@gcc -c $^ -o $@ $(compile_options)

workspace/exec : $(c_objs)
	@echo Link to $@
	@mkdir -p $(dir $@)
	@gcc $^ -o $@ $(linking_options)

run : workspace/exec
	@./$<

debug :
	@echo ${c_srcs}
	@echo $(c_objs)

clean :
	@rm -rf objs/* workspace/exec


.PHONY : debug run clean

