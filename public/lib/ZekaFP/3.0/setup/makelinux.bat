@echo off
cd ../../..

tar cvf ZekaFP/3.0/setup/output/zfplib31sdk.tar ZekaFP/3.0/include/
tar rvf ZekaFP/3.0/setup/output/zfplib31sdk.tar ZekaFP/3.0/zfplib/
tar rvf ZekaFP/3.0/setup/output/zfplib31sdk.tar ZekaFP/3.0/docs/api/
tar rvf ZekaFP/3.0/setup/output/zfplib31sdk.tar ZekaFP/3.0/docs/other/
tar rvf ZekaFP/3.0/setup/output/zfplib31sdk.tar ZekaFP/3.0/samples/cpp/sellfree/Makefile ZekaFP/3.0/samples/cpp/sellfree/sellfree.cpp
tar rvf ZekaFP/3.0/setup/output/zfplib31sdk.tar ZekaFP/3.0/license.html
gzip -9 -f ZekaFP/3.0/setup/output/zfplib31sdk.tar

cd ZekaFP/3.0/setup

pause
