#!/bin/bash


verilator -Wall --cc ../rtl/${1}.sv --exe ../tb/sim_${1}.cpp
make -j -C obj_dir -f V${1}.mk V${1}

cp obj_dir/V${1} .
rm -rf obj_dir

