#!/bin/bash
echo "/**"
echo " * This file is automaticly generated by genregs.awk. Please do not edit it "
echo " * Base files are ../ucode/register.h ../ucode/dos_register.h "
echo " *   ../ucode/c_always_on_pointer.h ../ucode/ddr3_reg.h "
echo " *   ../ucode/dmc_reg.h "
echo " *   ../ucode/c_stb_define.h ../ucode/secure_apb.h from VLSI team"
echo " * `date` "
echo " */"
echo "#ifndef __MACH_MESON8_REG_ADDR_H_"
echo "#define __MACH_MESON8_REG_ADDR_H_"
gawk -f genregs.awk ../ucode/register.h ../ucode/dos_register.h ../ucode/c_always_on_pointer.h ../ucode/ddr3_reg.h ../ucode/dmc_reg.h ../ucode/c_stb_define.h ../ucode/secure_apb.h ../ucode/hdmi.h


echo "#endif"